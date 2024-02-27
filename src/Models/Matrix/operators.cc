#include "matrix.h"

Matrix &Matrix::operator=(const Matrix &other) {
  if (this == &other) {
    return *this;
  }
  this->~Matrix();
  new (this) Matrix(other.rows_, other.cols_);
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
  return *this;
}

Matrix Matrix::operator+(const Matrix &other) const {
  Matrix result(*this);
  result.SumMatrix(other);
  return result;
}

Matrix Matrix::operator-(const Matrix &other) const {
  Matrix result(*this);
  result.SubMatrix(other);
  return result;
}

Matrix Matrix::operator*(const Matrix &other) const {
  Matrix result(*this);
  result.MulMatrix(other);
  return result;
}

Matrix Matrix::operator*(const double number) const {
  Matrix result(*this);
  result.MulNumber(number);
  return result;
}

bool Matrix::operator==(const Matrix &other) const {
  return this->EqMatrix(other);
}

Matrix Matrix::operator*=(const Matrix &other) {
  this->MulMatrix(other);

  return *this;
}

Matrix Matrix::operator+=(const Matrix &other) {
  this->SumMatrix(other);

  return *this;
}

Matrix Matrix::operator-=(const Matrix &other) {
  this->SubMatrix(other);

  return *this;
}

Matrix Matrix::operator*=(const double num) {
  this->MulNumber(num);

  return *this;
}

double &Matrix::operator()(int row, int col) {
  try {
    if (row >= rows_ || col >= cols_ || row < 0 || col < 0) {
      throw "Index is out of range!\n";
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }
  return matrix_[row][col];
}