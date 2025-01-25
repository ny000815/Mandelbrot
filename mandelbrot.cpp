#include <iostream>
#include <complex>
#include <string>
#include <cmath>

static std::string ansi256(int c) {
    return "\033[38;5;" + std::to_string(c) + "m";
}

static std::string reset() {
    return "\033[0m";
}

int main() {
    int width = 160;
    int height = 40;
    double x_min = -2.5;
    double x_max = 1.5;
    double y_min = -1.5;
    double y_max = 1.5;
    int max_iter = 2000;
    double escape_radius = 2.0;

    for (int py = 0; py < height; ++py) {
        double y = y_min + (y_max - y_min) * (static_cast<double>(py) / height);
        for (int px = 0; px < width; ++px) {
            double x = x_min + (x_max - x_min) * (static_cast<double>(px) / width);

            std::complex<double> z(0.0, 0.0);
            std::complex<double> c(x, y);

            int iter = 0;
            while (std::abs(z) <= escape_radius && iter < max_iter) {
                z = z * z + c;
                iter++;
            }

            if (iter == max_iter) {
                std::cout << ansi256(0) << "█";  
            } else {
                int color_idx = 16 + static_cast<int>(
                    (static_cast<double>(iter) / max_iter) * (231 - 16)
                );
                std::cout << ansi256(color_idx) << "█";
            }
        }
        std::cout << reset() << "\n";
    }

    std::cout << reset();
    return 0;
}

