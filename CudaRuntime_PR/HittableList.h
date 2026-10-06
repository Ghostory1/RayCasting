#pragma once

#include "Hittable.h"

#include <memory>
#include <vector>

class HittableList : public Hittable
{
public:
	HittableList() = default;

	explicit HittableList(const std::shared_ptr<Hittable>& object)
	{
		Add(object);
	}

	void Clear()
	{
		mObjects.clear();
	}

	void Add(const std::shared_ptr<Hittable>& object)
	{
		mObjects.push_back(object);
	}

	bool Hit(
		const Ray& ray,
		const Interval& rayT,
		HitRecord& hitRecord
	) const override
	{
		HitRecord temporaryHitRecord;
		bool bHitAnything = false;
		auto closetSoFar = rayT.Max;

		for (const auto& object : mObjects)
		{
			Interval currentRayT(rayT.Min, closetSoFar);
			if (object->Hit(ray, currentRayT, temporaryHitRecord))
			{
				bHitAnything = true;
				closetSoFar = temporaryHitRecord.T;
				hitRecord = temporaryHitRecord;
			}
		}
		return bHitAnything;
	}

private:
	std::vector<std::shared_ptr<Hittable>> mObjects;
};