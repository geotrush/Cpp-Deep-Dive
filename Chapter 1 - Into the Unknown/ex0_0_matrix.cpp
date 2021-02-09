/*
Task
You should define a class with the two constructors and the five public methods:
1) "Matrix()": default constructor that creates a matrix with 0 rows and 0 columns;
2) "Matrix(num_rows, num_columns)": custom constructor that creates a matrix with num_rows and num_columns;
3) "Reset(num_rows, num_columns)": changes the matrix size and nullifies all elements;
4) "At(row, column)": outputs the value at the given row and column;
5) "At(row, column)": returns the reference to the value at the given row and column;
6) "GetNumRows()": outputs the number of rows;
7) "GetNumColumns()": outputs the number of columns.
You should also define the following class operators:
1) Relational ("==");
2) Arithmetic ('+');
3) IO Stream (">>", "<<").
You should catch the following exceptions:
1) out_of_range: whenever the input values are negative or out of bounds;
2) invalid_argument: whenever two matrices cannot be added together.
Notes:
1) Matrices with 0 rows and 0 columns are recognized as empty;
2) Any two empty matrices are equal;
3) Sum of two empty matrices is an empty matrix.
*/
#include <exception>
#include <iostream>
#include <fstream>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::istream;
using std::ostream;
using std::out_of_range;
using std::invalid_argument;


class Matrix {
private:
    int num_rows;
    int num_columns;
    vector<vector<int>> elements;
public:
    Matrix() : num_rows(0), num_columns(0) {}
    Matrix(const int& num_rows, const int& num_columns) {
        Reset(num_rows, num_columns);
    }
    void Reset(const int& num_rows, const int& num_columns) {
        if (num_rows < 0) {
            throw out_of_range("num_rows must be >= 0");
        }
        if (num_columns < 0) {
            throw out_of_range("num_columns must be >= 0");
        }
        if (num_rows == 0 || num_columns == 0) {
            this -> num_rows = this -> num_columns = 0;
        }
        else {
            this -> num_rows = num_rows;
            this -> num_columns = num_columns;
        }
        elements.assign(num_rows, vector<int>(num_columns));
    }
    int At(const int& row, const int& column) const {
        return elements.at(row).at(column);
    }
    int& At(const int& row, const int& column) {
        return elements.at(row).at(column);
    }
    int GetNumRows() const {
        return num_rows;
    }
    int GetNumColumns() const {
        return num_columns;
    }
};


const bool operator == (const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows() ||
        one.GetNumColumns() != two.GetNumColumns()) {
        return false;
    }

    for (int row = 0; row < one.GetNumRows(); ++row) {
        for (int column = 0; column < one.GetNumColumns(); ++column) {
            if (one.At(row, column) != two.At(row, column)) {
                return false;
            }
        }
    }

    return true;
}


const Matrix operator + (const Matrix& one, const Matrix& two) {
    if (one.GetNumRows() != two.GetNumRows()) {
        throw invalid_argument("Mismatched number of rows");
    }

    if (one.GetNumColumns() != two.GetNumColumns()) {
        throw invalid_argument("Mismatched number of columns");
    }

    Matrix result(one.GetNumRows(), one.GetNumColumns());
    for (int row = 0; row < result.GetNumRows(); ++row) {
        for (int column = 0; column < result.GetNumColumns(); ++column) {
            result.At(row, column) = one.At(row, column) + two.At(row, column);
        }
    }

    return result;
}


istream& operator >> (istream& input, Matrix& matrix) {
    int num_rows, num_columns;
    input >> num_rows >> num_columns;

    matrix.Reset(num_rows, num_columns);
    for (int row = 0; row < num_rows; ++row) {
        for (int column = 0; column < num_columns; ++column) {
            input >> matrix.At(row, column);
        }
    }

    return input;
}


ostream& operator << (ostream& output, const Matrix& matrix) {
    output << matrix.GetNumRows() << ' ' << matrix.GetNumColumns() << endl;
    for (int row = 0; row < matrix.GetNumRows(); ++row) {
        for (int column = 0; column < matrix.GetNumColumns(); ++column) {
            if (column > 0) {
                output << ' ';
            }
            output << matrix.At(row, column);
        }
        output << endl;
    }

    return output;
}


int main() {
    Matrix one, two;
    cin >> one >> two;
    cout << one + two << endl;

    return 0;
}
