#include <iostream>
#include <vector>
using namespace std;

class WuZiQi {
private:
    static const int SIZE = 19;
    vector<vector<int>> board;

    bool isValid(int x, int y) {
        return x >= 0 && x < SIZE && y >= 0 && y < SIZE;
    }

    bool checkDirection(int x, int y, int dx, int dy, int color) {
        for (int i = 1; i < 5; ++i) {
            int nx = x + dx * i;
            int ny = y + dy * i;
            if (!isValid(nx, ny) || board[nx][ny] != color)
                return false;
        }
        return true;
    }

public:
    WuZiQi() {
        board.resize(SIZE, vector<int>(SIZE, 0));
    }

    void readBoard() {
        for (int i = 0; i < SIZE; ++i)
            for (int j = 0; j < SIZE; ++j)
                cin >> board[i][j];
    }

    void checkWinner() {
        const int dirs[4][2] = { {0,1}, {1,0}, {1,1}, {1,-1} };  // 右、下、右下、左下
        for (int i = 0; i < SIZE; ++i) {
            for (int j = 0; j < SIZE; ++j) {
                int color = board[i][j];
                if (color == 0) continue;

                for (auto& dir : dirs) {
                    int dx = dir[0], dy = dir[1];
                    if (checkDirection(i, j, dx, dy, color)) {
                        cout << color << ":" << i + 1 << "," << j + 1 << endl;
                        return;
                    }
                }
            }
        }
        cout << "No" << endl;
    }
};

int main() {
    WuZiQi game;
    game.readBoard();
    game.checkWinner();
    return 0;
}