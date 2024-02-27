#ifndef SRC_MATRIX_H_
#define SRC_MATRIX_H_

#include <cmath>
#include <iostream>

namespace s21 {

typedef class Matrix {
 private:
  // Attributes
  int rows_, cols_;  // Rows and columns
  double **matrix_;  // Pointer to the memory where the matrix is allocated

  void ExeptionNullColsRows() const;
  void ExeptionEqColsRows(const Matrix &) const;
  void ExeptionMultMatrixTerms(const Matrix &) const;
  void ExeptionSquareMatrix() const;

 public:
  // core
  Matrix();
  ~Matrix();
  Matrix(int, int);
  Matrix(const Matrix &);
  Matrix(Matrix &&);

  void CreateMatrix(int, int);
  void RemoveMatrix();

  // accessors
  int GetRows() const;
  int GetCols() const;
  // mutators
  void SetRows(int);
  void SetCols(int);

  // help functions
  void fill(double);
  // void print() const;
  Matrix GetMinor(int, int) const;

  // arith_logic
  double Determinant() const;
  void SumMatrix(const Matrix &);
  bool EqMatrix(const Matrix &) const;
  void SubMatrix(const Matrix &);
  void MulNumber(const double);
  void MulMatrix(const Matrix &);
  Matrix Transpose() const;
  Matrix CalcComplements() const;
  Matrix InverseMatrix() const;

  // operators
  bool operator==(const Matrix &) const;
  Matrix &operator=(const Matrix &);
  Matrix operator+(
      const Matrix &) const;  // для возможности b = a + c | c + a + b
  Matrix operator-(const Matrix &) const;
  Matrix operator*(const Matrix &) const;
  Matrix operator*(const double) const;
  Matrix operator*=(const double);
  Matrix operator*=(const Matrix &);
  Matrix operator+=(const Matrix &);
  Matrix operator-=(const Matrix &);
  double &operator()(int, int);

} Matrix;

}

#endif  // SRC_MATRIX_H_