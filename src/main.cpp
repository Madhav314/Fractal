#include <iostream>
#include <fstream>
#include <complex>

int mandelbrot(std::complex<double> c) {
	int k;

	std::complex<double> z(0, 0);
	/* a point c belongs to the Mandelbrot set if and only if
	   |Z_n| <= 2 for all values of n >= 0
	*/ 
	for (k = 0; k < 100; k++) {
		if (abs(z) > 2.0) {
			return k;
		}
		z = (z * z) + c;
	}
	
	return 100;
}

int main() {

	double i;
	double j;

	const int height = 500;
	const int width = 750;

	const double x_lit = 3.0 / width;
	const double y_lit = 2.0 / height;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << width << ' ' << height << "\n255\n";

	for (j = 1.0; j > -1.0; j -= y_lit) { // y-axis up to down
		for (i = -2.0; i < 1.0; i += x_lit) { //x-axis left to right
			std::complex<double> c(i, j);
			if (mandelbrot(c) == 100) {
				file << "0 0 0" << "\n";
			}
			else {
				file << "255 255 255" << "\n";
			}
		}
	}

	file.close();

	std::cout << "DONE!" << "\n";

}
