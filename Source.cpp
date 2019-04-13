#include "tracer.h"
#include "sphere.h"
#include "vect.h"

#include <iostream>
#include <fstream>

using namespace std;


int main() {

	int Height = 500;
	int Width = 500;

	Vec3 pix_col(0, 0, 0);

	Tracer mtracer = Tracer();

	Sphere sphere1(Vec3(Width*0.5, Height*0.5, 20), 100, Vec3(100, 255, 40));

	mtracer.add(sphere1);

	ofstream my_Image("image.ppm");


	if (my_Image.is_open()) {
		my_Image << "P3\n" << Width << " " << Height << " 255\n";
		for (int i = 0; i < Width; i++) {
			for (int j = 0; j < Height; j++) {

				pix_col = mtracer.trace(i, j);


				my_Image << (int)pix_col.X << ' ' << (int)pix_col.Y << ' ' << (int)pix_col.Z << "\n";
			}
		}
		my_Image.close();
	}
	else
		cout << "Could not open the file";

	return 0;


}