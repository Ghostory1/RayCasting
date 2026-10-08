#include "RTWeekend.h"

#include "camera.h"
#include "Hittable.h"
#include "HittableList.h"
#include "Sphere.h"
#include "Lambertian.h"
#include "Metal.h"
#include "Dielectric.h"

#include <iostream>
using namespace std;


int main()
{
	HittableList world;

	auto materialGround = std::make_shared<Lambertian>(Color(0.8, 0.8, 0.0));
	auto materialCenter = std::make_shared<Lambertian>(Color(0.1, 0.2, 0.5));
	auto materialLeft = std::make_shared<Dielectric>(1.50);
	auto materialBubble = std::make_shared<Dielectric>(1.0 / 1.50);
	auto materialRight = std::make_shared<Metal>(Color(0.8, 0.6, 0.2),1.0);


	world.Add(std::make_shared<Sphere>(Point3(0.0, -100.5, -1.0), 100.0 ,materialGround));
	world.Add(std::make_shared<Sphere>(Point3(0.0, 0.0, -1.2), 0.5, materialCenter));

	world.Add(std::make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), 0.5, materialLeft));
	world.Add(std::make_shared<Sphere>(Point3(-1.0, 0.0, -1.0), 0.4, materialBubble));

	world.Add(std::make_shared<Sphere>(Point3(1.0, 0.0, -1.0), 0.5, materialRight));

	Camera camera;
	camera.aspectRatio = 16.0 / 9.0;
	camera.imageWidth = 400;
	camera.samplesPerPixel = 100;
	camera.maxDepth = 50;

	camera.Render(world);
}

