#include <iostream>
#include <vector>
#include <string>
using namespace std;
//problem 8
bool isValidPart(string s) {
    if (s.empty() || s.size() > 3 || (s.size() > 1 && s[0] == '0')) {
        return false;
    }
    int num = stoi(s);
    return num >= 0 && num <= 255;
}

void backtrack(string s, int start, int part, string current, vector<string>& result) {
    if (part == 4 && start == s.size()) {
        result.push_back(current);
        return;
    }
    if (part == 4 || start == s.size()) {
        return;
    }
    for (int len = 1; len <= 3 && start + len <= s.size(); len++) {
        string sub = s.substr(start, len);
        if (isValidPart(sub)) {
            backtrack(s, start + len, part + 1, current + (part == 0 ? "" : ".") + sub, result);
        }
    }
}

vector<string> genIp(string S) {
    vector<string> result;
    if (S.size() < 4 || S.size() > 12) {
        return { "-1" };
    }
    backtrack(S, 0, 0, "", result);
    return result;
}

int main() {
    string S = "1111";
    vector<string> result = genIp(S);
    for (string ip : result) {
        cout << ip << endl; 
    }

    S = "55";
    result = genIp(S);
    for (string ip : result) {
        cout << ip << endl; 
    }

    return 0;
}
