//directories that need to be included
#include "sphere.h"
#include <iostream>

//creating the sphere and setting the radius and the center of the sphere
sphere::sphere()
{
    radius = 0.f;
    sphereCenter = glm::vec3(0, 0, 0);
}

//setting the previous values as new values so we can use them for the functions
sphere::sphere(float _radius, glm::vec3 _sphereCenter, Material _mat)
{
    radius = _radius;
    sphereCenter = _sphereCenter;
    material = _mat;
}

//creating materal for the sphere
Material::Material()
{
    //default material constructor
    diffuseColour = glm::vec3(0, 1, 1);
    specularStrength = 0.f;
}
Material::Material(glm::vec3 _diffuseColour, float _specularStrength)
{
    specularStrength = _specularStrength;
    diffuseColour = _diffuseColour;
}

//--intersection function--
IntersectionResult sphere::IntersectTest(ray _ray)
{
    //creating values
    IntersectionResult testResult;
    testResult.hitsphere = false;

    //p - a calucation for easier use in next calculations
    glm::vec3 delta = sphereCenter - _ray.origin;

    //calculating d
    float d = glm::length(delta - glm::dot(delta,_ray.dir) * _ray.dir);

    //--calculate intersection point--

    //calculating x
    float intersectx = glm::sqrt((radius * radius) - (d * d));

    //final intersect point calculation
    glm::vec3 Intersect_Point = _ray.origin + (glm::dot((sphereCenter - _ray.origin), _ray.dir) - intersectx) * _ray.dir;
    
    //main intersection test
    //if the ray is less than the radius of the sphere that means it hit so set hit to true
    if (d <= radius)
    {
        testResult.Intersectpoint = Intersect_Point;
        testResult.hitsphere = true;
    }

    //returns the result of the ray
    return testResult;
}

//shading and surface normal process
glm::vec3 sphere::ShadePixel(ray _ray, glm::vec3 Intersectpoint)
{
    //creates a material
    Material mat(glm::vec3(0.5), 3.5f);

    //calling the function sphere normal and creating a vec3 from it
    glm::vec3 Spherenormal = spherenormal(sphereCenter, Intersectpoint);

    //creating a vec3 with the light direction and normalising it with the intersectpoint
    glm::vec3 lightdir = glm::normalize(LightPosition - Intersectpoint);

    //calculating diffuse
    float diff = glm::max(glm::dot(Spherenormal, lightdir), 0.0f);

    //makes the colour of circle
    glm::vec3 diffuse = diff * lightcol;

    //calculating ambient and specular to use in the final result
    float ambientLightStrength = 0.2f;
    glm::vec3 ambient = ambientLightStrength * lightcol;
    glm::vec3 viewdir = -glm::normalize(Intersectpoint);
    glm::vec3 reflectdir = glm::normalize(glm::reflect(-lightdir, Spherenormal));
    float spec = pow(glm::max(glm::dot(viewdir, reflectdir), 0.0f), 64);
    glm::vec3 specular = spec * mat.specularStrength * lightcol;

    //add all the shadings together to produce the specular lighting
    glm::vec3 result = (ambient + diffuse + specular)* mat.diffuseColour;

    //returning the final result
    return result;
}

//calculating the sphere normal using the equation
glm::vec3 sphere::spherenormal(glm::vec3 sphereCenter, glm::vec3 threedeesamplepoint)
{
    glm::vec3 normalvector = threedeesamplepoint - sphereCenter;
    normalvector = glm::normalize(normalvector);
    return normalvector;
}
