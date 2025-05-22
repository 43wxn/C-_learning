#include <iostream>
#include <vector>
using namespace std;

class IslandCounter {
private:
    int n; 
    vector<vector<int>> grid;

public:
    void readInput() {
        cin >> n;
        grid.resize(n, vector<int>(n));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> grid[i][j];
    }

    bool hasOneOnBothSides(int row, int col) {
        bool left = false, right = false;
        for (int j = 0; j < col; ++j) {
            if (grid[row][j] == 1) {
                left = true;
                break;
            }
        }
        for (int j = col + 1; j < n; ++j) {
            if (grid[row][j] == 1) {
                right = true;
                break;
            }
        }
        return left && right;
    }

    bool hasOneAboveAndBelow(int row, int col) {
        bool up = false, down = false;
        for (int i = 0; i < row; ++i) {
            if (grid[i][col] == 1) {
                up = true;
                break;
            }
        }
        for (int i = row + 1; i < n; ++i) {
            if (grid[i][col] == 1) {
                down = true;
                break;
            }
        }
        return up && down;
    }

    int calculateIslandArea() {
        int area = 0;
        for (int i = 1; i < n - 1; ++i) {
            for (int j = 1; j < n - 1; ++j) {
                if (grid[i][j] == 0 &&
                    hasOneOnBothSides(i, j) &&
                    hasOneAboveAndBelow(i, j)) {
                    area++;
                }
            }
        }
        return area;
    }
};

int main() {
    IslandCounter island;
    island.readInput();
    cout << island.calculateIslandArea() << endl;
    return 0;
}