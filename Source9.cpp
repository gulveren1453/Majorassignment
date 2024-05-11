#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;
//problem9
bool isValid(int i, int j, int R, int C) {
    return (i >= 0 && i < R&& j >= 0 && j < C);
}

void dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j, string word, unordered_set<string>& dictionary, unordered_set<string>& result, int R, int C) {
    visited[i][j] = true;
    word += board[i][j];

    if (dictionary.find(word) != dictionary.end()) {
        result.insert(word);
    }

    
    int dx[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
    int dy[] = { -1, 0, 1, -1, 1, -1, 0, 1 };

    for (int k = 0; k < 8; k++) {
        int ni = i + dx[k];
        int nj = j + dy[k];
        if (isValid(ni, nj, R, C) && !visited[ni][nj]) {
            dfs(board, visited, ni, nj, word, dictionary, result, R, C);
        }
    }

    visited[i][j] = false;
}

vector<string> wordBoggle(vector<vector<char>>& board, vector<string>& dictionary, int R, int C) {
    unordered_set<string> dict(dictionary.begin(), dictionary.end());
    unordered_set<string> result;
    vector<vector<bool>> visited(R, vector<bool>(C, false));

    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            string word = "";
            dfs(board, visited, i, j, word, dict, result, R, C);
        }
    }

    return vector<string>(result.begin(), result.end());
}

int main() {
    int R = 3, C = 3;
    vector<vector<char>> board = { {'C','A','P'},{'A','N','D'},{'T','I','E'} };
    vector<string> dictionary = { "CAT" };
    vector<string> result = wordBoggle(board, dictionary, R, C);
    for (auto word : result) {
        cout << word << " ";
    }
    cout << endl; 

    R = 3; C = 3;
    board = { {'G','I','Z'},{'U','E','K'},{'Q','S','E'} };
    dictionary = { "GEEKS","FOR","QUIZ","GO" };
    result = wordBoggle(board, dictionary, R, C);
    for (auto word : result) {
        cout << word << " ";
    }
    cout << endl; 

    return 0;
}
