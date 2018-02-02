#include "Matrix.hpp"
// COMP_3512_Lab3.cpp : Defines the entry point for the console application.
//

Matrix::Matrix() : dimensions{ 1 }, arr(new int[1]) 
{
	arr[0] = {0};
}

Matrix::Matrix(int n) : dimensions{ n }, arr{new int[dimensions*dimensions] }
{
	clear();
}

Matrix::Matrix(int n[], int size_of_array) : dimensions{ sqrt(size_of_array) == 0 }, arr{ new int[dimensions * dimensions] }
{
	clear();
}

Matrix::~Matrix()
{
	delete[] arr;
}

void Matrix::set_value(int row, int col, int new_value)
{
	arr[(row * dimensions) +  col] = new_value;
}

int Matrix::get_value(int row, int col)
{
	return (row * dimensions) + col;
}

void Matrix::clear()
{
	for (int i = 0; i < dimensions * dimensions; ++i) {
		arr[i] = 0;
	}
}

Matrix Matrix::identity()
{
	Matrix mirror(dimensions);
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			if (i == j) {
				arr[i * dimensions + j] == 1;
			}
			else {
				arr[i * dimensions + j] == 0;
			}
		}
	}
	return mirror;
}

ostream & operator<<(ostream & output, const Matrix & matrix)
{
	for (int i = 0; i < matrix.dimensions; ++i) {
		for (int j = 0; j < matrix.dimensions; ++j) {
			output << matrix.arr[i * matrix.dimensions + j];
		}
		output << "\n";
	}
	return output;
}

bool operator<=(const Matrix& lefthand, const Matrix& righthand)
{
	
}
