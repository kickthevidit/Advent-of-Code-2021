#include <iostream>
#include <fstream>
#include <string>
#include <vector>

#include "Input.h"

std::vector<int> ReadInput() {
    std::vector<int> data;

    std::string line_from_input;

    while (std::cin >> line_from_input) {
        data.push_back(std::stoi(line_from_input));
    }

    return data;
}
