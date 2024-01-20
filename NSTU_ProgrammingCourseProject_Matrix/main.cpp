#include "Matrix.hpp"
#include <iostream>


int main()
{
	using namespace Math;

	Matrix matrix_1(3, 4);
	matrix_1.set(1, 2, 5);
	matrix_1.set(1, 1, 2);
	matrix_1.set(2, 2, 1);
	std::cout << "Matrix 1:\n";
	matrix_1.print();

	Matrix matrix_2(4, 3);
	matrix_2.set(3, 1, 3);
	matrix_2.set(2, 1, 1);
	matrix_2.set(2, 2, 7);
	std::cout << "\nMatrix 2:\n";
	matrix_2.print();

	Matrix matrix_3 = matrix_1 * matrix_2;
	std::cout << "\nMatrix 3 = Matrix 1 * Matrix 2\n";
	matrix_3.print();

	Matrix matrix_4(3, 4);
	matrix_4.set(1, 2, 3);
	matrix_4.set(2, 2, 6);
	matrix_4.set(1, 3, 1);

	matrix_4 += matrix_1;
	std::cout << "\nMatrix 4 += Matrix 1\n";
	matrix_4.print();

	Matrix matrix_5(3, 3);
	matrix_5.set(1, 1, 3);
	matrix_5.set(2, 1, 4);
	matrix_5.set(1, 2, 1);

	matrix_5 *= matrix_5;
	std::cout << "\nMatrix 5 *= Matrix 5\n";
	matrix_5.print();

	return 0;
}