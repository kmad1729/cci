//this program tests what happens when you declare a stack array inside a class
//
#define ROW_COUNT 4
#define COL_COUNT 3

#include <iostream>

using namespace std;

class Box {
    public:
        void print_box() {
            for(int r = 0; r < ROW_COUNT; r++) {
                for(int c = 0; c < ROW_COUNT; c++) {
                    cout << box_arr[r][c] << " ";
                }
                cout << endl;
            }
        }

        void manipulate_box() {
            for(int r = 0; r < ROW_COUNT; r++) {
                for(int c = 0; c < ROW_COUNT; c++) {
                    if(r == c)
                        box_arr[r][c] = 1;
                    else
                        box_arr[r][c] = 5;

                }
            }
        }

        void do_something() {
            manipulate_box();
        }
    private:
        int box_arr[ROW_COUNT][COL_COUNT];
};

int main()
{
    Box b;
    b.do_something();
    b.print_box();
}



