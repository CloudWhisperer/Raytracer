#pragma once
#include"Ray.h"

class camera
{
public:
	ray camray(glm::vec2);


protected:
	//viewing matrix
	//glm::mat4 viewmatrix;
	//glm::vec4 viewvector;
	//glm::vec4 viewtransformvector = viewmatrix * viewvector;

	//projection matrix
	//glm::mat4 lens{1.0f};


	glm::mat4 _viewMatrix = glm::mat4(1.0f);// glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f));
	glm::mat4 _projMatrix = glm::perspective(glm::radians(45.0f), (640.0f/480.0f), 0.1f, 100.0f);

};


