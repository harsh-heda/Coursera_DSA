#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
const double EPS = 1e-6;
const int PRECISION = 20;

typedef std::vector<double> Column;
typedef std::vector<double> Row;
typedef std::vector<Row> Matrix;

struct Equation {
    Equation(const Matrix &a, const Column &b):
        a(a),
        b(b)
    {}

    Matrix a;
    Column b;
};

struct Position {
    Position(int column, int row):
        column(column),
        row(row)
    {}

    int column;
    int row;
};

Equation ReadEquation() {
    int siz;
    std::cin >> siz;
    Matrix a(siz, std::vector <double> (siz, 0.0));
    Column b(siz, 0.0);
    for (int row = 0; row < siz; ++row) {
        for (int column = 0; column < siz; ++column){
            std::cin >> a[row][column];
        }
        std::cin >> b[row];
    }
    return Equation(move(a), move(b));
}

Position SelectPivotElement(const Matrix &a,vector <bool> &used_rows,vector <bool> &used_columns) {
    // This algorithm selects the first free element.
    // You'll need to improve it to pass the problem.
    Position pivot_element(0, 0);
    while (used_rows[pivot_element.row])
        ++pivot_element.row;
    while (used_columns[pivot_element.column])
        ++pivot_element.column;
    double ma = 0.0;
    for (int i = pivot_element.row, siz = a.size(); i < siz; i++) {
        if (fabs(a[i][pivot_element.column]) > fabs(ma)) {
            ma = a[i][pivot_element.column];
            pivot_element.row = i;
        }
    }
    return pivot_element;
}

void SwapLines(Matrix &a, Column &b, std::vector <bool> &used_rows, Position &pivot_element) {
    std::swap(a[pivot_element.column], a[pivot_element.row]);
    std::swap(b[pivot_element.column], b[pivot_element.row]);
    std::swap(used_rows[pivot_element.column], used_rows[pivot_element.row]);
    pivot_element.row = pivot_element.column;
}
void subs(Matrix& a, Column& b)
{
    for (int i = a.size() - 1; i; --i) {
        double v = b[i];
        for (int j = 0; j != i; ++j) {
            b[j] -= a[j][i] * v;
            a[j][i] = 0;
        }
    }
}

inline void scale_pivot(Matrix& a, Column& b, const Position& pivot_element)
{
    const double div = a[pivot_element.row][pivot_element.column];
    const int siz = a.size();

    for (int j = pivot_element.column; j < siz; ++j) {
        a[pivot_element.row][j] /= div;
    }

    b[pivot_element.row] /= div;
}
void ProcessPivotElement(Matrix &a, Column &b, const Position &pivot_element) {
    const int siz = a.size();
    double multi{ 0.0 };
    scale_pivot(a, b, pivot_element);
    for (int i = pivot_element.row + 1; i < siz; ++i) {
        multi = a[i][pivot_element.column];
        for (int j = pivot_element.column; j < siz; ++j) {
            a[i][j] -= (a[pivot_element.row][j] * multi);
        }
        b[i] -= (b[pivot_element.row] * multi);
    }
}

void MarkPivotElementUsed(const Position &pivot_element, std::vector <bool> &used_rows, std::vector <bool> &used_columns) {
    used_rows[pivot_element.row] = true;
    used_columns[pivot_element.column] = true;
}

Column SolveEquation(Equation equation) {
    Matrix &a = equation.a;
    Column &b = equation.b;
    int size = a.size();

    std::vector <bool> used_columns(size, false);
    std::vector <bool> used_rows(size, false);
    for (int step = 0; step < size; ++step) {
        Position pivot_element = SelectPivotElement(a, used_rows, used_columns);
        SwapLines(a, b, used_rows, pivot_element);
        ProcessPivotElement(a, b, pivot_element);
        MarkPivotElementUsed(pivot_element, used_rows, used_columns);
    }
    subs(a,b);

    return b;
}

void PrintColumn(const Column &column) {
    std::cout.precision(PRECISION);
    for (const auto it:column){
        std::cout << it << " ";
    }
    cout <<endl;
}

int main() {
    Equation equation = ReadEquation();
    if(equation.a.size()>0){
        Column solution = SolveEquation(equation);
        PrintColumn(solution);
    }
    return 0;
}
