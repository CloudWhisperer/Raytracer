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


	// Draws a single pixel at the specified coordinates in the specified colour!
	//MCG::DrawPixel( pixelPosition, pixelColour );

	// Do any other DrawPixel calls here
	// ...

	camera cam;
	Material spheremat;
	sphere inviscircle = sphere(0.001, glm::vec3(0, 0, 0), spheremat);
	Raytracer tracer;

	//Number of threads to use for ray tracing
	const int numThreads = 6;

	//initialize mutex
	std::mutex mtx;

	//vector of threads 
	std::vector<std::thread> threads;

	//main loop for the raytracer, checks every pixel
	for (int i = 0; i < numThreads; i++)
	{

		threads.push_back(std::thread([&tracer, &cam, &mtx]()
			{
				for (int y = 0; y < MCG::getwinsize().y; y++)
				{
					for (int x = 0; x < MCG::getwinsize().x; x++)
					{

						ray r = cam.camray(glm::vec2(x, y));
						mtx.lock();

						MCG::DrawPixel(glm::vec2(x, y), tracer.returncol(r));
						mtx.unlock();

					}
				}
			}));
	}

	//Joining threads
	for (int i = 0; i < numThreads; i++)
		threads[i].join();

	std::cout << " Finished tracing" << std::endl;

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	return MCG::ShowAndHold();


	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:
	// Variable to keep track of time
	//float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	//while (MCG::ProcessFrame())
	//{

	//}

	//// Set every pixel to the same colour
	//MCG::SetBackground(glm::vec3(0, 0, 0));

	//// Change our pixel's X coordinate according to time
	//pixelPosition.x = (windowSize.x / 2) + (int)(sin(timer) * 100.0f);
	//// Update our time variable
	//timer += 1.0f / 60.0f;

	//// Draw the pixel to the screen
	//MCG::DrawPixel(pixelPosition, pixelColour);

}