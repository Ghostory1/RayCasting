#pragma once
#include "Ray.h"

class HitRecord
{
public:
	void SetFaceNormal(const Ray& r, const Vec3& outwardNormal)
	{
		// 히트 레코드 법선 벡터를 설정
		// 참고: 매개변수 outwardNormal은 단위 벡터를 가진다고 가정
		bFrontFace = Dot(r.Direction(), outwardNormal) < 0;
		Normal = bFrontFace ? outwardNormal : -outwardNormal;

	}
	Point3 P;
	Vec3 Normal;
	double T;
	bool bFrontFace;
};

class Hittable
{
public:
	virtual ~Hittable() = default;

	virtual bool Hit(const Ray& ray,const Interval& rayT, HitRecord& hitRecord) const = 0;
};