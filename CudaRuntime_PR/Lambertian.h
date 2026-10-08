#pragma once
#include "Material.h"

class Lambertian : public Material
{
public:
	explicit Lambertian(const Color& albedo)
		:mAlbedo(albedo)
	{
	}

	bool Scatter(const Ray& rayIn, const HitRecord& hitRecord, Color& attenuation, Ray& scatterd) const override
	{
		Vec3 scatterDirection = hitRecord.Normal + RandomUnitVector();
		if (scatterDirection.NearZero())
			scatterDirection = hitRecord.Normal;
		scatterd = Ray(hitRecord.P, scatterDirection);
		attenuation = mAlbedo;

		return true;
	}

private:
	Color mAlbedo;
};