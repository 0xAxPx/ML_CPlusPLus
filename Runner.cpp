#include <iostream>
#include <string>
#include <vector>

#include "Utils.cpp"
#include "LinearRegression.h"


int main() {

	Utils u;
	std::string os{ u.getOsName() };
	
	std::cout << "Running on " << os << std::endl;

	LinearRegression linearRegression;

	//fit model
	auto d = linearRegression.fit();
	auto test{ 7.0 };
	auto prediction{ linearRegression.predict(d, test) };
	
	std::cout << "Test value = " << test << std::endl;
	std::cout << "Predicted value = " << linearRegression.predict(d, test) << std::endl;
	
	//Mean Absolute Error
	std::cout << "MAE = " << test - prediction << std::endl;
	
	return 0;
}

