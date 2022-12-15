//directories to inlclude
#pragma once
#include "Ray.h"
#include "sphere.h"
#include <vector>

//creates a raytracer class
class Raytracer
{
	//these are all public
public:
	//creates functions
	Raytracer();

	//function that returns a colour
	glm::vec3 returncol(ray _ray);

	//making a vector of objects to spawn lots of spheres
	std::vector<sphere> Objects;

	//a number determing how many sphere spawn in the scene
	int spawnamount;

	//these are all protected values
protected:
	//object of the sphere
	sphere _object;
};