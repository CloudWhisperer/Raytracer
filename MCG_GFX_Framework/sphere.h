#pragma once
#include <GLM/glm.hpp>
#include "Ray.h"

class sphereclass
{
public:
	glm::vec3 vecresult;
	bool returnresult;
};


class sphere
{

	float intersection(ray _ray, glm::vec3 _vintersectionpoint);

	glm::vec3 closepoint(ray _ray, glm::vec3 _3dquerypoint);

	sphereclass hitormiss(ray _ray, glm::vec3 _spherecentre, float radius);

	glm::vec3 getnormal(glm::vec3 _spherecentre, glm::vec3 _3dsamplepoint);

};
