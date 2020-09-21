#ifndef LOGISTICREGRESSION_H
#define LOGISTICREGRESSION_H

#include "BaseAlgo.h"

class LogisticRegression : public BaseAlgo {

	private:
		double x1[10] = { 2.7810836, 1.465489372, 3.396561688, 1.38807019, 3.06407232,7.627531214,5.332441248,6.922596716,8.675418651 ,7.673756466 };
		double x2[10] = { 2.550537003,2.362125076,4.400293529,1.850220317,3.005305973,2.759262235,2.088626775,1.77106367,-0.2420686549,3.508563011 };
		double y[10] = { 0, 0, 0, 0, 0, 1, 1, 1, 1, 1 };
		// error values
		std::vector<double> errors;
		// error for each step
		double err;    

		double b0 = 0; 
		double b1 = 0; 
		double b2 = 0; 
		// learing rate
		double alpha = 0.01;
		double e = 2.71828;

		class RegressionEquationParams {

		private:
			double b0{ 0 }, b1{ 0 }, b2{ 0 };

		public:
			RegressionEquationParams(double b0, double b1, double b2);
			double getB0();
			double getB1();
			double getB2();

		};


	public:
		LogisticRegression();
		LogisticRegression::RegressionEquationParams fit();
		double predict(LogisticRegression::RegressionEquationParams& params, double test1, double test2);
};

#endif