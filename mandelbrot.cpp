#include <iostream>
#include <complex>

int main() {
    int w = 90, h = 45, max_iter = 300;  // 3x bigger than the original
    std::string grad = " .:-=+*#%@";

    for (int iy = 0; iy < h; iy++) {
        double y = (iy - h / 2.0) / (h / 4.0);
        for (int ix = 0; ix < w; ix++) {
            double x = (ix - w / 2.0) / (w / 4.0);
            std::complex<double> c(x, y), z(0, 0);
            int iter = 0;
            while (iter < max_iter && std::abs(z) <= 2.0) {
                z = z * z + c;
                iter++;
            }
            if (iter == max_iter) {
                std::cout << grad.back();
            } else {
                int idx = iter * grad.size() / max_iter;
                std::cout << grad[idx];
            }
        }
        std::cout << "\n";
    }
}

