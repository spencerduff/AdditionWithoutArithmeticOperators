#include <iostream>

int add(int a, int b);
double average(int a, int b);
bool isPow2(int a);
int robotPaths(int n, int m);

int main(){
	//int a, b;
	//std::cout << "Num 1: ";
	//std::cin >> a;
	//std::cout << "Num 2: "; 
	//std::cin >> b;

	//std::cout << a << " + " << b << " = " << add(a, b) << std::endl;
	//std::cout << a << " averaged with " << b << " is " << average(a, b) << std::endl;
	//std::cout << a << " is ";
	//if (!isPow2(a)) 
	//	std::cout << "not ";
	//std::cout << "a power of 2." << std::endl;

	//std::cout << b << " is ";
	//if (!isPow2(b))
	//	std::cout << "not ";
	//std::cout << "a power of 2." << std::endl;

	int matrixSize;

	std::cout << "What NxN matrix for robot paths: ";
	std::cin >> matrixSize;

	std::cout << "Number of Paths: " << robotPaths(matrixSize, matrixSize);

	return 0;
}

int add(int a, int b){
	int temp2 = a | b;
	int temp = a & b;
	temp2 &= (temp^INT_MAX);
	temp <<= 1;
	while (temp & (a^b)){
		temp2 &= (temp^INT_MAX);
		temp &= (a^b);
		temp <<= 1;
	}
	return temp | temp2;
}

double average(int a, int b){
	int temp2 = a | b;
	int temp = a & b;
	temp2 &= (temp^INT_MAX);
	temp <<= 1;
	while (temp & (a^b)){
		temp2 &= (temp^INT_MAX);
		temp &= (a^b);
		temp <<= 1;
	}
	if (((temp | temp2) & 1) == 0){
		return double((temp | temp2) >> 1);
	}
	else{
		return double(temp | temp2) / 2;
	}
}

bool isPow2(int a){
	a &= (a - 1);
	return (a == 0);
}

int robotPaths(int n, int m){
	if (n == 1 && m == 1)
		return 1;
	if (n < 1 || m < 1)
		return 0;
	return robotPaths(n - 1, m) + robotPaths(n, m - 1);
}