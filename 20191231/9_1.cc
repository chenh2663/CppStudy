#include <iostream>
using namespace std;
namespace ch{

int getOne(int arr[],int length)
{
    int num=0;
    for(int i=0;i<length;++i)
    {
    num^=arr[i];
    }
    return num;
}



}
int main()
{

int arr[101];
cout<<"请输入101个整数："<<endl;
for(int i=0;i<101;++i)
    cin>>arr[i];
int num=ch::getOne(arr,101);
cout<<"the only one is "<<num<<endl;

}

