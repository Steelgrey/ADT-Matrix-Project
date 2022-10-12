

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstring>
#include <limits>

using namespace std;

struct Matrix {
    double 
        a1 = 0,
        b1 = 0,
        a2 = 0,
        b2 = 0;
    string name;
};

const string FILE_NAME = "results.txt";

Matrix CalculateSum(const Matrix&, const Matrix&);
Matrix CalculateDifference(const Matrix&, const Matrix&);
Matrix MultiplyByScalar(const Matrix&, const double&);
Matrix CalculateProduct(const Matrix&, const Matrix&);
Matrix CalculateInverse(const Matrix&);
void PrintMatrix(const Matrix&);
void OutputMatrix(const Matrix&, const double&, const Matrix&);
void OutputMatrix(const Matrix&, const Matrix&, const Matrix&);
void OutputMatrix(const Matrix&, const Matrix&);
void PrintMatrixToFile(const Matrix&);
void PrintScalarToFile(const double&);
void Halt(string = "Press any key to continue");


// Windows CMD Line clear
void ClearConsole() {
    system("cls");
}
// Clears input stream
void DumpCin() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

// Suspends console awaiting user entry
void Halt(string prompt) {
    cout << endl << prompt << "..." << endl;
    cin.ignore();
    cin.get();
}

Matrix CalculateSum(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix sum;
    sum.a1 = matrix_1.a1 + matrix_2.a1;
    sum.b1 = matrix_1.b1 + matrix_2.b1;
    sum.a2 = matrix_1.a2 + matrix_2.a2;
    sum.b2 = matrix_1.b2 + matrix_2.b2;
    sum.name = "Result";
    return sum;
}

Matrix CalculateDifference(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix diff;
    diff.a1 = matrix_1.a1 - matrix_2.a1;
    diff.b1 = matrix_1.b1 - matrix_2.b1;
    diff.a2 = matrix_1.a2 - matrix_2.a2;
    diff.b2 = matrix_1.b2 - matrix_2.b2;
    diff.name = "Result";
    return diff;
}

Matrix MultiplyByScalar(const Matrix& matrix_1, const double& scalar) {
    Matrix multScalar;
    multScalar.a1 = matrix_1.a1 * scalar;
    multScalar.b1 = matrix_1.b1 * scalar;
    multScalar.a2 = matrix_1.a2 * scalar;
    multScalar.b2 = matrix_1.b2 * scalar;
    multScalar.name = "Result";
    return multScalar;
}

Matrix CalculateProduct(const Matrix& matrix_1, const Matrix& matrix_2) {
    Matrix product;
    product.a1 = matrix_1.a1 * matrix_2.a1 + matrix_1.b1 * matrix_2.a2;
    product.b1 = matrix_1.a1 * matrix_2.b1 + matrix_1.b1 * matrix_2.b2;
    product.a2 = matrix_1.a2 * matrix_2.a1 + matrix_1.b2 * matrix_2.a2;
    product.b2 = matrix_1.a2 * matrix_2.b1 + matrix_1.b2 * matrix_2.b2;
    product.name = "Result";
    return product;
}

Matrix CalculateInverse(const Matrix& matrix) {
    Matrix inverse;
    double detA = matrix.a1 * matrix.b2 - matrix.a2 * matrix.b1;
    inverse.a1 = matrix.b2 / detA;
    inverse.b1 = -1 * matrix.b1 / detA;
    inverse.a2 = -1 * matrix.a2 / detA;
    inverse.b2 = matrix.a1 / detA;
    inverse.name = "Result";
    return inverse;

}

Matrix GetMatrix() {
    Matrix matrix;
    cout
        << "     Matrix Map    \n"
        << "+--------+--------+\n"
        << "|   A1   |   B1   |\n"
        << "+--------+--------+\n"
        << "|   A2   |   B2   |\n"
        << "+--------+--------+\n";
    cout << "\nEnter matrix name:" ;
    cin >> matrix.name >> endl;
    cout << "Enter cell A1:";
    cin >> matrix.a1;
    cout << "Enter cell B1:";
    cin >> matrix.b1;
    cout << "Enter cell A2:";
    cin >> matrix.a2;
    cout << "Enter cell B2:";
    cin >> matrix.b2;
    return matrix;
}

double GetScalar() {
    double scalar;
    cout << "Enter a scalar number:";
    cin >> scalar;
    return scalar;
}

void ExecuteChangeMatrices(Matrix& matrix_1, Matrix& matrix_2) {
    ClearConsole();
    matrix_1 = GetMatrix();
    cout << "\n\n";
    matrix_2 = GetMatrix();
}

void ExecuteChangeScalar(double& scalar) {
    ClearConsole();
    scalar = GetScalar();
}

void ExecuteCalculateSum(const Matrix& matrix_1, const Matrix& matrix_2) {
    ClearConsole();
    Matrix matrix = CalculateSum(matrix_1, matrix_2);
    OutputMatrix(matrix_1, matrix_2, matrix);
    Halt();
}

void ExecuteCalculateDifference(const Matrix& matrix_1, const Matrix& matrix_2) {
    ClearConsole();
    Matrix matrix = CalculateDifference(matrix_1, matrix_2);
    OutputMatrix(matrix_1, matrix_2, matrix);
    Halt();
}

void ExecuteMultiplyByScalar(const Matrix& matrix_1, const double& scalar) {
    ClearConsole();
    Matrix matrix = MultiplyByScalar(matrix_1, scalar);
    OutputMatrix(matrix_1, scalar, matrix);
    Halt();
}

