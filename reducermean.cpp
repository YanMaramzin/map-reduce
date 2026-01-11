#include <iostream>
#include <sstream>
#include <string>

int main() {
    double sum = 0.0;
    std::size_t count = 0;

    std::string line;
    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string key;
        double value;
        std::size_t c;

        ss >> key >> value >> c;
        sum += value;
        count += c;
    }

    if (count == 0) {
        std::cout << "mean_price\t0\n";
        return 0;
    }

    std::cout << "mean_price\t" << (sum / count) << "\n";
}
