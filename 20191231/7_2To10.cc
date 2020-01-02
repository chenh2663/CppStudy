#include <iostream>
#include <string.h>
#include <math.h>
using std::endl;
using std::cout;
int main()
{

    char buff[100]={0};
    scanf("%s",buff);
    int iflag;
        int length;    
        int m;
        int num;
    while(1)

    {
        iflag=0;
        length=strlen(buff);
        m=0;
        num=0;
        for(int i=length-1;i>0;--i)
        {
            if(buff[i]=='0'||buff[i]=='1')
            {
                num+=(buff[i]-'0')* pow(2,m);
                ++m;
            }
            else if(buff[i]==EOF)//ctrl+d不能终结进程
            {
            exit(0) ;//ctrl+D结束进程
            }
            else
        {
                iflag=1;//输入非法
            }

        }
        if(iflag==0&&buff[0]=='0')
        {
            cout<<"转换十进制为"<<num<<endl;
        }
        else if(iflag==0&&buff[0]=='1')
        {
            cout<<"转换十进制为"<<-num<<endl;

        }
        else {
            cout<<"输入为非法二进制数"<<endl;
        }
        memset(buff,0,100);
        printf("请输入一个二进制数:");
        scanf("%s",buff);

    }
    return 0;
}

