#include <iostream>
#include <sstream>
#include <string>

int main() {
    std::string line;
    std::getline(std::cin, line); // header

    while (std::getline(std::cin, line)) {
        std::stringstream ss(line);
        std::string token;

        for (int i = 0; i < 8; ++i)
            std::getline(ss, token, ',');

        std::getline(ss, token, ',');
        const auto price = std::stod(token);

        std::cout << "price\t"
                << price << "\t"
                << price * price << "\t"
                << 1 << "\n";
    }
}
