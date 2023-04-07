#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

const int ROWS = 10;
const int COLS = 10;

enum Direction { UP, DOWN, LEFT, RIGHT };

class Maze {
private:
    char cells[ROWS][COLS];
    int startRow, startCol;
    int endRow, endCol;
public:
    Maze() {
        srand(time(NULL));
        // set all cells to ' '
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                cells[row][col] = ' ';
            }
        }
        // set borders to '*'
        for (int row = 0; row < ROWS; row++) {
            cells[row][0] = '*';
            cells[row][COLS-1] = '*';
        }
        for (int col = 0; col < COLS; col++) {
            cells[0][col] = '*';
            cells[ROWS-1][col] = '*';
        }
        // set start and end positions
        startRow = rand() % (ROWS-2) + 1;
        startCol = rand() % (COLS-2) + 1;
        endRow = rand() % (ROWS-2) + 1;
        endCol = rand() % (COLS-2) + 1;
        cells[startRow][startCol] = 'S';
        cells[endRow][endCol] = 'E';
    }
    void print() const {
        for (int row = 0; row < ROWS; row++) {
            for (int col = 0; col < COLS; col++) {
                cout << cells[row][col] << ' ';
            }
            cout << endl;
        }
    }
    bool move(Direction dir) {
        int row = startRow;
        int col = startCol;
        switch (dir) {
        case UP:
            row--;
            break;
        case DOWN:
            row++;
            break;
        case LEFT:
            col--;
            break;
        case RIGHT:
            col++;
            break;
        }
        if (cells[row][col] == ' ') {
            cells[startRow][startCol] = ' ';
            startRow = row;
            startCol = col;
            cells[startRow][startCol] = 'S';
            return true;
        }
        else if (cells[row][col] == 'E') {
            cells[startRow][startCol] = ' ';
            startRow = row;
            startCol = col;
            cells[startRow][startCol] = 'S';
            return false;
        }
        else {
            return true;
        }
    }
};

int main() {
    Maze maze;
    maze.print();
    while (true) {
        // get player input
        char input = getch();
        Direction dir;
        switch (input) {
        case 'w':
        case 'W':
        case 72: // arrow up
            dir = UP;
            break;
        case 's':
        case 'S':
        case 80: // arrow down
            dir = DOWN;
            break;
        case 'a':
        case 'A':
        case 75: // arrow left
            dir = LEFT;
            break;
        case 'd':
        case 'D':
        case 77: // arrow right
            dir = RIGHT;
            break;
        default:
            continue; // ignore invalid input
            }
            // move player
            bool continueGame = maze.move(dir);
            system("cls"); // clear screen
            maze.print();
            if (!continueGame) {
                    cout << "You win!" << endl;
            break;
            }
            }
            return 0;
}
