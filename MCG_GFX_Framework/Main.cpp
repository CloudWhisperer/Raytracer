//include directories go here
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <vector>
#include <mutex>
#include "MCG_GFX_Lib.h"
#include "Camera.h"
#include "Ray.h"
#include "Raytracer.h"
#include "sphere.h"

//main function
int main(int argc, char* argv[])
{
	// Variable for storing window dimensions
	glm::ivec2 windowSize(640, 480);

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if (!MCG::Init(windowSize))
	{
		// We must check if something went wrong, (this is very unlikely)
		return -1;
	}

	// Sets every pixel to the same colour
	// parameters are RGB, numbers are from 0 to 1
	MCG::SetBackground(glm::vec3(0, 0, 0));

	// Preparing a position to draw a pixel
	glm::ivec2 pixelPosition = windowSize / 2;

	// Preparing a colour to draw
	// Colours are RGB, each value ranges between 0 and 1
	glm::vec3 pixelColour(1, 0, 0);

	//creates a camera,material,object, and raytracer to use in the main loop
	camera cam;
	Material spheremat;
	sphere inviscircle = sphere(0.001, glm::vec3(0, 0, 0), spheremat);
	Raytracer tracer;

	//Number of threads to use for ray tracing
	std::cout << "And please enter the amount of threads you would like to use" << std::endl;

	//this value is the amount of threads that will be used
	int noofthreads;

	//cin is where the user inputs a number
	std::cin >> noofthreads;

	//initialize mutex
	//mutex is for making sure the threads dont locke each other out
	std::mutex mtx;

	//vector of threads 
	std::vector<std::thread> threads;

	//main loop for the raytracer, checks every pixel
	//clock is used to calculate how long it took the program to load, measured in milliseconds
	std::chrono::steady_clock::time_point time1 = std::chrono::high_resolution_clock::now();

	//main loop, first does the whole loop based on the number of threads then generates the loop into split sections
	//so all the threads can work on the raytracer at the same time
	for (int i = 0; i < noofthreads; i++)
	{
		threads.push_back(std::thread([&tracer, &cam, &mtx, i, noofthreads]()
			{
				for (int y = i * (MCG::getwinsize().y / noofthreads); y < (i + 1)* (MCG::getwinsize().y / noofthreads); y++)
				{
					for (int x = 0; x < MCG::getwinsize().x; x++)
					{
						//turns the ray we made into the camera ray
						ray r = cam.camray(glm::vec2(x, y));
						//locks the thread to prevent deadlock
						mtx.lock();

						//draws the pixel on the screen with the colour
						MCG::DrawPixel(glm::vec2(x, y), tracer.returncol(r));
						//unlocks the mutex to allow thread to start working
						mtx.unlock();

					}
				}
			}));
	}

	//Joining threads
	for (int i = 0; i < noofthreads; i++)
	{
		threads[i].join();
	}

	//stops the timer and record how long it too
	std::chrono::steady_clock::time_point time2 = std::chrono::high_resolution_clock::now();
	std::chrono::milliseconds milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(time2 - time1);
	std::cout << "Time taken: " << milliseconds.count() << std::endl;

	//print to let user know tracer is finished
	std::cout << " Finished tracing" << std::endl;

	// Displays drawing to screen and holds until user closes window
	// You must call this AFTER all your drawing calls
	// Program will exit after this line
	return MCG::ShowAndHold();

}