#include <vector>
#include <iostream>
#include <algorithm>


#include "LogisticRegression.h"
#include "Utils.cpp"


/*
LogisticRegression (without SGD): predicted = 1 / (1 + e^-x)
if the probability > 0.5 then prediction is for class 0, otherwise - for class 1
SGD: output = b0 + b1*x1 + b2*x2
LogisticRegression (with SGD)
Our goal is to find the best values of BO,B1 and B2 based on training data
*/

LogisticRegression::LogisticRegression() {};

LogisticRegression::RegressionEquationParams LogisticRegression::fit() {
	
	Utils utils;
	// for storing the error values
	std::vector<double>error; 
	// for calculating error on each stage
	double err;    
	// initializing b0
	double b0{ 0 };
	// initializing b1
	double b1{ 0 };
	// initializing b2
	double b2{ 0 };
	// initializing learning rate
	double alpha{ 0.01 };
	// epsilon
	double  e{ 2.711828 };

	std::cout << "Running logistic regression algorigthm" << std::endl;

	//gradient descent
	for (int i = 0; i < 40; i++) { //Since there are 10 values in our dataset and we want to run for 4 epochs so total for loop run 40 times
		int idx = i % 10;   //for accessing index after every epoch
		double p = -(b0 + b1 * x1[idx] + b2 * x2[idx]); //making the prediction
		double pred = 1 / (1 + pow(e, p)); //calculating final prediction applying sigmoid
		err = y[idx] - pred;  //calculating the error
		b0 = b0 - alpha * err * pred * (1 - pred) * 1.0;   //updating b0
		b1 = b1 + alpha * err * pred * (1 - pred) * x1[idx];//updating b1
		b2 = b2 + alpha * err * pred * (1 - pred) * x2[idx];//updating b2
		//std::cout << "B0=" << b0 << " " << "B1=" << b1 << " " << "B2=" << b2 << " error=" << err << std::endl;

		error.push_back(err);

	}

	std::sort(errors.begin(), errors.end(), utils.sort_values);

	std::cout << "B0=" << b0 << " " << "B1=" << b1 << " " << "B2=" << b2 << " error=" << error[0] << std::endl;
	return RegressionEquationParams::RegressionEquationParams(b0, b1, b2);
}

double LogisticRegression::predict(LogisticRegression::RegressionEquationParams& params, double test1, double test2) {
	return params.getB0() + params.getB1() * test1 + params.getB2() * test2;
};

LogisticRegression::RegressionEquationParams::RegressionEquationParams(double b0, double b1, double b2) {
	this->b0 = b0;
	this->b1 = b1;
	this->b2 = b2;
}

double LogisticRegression::RegressionEquationParams::getB0() {
	return this->b0;
}

double LogisticRegression::RegressionEquationParams::getB1() {
	return this->b1;
}

double LogisticRegression::RegressionEquationParams::getB2() {
	return this->b2;
}
