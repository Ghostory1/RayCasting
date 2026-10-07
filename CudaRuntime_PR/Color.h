#ifndef COLOR_H
#define COLOR_H

#include "Vec3.h"
#include "Interval.h"
#include <iostream>

using Color = Vec3;
inline double LinearToGamma(double linearComponent)
{
	if (linearComponent > 0.0)
	{
		return std::sqrt(linearComponent);
	}
	return 0.0;
}
void WriteColor(std::ostream& out, const Color& pixelColor)
{
	auto r = pixelColor.X();
	auto g = pixelColor.Y();
	auto b = pixelColor.Z();

	r = LinearToGamma(r);
	g = LinearToGamma(g);
	b = LinearToGamma(b);

	// [0,1]범위의 컴포넌트 값을 바이트 범위 [ 0,255 ] 로 변환
	static const Interval intensity(0.000, 0.999);

	int rByte = int(256.0 * intensity.Clamp(r));
	int gByte = int(256.0 * intensity.Clamp(g));
	int bByte = int(256.0 * intensity.Clamp(b));

	//픽셀 색상 컴포넌트 출력
	out << rByte << ' ' << gByte << ' ' << bByte << '\n';
}

#endif