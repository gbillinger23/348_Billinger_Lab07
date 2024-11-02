#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

const int MAX_SIZE = 4; // Adjust if necessary

class Matrix{
  public:
    double data[MAX_SIZE][MAX_SIZE];
    int matrix_size;
    
    Matrix() : matrix_size(0) { // Constructor function
      for (int i = 0; i < MAX_SIZE; i++){
        for (int j = 0; j < MAX_SIZE; j++){
          data[i][j] = 0;
        }
      }
    }

    Matrix operator+(const Matrix& other) {
      Matrix add_result;
      add_result.matrix_size = matrix_size;
      for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
          add_result.data[i][j] = data[i][j] + other.data[i][j];
        }
      }
      return add_result;
    }

    Matrix operator*(const Matrix& other) {
      Matrix multiply_result;
      multiply_result.matrix_size = matrix_size;
      for (int i = 0; i < matrix_size; i++){
        for (int j = 0; j < matrix_size; j++){
          multiply_result.data[i][j] = 0;
          for (int k = 0; k < matrix_size; k++){
            multiply_result.data[i][j] += data[i][k] * other.data[k][j];
          }
        }
      }
      return multiply_result;
    }
};

void read_matrix_from_stream(double matrix_1[][MAX_SIZE], 
                             double matrix_2[][MAX_SIZE], 
                             int &matrix_size) {

  cout << "Enter the size of the matrices: ";
  cin >> matrix_size;

  // TODO: Read matrix data from cin into matrix_1 and matrix_2
  //       Make sure to handle potential errors and invalid input
  ifstream file("matrix-data-file.txt");

  if(!file) { // If file is invalid.
    cerr << "Unable to open file\n";
    return;
  }

  string line;
  int i = 0;
  int k = 0;
  while (getline(file, line)) { // Iterate through each line in the file.
    if (k == matrix_size){ // This checks for when the first matrix is full
      i = 0;
    }
    istringstream iss(line); // Create string stream for line
    string ch;

    int j = 0;
    while (iss >> ch) { // Iterate through each number in a line.
      if (k < matrix_size) {
        matrix_1[i][j] = stoi(ch); // Add the number to matrix 1.
        j++; // Increment column counter.
      }
      else {
        matrix_2[i][j] = stoi(ch); // Add the number to matrix 2.
        j++; // Increment column counter.
      }
    }
    i++; // Increment row counter.
    k++; // Increment array counter.
  }
  file.close();
}

void print_matrix(const double matrix[][MAX_SIZE], int matrix_size) {
  // TODO: Print the matrix to the console
	for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      cout << matrix[i][j] << "\t";
    }
    cout << endl;
	}
}

void print_matrix(const double matrix_1[][MAX_SIZE], 
                 const double matrix_2[][MAX_SIZE], 
                 int matrix_size){
  // TODO: Print both matrices to the console
  cout << "Matrix 1:" << endl;
  for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      cout << matrix_1[i][j] << "\t";
    }
    cout << endl;
	}
  cout << "Matrix 2:" << endl;
  for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      cout << matrix_2[i][j] << "\t";
    }
    cout << endl;
	}
}

void add_matrices(const double matrix_1[][MAX_SIZE], 
                 const double matrix_2[][MAX_SIZE], 
                 double result[][MAX_SIZE], 
                 int matrix_size) {
  // TODO: Implement matrix addition and store the result in 'result'
  Matrix mat1, mat2; // Create the matrix objects.
  mat1.matrix_size = matrix_size;
  mat2.matrix_size = matrix_size;
  for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      mat1.data[i][j] = matrix_1[i][j]; // Fill them with the given matrix data.
      mat2.data[i][j] = matrix_2[i][j];
    }
  }
  Matrix add_result = mat1 + mat2;
  for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      result[i][j] = add_result.data[i][j];
    }
  }
}

void multiply_matrices(const double matrix_1[][MAX_SIZE], 
                      const double matrix_2[][MAX_SIZE], 
                      double result[][MAX_SIZE], 
                      int matrix_size) {
  // TODO: Implement matrix multiplication and store the result in 'result'
  Matrix mat1, mat2; // Create the matrix objects.
  mat1.matrix_size = matrix_size;
  mat2.matrix_size = matrix_size;
  for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      mat1.data[i][j] = matrix_1[i][j]; // Fill them with the given matrix data.
      mat2.data[i][j] = matrix_2[i][j];
    }
  }
  Matrix multiply_result = mat1 * mat2; // Do the operation overloading.
  for (int i = 0; i < matrix_size; i++){
    for (int j = 0; j < matrix_size; j++){
      result[i][j] = multiply_result.data[i][j]; // Fill the result matrix
    }
  }
}

void get_diagonal_sum(const double matrix[][MAX_SIZE], int matrix_size) {
  // TODO: Calculate and print the sum of the diagonal elements
  double result = 0;
  for (int i = 0; i < matrix_size; i++){
    result += matrix[i][i];
  }
  cout << result << endl;
}

void swap_matrix_row(double matrix[][MAX_SIZE], int matrix_size, int row1, int row2) {
  // TODO: Swap the rows 'row1' and 'row2' in the matrix
  //       Handle invalid row indices
  if (matrix_size < 2) {
    cout << "No rows to swap." << endl;
  }
  else {
    if (row1 > matrix_size || row1 < 0){
      cout << "Invalid indices." << endl;
    }
    else if (row2 > matrix_size || row2 < 0){
      cout << "Invalid indices." << endl;
    }
    double temp_row[MAX_SIZE];
    for (int i = 0; i < matrix_size; i++){
      temp_row[i] = matrix[row1][i];
      matrix[row1][i] = matrix[row2][i];
      matrix[row2][i] = temp_row[i];
    }
    print_matrix(matrix, matrix_size);
  }
}

int main(int argc, char *argv[]) {
  double matrix_1[MAX_SIZE][MAX_SIZE], matrix_2[MAX_SIZE][MAX_SIZE];
  int matrix_size;

  read_matrix_from_stream(matrix_1, matrix_2, matrix_size);
  cout << "print_matrix" << endl;
  print_matrix(matrix_1, matrix_2, matrix_size);

  double add_result[MAX_SIZE][MAX_SIZE];
  add_matrices(matrix_1, matrix_2, add_result, matrix_size);
  cout << "add_matrices result:" << endl;
  print_matrix(add_result, matrix_size);

  double multiply_result[MAX_SIZE][MAX_SIZE];
  multiply_matrices(matrix_1, matrix_2, multiply_result, matrix_size);
  cout << "multiply_matrices result:" << endl;
  print_matrix(multiply_result, matrix_size);

  cout << "get matrix diagonal sum" << endl;
  get_diagonal_sum(matrix_1, matrix_size);

  cout << "swap matrix rows" << endl;
  swap_matrix_row(matrix_1, matrix_size, 0, 1);

  return 0;
}