#include "Raytracer.h"

//setting the radius and the position of the sphere
Raytracer::Raytracer()
{
    _object.SetRadius(6.0f);
    _object.SetPosition(glm::vec3(0, 0, -25.0f));
}

//function that returns the colour of the ray
glm::vec3 Raytracer::returncol(ray _ray)
{
    //checks if the ray has hit the sphere or not
    if (_object.IntersectTest(_ray).hitsphere)
    {
        //returns the colour which is calculated with this function
        return _object.ShadePixel(_ray, _object.IntersectTest(_ray).Intersectpoint);
    }

    //if it didnt hit then return 0 colour (which is the black background)
    return glm::vec3(0);
}
