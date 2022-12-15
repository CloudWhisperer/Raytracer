//include directories are here
#include "Camera.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include "MCG_GFX_Lib.h"

ray camera::camray(glm::vec2 _pixelpos)
{
    //this is written into tasks to explain what im doing and whats happenning here
    // Task 1: convert _pixelpos from range (e.g. 0 -> 640) to range -1 to +1 in x and y
    // x and y must be in a continuous range from -1 to +1, so use float calculations

    //creates the range
    float pixelx = ((float)_pixelpos.x / MCG::getwinsize().x) * 2.0f - 1.0f;
    float pixely = ((float)_pixelpos.y / MCG::getwinsize().y) * 2.0f - 1.0f;


    // Task 2: construct a near point and a far point - these must be vec4
    // the x and y will be those from Task 1
    // the near point will have a z of -1 and the far point will have a z of +1
    // the w for both must be 1

    //creates the near point and far point and sets thier w and z axis respectively
    glm::vec4 nearpoint(pixelx,pixely,-1,1);
    glm::vec4 farpoint(pixelx, pixely, 1, 1);


    // Task 3: multiply both points by inverse proj matrix times the near/farpoint

    nearpoint = glm::inverse(_projMatrix)* nearpoint;
    farpoint = glm::inverse(_projMatrix)* farpoint;


    // Task 4: divide each point by its own w

    nearpoint = nearpoint / nearpoint.w;
    farpoint = farpoint / farpoint.w;


    // Task 5: multiply both points by the inverse view matrix

    nearpoint = glm::inverse(_viewMatrix) * nearpoint;
    farpoint = glm::inverse(_viewMatrix) * farpoint;


    // Task 6: construct ray

    ray r;
    r.origin = glm::vec3(nearpoint);
    r.dir = glm::normalize(glm::vec3(farpoint - nearpoint));

    //returns the ray
    return r;
}


