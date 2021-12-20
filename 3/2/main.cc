#include <iostream>
#include <math.h>
#include <vector>

int main() {
    
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    std::string word_in_input;
    std::vector<std::vector<char>> data;

    while (std::cin >> word_in_input) {
        int j = 0;
        std::vector<char> x(12,'a');
        for (char c: word_in_input) {
            x[j] = c;
            j+=1;
        }
        data.push_back(x);
    }
/* 
    for (int i = 0; i < 12; i++) {
        std::vector<std::vector<char>> bits_1;
        std::vector<std::vector<char>> bits_2;
        int j = 0;
        int bit_frequency = 0; // if greater than 0, 1 is more frequent. Else 0 is.
        while (j < data.size()) {
            if (data[j][0] == '0') {
                data[j].erase(data[j].begin()); // remove the first element
                bits_1.push_back(data[j]);
                bit_frequency -= 1;
            } else if (data[j][0] == '1') {
                data[j].erase(data[j].begin()); // remove the first element
                bits_2.push_back(data[j]);
                bit_frequency += 1;
            } else {
                std::cout << "error, bit is neither 0 or 1";
            }
        }
        if (bit_frequency >= 0) { // if 1 is more frequent
            data = bits_1;
        } else { // if 0 is more frequent
            data = bits_2;
        }
        if (data[0].length == 1) {

        }
    } */

    std::cout << "oxygen rating: " <<;
}