void ExecuteCalculateProduct(const Matrix& matrix_1, const Matrix& matrix_2) {
    ClearConsole();
    Matrix matrix = CalculateProduct(matrix_1, matrix_2);
    OutputMatrix(matrix_1, matrix_2, matrix);
    Halt();
}

void ExecuteCalculateInverse(const Matrix& matrix_1) {
    ClearConsole();
    Matrix matrix = CalculateInverse(matrix_1);
    OutputMatrix(matrix_1, matrix);
    Halt();
}

// Prints matrix to console
void PrintMatrix(const Matrix& matrix) {
    if (matrix.name != "") {
        cout << "\n   " << matrix.name << "\n";
    }
    cout
        << fixed << setprecision(2) << endl
        << "    |   A   |   B   |\n"
        << " ---+-------+-------+\n"
        << "  1 |" << setw(6) << matrix.a1 << " |" << setw(6) << matrix.b1 << " |\n"
        << " ---+-------+-------+\n"
        << "  2 |" << setw(6) << matrix.a2 << " |" << setw(6) << matrix.b2 << " |\n";
}

void PrintScalar(const double& scalar) {
    cout << "Scalar Value: " << scalar << endl;
}

char GetOutputMethod() {
    ClearConsole();
    char method;
    cout << " p - print\n f - file\nSelect an output method:";
    cin >> method;
    ClearConsole();
    return method;
}
// Outputs matrix based on user selected method
void OutputMatrix(const Matrix& matrix_1, const Matrix& matrix_2, const Matrix& res) {
    if (GetOutputMethod() == 'f') {
        PrintMatrixToFile(matrix_1);
        PrintMatrixToFile(matrix_2);
        PrintMatrixToFile(res);
    }
    else {
        PrintMatrix(matrix_1);
        PrintMatrix(matrix_2);
        PrintMatrix(res);
    }
}
void OutputMatrix(const Matrix& matrix, const double& scalar, const Matrix& res) {
    if (GetOutputMethod() == 'f') {
        PrintMatrixToFile(matrix);
        PrintScalarToFile(scalar);
        PrintMatrixToFile(res);
    }
    else {
        PrintMatrix(matrix);
        PrintScalar(scalar);
        PrintMatrix(res);
    }
}
void OutputMatrix(const Matrix& matrix, const Matrix& res) {
    if (GetOutputMethod() == 'f') {
        PrintMatrixToFile(matrix);
        PrintMatrixToFile(res);
    }
    else {
        PrintMatrix(matrix);
        PrintMatrix(res);
    }
}
void PrintMatrixToFile(const Matrix &matrix){
    ofstream file(FILE_NAME, ios::out | ios::app);
    file << matrix.name;
	file << fixed << setprecision(2) << endl
		<< "    |   A   |   B   |\n"
		<< " ---+-------+-------+\n"
		<< "  1 |" << setw(6) << matrix.a1 << " |" << setw(6) << matrix.b1 << " |\n"
		<< " ---+-------+-------+\n"
		<< "  2 |" << setw(6) << matrix.a2 << " |" << setw(6) << matrix.b2 << " |\n\n";
    file.close();
}
void PrintScalarToFile(const double &scalar) {
	ofstream file(FILE_NAME, ios::out | ios::app);
    file << "\n" << scalar << "\n\n";
	file.close();
}

void ExecuteSelection(int& selection, Matrix& matrix_1, Matrix& matrix_2, double& scalar) {
	switch (selection) {
    case 1:
		ExecuteCalculateSum(matrix_1, matrix_2);
		break;
	case 2:
		ExecuteCalculateDifference(matrix_1, matrix_2);
		break;
	case 3:
		ExecuteMultiplyByScalar(matrix_1, scalar);
		break;
	case 4:
		ExecuteCalculateProduct(matrix_1, matrix_2);
		break;
	case 5:
		ExecuteCalculateInverse(matrix_1);
		break;
	case 6:
		ExecuteChangeMatrices(matrix_1, matrix_2);
		break;
	case 7:
		ExecuteChangeScalar(scalar);
		break;
	default: return;
	}
}

void PrintMenu() {
	cout << "0) Exit\n";
	cout << "1) Calculate Sum\n";
	cout << "2) Calculate Difference\n";
	cout << "3) Cauculate Scalar Multiplication\n";
	cout << "4) Calculate Multiplication\n";
	cout << "5) Calculate Inverse\n";
	cout << "6) Change Matrix\n";
	cout << "7) Change Scalar\n";
}

// Checks if the index selected is valid and requests correction if needed
void ValidateMenuOption(int& index) {
    while (cin.fail() || index < 0 || index > 7) {
        cout << "Invalid menu selection! Please enter a number from 0 to 7: ";
        cin >> index;
    }
}

// Retrieves a menu option selection with validation
void GetMenuOption(int& selection) {
    cout << "Enter number of menu item or 0 to exit: ";
    cin.clear();
    cin >> selection;
    ValidateMenuOption(selection);
}

int main() {

    Matrix matrix_1;
    Matrix matrix_2;
    double scalar;

    ExecuteChangeMatrices(matrix_1, matrix_2);
    ExecuteChangeScalar(scalar);

    int selection;
    do {
        ClearConsole();
        PrintMenu();
        GetMenuOption(selection);
        ExecuteSelection(selection, matrix_1, matrix_2, scalar);
    } while (selection != 0);
}
