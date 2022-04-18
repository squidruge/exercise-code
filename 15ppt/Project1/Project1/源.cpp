#include <iostream>
#include <fstream>
#include <cstring>
using namespace std;

int main(int argc, char* argv[])
{
    ofstream out("out.txt", ios::out);
    out << "hel\0lo" << endl;
    out.close();

    char str[80];
    ifstream in("out.txt", ios::in);
    in.getline(str, 80);
    cout << strlen(str) << endl;
    cout << in.peek() << endl;
    in.close();

    return 0;
}
