#include <iostream>
#include <vector>

void thomas_algorithm(const std::vector<double>& a, std::vector<double>& b,
                      const std::vector<double>& c, std::vector<double>& d,
                      std::vector<double>& x, int n) {
    // Forward elimination
    for (int i = 1; i < n; ++i) {
        double m = a[i] / b[i - 1];
        b[i] -= m * c[i - 1];
        d[i] -= m * d[i - 1];
    }

    // Back substitution
    x[n - 1] = d[n - 1] / b[n - 1];
    for (int i = n - 2; i >= 0; --i) {
        x[i] = (d[i] - c[i] * x[i + 1]) / b[i];
    }
}

int main() {
    // Example tridiagonal system of equations
    std::vector<double> a = {-1,-1,-1,-1};  // Lower diagonal
    std::vector<double> b = {2,2,2,2};  // Diagonal
    std::vector<double> c = {-1,-1,-1};  // Upper diagonal
    std::vector<double> d = {1,0,0,1};  // Right-hand side
    std::vector<double> x(4);              // Solution

    // Solve the system using Thomas algorithm
    thomas_algorithm(a, b, c, d, x, 4);

    // Output the solution
    std::cout << "Solution:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "x[" << i << "] = " << x[i] << std::endl;
    }

    return 0;
}
