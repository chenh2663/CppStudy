#include <stdlib.h>
#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        pthread_once(&_once,init);
        return _pInstance;

    }
    static void init ()
    {
        _pInstance=new Singleton();
        atexit(destory);
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
    static pthread_once_t _once;
};
Singleton *Singleton::_pInstance=getInstance();
pthread_once_t  Singleton::_once=PTHREAD_ONCE_INIT;
int main()
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();
    cout<<"p1 = "<<p1<<endl;
    cout<<"p2 = "<<p2<<endl;
    return 0;
}

