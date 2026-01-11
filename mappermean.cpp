#include <iostream>
#include <sstream>
#include <string>

int main()
{
    std::string line;

    // пропускаем заголовок
    std::getline(std::cin, line);

    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        std::string token;

        // price — 9-й столбец
        for (int i = 0; i < 8; ++i)
            std::getline(ss, token, ',');

        std::getline(ss, token, ','); // price
        double price = std::stod(token);

        std::cout << "price\t" << price << "\t1\n";
    }
}
