#include <iostream>

int main() {

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::string word_in_input;
    std::string value;

    int length = 0;
    int depth = 0;

    bool c = true; // true means command, false means value

    while (std::cin >> word_in_input) {
        if (c == true) { // parse command
            if (word_in_input=="forward") {
                std::cin >> value;
                length += std::stoi(value);

            } else if (word_in_input == "up") {
                std::cin >> value;
                depth -= std::stoi(value);
                
            } else if (word_in_input == "down") {
                std::cin >> value;
                depth += std::stoi(value);
            }
        }
    }

    std::cout << length*depth;
}