#include <iostream>
#include <istream>
#include <stdio.h>
#include <ostream>
using namespace std;
int main()
{
    char c;
    while((c=cin.get())!=EOF)
    {
        if(c>94&&c<123)
        { 
            c=c-32;
            cout << "转换大写字母为："<< c<<endl;
            
            cout.flush();
        }

    }
}
