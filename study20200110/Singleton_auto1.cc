#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr==_pInstance)
        {   ::atexit(destory);
            _pInstance=new Singleton();
        }
        return _pInstance;
    }
private:
    static void destory()
    {
        if(_pInstance)
            delete _pInstance;
    }
private:
    Singleton()
    {
        cout<<"Singleton()"<<endl;
    }
    ~Singleton()
    {
        cout<<"~Singleton()"<<endl;
    }
private:
    static Singleton * _pInstance;

};
Singleton *Singleton::_pInstance=getInstance();
int main()
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();
    cout<<"p1 = "<<p1<<endl;
    cout<<"p2 = "<<p2<<endl;
    return 0;
}

