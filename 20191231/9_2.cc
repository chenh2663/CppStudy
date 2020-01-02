#include <iostream>
#include <func.h>
using std::cout;
using std::cin;
using std::endl;
typedef struct twoNumber{
    int  number1;
    int number2;
}twoNumber;
namespace ch{

int getPos(int number)
{
    int pos=0;
    while((number&'\x01')==0)
    {
        ++pos;
        number >>=1;

    }

    return pos;

}

int getOne(int *arr,int length)
{
    int number=0;
    for(int i=0;i<length;++i)
    {
        number^=arr[i];

    }
    return number;

}
twoNumber getTwoNumber(int *arr,int length,int pos)
{
    twoNumber twoNu={0,0};

    for(int i=0;i<length;++i)
    {
        int temp=arr[i]>>pos;    
        if((temp&'\x01')==0)
        {
            twoNu.number1^=arr[i];

        }
        else {
            twoNu.number2^=arr[i];
        }


    }

    return twoNu;


}

}
int main()
{

    int arr[102];
    cout<< "请输入102个整数："<<endl;
    for(int i=0;i<102;++i)
    {

        cin>>arr[i];

    }
    int number=ch::getOne(arr,102);
    int pos = ch::getPos(number);
    twoNumber twoNu;
    twoNu=ch::getTwoNumber(arr,102,pos);
    cout<<"number1 is "<< twoNu.number1<<endl;
    cout<<"number2 is "<< twoNu.number2<<endl;
    return 0;
}

