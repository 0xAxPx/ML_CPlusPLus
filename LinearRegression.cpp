#include <iostream>
#include <vector>
#include <algorithm>

#include "LinearRegression.h"
#include "Utils.cpp"

/*
* Linear reqression equation: Y=B0+B*X, where BO (intercept) represent Y when X=0
* Loss Function: e(i) = p(i) - y(i), where p(i) - predicted value, y(i) - actual value of i-training example
* By gradient descent algo we find a minumum of Loss Function
**/

LinearRegression::LinearRegression() {};
	
LinearRegression::RegressionEquationParams LinearRegression::fit() {

	Utils utils;
	double b0{ 0 }, b1{ 0 };

	std::cout << "Running linear regression algorigthm" << std::endl;
	
	//gradient descent
	for (int i = 0; i < 20; i++) {
		int idx = i % 5;
		double p = b0 + b1 * x[idx];
		err = p - y[idx];
		b0 = b0 - a * err;
		b1 = b1 - a * err * x[idx];
		errors.push_back(err);
	}

	std::sort(errors.begin(), errors.end(), utils.sort_values);
	std::cout << "B0=" << b0 << ", B1=" << b1 << ", error(min)=" << errors[0] << std::endl;

	return RegressionEquationParams::RegressionEquationParams(b0, b1);
};

double LinearRegression::predict(LinearRegression::RegressionEquationParams& params, double test) {
	return params.getB0() + params.getB1() * test;
};

LinearRegression::RegressionEquationParams::RegressionEquationParams(double b0, double b1) {
	this->b0 = b0;
	this->b1 = b1;
}

double LinearRegression::RegressionEquationParams::getB0() {
	return this->b0;
}

double LinearRegression::RegressionEquationParams::getB1() {
	return this->b1;
}
