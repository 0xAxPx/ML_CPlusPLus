#ifndef BASEALGO_H
#define BASEALGO_H

class BaseAlgo {

public:
	template <class T>
	T fit();

	template <class T>
	double predict(T params, double a);
};

#endif