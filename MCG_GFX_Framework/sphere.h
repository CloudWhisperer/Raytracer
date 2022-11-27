#pragma once
#include <GLM/glm.hpp>
#include "Ray.h"

class sphere
{

	float intersection(ray _ray, glm::vec3 _vintersectionpoint);

	glm::vec3 closepoint(ray _ray, glm::vec3 _3dquerypoint);

	bool hitormiss(ray _ray, glm::vec3 _spherecentre, float radius);

	glm::vec3 getnormal(glm::vec3 _spherecentre, glm::vec3 _3dsamplepoint);

};
