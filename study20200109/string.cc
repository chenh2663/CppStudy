#include <string.h>

#include <cstring>
#include <iostream>

using std::string;
using  std::cout;
using std::endl;

class String{

public:
    String()//默认构造函数
        :_pstr(nullptr)
    {
        cout<<"String()"<<endl;
    }

    String(const char * str)
        :_pstr(new char[strlen(str)+1]())
    {
        cout<<"String(const char *)"<<endl;
        strcpy(_pstr,str);
    }

    String(const String & rhs)//赋值构造函数？
        :_pstr(new char[strlen(rhs._pstr)+1]())
    {
        cout<<"String(const String &)"<<endl;
        strcpy(_pstr,rhs._pstr);
    }
    ~String()
    {

        cout<<"~String()"<<endl;
        if(nullptr!=_pstr) 
            delete []_pstr;
    }

    String & operator=(const String &rhs)
    {
        if(nullptr!=_pstr)
            delete [] _pstr;
        _pstr=new char[strlen(rhs._pstr)+1]();
        strcpy(_pstr,rhs._pstr);
        return *this;//
    }

    String &operator =(const char *s)
        //这个地方如果原来有数据呢？直接覆盖？
    {
        if(nullptr!=_pstr)
            delete []_pstr;
        _pstr=new char[strlen(s)+1]();
        strcpy(_pstr,s);
        return *this;
    }

    String &operator +=(const String &rhs)
    {
        strcat(_pstr,rhs._pstr);
        return *this;

    }

    String &operator+=(const char *str)
    {
        strcat(_pstr,str);
        return *this;
    }

    char &operator[](std::size_t index)
    {
        if( index<0 || index>=strlen(_pstr) )
        { 
            cout<<"访问下标出错！"<<endl;
            static char nullchar='\0';
            return nullchar;
        }
        return _pstr[index];
    }

    const char &operator[](std::size_t index) const
    {
        return _pstr[index];
    }

    std::size_t size()const 
    {
        return strlen(_pstr);
    }

    const char *c_str()const   //有疑问
    {
        return _pstr;
    }

    friend bool operator==(const String &lhs,const String &rhs);
    friend bool operator!=(const String &lhs,const String &rhs);
    friend bool operator<(const String &lhs,const String &rhs);
    friend bool operator>(const String &lhs,const String &rhs);
    friend bool operator<=(const String &lhs,const String &rhs);
    friend bool operator>=(const String &lhs,const String &rhs);
    friend std::ostream &operator << (std::ostream&os,const String &s);
    friend std::istream &operator >> (std::istream&is,const String &s);
    char * getPstr() const 
    {
        return _pstr;
    }
private:
    char * _pstr;



};
bool operator == (const String &lhs, const String &rhs)
{
    return !strcmp(lhs._pstr,rhs._pstr);
}

bool operator != (const String &lhs,const String &rhs)
{
    return strcmp(lhs._pstr,rhs._pstr);
}

bool operator<(const String &lhs,const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)<0)
        return true;
    return false;
}
bool operator>(const String &lhs,const String &rhs)
{

    if(strcmp(lhs._pstr,rhs._pstr)>0)
        return true;
    return false;

}
bool operator <= (const String &lhs,const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)<=0)
        return true;
    return false;
}
bool operator >= (const String &lhs,const String &rhs)
{
    if(strcmp(lhs._pstr,rhs._pstr)>=0)
        return true;
    return false;
}

std::ostream &operator << (std::ostream&os,const String &s)
{
    string s1=s._pstr;
    os<<s1;
    return os;
}

std::istream &operator >> (std::istream &is,String &s)
{
    string s1;
    is>>s1;
    s=s1.c_str();
    return is;
}

String operator + (const String &lhs, const String &rhs)
{
    return strcat(lhs.getPstr(),rhs.getPstr());
}

String operator + (const String &lhs,const char *str)
{
    return strcat(lhs.getPstr(),str);
}

String operator + (const char *str1,const String & rhs)
    //String operator+(const char *str1,const char *str2)
{
    char *p_str=new char[strlen(str1)+strlen(rhs.getPstr())+1]();
    strcpy(p_str,str1);
    strcat(p_str,rhs.getPstr());
    return p_str;
}
int main()
{
    String s1;

    cout<<"&s1:  "<<&s1<<endl;

    String s2("hello");
    cout <<"s2: "<<s2<<endl;

    String s3(s2);
    cout<<"s3:  "<<s3<<endl;

    String s4=s3;
    cout<<"s4:  "<<endl;

    String s5=" world";
    cout<<"s5:  "<<endl;

    s4+=s5;
    cout<<"s4+=s5:  "<<s4<<endl;

    cout<<"s4[3]:   "<<s4[3]<<endl;

    cout<<"s4.size():    "<<s4.size()<<endl; 

    cout<<s4.c_str()<<endl;

    cout<<"s3==s4?: "<<(s3==s4)<<endl;
    cout<<"s4==s4?: "<<(s4==s4)<<endl;
    cout<<"s3!=s4?: "<<(s3!=s4)<<endl;
    cout<<"s4!=s4?: "<<(s4!=s4)<<endl;


    cout<<"s3>s4?:  "<<(s3>s4)<<endl;
    cout<<"s4<s4?:  "<<(s4<s4)<<endl;
    cout<<"s3<=s4?: "<<(s3<=s4)<<endl;
    cout<<"s4>=s4?: "<<(s4>=s4)<<endl;

    std::cin>>s1;
    cout<<"s1: "<<s1<<endl;

    s5=s1+s4;
    String s6=s4+"  hahahah ";
    String  s7="yyyyyyyyyyy   "+s4;
    cout <<"s5:  "<<s5<<endl;
    cout <<"s6:  "<<s6<<endl;
    cout <<"s7:  "<<s7<<endl;

    return 0;
}

