#ifndef ray_h
#define ray_h

#include "vect.h"
class Ray {

	Vec3 origin;
	Vec3 direction;
public:

	Ray(Vec3 ori, Vec3 dir) : origin(ori), direction(dir) {}
	Vec3 get_origin() {
	
		return origin;
	}
	Vec3 get_direction() {
		return direction;
	
	}


};








#endif 

