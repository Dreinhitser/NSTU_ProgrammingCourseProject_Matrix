#include "Matrix.hpp"

#include <iostream>

using namespace Math;

Matrix::Matrix(const Matrix& other)
{
	this->_matrix = other._matrix;
	this->_rows = other._rows;
	this->_columns = other._columns;
}


void Matrix::set(size_t i, size_t j, int value)
{
	if (i >= 0 && i < _rows && j >= 0 && j < _columns) {
		if (value != 0)
			_matrix.emplace(std::make_pair(i, j), value);
	}
	else {
		throw std::out_of_range("");
	}
}

int Matrix::get(size_t i, size_t j) const
{
	if (i < 0 || i >= _rows || j < 0 || j >= _columns)
		throw std::out_of_range("");

	auto it = _matrix.find(std::make_pair(i, j));
	if (it != _matrix.end())
		return it->second;
	else
		return 0;
}

void Matrix::print() const
{
	for (int i = 0; i < _rows; i++) {
		for (int j = 0; j < _columns; j++)
			std::cout << this->get(i, j) << "\t";

		std::cout << "\n";
	}
}

Matrix& Matrix::operator=(const Matrix& other)
{
	this->_matrix = other._matrix;
	this->_rows = other._rows;
	this->_columns = other._columns;

	return *this;
}

Matrix Matrix::operator*(const long& value)
{
	Matrix result(this->_rows, this->_columns);
	for (auto& it : this->_matrix)
		result.set(it.first.first, it.first.second, it.second * value);

	return result;
}

Matrix Matrix::operator+=(const Matrix& other)
{
	return *this + other;
}

Matrix Matrix::operator-=(const Matrix& other)
{
	return *this - other;
}

Matrix Matrix::operator*=(const Matrix& other)
{
	return *this * other;
}

bool Matrix::operator==(const Matrix& other)
{
	if (other._matrix == this->_matrix)
		return true;
	else
		return false;
}

bool Matrix::operator!=(const Matrix& other)
{
	if (other._matrix != this->_matrix)
		return true;
	else
		return false;
}

Matrix Math::operator+(const Matrix& matrix_1, const Matrix& matrix_2)
{
	if (matrix_1._rows != matrix_2._rows || matrix_1._columns != matrix_2._columns)
		throw std::logic_error("sum error");

	Matrix result(matrix_2._rows, matrix_2._columns);
	for (auto& it : matrix_1._matrix) {
		auto it_other = matrix_2._matrix.find(it.first);

		if (it_other != matrix_2._matrix.end())
			result.set(it.first.first, it.first.second, it.second + it_other->second);
		else
			result.set(it.first.first, it.first.second, it.second);
	}

	return result;
}

Matrix Math::operator-(const Matrix& matrix_1, const Matrix& matrix_2)
{
	if (matrix_1._rows != matrix_2._rows || matrix_1._columns != matrix_2._columns)
		throw std::logic_error("subtraction error");

	Matrix result(matrix_2._rows, matrix_2._columns);
	for (auto& it : matrix_1._matrix) {
		auto it_other = matrix_2._matrix.find(it.first);

		if (it_other != matrix_2._matrix.end())
			result.set(it.first.first, it.first.second, it.second - it_other->second);
		else
			result.set(it.first.first, it.first.second, it.second);
	}

	return result;
}

Matrix Math::operator*(const Matrix& matrix_1, const Matrix& matrix_2)
{
	if (matrix_1._rows != matrix_2._columns)
		throw std::logic_error("multiplication error");

	auto calc_element = [&](size_t i, size_t j) {
		int value = 0;
		for (int k = 0; k < matrix_1._rows; k++) {
			auto it_1 = matrix_1._matrix.find(std::make_pair(i, k));
			int value_1 = it_1 != matrix_1._matrix.end() ? it_1->second : 0;

			auto it_2 = matrix_2._matrix.find(std::make_pair(k, j));
			int value_2 = it_2 != matrix_2._matrix.end() ? it_2->second : 0;

			value += value_1 * value_2;
		}

		return value;
		};

	Matrix result(matrix_1._rows, matrix_2._columns);
	for (int i = 0; i < matrix_1._rows; i++)
		for (int j = 0; j < matrix_2._columns; j++)
			result.set(i, j, calc_element(i, j));

	return result;
}
