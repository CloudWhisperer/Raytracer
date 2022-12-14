#pragma once
#include <GLM/glm.hpp>
#include "Ray.h"

//class for material
class Material
{
 public:
	glm::vec3 diffuseColour = glm::vec3 (0,0,1);
	float specularStrength = 0.5f;
	Material();
	Material(glm::vec3 _diffuseColour, float _specularStrength);
};

//class for intersection result
class IntersectionResult
{
 public:
	glm::vec3 Intersectpoint;
	bool hitsphere;
};


class sphere
{
public:
	//light position and colour values
	glm::vec3 LightPosition = glm::vec3(25.0f, -20.0f, 15.0f);
	glm::vec3 lightcol = glm::vec3(0.8, 0.4, 0.5);
	Material material;

	//all functions are here
	sphere();
	sphere(float _radius, glm::vec3 _sphereCenter, Material _mat);
	void SetRadius(float value) { radius = value; }
	void SetPosition(glm::vec3 value) { sphereCenter = value; }
	float GetRadius() { return radius; }
	glm::vec3 GetSphereCenter() { return sphereCenter; }
	Material GetMaterial() { return material; }
	glm::vec3 ShadePixel(ray _ray, glm::vec3 intersectionPoint);
	IntersectionResult IntersectTest(ray _ray);
	glm::vec3 spherenormal(glm::vec3 sphereCenter, glm::vec3 threedeesamplepoint);

protected:
	//other values that dont need to be public are here

	float radius;
	glm::vec3 sphereCenter;
};
