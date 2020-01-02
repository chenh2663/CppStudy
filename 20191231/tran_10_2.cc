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
    struct l *q=NULL,*p;
    while(cin>>num)
    {
        if(num<0)
        {
            *flag=1;
            num=-num;
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
        cout<<q->date;
        p=q;
        q=q->next;
        }
        cout<<endl;
    }
    return 0;
}
