#include <iostream>
#include <fstream>
#include <complex>
#include <vector>
#include <algorithm>

bool equation(std::complex<double> z) {
	std::vector<double> list;
	list.push_back(std::norm(z));
	int k;

	std::complex<double> temp(0, 0);

	for (k = 0; k < 5; k++) {
		temp = (temp * temp) + z;
		list.push_back(std::norm(temp));
	}

	if (std::is_sorted(begin(list), end(list))) {
		return false;
	}
	
	return true;
}

int main() {

	int i;
	int j;

	int x = 500;
	int y = 500;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << x << ' ' << y << "\n255\n";




	for (i = 0; i < y; i++) {
		for (j = 0; j < x; j++) {
			std::complex<double> z(j, i);
			if (equation(z)) {
				file << "225 225 225" << "\n";
			}
			else {
				file << "0 0 0" << "\n";
			}
		}
	}

	file.close();

	std::cout << "DONE!" << "\n";

}