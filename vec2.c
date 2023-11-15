#include "main.h"

Vec2 vec_add(Vec2 v1, Vec2 v2)
{
	return (Vec2) { v1.x + v2.x, v1.y + v2.y };
}

Vec2 vec_sub(Vec2 v1, Vec2 v2)
{
	return (Vec2) { v1.x - v2.x, v1.y - v2.y };
}

Vec2 vec_scale(Vec2 v, float s)
{
	return (Vec2) {v.x * s, v.y * s};
}