#pragma once
#include"Ray.h"

class camera
{
public:

	//viewing matrix
	glm::mat4 viewmatrix;
	glm::vec4 viewvector;
	glm::vec4 viewtransformvector = viewmatrix * viewvector;
	//_viewMatrix = glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f));

	//projection matrix
	glm::mat4 lens{1.0f};
	//_projMatrix = glm::perspective(45.0f, 1.0f, 0.1f, 100.0f);

	ray camray(glm::vec2);
};


