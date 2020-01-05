#include <iostream>
#include<func.h>
using std::cout;
using std::endl;
#define MAX 10
class Queue{
public:
    void push(int num){
        if(!full()){
            //入队操作
            _queue_member[_tail]=num;
            _tail=(_tail+1)%MAX;
            cout<<"push():"<<num<<endl;
        }
        else{
            cout<<"当前队列已满，入队失败，程序终止"<<endl;
            exit(-1);
        }
    }
    void pop()//出队操作
    {
        if(empty())
        {
            cout<<"当前队列为空，出队失败"<<endl;
        }
        else{
            cout<<"pop():"<<(_queue_member[_fro])<<endl;
            _fro=((_fro+1)%MAX);
        }
    }
    int front() const//读取队头操作
    {
        if(!empty())
        {
            return _queue_member[_fro];
        }

        //队列空 没有返回   或者返回一个特定值
    }
    int back() const
    {    if(!empty())
        {
            return _queue_member[(_tail-1)%MAX];
        }
        //队列空 没有返回   或者返回一个特定值

    }
    bool empty() const {
        if(_fro==_tail)
            return true;
        return false;
    }
    bool full() const {
        if(((_tail+1)%MAX)==_fro)
            return true;
        return   false;
    }
    Queue() //默认构造函数，初始化对象成员
    :_fro(0)
    ,_tail(0)
    {
        memset(_queue_member,0,MAX);
    }
private:
    int _queue_member[MAX];
    int _fro;
    int _tail;

};

int main()
{
    Queue que;
    que.push(10);
    que.push(12);
    que.push(14);
    int froNum=que.front();
    cout<<"froNum:"<<froNum<<endl;
    que.pop();
    int tailNum=que.front();
    cout<<"tailNum:"<<tailNum<<endl;

    return 0;
}

