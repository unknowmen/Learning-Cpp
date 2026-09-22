#include <chrono>
#include <cmath>
#include <iostream>
#include <vector>
#include <stdexcept>

double pearson(
    const std::vector<double>& x,
    const std::vector<double>& y
) {
    double sum_xiyi{};
    double sum_xi{};
    double sum_yi{};
    double sum_xi_squared{};
    double sum_yi_squared{};

    for (std::size_t i = 0; i < x.size(); ++i) {
        sum_xiyi += x[i] * y[i];
        sum_xi += x[i];
        sum_yi += y[i];
        sum_xi_squared += x[i] * x[i];
        sum_yi_squared += y[i] * y[i];
    }

    const double n = static_cast<double>(x.size());

    const double numerator =
        n * sum_xiyi - sum_xi * sum_yi;

    const double x_term =
        n * sum_xi_squared - sum_xi * sum_xi;

    const double y_term =
        n * sum_yi_squared - sum_yi * sum_yi;

    const double denominator_squared = x_term * y_term;

    if (denominator_squared <= 0.0) {
        throw std::domain_error(
            "Pearson correlation is undefined"
        );
    }

    return numerator / std::sqrt(denominator_squared);
}

int main(){

    int index{};
    std:: cin >> index;

    if (index < 2) {
        std::cout << "Pearson correlation requires at least 2 pairs\n";
        return 1;
    }

    std:: vector <double> x{};
    std:: vector <double> y{};

    x.reserve(index);
    y.reserve(index);

    for( int i= 0; i < index; i++){
        double x_i{};
        std::cin >> x_i;
        x.push_back(x_i);
    }
    std::cout << "Variables of X have : ";
    for (double value : x) {
    std::cout << value << ' ';
    }
    std::cout << '\n';

    for (int i=0; i<index; i++){
        double y_i{};
        std::cin >> y_i;
        y.push_back(y_i);
    }
    std::cout << "Variables of Y have : ";
    for (double value : y) {
    std::cout << value << ' ';
    }
    std::cout << '\n';

    const auto start = std::chrono::steady_clock::now();

    double pearson_r{};

    try {
        pearson_r = pearson(x, y);
    }
    catch (const std::domain_error& error) {
        std::cout << error.what() << '\n';
        return 1;
    }

    const double absolute_r = std::abs(pearson_r);

    const char* strength{};

    if (absolute_r >= 0.8) {
        strength = "Very Strong";
    }
    else if (absolute_r >= 0.6) {
        strength = "Strong";
    }
    else if (absolute_r >= 0.4) {
        strength = "Moderate";
    }
    else if (absolute_r >= 0.2) {
        strength = "Weak";
    }
    else {
        strength = "Very Weak";
    }

    const char* direction{};

    if (pearson_r > 0.0) {
        direction = "Positive";
    }
    else if (pearson_r < 0.0) {
        direction = "Negative";
    }
    else {
        direction = "No linear correlation";
    }

    const auto stop = std::chrono::steady_clock::now();

const auto elapsed =
    std::chrono::duration_cast<std::chrono::nanoseconds>(
        stop - start
    );

    std::cout << "Pearson r: " << pearson_r << '\n';
    std::cout << "Strength: " << strength << '\n';
    std::cout << "Direction: " << direction << '\n';
    std::cout << "Computation time: "
            << elapsed.count() << " ns\n";

    return 0;
}
