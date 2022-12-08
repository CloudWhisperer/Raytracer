#pragma once
#include <GLM/glm.hpp>
#include "Ray.h"

class Material
{
public:
	glm::vec3 diffuseColour;
	float specularStrength;
	Material();
	Material(glm::vec3 _diffuseColour, float _specularStrength);
};

class IntersectionResult
{
public:
	glm::vec3 intersectionPoint;
	bool hit;
};


class sphere
{
public:
	//IntersectionResult sp_class;

	sphere();
	sphere(float _radius, glm::vec3 _sphereCenter, Material _mat);


	void SetRadius(float value) { radius = value; }
	void SetPosition(glm::vec3 value) { sphereCenter = value; }
	float GetRadius() { return radius; }
	glm::vec3 GetSphereCenter() { return sphereCenter; }
	Material GetMaterial() { return material; }

	glm::vec3 ShadePixel(ray _ray, glm::vec3 intersectionPoint);

	IntersectionResult IntersectTest(ray _ray);


	//glm::vec3 closepoint(ray _ray, glm::vec3 _3dquerypoint);

	//sphereclass hitormiss(ray _ray, glm::vec3 _spherecentre, float radius);

	//glm::vec3 getnormal(glm::vec3 _spherecentre, glm::vec3 _3dsamplepoint);

protected:

	Material material;
	float radius;
	glm::vec3 sphereCenter;


};
