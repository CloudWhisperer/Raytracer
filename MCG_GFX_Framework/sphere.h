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

class sphereclass
{
public:
	glm::vec3 vecresult;
	bool returnresult;
};


class sphere
{
public:
	sphereclass sp_class;
	glm::vec3 ShadePixel(ray _ray, glm::vec3 intersectionPoint);
	sphere();
	sphere(float _radius, glm::vec3 _sphereCenter, Material _mat);
	float GetRadius() { return radius; }
	glm::vec3 GetSphereCenter() { return sphereCenter; }
	Material GetMaterial() { return material; }
	Material material;
	float radius;
	glm::vec3 sphereCenter;


	float intersection(ray _ray, glm::vec3 _vintersectionpoint);

	glm::vec3 closepoint(ray _ray, glm::vec3 _3dquerypoint);

	sphereclass hitormiss(ray _ray, glm::vec3 _spherecentre, float radius);

	//glm::vec3 getnormal(glm::vec3 _spherecentre, glm::vec3 _3dsamplepoint);

};
