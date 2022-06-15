#include <iostream>
#include <string>
using namespace std;
int main()
{
    char name[30];
    cin.getline(name, 30, '#');
    cout << name << endl;
    return 0;
}