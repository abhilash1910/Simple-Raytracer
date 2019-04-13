#ifndef Tracer_h
#define Tracer_h

#include "sphere.h"

#include <vector>


using namespace std;

class Tracer {

	vector<Sphere> spheres;

public:
	Tracer() {}

	void add(Sphere sphere) {
		spheres.push_back(sphere);

	}

	Vec3 Shading(Ray ray, Sphere sphere, float &t) {
		Vec3 color(0, 0, 0);

		if (sphere.intersect(ray, t)) {
			Vec3 V = ray.get_direction();
			Vec3 P = ray.get_origin() + V * t;
			Vec3 N = sphere.get_normal(P);

			V = V.normalize();
			N = N.normalize();

			float facing_ratio = N.dot(V);

			color = sphere.get_color() * (facing_ratio * 0.5);
		}
		return color;
	}


	Vec3 trace(int x, int y) {


		Vec3 pix_col(0, 0, 0);


		float min_t = 1000000;
		float t;
		// I will correct this later        
		Vec3 ray_origin = Vec3(x, y, 0);
		Vec3 ray_direction = Vec3(0, 0, 1);

		Ray ray(ray_origin, ray_direction);
		for (int i = 0; i < spheres.size(); i++) {
			Vec3 color = Shading(ray, spheres[i], t);
			if (min_t > t) {
				pix_col = color;
				min_t = t;
			}
		}
		return pix_col;
	}

};
#endif
