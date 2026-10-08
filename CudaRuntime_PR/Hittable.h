#pragma once
#include "Ray.h"
#include "Color.h"

class Material;

class HitRecord
{
public:

	std::shared_ptr<Material> material;
	Point3 P;
	Vec3 Normal;
	double T =0.0;
	bool bFrontFace = false;

	void SetFaceNormal(const Ray& ray, const Vec3& outwardNormal)
	{	
		// 히트 레코드 법선 벡터를 설정
		// 참고: 매개변수 outwardNormal은 단위 벡터를 가진다고 가정
		bFrontFace = Dot(ray.Direction(), outwardNormal) < 0.0;
		Normal = bFrontFace ? outwardNormal : -outwardNormal;
	}
};

class Hittable
{
public:
	virtual ~Hittable() = default;

	virtual bool Hit(const Ray& ray,const Interval& rayT, HitRecord& hitRecord) const = 0;
};