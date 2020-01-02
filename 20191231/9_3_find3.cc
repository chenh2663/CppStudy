#include <iostream>
#include <func.h>
#define Size 7
using namespace std;
int find1(int arr[],int count)
{
    int number =0;
    for(int i=0;i<count;++i)
        number ^= arr[i];
    return number ;
}
void  find2(int arr[],int count)
{
    int n=find1(arr,count);
    int mask= n &(~n+1);
    int number1=0,number2=0;
    for(int i=0;i<count;++i)
    {
        if(arr[i]&mask)
        {
            number1 ^= arr[i];
        }
        else {
            number2 ^= arr[i];
        }
    }
    cout << "number1 = "<<number1<<"\nnumber2 = "<<number2<<endl;
}
void find3 (int arr[])
{
    int heap1[Size]={0};
    int heap2[Size]={0};
    int count1=0,count2=0;
    int number1=0,number2=0;
    for(int i=0;i<32;++i)
    {
        for(int j=0;j<Size;++j)
        {
            if((arr[i]&(1<<i)))
            {
                number1 ^=arr[i];
                heap1[count1++]=arr[i];
            }
            else {
                number2 ^= arr[i];
                heap2[count2++]=arr[i];

            }
        }
        if(number1 ==0||number2 == 0)
            continue;

        if(count1>0&&count1%2==0)//若count1 为偶数 说明 第一个堆里面有两个只出现一次的数
        {

            find2(heap1,count1);
            cout<< "numer3 = "<<number2<<endl;
            break;



        }else if(count2>0&&count2%2==0)
        {

            find2(heap2,count2);
            cout<< "numer3 = "<<number1<<endl;
            break;
        }
    }
}
    int main()
{

    int arr[Size]={0};
    cout<<"请输入103个数："<<endl;
    for(int i=0;i<Size;++i)
        cin>>arr[i];
        find3(arr);
        return 0;
    }

