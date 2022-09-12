#pragma once
#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
	T** data;
	int rows, cols;

	public:
		Matrix(int rows, int cols) {
			this->rows = rows;
			this->cols = cols;

			this->data = new T*[rows];

			for (int i = 0; i < rows; i++) {
				data[i] = new T[cols];
			}
		}

		~Matrix() {
			for (int i = 0; i < rows; i++) {
				delete[] this->data[i];
			}

			delete[] this->data;
		}

		void print() {
			cout << "Matrix: \n";

			for (int i = 0; i < rows; i++) {
				for (int j = 0; j < cols; j++) {
					cout << this->data[i][j] << " ";
				}
				cout << "\n";
			}
		}

		void fillFromKeyboard();
		void fillRandomly();

		const Matrix operator+(const Matrix& add) const;

		const Matrix operator-(const Matrix& minus) const;

		const Matrix operator*(const Matrix& umn) const;

};

