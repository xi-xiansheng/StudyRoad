#include <iostream>

using namespace std;

int main()
{
    string str;
    getline(cin, str);
    int count = 0;
    string::reverse_iterator rit = str.rbegin();
    while (rit != str.rend() && *rit++ != ' ')
    {
        count++;
    }
    cout << count;

    return 0;
}