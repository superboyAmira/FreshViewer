#include "matrix.h"

Matrix::Matrix() : rows_(0), cols_(0), matrix_(nullptr) {}

void Matrix::CreateMatrix(int rows, int cols) {
  try {
    rows_ = rows;
    cols_ = cols;
    this->ExeptionNullColsRows();

    matrix_ = new double *[rows_]();
    for (int i = 0; i < rows; i++) {
      this->matrix_[i] = new double[cols_]();
    }
  } catch (const char *error_messege) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n" << error_messege;
  } catch (const std::bad_alloc &e) {
    std::cerr << __FILE__ << ":" << __LINE__ << "\n"
              << "Allocation failed:" << e.what() << "\n";
  }
}

Matrix::Matrix(int rows, int cols) { this->CreateMatrix(rows, cols); }

Matrix::Matrix(const Matrix &other) {
  // if (this->matrix_ != nullptr) {
  //   this->RemoveMatrix();
  // }
  this->CreateMatrix(other.rows_, other.cols_);
  for (int i = 0; i < other.rows_; i++) {
    for (int j = 0; j < other.cols_; j++) {
      this->matrix_[i][j] = other.matrix_[i][j];
    }
  }
}

Matrix::Matrix(Matrix &&other)
    : rows_(std::move(other.rows_)), cols_(std::move(other.cols_)) {
  /*
  Здесь используется rValue ссылки для обеспечения производительной семантики
  перемещения, а не копирования - без использования дополнительного выделения
  памяти и использования временных объектов.
  https://habr.com/ru/articles/226229/
  */
  matrix_ = std::move(other.matrix_);
  other.cols_ = 0;
  other.rows_ = 0;
  other.matrix_ = nullptr;  // В данном случае не нужно вызывать
                            // деструктор для объекта other в конструкторе
                            // перемещения, так как в нем не происходит удаление
                            // объекта, а только перенос его ресурсов.
}

void Matrix::RemoveMatrix() {
  if (matrix_ != nullptr) {
    for (int i = 0; i < rows_; i++) {
      if (matrix_[i] != 0) {
        delete[] matrix_[i];
      }
    }
    delete[] matrix_;
    matrix_ = nullptr;
  }
  rows_ = 0;
  cols_ = 0;
}

Matrix::~Matrix() { this->RemoveMatrix(); }

// access and mutate

int Matrix::GetRows() const { return this->rows_; }

int Matrix::GetCols() const { return this->cols_; }

void Matrix::SetRows(int rows) {
  Matrix t(rows, this->cols_);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < this->cols_; j++) {
      if (i >= this->rows_) {
        t.matrix_[i][j] = 0.0;
      } else {
        t.matrix_[i][j] = this->matrix_[i][j];
      }
    }
  }

  this->~Matrix();
  new (this) Matrix{std::move(t)};
}

void Matrix::SetCols(int cols) {
  Matrix t(this->rows_, cols);

  for (int i = 0; i < this->rows_; i++) {
    for (int j = 0; j < cols; j++) {
      if (j >= this->cols_) {
        t.matrix_[i][j] = 0.0;
      } else {
        t.matrix_[i][j] = this->matrix_[i][j];
      }
    }
  }
  this->~Matrix();
  new (this) Matrix{std::move(t)};
}

// Exeptions

void Matrix::ExeptionEqColsRows(const Matrix &other) const {
  if (rows_ != other.rows_ || cols_ != other.cols_) {
    throw "Cols or rows doesn't equal!\n";
  }
}

void Matrix::ExeptionNullColsRows() const {
  if (rows_ < 1 || cols_ < 1) {
    throw "Invalid number of rows or cols!\n";
  }
}

void Matrix::ExeptionMultMatrixTerms(const Matrix &other) const {
  if (this->rows_ != other.cols_) {
    throw "Unacceptable terms for matrix multiplication!\n";
  }
}

void Matrix::ExeptionSquareMatrix() const {
  if (this->rows_ != this->cols_) {
    throw "Unacceptable terms for matrix multiplication!\n";
  }
}