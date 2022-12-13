//include directories
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <vector>
#include "MCG_GFX_Lib.h"
#include "Camera.h"
#include "Ray.h"
#include "Raytracer.h"
#include "sphere.h"
#include <thread>
#include <mutex>
#include <Windows.h>

std::mutex m;
camera cam;
Material spheremat;
sphere inviscircle = sphere(0.001, glm::vec3(0, 0, 0), spheremat);
Raytracer tracer;
ray r;

int loop()
{
	m.lock();

	//main loop for the raytracer, checks every pixel
	for (int y = 0; y < MCG::getwinsize().y; y++)
	{
		r = cam.camray(glm::vec2(y));
		MCG::DrawPixel(glm::vec2(y), tracer.returncol(r));

		std::cout << "1" << std::endl;
	}
	m.unlock();

}

int loop2()
{
	m.lock();
	for (int x = 0; x < MCG::getwinsize().x; x++)
	{
		r = cam.camray(glm::vec2(x));
		MCG::DrawPixel(glm::vec2(x), tracer.returncol(r));

		std::cout << "2" << std::endl;
	}
	m.unlock();
}

//void loopfinal()
//{
//	m.lock();
//	ray r = cam.camray(glm::vec2(y,x));
//	MCG::DrawPixel(glm::vec2(x), tracer.returncol(r));
//	std::cout << "3" << std::endl;
//	m.unlock();
//}


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


	//std::thread t1(loop); std::thread t2(loop2);
	//t1.join(); t2.join();

	std::thread myThreads[4];

	myThreads[0] = std::thread(loop);
	myThreads[1] = std::thread(loop2);
	myThreads[0].join();
	myThreads[1].join();







		// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	std::cout << " Finished tracing" << std::endl;
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

	//}

}
