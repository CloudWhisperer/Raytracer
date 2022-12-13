
#include <iostream>
#include <cmath>
#include <SDL/SDL.h>
#include <vector>
#include "MCG_GFX_Lib.h"
#include "Camera.h"
#include "Ray.h"
#include "Raytracer.h"
#include "sphere.h"

//bool hit_sphere(glm::vec3 center, float radius, ray& r)
//{
//
//	glm::vec3 oc = r.origin - center;
//	float a = glm::dot(r.dir, r.dir);
//	float b = 2.0f * glm::dot(oc, r.dir);
//	float c = glm::dot(oc, oc) - radius * radius;
//	float discriminant = b * b - 4 * a * c;
//	return (discriminant > 0);
//
//	if (hit_sphere(sphere, sphereradius, r))
//	{
//		std::cout << "hit a sphere" << std::endl;
//	}
//}

////glm::vec3 colour(const ray& r)
//{
//	if (hit_sphere(sphere, sphereradius, r))
//	glm::vec3 unit_dir = r.dir;
//	float t = 0.5 * r.dir.y + 1.0f;
//	glm::vec3 u (1.0, 1.0, 1.0);
//	return (1.0-t) * u + t * glm::vec3(0.5, 0.7, 1.0);
//}

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

	//hit_sphere((0,0,0), 3.14f,ray);

	camera cam;


	Material spheremat;
	sphere inviscircle = sphere(0.001, glm::vec3(0, 0, 0), spheremat);

	Raytracer tracer;
	//tracer.arr.push_back(inviscircle);


	for (int y = 0; y < MCG::getwinsize().y; y++)
	{
		for (int x = 0; x < MCG::getwinsize().x; x++)
		{

			ray r = cam.camray(glm::vec2(x, y));
			MCG::DrawPixel(glm::vec2(x, y), tracer.returncol(r));

			//if (inviscircle.IntersectTest(r).hit == true)
			//{
			//	MCG::DrawPixel(glm::vec2(x, y), inviscircle.ShadePixel(r, inviscircle.IntersectTest(r).intersectionPoint));
			//}

			//else
			//{
			//	MCG::DrawPixel(glm::vec2(x, y), glm::vec3(0, 0, 0));
			//}



			/*
			inviscircle.hitormiss(r,inviscircle.GetSphereCenter(), inviscircle.GetRadius());
			//inviscircle.hitormiss(r, glm::vec3(0,0,0), 0.1);
			if (inviscircle.sp_class.returnresult == true)
			{
				//std::cout << "Hit circle at " << y << "y " << x << "x " << std::endl;

			}
			*/


			//std::cout << r.origin.x << std::endl;
			//std::cout << r.origin.y << std::endl;
			//std::cout << x << " x pos" << "  " << y << "y pos" << std::endl;

		}
	}

	std::cout << " Finished tracing" << std::endl;


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

		//}

		//cam.cammovement();
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
