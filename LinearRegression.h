#ifndef LINEARREGRESSION_H
#define LINEARREGRESSION_H
#endif

#include "BaseAlgo.h"

class LinearRegression : public BaseAlgo 
{
private:

	//Definetely 10 elements size array is not enough to learn model, it is just example
	//X - independent var
	double x[10] = { 1, 3, 4, 6, 7, 8, 9, 8, 9, 10 };
	//Y - dependent var
	double y[10] = { 1, 3, 4, 6, 7, 8, 9, 8, 9, 10 };
	//errors
	std::vector<double> errors;
	double err;
	//a - learning rate
	double a{ 0.01 };

	class RegressionEquationParams {

	private:
		double b0{ 0 }, b1{ 0 };

	public:
		RegressionEquationParams(double b0, double b1);
		double getB0();
		double getB1();

	};

public:
	LinearRegression();

	LinearRegression::RegressionEquationParams fit();

	double predict(LinearRegression::RegressionEquationParams& params, int test);
};
