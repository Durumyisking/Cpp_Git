#pragma once

struct Vec2
{
	float x;
	float y;

public:
	float Length() { return sqrt(x * x + y * y); } // 빗변

	Vec2& Nomalize()
	{
		float fLen = Length();

		assert(fLen != 0.f); // 분모가 0이면 inf되니까 예외처리
		x /= fLen;
		y /= fLen;

		return *this;
	}

public:
	Vec2()
		: x(0.f)
		, y(0.f)
	{}

	Vec2(float _x, float _y)
		: x(_x)
		, y(_y)
	{}

	Vec2(int _x, int _y)
		: x((float)_x)
		, y((float)_y)
	{}
	Vec2(const Vec2& _vec)
		: x((float)_vec.x)
		, y((float)_vec.y)
	{}



};