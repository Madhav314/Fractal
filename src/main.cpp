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

	double i;
	double j;

	std::ofstream file;
	file.open("image.ppm");

	file << "P3\n" << 500 << ' ' << 500 << "\n255\n";

	equation(std::complex<double>(1, 0));


	for (i = -2; i < 1; i+=0.006) {
		for (j = -1; j < 1; j+=0.004) {
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