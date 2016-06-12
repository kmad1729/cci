#include<iostream>
#include <stack>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <cstring>


#define BOARD_SIZE 3
#define MIN_WORD_SIZE 3

using namespace std;

typedef pair<int, int> int_pair;
typedef pair<int_pair, string> node;

bool valid_word(const string& s) {
    vector<string> words;
    words.push_back("geek");
    words.push_back("for");
    words.push_back("quiz");
    words.push_back("go");
    return find(words.begin(), words.end(), s) != words.end();
}

void find_words_util(const vector<vector<char> > board,
        bool visited[BOARD_SIZE][BOARD_SIZE], int r, int c,
        string& pref, vector<string>& words)
{
    if( r < 0 || r >= BOARD_SIZE) return;
    if( c < 0 || c >= BOARD_SIZE) return;
    if(visited[r][c]) return;
    pref.push_back(board[r][c]);
    if(valid_word(pref)) words.push_back(pref);
    visited[r][c] = true;

    for(int i = -1; i <= 1; i++) {
        for(int j = -1; j <= 1; j++) {
            find_words_util(board, visited, r + i, j + c, pref, words);
        }
    }

    visited[r][c] = false;
    pref.erase(pref.end() - 1);

}

vector<string> solve_boggle(const vector<vector<char> >& board)
{
    vector<string> results;
    bool visited[BOARD_SIZE][BOARD_SIZE];
    for(int r = 0; r < BOARD_SIZE; r++) {
        for(int c = 0; c < BOARD_SIZE; c++) {
            memset(visited, false, sizeof(visited[0]) * BOARD_SIZE * BOARD_SIZE);
            string pref;
            find_words_util(board, visited, r, c, pref, results);
        }
    }
    return results;
}

int main()
{
    string delim = string(20, '#') + '\n';
    vector<string> results;
    vector<vector<char> > grid;
    for(int i = 0; i < BOARD_SIZE; i++) {
        grid.push_back(vector<char>(BOARD_SIZE, 'O'));
    }

    grid[0][0] = 'g';
    grid[0][1] = 'i';
    grid[0][2] = 'z';
    grid[1][0] = 'u';
    grid[1][1] = 'e';
    grid[1][2] = 'k';
    grid[2][0] = 'q';
    grid[2][1] = 's';
    grid[2][2] = 'e';
    
    results = solve_boggle(grid);

    cout << "words found -->" << endl;
    for(vector<string>::size_type i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
}
