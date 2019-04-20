#ifndef NEWTONCOTES_H
#define NEWTONCOTES_H

#include <vector>
#include <functional>

double trapezoidalIntegral(double a, double b, size_t n, const std::function<double (double)> &f) {
    const double width = (b-a)/n;

    double trapezoidal_integral = 0;
    for(size_t step = 0; step < n; step++) {
        const double x1 = a + step*width;
        const double x2 = a + (step+1)*width;

        trapezoidal_integral += 0.5*(x2-x1)*(f(x1) + f(x2));
    }

    return trapezoidal_integral;
}

double simpsonIntegral(double a, double b, size_t n, const std::function<double (double)> &f) {
    const double width = (b-a)/n;

    double simpson_integral = 0;
    for(size_t step = 0; step < n; step++) {
        const double x1 = a + step*width;
        const double x2 = a + (step+1)*width;

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

#endif