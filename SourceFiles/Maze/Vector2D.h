#ifndef VECTOR2D_H
#define VECTOR2D_H

struct Vector2D
{
	float x;
	float y;

	Vector2D();
	Vector2D(float x, float y);

	bool IsZero();
	void Set(float X, float Y) {x = X; y = Y;}

	const Vector2D& operator+=(const Vector2D& rhs);
	const Vector2D& operator-=(const Vector2D& rhs);
	const Vector2D& operator*=(const Vector2D& rhs);
	const Vector2D& operator/=(const Vector2D& rhs);
};

#endif