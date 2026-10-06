#pragma once

#include "Hittable.h"
#include "RTWeekend.h"

class Camera
{
public:
	double aspectRatio = 1.0;
	int imageWidth = 100;

	void Render(const Hittable& world)
	{
		Initialize();

		std::cout << "P3\n " << imageWidth << ' ' << mImageHeight << " \n255\n";

		for (int scanlineIndex = 0; scanlineIndex < mImageHeight; scanlineIndex++)
		{
			std::clog << "\rScanlines remaining: "
				<< (mImageHeight - scanlineIndex)
				<< ' '
				<< std::flush;

			for (int pixelIndex = 0; pixelIndex < imageWidth; pixelIndex++)
			{
				auto pixelCenter =
					mPixel00Location
					+ (pixelIndex * mPixelDeltaU)
					+ (scanlineIndex * mPixelDeltaV);

				auto rayDirection = pixelCenter - mCenter;
				Ray ray(mCenter, rayDirection);

				Color pixelColor = RayColor(ray, world);
				WriteColor(std::cout, pixelColor);
			}
		}
		std::clog << "\rDone.                  \n";
	}

private:
	void Initialize()
	{
		mImageHeight = static_cast<int>(imageWidth / aspectRatio);
		mImageHeight = (mImageHeight < 1) ? 1 : mImageHeight;

		mCenter = Point3(0.0, 0.0, 0.0);

		// ºäÆ÷Æ®
		auto focalLength = 1.0;
		auto viewportHeight = 2.0;
		auto viewportWidth = viewportHeight * (static_cast<double>(imageWidth) / mImageHeight);

		auto viewportU = Vec3(viewportWidth, 0.0, 0.0);
		auto viewportV = Vec3(0.0, -viewportHeight, 0.0);

		mPixelDeltaU = viewportU / imageWidth;
		mPixelDeltaV = viewportV / mImageHeight;
		
		auto viewportUpperLeft =
			mCenter
			- Vec3(0.0, 0.0, focalLength)
			- viewportU / 2.0
			- viewportV / 2.0;

		mPixel00Location = viewportUpperLeft + 0.5 * (mPixelDeltaU + mPixelDeltaV);
	}

	Color RayColor(const Ray& ray, const Hittable& world) const
	{
		HitRecord hitRecord;

		if (world.Hit(ray, Interval(0.0, Infinity), hitRecord))
		{
			return 0.5 * (hitRecord.Normal + Color(1.0, 1.0, 1.0));
		}

		Vec3 unitDirection = UnitVector(ray.Direction());
		auto a = 0.5 * (unitDirection.Y() + 1.0);

		return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
	}


private:
	int mImageHeight = 0;
	Point3 mCenter;
	Point3 mPixel00Location;
	Vec3 mPixelDeltaU;
	Vec3 mPixelDeltaV;
};