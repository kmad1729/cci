#include <iostream>
#include <fstream>
#include <string>

using std::getline;
using std::cout;
using std::endl;
using std::cerr;
using std::ifstream;
using std::string;

int main(int argc, char* argv[])
{
    if(argc < 2) {
        cerr << "please specify an approprate file name to cat" << endl;
    }
    int fail_count = 0;

    for(int i = 1; i < argc; i++) {
        ifstream in(argv[i]);
        if(in) {
            string line;
            while(getline(in, line)) {
                cout << line << endl;
            }
        } else {
            ++fail_count;
            cerr << "failed to open file " << argv[i] << endl;
        }
        cout << string(20, '#') << endl;
    }
    return fail_count;
}
