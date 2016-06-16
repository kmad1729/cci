//write a program to solve Towers of Hanoi problem
//
#define TOWER_SIZE 5

#include <stack>
#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class StackTower {
    public:
        stack<int> rod;
        string name;
        StackTower(string n) {
            name = n;
            rod = stack<int>();
        }

        void add_to_top(int disk) {
            if(!rod.empty()) {
                if(disk > rod.top())
                    throw domain_error("disk val greater than rod top!");
            }
            rod.push(disk);
        }

        void move_top_to(StackTower& dest_tower) {
            if(rod.empty()) {
                throw domain_error("there is no top!");
            }

            cout << "moving disk " << rod.top()
                << " from " << name << " to " << dest_tower.name << endl;
            dest_tower.add_to_top(rod.top());
            rod.pop();
        }

        void move_disks(int disk_num, StackTower& dest,
                StackTower& spare) {
            if(disk_num > 0) {
                move_disks(disk_num - 1, spare, dest);
                move_top_to(dest);
                spare.move_disks(disk_num - 1, dest, *this);
            }
        }

        void print_stacks(StackTower spare, StackTower dest) {
            stack<int> rod_copy(rod);
        }

};


int main()
{
    string delim = string(20,'#') + '\n';
    int N = TOWER_SIZE;

    StackTower s1("s1");
    StackTower s2("s2");
    StackTower s3("s3");

    for(int i = N - 1; i > -1; i--)
        s1.add_to_top(i);

    cout << "implementing towers of hanoi problem from"
        << " s1 to s3 " << endl;

    s1.move_disks(N, s3, s2);
}
