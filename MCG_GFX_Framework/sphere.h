//include directories
#pragma once
#include <GLM/glm.hpp>
#include "Ray.h"

//class for material
class Material
{
	//these values are all public
 public:
	 //vec3 with a diffuse colour
	glm::vec3 diffuseColour = glm::vec3 (0,0,1);

	//strength of the specular
	float specularStrength = 0.5f;

	//material constructor
	Material();
	Material(glm::vec3 _diffuseColour, float _specularStrength);
};

//class for intersection result
class IntersectionResult
{
	//these values are public
 public:
	 //vector 3 with the intersectionpoint
	glm::vec3 Intersectpoint;

	//boolean to check whether we hit the sphere or not
	bool hitsphere;
};


class sphere
{
public:
	//these are all public
	//light position and colour values, creation of material
	glm::vec3 LightPosition = glm::vec3(25.0f, -20.0f, 15.0f);
	glm::vec3 lightcol = glm::vec3(1, 0.0, 0.0);
	Material material;

	//all functions are here
	//constructor of sphere
	sphere();
	sphere(float _radius, glm::vec3 _sphereCenter, Material _mat);

	//function to set the radius of the sphere
	void SetRadius(float value) { radius = value; }

	//function to set the position
	void SetPosition(glm::vec3 value) { sphereCenter = value; }

	//function to get the radius of the sphere
	float GetRadius() { return radius; }

	//function to get sphere center
	glm::vec3 GetSphereCenter() { return sphereCenter; }

	//function to get material
	Material GetMaterial() { return material; }

	//function that shades the pixel
	glm::vec3 ShadePixel(ray _ray, glm::vec3 intersectionPoint);

	//function that does the intersection calculations
	IntersectionResult IntersectTest(ray _ray);

	//function for the sphere normal calculations
	glm::vec3 spherenormal(glm::vec3 sphereCenter, glm::vec3 threedeesamplepoint);

protected:
	//other values that dont need to be public are here
	float radius;
	glm::vec3 sphereCenter;
};
