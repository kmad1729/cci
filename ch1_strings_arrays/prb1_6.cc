/*rotate 2-d matrix by 90 degrees
 *
 * e.g
 *  1  2  3  4
 *  5  6  7  8
 *  9 10 11 12
 * 13 14 15 16
 *
 * becomes
 *  
 * 13  9  5  1
 * 14 10  6  2
 * 15 11  7  3
 * 16 12  8  4
 */

#include <ios>
#include <iomanip>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

template <class T>
using vec_sz = typename vector<T>::size_type;

template <class T>
void print_2d_vec(const vector<vector<T> >& v, streamsize width = 3) {
    vec_sz<T> size = v.size();
    for(vec_sz<T> r = 0; r < size; r++) {
        for(vec_sz<T> c = 0; c < size; c++) {
            streamsize prec = cout.precision();
            cout << setw(width) << v[r][c] << setw(prec);
        }
        cout << endl;
    }
}

template <class T>
void create_vec(vector<vector<T> >& v, T counter, vec_sz<T> n) {
    for(vec_sz<T> i = 0; i < n; i++) {
        v.push_back(vector<T>(n, -1));
    }

    for(vec_sz<T> r = 0; r < n; r++) {
        for(vec_sz<T> c = 0; c < n; c++) {
            v[r][c] = counter++;
        }
    }
}

template <class T>
void util_rotate_90(vector<vector<T> >& v, vec_sz<T> start_row, vec_sz<T> n) {
    if(n <= 1) return;
    for(vec_sz<T> k = start_row; k < start_row + n - 1; k++) {
        pair<vec_sz<T>, vec_sz<T> > p1(start_row, start_row + k);
        pair<vec_sz<T>, vec_sz<T> > p2(start_row + k, 
                start_row + n - 1);
        pair<vec_sz<T>, vec_sz<T> > p3(start_row + n -1, 
                start_row + n - 1 -k);
        pair<vec_sz<T>, vec_sz<T> > p4(start_row + n -1 -k, 
                start_row);
        swap(v[p1.first][p1.second], v[p2.first][p2.second]);
        swap(v[p1.first][p1.second], v[p3.first][p3.second]);
        swap(v[p1.first][p1.second], v[p4.first][p4.second]);
    }
    util_rotate_90(v, start_row + 1, n - 2);
}

template <class T>
void rotate_90(vector<vector<T> >& v) {
    util_rotate_90(v, 0, v.size());
}


template <class T>
void print_rotate_analysis(vector<vector<T> >& v) {
    cout << "orig array --> " << endl;
    print_2d_vec(v);

    rotate_90(v);

    cout << "after rotating by 90 degrees. array -->" << endl;
    print_2d_vec(v);
    
}

int main()
{
    string delim = string(20, '#') + '\n';
    vector<vector<int> > v1;
    create_vec(v1, 1, 4);
    print_rotate_analysis(v1);
    cout << delim;

    vector<vector<char> > v2;
    create_vec(v2, 'a', 5);

    print_rotate_analysis(v2);
}
