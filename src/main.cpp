#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <algorithm>

bool finite(std::complex<double> z) {
	std::vector<double> list;
	list.push_back(abs(z));
	int k;

	std::complex<double> temp(0, 0);

	for (k = 0; k < 10; k++) {
		temp = (temp * temp) + z;
		list.push_back(abs(temp));
	}

	if (std::is_sorted(begin(list), end(list))) {
		return false;
	}
	
	return true;
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
			std::complex<double> z(i, j);
			if (finite(z)) {
				file << "255 255 255" << "\n";
			}
			else {
				file << "0 0 0" << "\n";
			}
		}
	}

	file.close();

	std::cout << "DONE!" << "\n";

}