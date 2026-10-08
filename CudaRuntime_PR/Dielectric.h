#pragma once

#include "Material.h"

class Dielectric : public Material
{
public:
	explicit Dielectric(double refractionIndex)
		:mRefractionIndex(refractionIndex)
	{ }
	bool Scatter(const Ray& rayIn, const HitRecord& hitRecord, Color& attenuation, Ray& scattered) const override
	{
		attenuation = Color(1.0, 1.0, 1.0);

		// eta 는 굴절률 , etaIn 들어오는쪽 물질의 굴절률 , etaOut 나가는 쪽 물질의 굴절률 그래서, 밑에서 etaIn/ etaOut을 계산
		// 여기서 etaIn : 1.0 , etaOut : mRefractionIndex
		// bFrontFace가 true면 밖 -> 유리표면  //false면 유리내부 -> 밖으로
		const double refractionRatio = hitRecord.bFrontFace ? (1.0 / mRefractionIndex) : mRefractionIndex;

		const Vec3 unitDirection = UnitVector(rayIn.Direction());

		const double cosTheta = std::fmin(Dot(-unitDirection, hitRecord.Normal), 1.0);
		const double sinTheta = std::sqrt(1.0 - cosTheta * cosTheta);

		const bool cannotRefract = refractionRatio * sinTheta > 1.0;
		
		Vec3 direction;
		if (cannotRefract || Reflectance(cosTheta, refractionRatio) > RandomDouble())
		{
			direction = Reflect(unitDirection, hitRecord.Normal);
		}
		else
		{
			direction = Refract(unitDirection, hitRecord.Normal, refractionRatio);
		}
		scattered = Ray(hitRecord.P, direction);

		return true;
	}

private:
	//진공 또는 공기 중 굴절률, 또는 재질의 굴절률을 둘러싼 매질의 굴절률로 나눈 비율
	double mRefractionIndex;

	static double Reflectance(double cosine, double refractionIndex)
	{
		// Schlick의 반사율 근사 사용
		auto r0 = (1.0 - refractionIndex) / (1.0 + refractionIndex);
		r0 = r0 * r0;
		return r0 + (1.0 - r0) * std::pow((1.0 - cosine), 5);
	}
};