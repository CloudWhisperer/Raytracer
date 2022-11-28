#pragma once
#include"Ray.h"

class camera
{
public:

	//viewing matrix
	glm::mat4 viewmatrix;
	glm::vec4 viewvector;
	glm::vec4 viewtransformvector = viewmatrix * viewvector;

	//projection matrix
	glm::mat4 lens{1.0f};

	ray camray(glm::vec2, glm::vec2);
};


