//include directories go here
#include "Raytracer.h"
#include <iostream>

//setting the radius and the position of the sphere
Raytracer::Raytracer()
{
    _object.SetRadius(6.0f);
    _object.SetPosition(glm::vec3(0, 0, -17.0f));

    //user enters the amount of spheres they would like to add in the scene
    std::cout << "Please enter the amount of Spheres you would like to spawn" << std::endl;
    std::cin >> spawnamount;

        //spawns in lots of spheres
        //loops depends on how many spheres the user asked to load
        for (int i = 0; i < spawnamount; i++)
        {
            sphere _spobject;
            _spobject.SetRadius(3.0f);
            _spobject.SetPosition(glm::vec3(std::rand() % 100 - 50, std::rand() % 100 - 50, std::rand() % 40 + 20));
            _spobject.material.diffuseColour = glm::vec3(0, 1, 0);
            _spobject.material.specularStrength = (0.5f);
            Objects.push_back(_spobject);
        }

}

//function that returns the colour of the ray
glm::vec3 Raytracer::returncol(ray _ray)
{
    //checks if the user put 1 sphere, since the location is random it could spawn a sphere off the screen
    //so hard code one sphere to make sure the user can see it
    if (spawnamount == 1)
    {
        //checks if the ray has hit the sphere or not
        if (_object.IntersectTest(_ray).hitsphere)
        {
            //returns the colour which is calculated with this function
            return _object.ShadePixel(_ray, _object.IntersectTest(_ray).Intersectpoint);
        }
    }
    //if the user has not entered 1
    else
    {
        //loops based on how many objects the user typed in
        for (int i = 0; i < Objects.size(); i++)
        {
            //checks if the ray has hit the sphere or not
            if (Objects[i].IntersectTest(_ray).hitsphere)
            {
                //returns the colour which is calculated with this function
                //change _object to Objects[i] for the multi sphere mode
                return Objects[i].ShadePixel(_ray, Objects[i].IntersectTest(_ray).Intersectpoint);
            }
        }
    }

    //if it didnt hit then return 0 colour (which is the black background)
    return glm::vec3(0);
}


