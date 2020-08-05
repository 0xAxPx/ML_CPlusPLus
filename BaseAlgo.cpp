#include <iostream>
#include <vector>
#include <string>

//interface
class BaseAlgo {

public:
	
	template <class T>
	T fit() {}

	template <class T>
	double predict(T params, double a) {};
};