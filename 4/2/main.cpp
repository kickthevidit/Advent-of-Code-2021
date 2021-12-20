#include "solution.h"
#include <numeric>
#include <string_view>

int main() {

    // take in input
    
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "o", stdout);

    // make vector of the strings
    std::vector<int> numbers;
    std::string inp;
    
    std::cin >> inp;

    int lb = 0;
    int ub = 0;

    for (int i = 0; i < inp.length(); i++) {
        if (inp[i] == ','){
            ub = i;
            std::string num;
            for (int j = lb; j < ub; j++) {
                num += inp[j];
            }
            lb = ub+1;
            numbers.push_back(std::stoi(num)); // std::stoi is imported with string
        }
    }

    /* for (int x : numbers){
        std::cout << x << " ";
    }
    std::cout << "\n"; */

    // process board data
    std::vector<std::vector<std::vector<int>>> boards;
    std::vector<std::vector<int>> board;
    std::vector<int> row;

    std::vector<int> board_sums; // sum of numbers on each board

    std::string num;
    int c = 0;
    int sum = 0;
    bool first = true;
    while (std::cin >> num) {
        //std::cout << num << "";
        if (c%5 == 0 and !first) {
            board.push_back(row);
            row.clear();
            //std::cout << "\n";
        }
        if (c%25 == 0 and !first) {
            boards.push_back(board);
            board.clear();
            row.clear();

            board_sums.push_back(sum);
            sum = 0;
            //std::cout << "\n--------------------\n" ;
        }
        if (first) {
            first = !first;
        }
        sum += std::stoi(num);
        row.push_back(std::stoi(num));
        c+=1;
    }
    board.push_back(row);
    boards.push_back(board);
    board_sums.push_back(sum);

    for (std::vector<std::vector<int>> board : boards) {
        for (std::vector<int> row : board) {
            for (int x: row) {
                std::cout << x << " ";
            }
            std::cout << "\n";
        }
        std::cout << "\n";
    }

    int l = boards.size();

    std::vector<int> remaining_boards;
    for (int i = 0; i < boards.size(); i++) {
        remaining_boards.push_back(i);
    }

    for (int x : remaining_boards) {
        std::cout << x << ",";
    }
    std::cout << "\n";

    bool j_break = false; // tells when the second internal loop should break

    for (int n : numbers) {
        //std::cout << n << "\n";

        for (int x : remaining_boards) {
            std::cout << x << ",";
        }
        std::cout << "\n";

        if (remaining_boards.size() == 0) {
            break;
        }

        for (int i: remaining_boards) {
            for (int j = 0; j < boards[i].size(); j++) {
                for (int k = 0; k < boards[i][j].size(); k++) {
                    //std::cout << i << "," << j << "," << k << "|" << boards[i][j][k] << '\n';
                    if (boards[i][j][k] == n) {
                        boards[i][j][k] = 10123; // mark the number on the board
                        board_sums[i] -= n;
                        
                        // check if the row and column are all marked
                        bool row = true;
                        bool column = true;
                        for (int x = 0; x < boards[i][j].size(); x++) {
                            if (boards[i][j][x] != 10123) {
                                row = false;
                                break;
                            }
                        }
                        for (int y = 0; y < boards[i].size(); y++) {
                            if (boards[i][y][k] != 10123) {
                                column = false;
                                break;
                            }
                        }
                        
                        // if a row or column is all marked
                        if (row == true || column == true) {
                            std::cout << "Answer : " <<  board_sums[i] * n << "\n";
                            std::vector<int> x;
                            j_break = true; // breaks the loop going through the other part of the board
                            break;
                        }
                    }
                }
                if (j_break) {
                    j_break = false;
                    break;
                }
            }
        }
    }

}