#include "Camera.h"
#include <vector>
#include <algorithm>

ray camera::camray(glm::vec2 _pixelpos,glm::vec2 _screenres)
{

    // Task 1: convert _pixelpos from range (e.g. 0 -> 640) to range -1 to +1 in x and y
    // x and y must be in a continuous range from -1 to +1

    glm::distance(_pixelpos.x, _pixelpos.y);


    //tried to use std::generate
    //float e = 1.0f;
    //std::vector<float> b(e);
    //std::generate_e(b.begin(), e, increment());


    //tried to use glm length to determine the diffrence between them to calucate where the pixel is
    //glm::length(pixelx, pixely);

    // Task 2: construct a near point and a far point - these must be vec4

    glm::vec4 nearpoint;
    glm::vec4 farpoint;

    nearpoint.z = -1;
    nearpoint.w = 1;
    farpoint.z = 1;
    farpoint.w = 1;

    // the x and y will be those from Task 1
    // the near point will have a z of -1
    // the far point will have a z of +1
    // the w for both must be 1

    // Task 3: multiply both points by inverse proj matrix


    //glm::inverse(camera::lens(nearpoint * farpoint));


    // Task 4: divide each point by its own w

    nearpoint / nearpoint.w;
    farpoint / farpoint.w;

    // Task 5: multiply both points by the inverse view matrix




    // Task 6: construct ray




    //const float xnormal = static_cast<float>(_pixelpos.x), 0.0f, static_cast<float>(_screenres.y), 1.0f, -1.0f;

    //std::map<float, float*>_pixelpos,_screenres;
    //_pixelpos.x = 0.0f;
    //_screenres.y = 0.0f;

    //const float xnormal = map(static_cast<float>(pixelpos.x), 0.0f, static_cast<float>(mscreenresolution.y), 1.0f, -1.0f);

    return ray();
}
