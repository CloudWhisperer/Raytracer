#pragma once
#include "Ray.h"
#include "sphere.h"
#include <vector>


class Raytracer
{
public:
	Raytracer();

	glm::vec3 returncol(ray _ray);


protected:
	//std::vector<sphere> _objectList;

	sphere _object;

};