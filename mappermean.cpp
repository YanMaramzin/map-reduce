#include <iostream>
#include <string>
#include <vector>

// CSV parser
std::vector<std::string> parse_csv_line(const std::string &line) {
    std::vector<std::string> cols;
    std::string cur;
    bool in_quotes = false;

    for (char c: line) {
        if (c == '"')
            in_quotes = !in_quotes;
        else if (c == ',' && !in_quotes) {
            cols.push_back(cur);
            cur.clear();
        } else {
            cur += c;
        }
    }
    cols.push_back(cur);
    return cols;
}

int main() {
    std::string line;

    // пропускаем заголовок
    std::getline(std::cin, line);

    while (std::getline(std::cin, line)) {
        if (line.empty())
            continue;

        auto cols = parse_csv_line(line);

        if (cols.size() <= 9)
            continue;

        const std::string &price_str = cols[9];
        if (price_str.empty())
            continue;

        const double price = std::stod(price_str);

        std::cout << "price\t" << price << "\t1\n";
    }
}
