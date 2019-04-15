#include <fmt/format.h>
#include <functional>
#include <cmath>
#include <vector>

double trapezoidalIntegral(double a, double b, size_t n, const std::function<double (double)> &f) {
    const double stepSize = (b-a)/n;

    double trapezoidal_integral = 0;
    for(size_t step = 0; step < n; step++) {
        const double x1 = a + step*stepSize;
        const double x2 = a + (step+1)*stepSize;

        trapezoidal_integral += 0.5*(x2-x1)*(f(x1) + f(x2));
    }

    return trapezoidal_integral;
}

double simpsonIntegral(double a, double b, size_t n, const std::function<double (double)> &f) {
    const double stepSize = (b-a)/n;

    double simpson_integral = 0;
    for(size_t step = 0; step < n; step++) {
        const double x1 = a + step*stepSize;
        const double x2 = a + (step+1)*stepSize;

        simpson_integral += (x2-x1)/6.0*(f(x1) + 4.0*f(0.5*(x1+x2)) + f(x2));
    }

    return simpson_integral;
}

std::vector<std::vector<double>> rombergIntegral(double a, double b, size_t n, const std::function<double (double)> &f) {
    std::vector<std::vector<double>> romberg_integral(n, std::vector<double>(n));

    //R(0,0) Start with trapezoidal integration with N = 1
    romberg_integral.front().front() = trapezoidalIntegral(a, b, 1, f);

    double h = b-a;
    for(size_t step = 1; step < n; step++) {
        h *= 0.5;

        //R(step, 0) Improve trapezoidal integration with decreasing h
        double trapezoidal_integration = 0;
        size_t stepEnd = pow(2, step - 1);
        for(size_t tzStep = 1; tzStep <= stepEnd; tzStep++) {
            const double deltaX = (2*tzStep - 1)*h;
            trapezoidal_integration += f(a + deltaX);
        }
        romberg_integral[step].front() = 0.5*romberg_integral[step - 1].front() + trapezoidal_integration*h;

        //R(m,n) Romberg integration with R(m,1) -> Simpson rule, R(m,2) -> Boole's rule
        for(size_t rbStep = 1; rbStep <= step; rbStep++) {
            const double k = pow(4, rbStep);
            romberg_integral[step][rbStep] = (k*romberg_integral[step][rbStep-1] - romberg_integral[step-1][rbStep-1])/(k-1);
        }
    }

    return romberg_integral;
}

int main() {
    auto func = [](double x) {
        return 5.0/(std::pow(M_E, M_PI) - 2.0) * exp(2.0*x) * cos(x);
    };

    const double trapeze = trapezoidalIntegral(0, M_PI_2, 4, func);
    const double simpson = simpsonIntegral(0, M_PI_2, 4, func);
    const std::vector<std::vector<double>> romberg = rombergIntegral(0, M_PI_2, 4, func);

    fmt::print("Solving Integral for 5/(e^pi - 2) * exp(2x) * cos(x) from 0 to pi/2 \n");
    fmt::print("With n = 4, h = (b-a)/n, a = 0, b = pi/2 -> h = pi/8 \n\n");

    fmt::print("Rule    |  h   |{:<10}|{:<10}|{:<10}\n", "~I", "I", "I-~I");
    fmt::print("----------------------------------------------------------- \n");
    fmt::print("trapeze | pi/8 |{:<10}|{:<10}|{:<10}\n", trapeze, 1.0, 1.0-trapeze);
    fmt::print("simpson | pi/8 |{:<10}|{:<10}|{:<10}\n", simpson, 1.0, 1.0-simpson);
    fmt::print("romberg | pi/8 |{:<10}|{:<10}|{:<10}\n\n", romberg.back().back(), 1.0, 1.0-romberg.back().back());

    int m=0;
    fmt::print("Romberg results:\n");
    fmt::print("m   |{:<10}|{:<10}|{:<10}|{:<10}\n", "R(m,0)", "R(m,1)", "R(m,2)", "R(m,3)");
    for(const auto & row : romberg) {
        fmt::print("{}   ", m++);
        for(const auto & column : row) {
            fmt::print("|{:<10}", column);
        }
        fmt::print("\n");
    }
}