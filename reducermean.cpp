#include <iostream>
#include <string>
#include <sstream>

int main() {
    std::string key;
    double sum = 0.0;
    size_t count = 0;

    while (true) {
        std::string line;
        if (!std::getline(std::cin, line))
            break;

        std::stringstream ss(line);
        std::string k;
        double value;
        size_t c;

        ss >> k >> value >> c;
        sum += value;
        count += c;
    }

    std::cout << "mean_price\t" << (sum / count) << std::endl;
}
