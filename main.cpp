/*
 * main.cpp
 *
 *  Created on: Nov 11, 2023
 *      Author: spenc
 */
#include <iostream>
#include <vector>
#include <iomanip>

class KnightTour {
public:
    KnightTour() : board(8, std::vector<int>(8, -1)), moves(8, std::vector<int>(8, 0)), count(0) {}

    bool findTour() {
        board[0][0] = count++;
        return findTourRecursive(0, 0);
    }

    void printTour() const {
        for (int row = 0; row < 8; row++) {
            for (int col = 0; col < 8; col++) {
                std::cout << std::setw(4) << moves[row][col] << " ";
            }
            std::cout << std::endl;
        }
    }

private:
    std::vector<std::vector<int>> board;
    std::vector<std::vector<int>> moves;
    int count;

    const int rowMove[8] = {2, 1, -1, -2, -2, -1, 1, 2};
    const int colMove[8] = {1, 2, 2, 1, -1, -2, -2, -1};

    bool isValidMove(const int row, const int col) const {
        return (row >= 0 && col >= 0 && row < 8 && col < 8 && board[row][col] == -1);
    }

    bool findTourRecursive(const int row, const int col) {
        if (count == 64) {
            return true;
        }

        for (int move = 0; move < 8; move++) {
            int nextRow = row + rowMove[move];
            int nextCol = col + colMove[move];

            if (isValidMove(nextRow, nextCol)) {
                board[nextRow][nextCol] = count;
                moves[nextRow][nextCol] = count++;
                if (findTourRecursive(nextRow, nextCol)) {
                    return true;
                }
                board[nextRow][nextCol] = -1;
                count--;
                moves[nextRow][nextCol] = 0;
            }
        }

        return false;
    }
};

int main() {
    KnightTour tour;
    tour.findTour();
    tour.printTour();

    return 0;
}





