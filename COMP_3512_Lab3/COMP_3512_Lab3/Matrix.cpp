#include "Matrix.hpp"
// COMP_3512_Lab3.cpp : Defines the entry point for the console application.
//

/*
DESCP:  Main constructor for the Matrix class
PRE: Takes no parameters
POST: Created a default 1x1 matrix with 0 stored in it.
*/
Matrix::Matrix() : dimensions{ 1 }, arr(new int[1])
{
	arr[0] = {0};
}

/*
DESCP: Constructor that takes an int for the Matrix class
PRE: Takes an int for the parament, and assumes this int is an non-negative number
POST: Creates a Matrix of size n^2 stored with 0 in it.
RETURN:
*/
Matrix::Matrix(int n) : dimensions{ n }, arr{new int[n*n] }
{
	clear();
}

/*
DESCP: Constructor that takes an int array and an int for the Matrix class
PRE: Assumes that the array is not null, and the size of the array is not a negative number
POST: Cop
RETURN: 
*/
Matrix::Matrix(int n[], int size_of_array) : dimensions{ (int)sqrt(size_of_array) }
{
	if (pow(dimensions, 2) != size_of_array) {
		cerr << "Error, wrong size" << endl;
	}
	arr = new int[size_of_array];
	for (int i = 0; i < size_of_array; ++i) {
		arr[i] = n[i];
	}
}

/*
DESCP: 
PRE: 
POST: 
RETURN: 
*/
Matrix::Matrix(const Matrix & other) : dimensions{ other.dimensions }
{
	arr = new int[dimensions * dimensions];
	for (int i = 0; i < dimensions * dimensions; ++i) {
		arr[i] = other.arr[i];
	}
}

Matrix::~Matrix()
{
	delete[] arr;
}

void Matrix::set_value(int row, int col, int new_value)
{
	arr[(row * dimensions) +  col] = new_value;
}

int Matrix::get_value(int row, int col) const
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
	Matrix a(dimensions);
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			if (i == j) {
				a.set_value(i, j, 1);
			}
			else {
				a.set_value(i, j, 0);
			}
		}
	}
	return a;
}

ostream& operator<<(ostream & output, const Matrix & matrix)
{
	for (int i = 0; i < matrix.dimensions; ++i) {
		for (int j = 0; j < matrix.dimensions; ++j) {
			output << matrix.arr[i * matrix.dimensions + j];
		}
		output << "\n";
	}
	return output;
}

bool operator==(const Matrix & lefthand, const Matrix & righthand)
{
	if (lefthand.dimensions != righthand.dimensions) {
		return false;
	}
	for (int i = 0; i < lefthand.dimensions; ++i) {
		for (int j = 0; j < righthand.dimensions; ++j) {
			if (lefthand.get_value(i, j) != righthand.get_value(i, j)) {
				return false;
			}
		}
	}
	return true;
}

bool operator!=(const Matrix & lefthand, const Matrix & righthand)
{
	return !operator==(lefthand, righthand);
}

bool operator<(const Matrix & lefthand, const Matrix & righthand)
{
	return lefthand.dimensions < righthand.dimensions;
}

bool operator>(const Matrix & lefthand, const Matrix & righthand)
{
	return operator< (righthand, lefthand);
}

bool operator<=(const Matrix & lefthand, const Matrix & righthand)
{
	return !operator> (lefthand, righthand);
}

bool operator>=(const Matrix & lefthand, const Matrix & righthand)
{
	return !operator< (lefthand, righthand);
}

Matrix operator+(Matrix lefthand, const Matrix & righthand)
{
	lefthand += righthand;
	return lefthand;
}

Matrix operator-(Matrix lefthand, const Matrix & righthand)
{
	lefthand -= righthand;
	return lefthand;
}

Matrix& Matrix::operator++()
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] = 1 + arr[tmp];
		}
	}
	return *this;
}

Matrix Matrix::operator++(int)
{
	Matrix tmp(*this);
	operator++();
	return tmp;
}

Matrix& Matrix::operator--()
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] = arr[tmp] - 1;
		}
	}
	return *this;
}

Matrix Matrix::operator--(int)
{
	Matrix tmp(*this);
	operator--();
	return tmp;
}

void Matrix::swap(Matrix & lefthand, Matrix & righthand)
{
	using std::swap;
	swap(lefthand.dimensions, righthand.dimensions);
	swap(lefthand.arr, righthand.arr);
}

Matrix& Matrix::operator=(Matrix righthand)
{
	swap(*this, righthand);
	return *this;
}

Matrix& Matrix::operator+=(const Matrix& righthand)
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[i * dimensions + j] += righthand.arr[i * dimensions + j];
		}
	}
	return *this;
}

Matrix& Matrix::operator-=(const Matrix & righthand)
{
	for (int i = 0; i < dimensions; ++i) {
		for (int j = 0; j < dimensions; ++j) {
			int tmp = i * dimensions + j;
			arr[tmp] -= righthand.arr[tmp];
		}
	}
	return *this;
}
