#pragma once
#include "Ray.h"
#include "sphere.h"
#include <vector>


class Raytracer
{



public:
	glm::vec3 returncol(ray _ray);
	std::vector<sphere> arr;
};