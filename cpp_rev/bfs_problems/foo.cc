#include <cstring>
#include <iostream>
#include <iomanip>
#include <climits>
#include <algorithm>

using namespace std;

int main()
{
    int board[5][5];

    memset(board, 5, sizeof(board) * sizeof(int));

    cout << "int_max = " << INT_MAX << endl;

    for(int r = 0; r < 5; r++) {
        for(int c = 0; c < 5; c++) {
            cout << setw(3) << board[r][c];
        }
        cout << endl;
    }
}
