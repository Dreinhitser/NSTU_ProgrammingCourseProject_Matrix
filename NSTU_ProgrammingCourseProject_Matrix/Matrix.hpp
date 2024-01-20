#pragma once

#include <type_traits>
#include <stdexcept>
#include <map>

namespace Math {
	class Matrix {
	public:
		Matrix(size_t rows, size_t columns) : _rows(rows), _columns(columns)
		{ }

		Matrix(const Matrix& other);

		size_t get_rows() const { return _rows; }
		size_t get_columns() const { return _columns; }

		void set(size_t i, size_t j, int value);
		int get(size_t i, size_t j) const;
		void print() const;

		Matrix& operator=(const Matrix& other);
		Matrix operator*(const long& value);
		Matrix operator+=(const Matrix& other);
		Matrix operator*=(const Matrix& other);

		friend Matrix operator+(const Matrix & matrix_1, const Matrix & matrix_2);
		friend Matrix operator-(const Matrix& matrix_1, const Matrix& matrix_2);
		friend Matrix operator*(const Matrix& matrix_1, const Matrix& matrix_2);

	private:
		std::map<std::pair<size_t, size_t>, long> _matrix;
		size_t _rows;
		size_t _columns;
	};
}