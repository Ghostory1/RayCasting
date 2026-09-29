#include <iostream>
#include "Color.h"
#include "Vec3.h"
#include "Ray.h"

using namespace std;

Color RayColor(const Ray& r)
{
	Vec3 unitDirection = UnitVector(r.Direction());
	auto a = 0.5 * (unitDirection.Y() + 1.0);

	return (1.0 - a) * Color(1.0, 1.0, 1.0) + a * Color(0.5, 0.7, 1.0);
}
int main()
{
	// 이미지
	auto aspectRatio = 16.0 / 9.0;
	int imageWidth = 400;

	// 이미지 높이를 계산 최소 1이 되도록
	int imageHeight = int(imageWidth / aspectRatio);
	imageHeight = (imageHeight < 0) ? 1 : imageHeight;

	// 카메라
	auto focalLength = 1.0;
	auto viewportHeight = 2.0;
	auto viewportWidth = viewportHeight * (double(imageWidth) / imageHeight);
	auto cameraCenter = Point3(0, 0, 0);

	//뷰포트의 수평 및 수직 가장자리를 가로지르는 벡터 계산
	auto viewportU = Vec3(viewportWidth, 0, 0);
	auto viewportV = Vec3(0, -viewportHeight, 0);

	// 픽셀 간 수평 및 수직 델타 벡터를 계산
	auto pixelDeltaU = viewportU / imageWidth;
	auto pixelDeltaV = viewportV / imageHeight;

	// 왼쪽 위 픽셀의 위치를 계산
	auto viewportUpperLeft = cameraCenter
		- Vec3(0, 0, focalLength) - viewportU / 2 - viewportV / 2;
	auto pixel100Loc = viewportUpperLeft + 0.5 * (pixelDeltaU + pixelDeltaV);

	// Render
	cout << "P3\n" << imageWidth << " " << imageHeight << "\n255\n";

	for (int y = 0; y < imageHeight; y++)
	{
		clog << "\rScanlines remaining: " << (imageHeight - y) << ' ' << flush;
		for (int x = 0; x < imageWidth; x++)
		{
			auto pixelCenter = pixel100Loc + (x * pixelDeltaU) + (y * pixelDeltaV);
			auto rayDirection = pixelCenter - cameraCenter;
			Ray r(cameraCenter, rayDirection);
			
			Color pixelColor = RayColor(r);
			WriteColor(cout, pixelColor);
		}
	}

	clog << "\rDone.                   \n";
}