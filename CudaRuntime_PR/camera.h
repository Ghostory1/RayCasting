#pragma once

#include "Hittable.h"
#include "Material.h"
#include "RTWeekend.h"

class Camera
{
public:
	double aspectRatio = 1.0; // 이미지 넓이 대 높이 비율
	int imageWidth = 100; // 렌더링된 이미지 넓이 (픽셀 단위)
	int samplesPerPixel = 10; // 각 픽셀당 랜덤 샘플 수
	int maxDepth = 10; // 장면으로의 최대 광선 반사 횟수

	double vfov = 90; //수직 시야각
	Point3 lookfrom = Point3(0, 0, 0); // 카메라가 바라보는 위치
	Point3 lookat = Point3(0, 0, -1); // 카메라가 바라보는 점
	Vec3 vup = Vec3(0, 1, 0); // 카메라가 상대 "위쪽" 방향

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
				Color pixelColor(0.0, 0.0, 0.0);

				for (int sampleIndex = 0; sampleIndex < samplesPerPixel; sampleIndex++)
				{
					Ray ray = GetRay(pixelIndex, scanlineIndex);
					pixelColor += RayColor(ray,maxDepth ,world);
				}

				WriteColor(std::cout, mPixelSamplesScale * pixelColor);
			}
		}
		std::clog << "\rDone.                  \n";
	}

private:
	void Initialize()
	{
		mImageHeight = static_cast<int>(imageWidth / aspectRatio);
		mImageHeight = (mImageHeight < 1) ? 1 : mImageHeight;

		mPixelSamplesScale = 1.0 / static_cast<double>(samplesPerPixel);

		mCenter = lookfrom;

		// 뷰포트
		auto focalLength = (lookfrom - lookat).Length();
		auto theta = DegreesToRadians(vfov);
		auto h = std::tan(theta / 2);
		auto viewportHeight = 2.0 * h * focalLength;
		auto viewportWidth = viewportHeight * (static_cast<double>(imageWidth) / mImageHeight);

		// 카메라 좌표 프레임에 대한 u,v,w 단위 기저 벡터 계산
		w = UnitVector(lookfrom - lookat);
		u = UnitVector(Cross(vup,w));
		v = Cross(w, u);

		auto viewportU = viewportWidth * u; // 뷰포트 수평 가장자리를 가로지르는 벡터
		auto viewportV = viewportHeight * -v; // 뷰포트 수직 가장자리를 따라 내려가는 벡터

		mPixelDeltaU = viewportU / imageWidth;
		mPixelDeltaV = viewportV / mImageHeight;
		
		auto viewportUpperLeft =
			mCenter
			- (focalLength * w)
			- viewportU / 2.0
			- viewportV / 2.0;

		mPixel00Location = viewportUpperLeft + 0.5 * (mPixelDeltaU + mPixelDeltaV);
	}
	Ray GetRay(int pixelIndex, int scanlineIndex) const
	{
		auto offset = SampleSquare();
		auto pixelSample =
			mPixel00Location
			+ ((pixelIndex + offset.X()) * mPixelDeltaU)
			+ ((scanlineIndex + offset.Y()) * mPixelDeltaV);

		auto rayOrigin = mCenter;
		auto rayDirection = pixelSample - rayOrigin;

		return Ray(rayOrigin, rayDirection);
	}
	Vec3 SampleSquare() const
	{
		return Vec3(RandomDouble() - 0.5, RandomDouble() - 0.5, 0.0);
	}
	Color RayColor(const Ray& ray,int depth ,const Hittable& world) const
	{
		if (depth <= 0)
		{
			return Color(0.0, 0.0, 0.0);
		}
		HitRecord hitRecord;

		if (world.Hit(ray, Interval(0.001, Infinity), hitRecord))
		{
			Ray scattered;
			Color attenuation;
			if (hitRecord.material->Scatter(ray, hitRecord, attenuation, scattered))
			{
				return attenuation * RayColor(scattered, depth - 1, world);
			}
			return Color(0.0, 0.0, 0.0);
		}

		Vec3 unitDirection = UnitVector(ray.Direction());
		auto a = 0.5 * (unitDirection.Y() + 1.0);

		return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
	}


private:

	int mImageHeight = 0; //렌더링된 이미지 높이
	double mPixelSamplesScale = 1.0; // 픽셀 샘플 합계에 대한 색상 스케일 팩터

	Point3 mCenter; //카메라 중심
	Point3 mPixel00Location; //픽셀 0,0의 위치
	Vec3 mPixelDeltaU; // 오른쪽 픽셀로의 오프셋
	Vec3 mPixelDeltaV; // 아래 픽셀로의 오프셋
	Vec3 u, v, w; // 카메라 프레임 기저 벡터
};