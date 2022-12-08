#pragma once
#include <GLM/glm.hpp>
#include <GLM/gtc/matrix_transform.hpp>

class ray
{

public:
	glm::vec3 dir = glm::vec3(0, 0, 1);
	glm::vec3 origin = glm::vec3(0,0,0);

};