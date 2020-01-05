#include <iostream>
#include<func.h>
using std::cout;
using std::endl;
#define MAX 10
class Stack{
public:
    void push(int num)
    {
        if(full())
        {
            cout<<"栈溢出，程序终止"<<endl;
            exit(-1);
        }
        ++_sp;
        _stack_member[_sp]=num;
    }
    void pop()
    {
        if(empty())
        {
            cout<<"栈空，出栈失败"<<endl;
        }else{
            cout<<(_stack_member[_sp--])<<endl;
        }
    }
    int top() const
    {
        if(!empty())
        {
            return _stack_member[_sp];
        }
        return 0;
    }
    bool empty() const {
        if(_sp<0)
            return true;
        return false;
    }
    bool full() const{
        if(_sp>=MAX-1)
            return true;
        return false;

    }
    Stack()
    {
        memset(_stack_member,0,sizeof(_stack_member));
        _sp=-1;
        cout<<"初始化栈成功......"<<endl;
    }

private:
    int _stack_member[MAX];
    int _sp;

};
int main()
{
    Stack st;
    st.push(10);
    st.push(12);
    st.push(14);
    int topNum=st.top();
    cout<<"topNum = "<<topNum<<endl;
    st.pop();
    topNum=st.top();
    cout<<"topNum = "<<topNum<<endl;
    return 0;
}

