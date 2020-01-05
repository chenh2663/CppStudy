#include <iostream>
using std::cout;
using std::endl;
//单例模式就是一个类只能创建一个对象
class Single{

public:
    static Single * getSingle()
    {
        if(_pstr==nullptr)
        {
            _pstr=new Single();

        }
        return _pstr;
    }

   static  void destory()
    {
        if(Single::_pstr!=nullptr)
        {
            delete _pstr;
            _pstr=nullptr;
        }
    }




private:
    Single()
    {
        cout<< "i am Single()"<<endl;
    }
    ~Single()
    {
        cout <<"I am ~Single()"<<endl;

    }

    static Single *_pstr;
};



Single *Single::_pstr=nullptr;

int main()
{
    
    Single *pstr1=Single::getSingle();
    Single *pstr2=Single::getSingle();
   cout<< pstr1<<endl;
   cout << pstr2<<endl;
    
   pstr1->destory();
   pstr2->destory();
    
    std::cout << "Hello world" << std::endl;
    return 0;
}

