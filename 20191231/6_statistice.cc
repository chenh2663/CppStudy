#include <iostream>
using namespace std;

namespace judge{

int IsAlpha(char c)
{
    if((c>=65&&c<=90 )||( c>=97&&c<=122))
        return 1;
    return 0;
}
int IsNum(char c)
{
    if(c>=48&&c<=57)
        return 1;
    return 0;
}

}
int main()
{
    using namespace judge;
    int i=0;
    int *num = new int[3]();
    string buff;
    getline(cin,buff);
    while(buff[i])
    {
     if(IsAlpha(buff[i]))
     {
         ++num[0];
     }
     else if(IsNum(buff[i]))
     {
         ++num[1];
     }
     else{
         ++num[2];
     }
    ++i;
    }
    int *count = new int[3];//用来记录与最大值的差值
    int max=num[0];
    if(max<num[1])
        max=num[1];
    if(max<num[2])
        max=num[2];
    for(i=0;i<3;++i)
    {
        count[i]=num[i]-max;
    }
    for(i=0;i<=max;++i)
    {
        for(int j=0;j<3;++j)
        {
            if(count[j]==0)
            {
                cout<< "   "<<num[j]<<"     ";
            }
            else if(count[j]>0)
            {
                cout<<"******   ";
            }
            else {
                cout<<"         ";
            }
            ++count[j];
        }
        
        cout<<endl;
    }
    cout<<" Alpha     num     other "<<endl;    
    
    
    delete []num;
    return 0;
}

