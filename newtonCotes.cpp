#include <fmt/format.h>
#include <functional>
#include <cmath>
#include <vector>

double trapezoidalIntegral(double a, double b, int n, const std::function<double (double)> &f) {
    const double stepSize = (b-a)/n;

    double trapezoidal_integral = 0;
    for(int step = 0; step < n; step++) {
        const double x1 = a + step*stepSize;
        const double x2 = a + (step+1)*stepSize;

        trapezoidal_integral += 0.5*(x2-x1)*(f(x1) + f(x2));
    }

    return trapezoidal_integral;
}

double simpsonIntegral(double a, double b, int n, const std::function<double (double)> &f) {
    const double stepSize = (b-a)/n;

    double simpson_integral = 0;
    for(int step = 0; step < n; step++) {
        const double x1 = a + step*stepSize;
        const double x2 = a + (step+1)*stepSize;

        simpson_integral += (x2-x1)/6.0*(f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
    }

    return simpson_integral;
}

int main() {
    auto func = [](double x) {
        return 5.0/(std::pow(M_E, M_PI) - 2.0) * exp(2.0*x) * cos(x);
    };

    const double trapeze = trapezoidalIntegral(0, M_PI_2, 4, func);
    const double simpson = simpsonIntegral(0, M_PI_2, 4, func);

    fmt::print("Solving Integral for 5/(e^pi - 2) * exp(2x) * cos(x) from 0 to pi/2 \n");
    fmt::print("With n = 4, h = (b-a)/n, a = 0, b = pi/2 -> h = pi/8 \n\n");

    fmt::print("Rule    |  h   | Solution | Reference Solution | Difference\n");
    fmt::print("----------------------------------------------------------- \n");
    fmt::print("trapeze | pi/8 | {} | {}                  | {}\n", trapeze, 1.0, 1.0-trapeze);
    fmt::print("simpson | pi/8 | {} | {}                  | {}\n", simpson, 1.0, 1.0-simpson);
}