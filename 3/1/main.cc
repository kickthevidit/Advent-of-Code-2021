#include <iostream>
#include <math.h>
#include <vector>

int main() {
    
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    std::vector<std::vector<int>> data(12,std::vector<int>(2,0)); // {number of 0, number of 1}
    std::string word_in_input;

    while (std::cin >> word_in_input) {
        int j = 0;
        for (char c: word_in_input) {
            if ((c - '0') == 1) {
                data[j][1] +=1;
            } else if ((c - '0') == 0) {
                data[j][0] +=1;
            } else {
                std::cout << "error, bit is not 0 or 1";
                exit(1);
            }
            j += 1;
        }
    }

    std::vector<int> bit_value(12,0);

    for (int i = 0; i < 12; i++) {
        if (data[i][0] < data[i][1]) {
            bit_value[i] = 1;
        }
    }

    int gamma = 0,epsilon = 0;

    for (int i = 0; i < 12; i++) {
        gamma += int(bit_value[11-i]*pow(2,i));
        epsilon += int(((bit_value[11-i]+1)%2) * pow(2,i));
    }

    std::cout << "gamma: " << gamma << "\nepsilon: " << epsilon << "\npower consumption: ";
    std::cout << gamma * epsilon;
}