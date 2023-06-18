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
			switch (mandelbrot(c)) {
			case 100:
				file << "0 0 0" << "\n";
				break;
			case 90:
				file << "25 25 25" << "\n";
				break;
			case 80:
				file << "50 50 50" << "\n";
				break;
			case 70:
				file << "75 75 75" << "\n";
				break;
			case 60:
				file << "100 100 100" << "\n";
				break;
			case 50:
				file << "125 125 125" << "\n";
				break;
			case 40:
				file << "150 150 150" << "\n";
				break;
			case 30:
				file << "175 175 175" << "\n";
				break;
			case 20:
				file << "200 200 200" << "\n";
				break;
			case 10:
				file << "225 225 225" << "\n";
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
