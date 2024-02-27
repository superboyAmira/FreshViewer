#include "matrix.h"

Matrix Matrix::GetMinor(const int rows, const int cols) const {
  Matrix minor(rows_ - 1, cols_ - 1);
  int Row = 0;
  int Col = 0;
  for (int i = 0; i < this->rows_ - 1; i++) {
    if (i == rows) {
      Row = 1;
    }
    Col = 0;
    for (int j = 0; j < this->cols_ - 1; j++) {
      if (j == cols) {
        Col = 1;
      }
      minor.matrix_[i][j] = this->matrix_[i + Row][j + Col];
    }
  }

  return minor;
}

void Matrix::fill(double value) {
  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < this->cols_; j++) {
      this->matrix_[i][j] = value;
    }
  }
}
