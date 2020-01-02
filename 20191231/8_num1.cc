#include <iostream>
#include <func.h>
using namespace std;
typedef struct l{

    int date;
    struct l *next;

}l;
int main()
{
    int *flag=new int();
    int num;
    int count;
    struct l *q=NULL,*p;
    while(cin>>num)
    {
        count=0;
        if(num<0)
        {
            *flag=1;
            num=-num;
            ++count;
        }
        while(num)
        {
            p=new l;
            memset (p,0,sizeof(l));
            p->date= num%2;
            p->next=q;
            q=p;
            num=num/2;
        }
        cout<<*flag;

        while(q)
        {
            if(q->date==1)
            {
                count++;
            }

            cout<<q->date;
            p=q;
            q=q->next;
        }
        cout<<"\n1的个数为："<<count <<endl;
    }
    return 0;
}
