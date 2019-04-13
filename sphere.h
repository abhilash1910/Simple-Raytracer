#ifndef Sphere_h
#define Sphere_h

#include "vect.h"
#include "ray.h"
#include <cmath>



class Sphere {
	Vec3 Center;
	float Radius;

	Vec3 Color;

public:
	Sphere(Vec3 center, float radius, Vec3 color) : Center(center), Radius(radius), Color(color) {}

	Vec3 get_center() {
		return Center;
	}

	Vec3 get_color() {
		return Color;
	}

	Vec3 get_normal(Vec3 p) {
		return (p - Center) * (-1 / Radius);
	}

	bool intersect(Ray& ray, float &t) {
		Vec3 o = ray.get_origin();
		Vec3 d = ray.get_direction();

		Vec3 v = o - Center;

		const float b = 2 * v.dot(d);
		const float c = v.dot(v) - Radius * Radius;
		float delta = b * b - 4 * c;

		if (delta < 1e-4)
			return false;

		const float t1 = (-b - sqrt(delta)) / 2;
		const float t2 = (-b + sqrt(delta)) / 2;

		t = (t1 < t2) ? t1 : t2; // get the first intersection only

		return true;
	}
};
#endif