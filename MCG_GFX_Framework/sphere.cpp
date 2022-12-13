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

/*
float sphere::intersection(ray _ray, glm::vec3 _vec3)
{
    _vec3.x / 255;
    _vec3.y / 255;
    _vec3.z / 255;

    //if (_ray.origin == )


    return  _vec3.x / 255;
}

glm::vec3 sphere::closepoint(ray _ray, glm::vec3 _3dquerypoint)
{
    glm::vec3 randompoint = _3dquerypoint - _ray.origin;

    float result = glm::dot((randompoint), _ray.origin);

    glm::vec3 x = _ray.origin + glm::dot((_3dquerypoint - _ray.origin), _ray.dir) * _ray.dir;

    return x;
}
*/

IntersectionResult sphere::IntersectTest(ray _ray)
{
    IntersectionResult testResult;
    testResult.hit = false;

    //get closest point on a line
    //glm::vec3 closepointx = _ray.origin + glm::dot((sphereCenter - _ray.origin), _ray.dir) * _ray.dir;

    //p - a thing
    glm::vec3 delta = sphereCenter - _ray.origin;

    //calculate d
    float d = glm::length(delta - glm::dot(delta,_ray.dir) * _ray.dir);

    //--calculate intersection point--

    //calculate x
    float intersectx = glm::sqrt((radius * radius) - (d * d));

    //making the intersect point
    glm::vec3 intersectpoint2 = _ray.origin + (glm::dot((sphereCenter - _ray.origin), _ray.dir) - intersectx) * _ray.dir;
    
    // main intersection test
    if (d <= radius)
    {
       //testResult.intersectionPoint = delta;
        testResult.intersectpoint2 = intersectpoint2;
        testResult.hit = true;
    }

    return testResult;


    /*
    if (delta.x  <= radius && delta.y <= radius && delta.z <= radius)
    {
        sp_class.returnresult = true;
        //std::cout << "x " << delta.x << std::endl;
        //std::cout << "y " << delta.y << std::endl;
        //std::cout << "z " << delta.z << std::endl;

    }

    else
    {
        sp_class.returnresult = false;
        //std::cout << sp_class.returnresult << std::endl;

    }

    //if (deltadot < 0)
    //{
    //    sp_class.returnresult = false;
    //   //std::cout << sp_class.returnresult;
    //    return sp_class;
    //}
       
    glm::vec3 d = _spherecentre - _ray.origin - glm::dot((_spherecentre - _ray.origin), _ray.dir) * _ray.dir;
    glm::vec3 x = glm::sqrt((_radius * _radius) - (d * d));

    //closest intersection point
    glm::vec3 closestintersectionpoint = _ray.origin + (glm::dot((_spherecentre - _ray.origin), _ray.dir) - x) * _ray.dir;

    sp_class.vecresult = closestintersectionpoint;


    //std::cout << "x " << closestintersectionpoint.x << std::endl;
    //std::cout << "y " << closestintersectionpoint.y << std::endl;
    //std::cout << "z " << closestintersectionpoint.z << std::endl;



    //const float closestpoint = glm::length(delta - (deltadot * _ray.dir));

    //if (closestpoint > _radius)
    //{
    //    sp_class.returnresult = false;
    //    //std::cout << sp_class.returnresult;
    //}
    //  


    //const float x = glm::sqrt(_radius * _radius - closestpoint * closestpoint);
    //glm::vec3 hitposition = _ray.origin + (deltadot - x) * _ray.dir;

    //glm::vec3 hitnormal = glm::normalize(hitposition - _spherecentre);

    //sp_class.returnresult = true;
    //sp_class.vecresult = hitposition;
    //std::cout << sp_class.returnresult;


    return sp_class;
    */
}

//shading and surface normal process
glm::vec3 sphere::ShadePixel(ray _ray, glm::vec3 intersectpoint2)
{
    Material mat(glm::vec3(0.5), 3.5f);

    glm::vec3 Spherenormal = spherenormal(sphereCenter, intersectpoint2);

    glm::vec3 lightdir = glm::normalize(lightpos - intersectpoint2);

    float diff = glm::max(glm::dot(Spherenormal, lightdir), 0.0f);

    //makes the colour of circle
    glm::vec3 diffuse = diff * lightcol;

    //calculating ambient and specular
    float ambientLightStrength = 0.1f;
    glm::vec3 ambient = ambientLightStrength * lightcol;
    glm::vec3 viewdir = -glm::normalize(intersectpoint2);
    glm::vec3 reflectdir = glm::normalize(glm::reflect(-lightdir, Spherenormal));
    float spec = pow(glm::max(glm::dot(viewdir, reflectdir), 0.0f), 64);
    glm::vec3 specular = spec * mat.specularStrength * lightcol;

    //add all the shadings together
    glm::vec3 result = (ambient + diffuse + specular)* mat.diffuseColour;

    return result;
}

glm::vec3 sphere::spherenormal(glm::vec3 sphereCenter, glm::vec3 threedeesamplepoint)
{
    glm::vec3 normalvector = threedeesamplepoint - sphereCenter;
    normalvector = glm::normalize(normalvector);
    return normalvector;
}
