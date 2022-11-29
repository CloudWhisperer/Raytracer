
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include "MCG_GFX_Lib.h"
#include "Camera.h"
#include "Ray.h"
#include "Raytracer.h"

void drawcirclesmooth(int x, int y, float r, int colour);

int main(int argc, char* argv[])
{
	// Variable for storing window dimensions
	glm::ivec2 windowSize(640, 480);

	// Call MCG::Init to initialise and create your window
	// Tell it what size you want the window to be
	if (!MCG::Init(windowSize))
	{
		// We must check if something went wrong
		// (this is very unlikely)
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


	for (int y = 0; y < MCG::getwinsize().y; y++)
	{
		for (int x = 0; x < MCG::getwinsize().x; x++)
		{
			ray r = cam.camray(glm::vec2(y, x));

			Raytracer tracer;

			//MCG::DrawPixel(glm::vec2(x, y), tracer.returncol(r));

			//std::cout << x << " x pos" << "  " << y << "y pos" << std::endl;

		}

	}



	//std::cout << " Finished tracing" << std::endl;

	// Displays drawing to screen and holds until user closes window
	// You must call this after all your drawing calls
	// Program will exit after this line
	//return MCG::ShowAndHold();


	// Advanced access - comment out the above DrawPixel and MCG::ShowAndHold lines, then uncomment the following:
	// Variable to keep track of time
	float timer = 0.0f;

	// This is our game loop
	// It will run until the user presses 'escape' or closes the window
	//while (MCG::ProcessFrame())
	//{

	for (float i = 100.0f; i > 0;)
	{
		drawcirclesmooth(300, 250, i, 1);
		i -= 1;
	}
		return MCG::ShowAndHold();


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

void drawcirclesmooth(int x, int y, float r, int colour)
{
	static const double PI = 3.1415926535;
	double i, angle, x1, y1;
	glm::vec3 pixelColour(1, 0, 0);

	for (i = 0; i < 100; i += 0.001)
	{
		glm::ivec2 pixelPosition;
		angle = i;
		x1 = r * cos(angle * PI / 2) + x;
		y1 = r * sin(angle * PI / 2) + y;
		pixelPosition.x = x1;
		pixelPosition.y = y1;
		MCG::DrawPixel(pixelPosition, pixelColour);
	}
}
