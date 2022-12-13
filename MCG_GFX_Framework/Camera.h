#pragma once
#include"Ray.h"
#include "MCG_GFX_Lib.h"
#include "SDL/SDL.h"

//creates camera class
class camera
{
public:
	//creates a function for the ray
	ray camray(glm::vec2);

protected:
	//creates projection and view matrixes for the near and far planes
	glm::mat4 _viewMatrix = glm::mat4(1.0f);// glm::translate(glm::mat4(1.0f), glm::vec3(0, 0, -3.5f));
	glm::mat4 _projMatrix = glm::perspective(glm::radians(45.0f), (640.0f/480.0f), 0.1f, 100.0f);
};


