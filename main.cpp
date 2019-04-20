#include <fmt/format.h>
#include <cmath>
#include <vector>
#include "newtonCotes.h"
#include "gausslegendre.h"

int main() {
    auto func = [](double x) {
        return 5.0/(std::pow(M_E, M_PI) - 2.0) * exp(2.0*x) * cos(x);
    };

    const double trapezodial = trapezoidalIntegral(0, M_PI_2, 4, func);
    const double simpson = simpsonIntegral(0, M_PI_2, 4, func);
    const std::vector<std::vector<double>> romberg = rombergIntegral(0, M_PI_2, 4, func);
    const double gaussLegendre = gaussLegendreIntegral(0, M_PI_2, 4, func);

    fmt::print("Solving Integral for 5/(e^pi - 2) * exp(2x) * cos(x) from 0 to pi/2 \n");
    fmt::print("With n = 4, h = (b-a)/n, a = 0, b = pi/2 -> h = pi/8 \n\n");

    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}|{:<10}\n", "Rule", "h", "~I", "I", "I-~I");
    fmt::print("----------------------------------------------------------------- \n");
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}|{:<10}\n", "Trapezodial", "pi/8", trapezodial, 1.0, 1.0-trapezodial);
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}|{:<10}\n", "Simpson", "pi/8", simpson, 1.0, 1.0-simpson);
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}|{:<10}\n", "Romberg", "pi/8", romberg.back().back(), 1.0, 1.0-romberg.back().back());
    fmt::print("{:<20}|{:<10}|{:<10}|{:<10}|{:<10}\n\n", "Gauss-Legendre", "pi/8", gaussLegendre, 1.0, 1.0-gaussLegendre);

    int m=0;
    fmt::print("Romberg results:\n");
    fmt::print("m   |{:<10}|{:<10}|{:<10}|{:<10}\n", "R(m,0)", "R(m,1)", "R(m,2)", "R(m,3)");
    fmt::print("----------------------------------------------- \n");
    for(const auto & row : romberg) {
        fmt::print("{}   ", m++);
        for(const auto & column : row) {
            fmt::print("|{:<10}", column);
        }
        fmt::print("\n");
    }
}