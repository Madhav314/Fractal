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

	const int width = 750;
	const int height = 625;

	const double x_lit = 3.0 / width;
	const double y_lit = 2.5 / height;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << width << ' ' << height << "\n255\n";

	for (j = 1.25; j > -1.25; j -= y_lit) { // y-axis up to down
		for (i = -2.25; i < 0.75; i += x_lit) { //x-axis left to right
			std::complex<double> c(i, j);
			switch (mandelbrot(c)) {
			case 100:
				file << "0 0 0" << "\n";
				break;
			case 90:
				file << "90 0 0" << "\n";
				break;
			case 80:
				file << "180 0 0" << "\n";
				break;
			case 70:
				file << "255 0 0" << "\n";
				break;
			case 60:
				file << "0 90 0" << "\n";
				break;
			case 50:
				file << "0 180 0" << "\n";
				break;
			case 40:
				file << "0 255 0" << "\n";
				break;
			case 30:
				file << "0 0 90" << "\n";
				break;
			case 20:
				file << "0 0 180" << "\n";
				break;
			case 10:
				file << "0 0 225" << "\n";
				break;
			default:
				file << "255 255 255" << "\n";
				break;
			}
		}
	}

	file.close();

	std::cout << "DONE!" << "\n";

}
