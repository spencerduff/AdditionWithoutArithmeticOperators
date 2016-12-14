#include <iostream>

int add(int a, int b);
float average(int a, int b);
bool isPow2(int a);
int robotPaths(int n, int m);

int main(){
	int a, b;
	std::cout << "Num 1: ";
	std::cin >> a;
	std::cout << "Num 2: "; 
	std::cin >> b;

	std::cout << a << " + " << b << " = " << add(a, b) << std::endl;
	std::cout << a << " averaged with " << b << " is " << average(a, b) << std::endl;
	std::cout << a << " is ";
	if (!isPow2(a)) 
		std::cout << "not ";
	std::cout << "a power of 2." << std::endl;

	std::cout << b << " is ";
	if (!isPow2(b))
		std::cout << "not ";
	std::cout << "a power of 2." << std::endl;

	//int matrixSize;

	//std::cout << "What NxN matrix for robot paths: ";
	//std::cin >> matrixSize;

	//std::cout << "Number of Paths: " << robotPaths(matrixSize, matrixSize);

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

float average(int a, int b){
	int i = add(a, b);
	if ((i & 1) == 0){
		return float(i >> 1);
	}
	else{ //Hacky type-casting bit arithmetic
		float f = float(i);
		int l = *(int*) &f;
		int l2 = *(int*)&f;
		l >>= 23;
		--l;
		l <<= 23;
		l2 <<= 8;
		l2 >>= 8;
		l |= l2;
		return *(float *) & l;
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