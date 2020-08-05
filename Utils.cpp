#include <iostream>
#include <vector>

class Utils {

public:
	// determine of OS
	static std::string getOsName() {
	#ifdef _WIN32
		return "Windows 32-bit";	
	#elif _WIN64
		return "Windows 64-bit";
	#elif __linux__
		return "Linux";
	#elif __unix || __unix__
		return "Unix";
	#endif
	};

	static bool sort_values(double a, double b) {
		double a1 = abs(a - 0);
		double b1 = abs(b - 0);
		return a1 < b1;
	};
};