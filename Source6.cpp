//6.problem
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

void findPaths(vector<vector<int>>& maze, int x, int y, int N, string path, vector<string>& result) {
    // Base case: if current position is the destination
    if (x == N - 1 && y == N - 1) {
        result.push_back(path);
        return;
    }

    // Mark current cell as visited
    maze[x][y] = 0;

    // Possible moves: up, down, left, right
    int dx[] = { -1, 1, 0, 0 };
    int dy[] = { 0, 0, -1, 1 };
    char directions[] = { 'U', 'D', 'L', 'R' };

    // Try all possible moves
    for (int i = 0; i < 4; ++i) {
        int newX = x + dx[i];
        int newY = y + dy[i];

        // Check if new position is within bounds and not blocked
        if (newX >= 0 && newX < N && newY >= 0 && newY < N && maze[newX][newY] == 1) {
            findPaths(maze, newX, newY, N, path + directions[i], result);
        }
    }

    // Unmark current cell before backtracking
    maze[x][y] = 1;
}

vector<string> ratInAMaze(vector<vector<int>>& maze, int N) {
    vector<string> result;
    // Check if source or destination is blocked
    if (maze[0][0] == 0 || maze[N - 1][N - 1] == 0) {
        result.push_back("-1");
        return result;
    }
    findPaths(maze, 0, 0, N, "", result);
    if (result.empty()) {
        result.push_back("-1");
    }
    else {
        // Sort the result in lexicographical order
        sort(result.begin(), result.end());
    }
    return result;
}

int main() {
    vector<vector<int>> maze1 = { {1, 0, 0, 0}, {1, 1, 0, 1}, {1, 1, 0, 0}, {0, 1, 1, 1} };
    int N1 = 4;

    vector<string> paths1 = ratInAMaze(maze1, N1);
    cout << "Example 1:\n";
    for (const string& path : paths1) {
        cout << path << " ";
    }
    cout << endl;

    vector<vector<int>> maze2 = { {1, 0}, {1, 0} };
    int N2 = 2;

    vector<string> paths2 = ratInAMaze(maze2, N2);
    cout << "Example 2:\n";
    for (const string& path : paths2) {
        cout << path << " ";
    }
    cout << endl;

    return 0;
}
