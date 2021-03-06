# numericalIntegration

A collection of numerical integration methods, as discussed on [thoughts-on-coding.com](https://thoughts-on-coding.com).

[Numerical Methods in C++ Part 1: Newton-Cotes Integration](https://thoughts-on-coding.com/2019/04/17/numerical-methods-in-cpp-part-1-newton-cotes-integration)
- Trapezoidal
- Simpson rule
- Romberg

[Numerical Methods in C++ Part 2: Gauss-Legendre Integration](https://thoughts-on-coding.com/2019/04/25/numerical-methods-in-cpp-part-2-gauss-legendre-integration)
- Gauss-Legendre

## Getting Started

To get it up and running you just need to execute:
- `~\numericalIntegration\build\cmake .. -DCMAKE_TOOLCHAIN_FILE={YOUR_PATH_TO_VCPKG}/scripts/buildsystems/vcpkg.cmake`
- `~\numericalIntegration\build\cmake --build .`

You can execute the program by `./numericalIntegration`

![Screen capture of programm execution](numericalIntegration.gif)

### Prerequisites

- [fmt](http://fmtlib.net/latest/index.html) external library used for formatting and printing results

## Authors

* **Benjamin Mahr** - [Ben1980](https://github.com/Ben1980)

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details
