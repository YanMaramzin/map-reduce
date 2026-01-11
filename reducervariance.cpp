#include <iostream>
#include <sstream>
#include <string>

int main()
{
    double sum = 0.0;
    double sum_sq = 0.0;
    size_t count = 0;

    std::string line;
    while (std::getline(std::cin, line))
    {
        std::stringstream ss(line);
        std::string key;
        double x, x2;
        size_t c;

        ss >> key >> x >> x2 >> c;
        sum += x;
        sum_sq += x2;
        count += c;
    }

    const double mean = sum / count;
    const double variance = (sum_sq / count) - (mean * mean);

    std::cout << "variance_price\t" << variance << std::endl;
}
