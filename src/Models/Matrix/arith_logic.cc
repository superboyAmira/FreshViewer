#include "matrix.h"

void Matrix::SumMatrix(const Matrix &other) {
  try {
    this->ExeptionEqColsRows(other);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] += other.matrix_[i][j];
      }
    }
  } catch (const char *error_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << error_messege;
  }
}

void Matrix::SubMatrix(const Matrix &other) {
  try {
    this->ExeptionEqColsRows(other);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] -= other.matrix_[i][j];
      }
    }
  } catch (const char *error_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << error_messege;
  }
}

bool Matrix::EqMatrix(const Matrix &other) const {
  bool status = true;
  try {
    this->ExeptionEqColsRows(other);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        if (fabs(this->matrix_[i][j] - other.matrix_[i][j]) > 1E-7)
          status = false;
      }
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
    status = false;
  }
  return status;
}

void Matrix::MulMatrix(const Matrix &other) {
  try {
    this->ExeptionNullColsRows();
    this->ExeptionMultMatrixTerms(other);
    other.ExeptionNullColsRows();

    Matrix result(this->rows_, other.cols_);
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < other.cols_; j++) {
        for (int k = 0; k < cols_; k++) {
          result.matrix_[i][j] += this->matrix_[i][k] * other.matrix_[k][j];
        }
      }
    }
    *this = result;
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }
}

void Matrix::MulNumber(const double num) {
  try {
    this->ExeptionNullColsRows();
    for (int i = 0; i < this->rows_; i++) {
      for (int j = 0; j < this->cols_; j++) {
        this->matrix_[i][j] *= num;
      }
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }
}

Matrix Matrix::Transpose() const {
  Matrix result;
  try {
    this->ExeptionNullColsRows();
    new (&result) Matrix{rows_, cols_};

    for (int i = 0; i < result.rows_; i++) {
      for (int j = 0; j < result.cols_; j++) {
        result.matrix_[i][j] = matrix_[j][i];
      }
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }
  return result;
}

Matrix Matrix::CalcComplements() const {
  Matrix result;
  try {
    this->ExeptionNullColsRows();
    this->ExeptionSquareMatrix();

    new (&result) Matrix{rows_, cols_};
    if (rows_ == 1) {
      result.matrix_[0][0] = matrix_[0][0];
    } else {
      // Matrix minor(rows_ - 1, cols_ - 1);
      for (int i = 0; i < rows_; i++) {
        for (int j = 0; j < cols_; j++) {
          Matrix minor(this->GetMinor(i, j));
          // minor.print();
          // double _t = minor.Determinant();
          result.matrix_[i][j] = minor.Determinant() * pow(-1, i + j);
          // result.print();
        }
      }
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }
  return result;
}

double Matrix::Determinant() const {
  double det = 0.0;
  try {
    this->ExeptionNullColsRows();
    this->ExeptionSquareMatrix();

    // printf("\n");
    // this->print();
    if (rows_ == 1) {
      det = matrix_[0][0];
    } else if (rows_ == 2) {
      det = matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0];
    } else {
      Matrix minor(rows_ - 1, cols_ - 1);

      for (int i = 0, sign = 1; i < rows_; i++, sign *= -1) {
        Matrix minor(this->GetMinor(i, 0));
        det += sign * matrix_[i][0] * minor.Determinant();
      }
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }
  return det;
}

Matrix Matrix::InverseMatrix() const {
  Matrix result;
  try {
    this->ExeptionNullColsRows();
    this->ExeptionSquareMatrix();
    // Matrix result(rows_, cols_);
    new (&result) Matrix{rows_, cols_};

    if (double det = Determinant(); fabs(det) > 1e-6) {
      if (rows_ == 1) {
        result.matrix_[0][0] = 1 / det;
      } else {
        result = CalcComplements();
        // result.print();
        result = result.Transpose();
        // result.print();
        result.MulNumber(1.0 / det);
        // result.print();
      }
    } else {
      throw "The determinant is 0!\n";
    }
  } catch (const char *err_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << err_messege;
  }

  return result;
}