//if an element in M X N matrix is 0 set entire row and col to 0
//
#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <ios>
#include <cstring>

using namespace std;

#define ROWS 4
#define COLS 5

typedef vector<int>::size_type vec_sz;

void print_vec(int v[ROWS][COLS], streamsize width = 2)
{
    for(vec_sz r = 0; r < ROWS; r++) {
        for(vec_sz c = 0; c < COLS; c++) {
            streamsize prec = cout.precision();
            cout << setw(width) << v[r][c] <<  " " << setw(prec);
        }
        cout << endl;
    }
}

void set_row_col_0(int v[ROWS][COLS]) {
    bool skipped_rows[ROWS];
    bool skipped_cols[COLS];
    memset(skipped_rows, false, sizeof(skipped_rows));
    memset(skipped_cols, false, sizeof(skipped_cols));

    int result[ROWS][COLS];

    memcpy(result, v, ROWS * COLS * sizeof(int));

    for(int r = 0; r < ROWS; r++) {
        for(int c = 0; c < COLS; c++) {
            if(v[r][c] == 0) {
                for(int c1 = 0; c1 < COLS; c1++) {
                    result[r][c1] = 0;
                }
                for(int r1 = 0; r1 < ROWS; r1++) {
                    result[r1][c] = 0;
                }

                skipped_rows[r] = true;
                skipped_cols[c] = true;
            }
        }
    }

    memcpy(v, result, ROWS * COLS * sizeof(int));

}

int main()
{
    int v1[][COLS] = {
        {1, 2, 1, 1, 1},
        {6, 0, 3, 0, 5},
        {1, 0, 1, 1, 3},
        {4, 3,-1, 6, 2}
    };

    int v2[][COLS] = {
        {1, 2, 1, 1, 1},
        {6, 0, 3, 0, 5},
        {1, 6, 1, 1, 3},
        {4, 3,-1, 6, 2}
    };

    string delim = string(20, '#') + '\n';

    cout << "v1 --> " << endl;
    print_vec(v1);

    cout << "after setting to M and N to 0 -->" << endl;
    set_row_col_0(v1);
    print_vec(v1);
    cout << delim;

    cout << "v2 --> " << endl;
    print_vec(v2);

    cout << "after setting to M and N to 0 -->" << endl;
    set_row_col_0(v2);
    print_vec(v2);
    cout << delim;
}
