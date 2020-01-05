#include <iostream>
#include <func.h>
using std::cout;
using std::endl;
struct Node{
    int data;
    Node *pre;
    Node *next;
};
class List{
public:
    List()   //默认构造韩式
        :_head(nullptr)
         ,_tail(nullptr)
         ,_size(0)
    {
        cout<<"List()"<<endl;
    }
    ~List()  //析构函数
    {
        Node *p_temp;
        for(int i=0;i<_size;++i)
        {
        //    cout<<"_size:"<<_size<<endl;
            cout<<"~List()"<<endl;//测试用
            p_temp=_head;
            _head=_head->next;
            delete p_temp;
        }
    }
    void push_back(int value)   //在尾部添加数据
    {
        Node *p_new= new Node();
        p_new->data=value;
        if(_size==0)  //循环链表为空，新建节点为头尾节点
            _head=_tail=p_new;
        else {
            //插入循环链表的尾部
            _tail->next=p_new;
            p_new->pre=_tail;
            _tail=p_new;
            //p_new初始化已经 next与pre都初始化为空，next不再需要特意指定空指针
        }
       // cout<<_tail->next<<endl;    //调试用
        ++_size;
        cout << "新插入尾节点为："<<value
            <<"当前节点个数为："<<_size<<endl;
    }
    void push_front(int value)
    {
        Node *p_new= new Node();
        p_new->data=value;
        if(_size==0)
            _head=_tail=p_new;
        else {
            //插入循环链表的首部
            p_new->next=_head;
            _head->pre=p_new;
            _head=p_new;
        }
        ++_size;
        //p_new初始化已经 next与pre都初始化为空，pre不再需要特意指定空指针
        cout << "新插入头节点为："<<value
            <<"当前节点个数为："<<_size<<endl;
    }

    void pop_back()//在尾部删除一个数据
    {
        if(_size==0)
        {
            cout <<"当前链表为空，删除尾部节点失败!"<<endl; 
        }else{
            Node *p_temp=_tail;
            _tail=_tail->pre;
            _tail->next=nullptr;
            delete p_temp;
            --_size;
        }
    }
    void pop_front()//在头部删除一个数据
    {
        if(_size==0)
        {
            cout <<"当前链表为空，删除头部节点失败!"<<endl; 
        }else{
            Node *p_temp=_head;
            _head=_head->next;
            _head->pre=nullptr;
            delete p_temp;
            --_size;
        }
    }
    void insert(Node *p,int value)
    {
        if(find(p))//如果节点存在就插入 ，不存在就不做任何操作
        {
            Node *p_temp=new Node();
            p_temp->data=value;
            p_temp->next=p;
            p_temp->pre=p->pre;
            p->pre->next=p_temp;
            p->pre=p_temp;
            ++_size;
        }

    }
    void erase(int data)//判断该节点在不在链表之中
    {
        Node *p_temp=_head;
        for(int i=0;i<_size;++i)// 共有_size个节点  判断_size个节点即可
        {
            if(p_temp->data==data)
            {
                erase(p_temp);
                cout<<"erase(data):"<<data<<"存在于队列中第"<<(i+1)<<"个节点中,并删除该节点"<<endl;
                cout<<"删除data后：";
                display();
                return;
            }
            p_temp=p_temp->next;

        }
        cout<<"data:"<<data<<"不存在于队列中"<<endl;
    }
    void display() const
    {
        Node *p_temp=_head;
        if(_size)
        {
            cout<<"链表为：";
            cout<<(p_temp->data);//为了打印出来的链表美观
            p_temp=p_temp->next;
        } 
        else{
            cout<<"当前链表为空！";
        }
        for(int i=1;i<_size;++i)
        {
            
            cout<<"-->"<<(p_temp->data);
            p_temp=p_temp->next;
        }
        //cout<<"_size:"<<_size<<endl;
         cout<<endl;
    }
    void find(int data)//判断该节点在不在链表之中
    {
        Node *p_temp=_head;
        for(int i=0;i<_size;++i)// 共有_size个节点  判断_size个节点即可
        {
            if(p_temp->data==data)
            {
                cout<<"find(data):"<<data<<"存在于队列中第"<<(i+1)<<"个节点中"<<endl;
            }

        }
        cout<<"find(data):"<<data<<"不存在于队列中"<<endl;
    }
    void reverse()
    {
        cout << "逆置前为："<<endl;
        display();

        Node *p1=nullptr,*p2=nullptr,*p3=nullptr;//三个节点用于逆置

        if(_size>1)//当链表中只有一个或者0个节点时，不需要逆置
        {
            p1=_head;
            p2=p1->next;
            p3=p2->next;
            _tail=_head;
            _tail->next=nullptr;
           // cout<<(_tail->data)<<endl;
           // cout<<(p2->data)<<endl;
           // cout<<(p3->data)<<endl;
            for(int i=1;i<_size;++i)
            {
            //    cout<<(p1->data)<<endl;   //调试用
                p2->next=p1;
                p1->pre=p2;
                p1=p2;
                p2=p3;
                if(i<(_size-1))
                    p3=p3->next;
                else 
                    p3=nullptr;
            }

        _head=p1;
        _head->pre=nullptr;
        }
        cout << "逆置后为："<<endl;
        display();
    }



private://私有函数
    Node * find(Node * p)   //如果存在，就返回该节点；不存在，就返回空指针
    {
        Node *p_temp=_head;
        for(int i=0;i<_size;++i)
        {
            if(p==p_temp)
                return p_temp;

        }
        return nullptr;//该节点不存在于链表中，返回空指针
    }
    //                Node * insert(Node *p) //确定节点存在时，在该直接插入元素
    //            {
    //
    //            }
    void erase(Node *p_delete)         //删除一个指定的节点
    {
        Node * p_temp=p_delete;
        if(_size==1)
        {
            _head=_tail=nullptr;
        }
        else if(_head==p_delete)
        {
            _head=_head->next;
            _head->pre=nullptr;
        }else if(_tail==p_temp)
        {
            _tail=_tail->pre;
            _tail->next=nullptr;
        }
        else
        {
        p_delete->pre->next=p_delete->next;
        p_delete->next->pre=p_delete->pre;
        }
        delete p_temp;
        --_size;
        cout<<_size<<endl;
    }

private://私有成员
    Node *_head;
    Node *_tail;
    int _size;



};

int main()
{
    //实现链表逆置 利用头插法
    List l;
    l.push_back(4);
    l.push_back(3);
    l.push_front(1);
    l.push_front(2);
   // l.display();
    l.reverse();
    l.erase(1);
    l.erase(2);
    l.display();
    return 0;
}

