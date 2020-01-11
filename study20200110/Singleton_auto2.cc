#include <iostream>
using std::cout;
using std::endl;

class Singleton
{
public:
    static Singleton *getInstance()
    {
        if(nullptr==_pInstance)
            _pInstance=new Singleton();

            return _pInstance;
    }
private:
    class AutoRelease{
    public:
        AutoRelease()
        {

        }
        ~AutoRelease()
        {
            if(_pInstance)
            {
                delete _pInstance;
                cout <<"~AutoRelease()"<<endl;
            }
        }
    };
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
    static AutoRelease _ar;
    int _ix;

};
Singleton *Singleton::_pInstance=getInstance();
Singleton::AutoRelease Singleton::_ar;
int main()
{
    Singleton *p1=Singleton::getInstance();
    Singleton *p2=Singleton::getInstance();
    cout<<"p1 = "<<p1<<endl;
    cout<<"p2 = "<<p2<<endl;
    return 0;
}

