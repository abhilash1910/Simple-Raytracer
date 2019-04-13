#ifndef Vect_h
#define Vect_h

#include <cmath>


using namespace std;

class Vec3 {
public:

	float X;
	float Y;
	float Z;

	Vec3(float x, float y, float z) : X(x), Y(y), Z(z) {}

	Vec3 operator +(Vec3 vec) {
		return Vec3(X + vec.X, Y + vec.Y, Z + vec.Z);
	}

	Vec3 operator -(Vec3 vec) {
		return Vec3(X - vec.X, Y - vec.Y, Z - vec.Z);
	}

	Vec3 operator *(float scalar) {
		return Vec3(scalar*X, scalar*Y, scalar*Z);
	}

	Vec3 operator *(Vec3 vec) {
		return Vec3(vec.X*X, vec.Y*Y, vec.Z*Z);
	}

	float dot(Vec3 vec) {
		return X * vec.X + Y * vec.Y + Z * vec.Z;
	}

	float norm() {
		return sqrt(dot(*this));
	}

	Vec3 normalize() {
		return (*this)*(1 / norm());
	}

};

#endif
