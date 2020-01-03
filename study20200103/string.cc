#include <iostream>
#include <func.h>
using std::cout;
using std::endl;
class String{
public:
    String()//默认构造函数
        :_pstr(new char())
    {

    }
    String (const char *pstr)                  //构造函数
     :_pstr(new char[strlen(pstr)+1]())
    {
        strcpy(_pstr,pstr);
    }

    String (const String &rhs)//拷贝构造函数
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        strcpy(_pstr,rhs._pstr);
    }
    String & operator=(const String &rhs)//赋值运算符函数 
    {
        if(this != &rhs)
        {
            delete []_pstr;
            _pstr =new char[strlen(rhs._pstr)+1]();
            strcpy(_pstr,rhs._pstr);
        }
    }

    ~String()     //析构函数
    {
        delete []_pstr;
    }

    void print()
    {
        cout<< "I am print()"<<endl;
        cout<< _pstr<<endl;

    }
private:
    char * _pstr;


};
int main(void)

{
    String str1;
    str1.print();
    
    String str2="Hello,world";
    str2.print();

    String str3("chenhao");
    str3.print();

    String str4=str3;  //这个是拷贝构造函数     
    str4.print();
    
    str4=str2;        //这个是赋值运算符函数
    str4.print();

    
    return 0;
}

