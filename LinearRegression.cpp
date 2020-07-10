#include <iostream>
#include <vector>
#include <algorithm>

/*
* Linear reqression equation: Y=B0+B*X
* Loss Function: e(i) = p(i) - y(i), where p(i) - predicted value, y(i) - actual value of i-training example
* We will develop gradient descent algo to find of minumum of Loss Function
*/

bool sort_values(double a, double b);

int main()
{
	double x[]{ 1,3,4,6,7,8,9,8,9,10,11};
	double y[]{ 1,3,4,6,6,5,9,8,9,10,11};

	std::vector<double> errors;
	double err;
	//a - learning rate
	double b0{ 0 }, b1{ 0 }, a{ 0.01 };

	for (int i = 0; i < 20; i++) {
		int idx = i % 5;
		double p = b0 + b1* x[idx];
		err = p - y[idx];
		b0 = b0 - a * err;
		b1 = b1 - a * err * x[idx];
		errors.push_back(err);
	}

	std::sort(errors.begin(), errors.end(), sort_values);
	std::cout << "B0=" << b0 << ", B1=" << b1 << ", error(min)=" << errors[0] << std::endl;


	/*
	* Testing phase
	*/

	std::cout << "Enter any value to predict" << std::endl;
	double test;
	std::cin >> test;
	double predicted = b0 + b1 * test;
	std::cout << "Predicted value is  " << predicted << std::endl;
}


bool sort_values(double a, double b) {
	double a1 = abs(a - 0);
	double b1 = abs(b - 0);
	return a1 < b1;
}