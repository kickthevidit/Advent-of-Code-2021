#include <iostream>
#include <vector>
#include "Input.h"
//#include "InputFunctions.cc"

int main() {

    freopen("input.txt", "r", stdin); 
    freopen("output.txt", "w", stdout);

    std::vector<int> data;

    std::string line_in_input;

    while (std::cin >> line_in_input) {
        //std::cout << line_in_input << ",";
        data.push_back(std::stoi(line_in_input));
    }

    int score = 0;

    for (int i = 1; i < data.size(); i++) {
        if (data.at(i)>data.at(i-1)) {
            score +=1;
        }
    }

    std::cout << score;
}