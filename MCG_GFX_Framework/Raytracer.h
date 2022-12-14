#pragma once
#include "Ray.h"
#include "sphere.h"
#include <vector>

//creates a raytracer class
class Raytracer
{
public:
	//creates functions
	Raytracer();
	glm::vec3 returncol(ray _ray);
	int xaxis = 0;
	int yaxis = 0;
	std::vector<sphere> Objects;
	int spawnamount;

protected:
	//object of the sphere
	sphere _object;
};