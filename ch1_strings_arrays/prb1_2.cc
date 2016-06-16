//reverse a c style string

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

void reverse_str(char* s)
{
    int i = 0;
    int j = strlen(s) - 1;
    while(i < j) {
        char tmp = s[i];
        s[i] = s[j];
        s[j] = tmp;
        i++; j--;
    }
}

int main()
{
    char s1[] = "abcd";
    char s2[] = "abcde";
    char s3[] = "a";
    char s4[] = "";

    cout << "before reverse s1 --> (" << s1 << ")" << endl;
    reverse_str(s1);
    cout << "after reverse s1 --> (" << s1 << ")" << endl;

    cout << "before reverse s2 --> (" << s2 << ")" << endl;
    reverse_str(s2);
    cout << "after reverse s2 --> (" << s2 << ")" << endl;

    cout << "before reverse s3 --> (" << s3 << ")" << endl;
    reverse_str(s3);
    cout << "after reverse s3 --> (" << s3 << ")" << endl;

    cout << "before reverse s4 --> (" << s4 << ")" << endl;
    reverse_str(s4);
    cout << "after reverse s4 --> (" << s4 << ")" << endl;


}
