#include <iostream>
#include <string>
#include <vector>

#include "Utils.cpp"
#include "LinearRegression.h"
#include "LogisticRegression.h"


int main() {

	Utils u;
	std::string os{ u.getOsName() };
	
	std::cout << "Running on: " << os << std::endl;

	LinearRegression linearRegression;
	LogisticRegression logisticRegression;
	

	//fit model
	auto linearParams = linearRegression.fit();
	auto test{ 7.0 };
	double predictionLin{ linearRegression.predict(linearParams, test) };
	
	std::cout << "Test value = " << test << std::endl;
	std::cout << "Predicted value = " << predictionLin << std::endl;

	//Mean Absolute Error
	std::cout << "MAE (LinearRegression) = " << test - predictionLin << std::endl;
	
	//LogisticRegression
	auto logisticParams = logisticRegression.fit();
	double test1{ 1.31107019 };
	double test2{ 2.862125076 };
	double predictionLog{ logisticRegression.predict(logisticParams, test1, test2) };
	std::cout << "Test1 value = " << test1 << std::endl;
	std::cout << "Test2 value = " << test2 << std::endl;

	
	if (predictionLog > 0.5) {
		predictionLog = 1; //Class 1
	}
	else {
		predictionLog = 0; //Class 0
	}

	std::cout << "Class predicted by LogisticRegression = " << predictionLog << std::endl;

	return 0;
}

