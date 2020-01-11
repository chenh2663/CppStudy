#include <string.h>

#include <iostream>

using std::cout;
using std::endl;

class String{
    class charProxy;
public:
    String()//默认构造函数
        :_pstr(new char[5]()+4)
    {
        initRefcount();
        cout<<"String()"<<endl;
    }

    String(const char * str)//
        :_pstr(new char[strlen(str)+5]()+4)
    {
        initRefcount();
        strcpy(_pstr,str);
        cout<<"String(const char *)"<<endl;
    }

    String(const String &rhs)//拷贝构造函数
        :_pstr(rhs._pstr)
    {
        increRefcount();
        cout<<"String(const String &)"<<endl;
    }

    String & operator = (const String &rhs)   //赋值构造函数
    {
        if(this!=&rhs)//自复制问题
        {
            releasePstr();
            _pstr=rhs._pstr;
            increRefcount();
        }
        return *this;
    }
    charProxy operator[](int idx);
    ~String()     
    {
        releasePstr();
        cout<<"~String()"<<endl;
    }
    const char *c_str() const 
    {
        return _pstr;
    }
    int  getRefcount() const 
    {
        return *(int *)(_pstr-4);
    }
    int size() const 
    {
        return strlen(_pstr);
    }
private:
    void  initRefcount()
    {
        *(int *) (_pstr-4)=1;
    }
    void increRefcount()
    {
        ++ *(int *)(_pstr-4);
    }
    void decreRefcount()
    {
        -- *(int *)(_pstr-4);
    }
    void releasePstr()
    {
        if(getRefcount()>1)
            decreRefcount();
        else 
            delete [](_pstr-4);
    }

    class charProxy{
    public:
        charProxy(String &str,size_t idx)
            :_str(str)
             ,_idx(idx)
        {
            cout<<"charProxy(String &,size_t )"<<endl;
        }
        char &operator =(char ch);

        operator char ()
        {
            cout<<"operator char()"<<endl;
            return _str._pstr[_idx];
        }

    private:
        String & _str;
        int _idx;
    };
private:
    char * _pstr;
};
String::charProxy String::operator[](int idx)
{
    cout<<"charProxy operator[](int )"<<endl;
    return charProxy(*this ,idx);
}
char &String::charProxy::operator = (char ch)
{
    cout<<"char & operator=(char)"<<endl;
    if(_idx>=0&&_idx<(_str.size()))
    {   
        if(1==_str.getRefcount())
        {
            _str._pstr[_idx]=ch;
            return _str._pstr[_idx];
        }
        else
        {
            _str.decreRefcount();//
            char *ptemp=new char[_str.size()+5]()+4;
            strcpy(ptemp,_str._pstr);
            _str._pstr=ptemp;
            _str._pstr[_idx]=ch;
            _str.initRefcount();
            return _str._pstr[_idx];
        }
    }
}

//void operator = (int &lchar,const char &c)
void test0()
{
    String s1="hello";
    String s2=s1;
    cout<<" s1= "<<s1.c_str()<<endl;
    cout<<" s1.getRefcount "<<s1.getRefcount()<<endl;
    printf("s1's address is %p\n",s1.c_str()); 
    cout<<" s2= "<<s2.c_str()<<endl;
    cout<<" s2.getRefcount "<<s2.getRefcount()<<endl;
    printf("s2's address is %p\n",s2.c_str()); 
    String s3="world";
    cout<<" s3= "<<s3.c_str()<<endl;
    cout<<" s3.getRefcount "<<s3.getRefcount()<<endl;
    printf("s3's address is %p\n",s3.c_str()); 

    s3=s2;
    cout<<"after s3=s2"<<endl;
    cout<<" s1= "<<s1.c_str()<<endl;
    cout<<" s1.getRefcount "<<s1.getRefcount()<<endl;
    printf("s1's address is %p\n",s1.c_str()); 
    cout<<" s2= "<<s2.c_str()<<endl;
    cout<<" s2.getRefcount "<<s2.getRefcount()<<endl;
    printf("s2's address is %p\n",s2.c_str()); 
    cout<<" s3= "<<s3.c_str()<<endl;
    cout<<" s3.getRefcount "<<s3.getRefcount()<<endl;
    printf("s3's address is %p\n",s3.c_str()); 

    cout<<endl;
    cout<<endl;
    cout<<endl;

    cout<<" after s3[3]"<<endl; //下标访问
    cout<<"s3[3]=" <<s3[3]<<endl; //下标访问
    cout<<" s3= "<<s3.c_str()<<endl;
    cout<<" s3.getRefcount "<<s3.getRefcount()<<endl;
    printf("s3's address is %p\n",s3.c_str());
    cout<<endl;
    s3[3]='P';
    cout<<"after s[3]='p'"<<endl;
    cout<<" s1= "<<s1.c_str()<<endl;
    cout<<" s1.getRefcount "<<s1.getRefcount()<<endl;
    printf("s1's address is %p\n",s1.c_str()); 
    cout<<" s2= "<<s2.c_str()<<endl;
    cout<<" s2.getRefcount "<<s2.getRefcount()<<endl;
    printf("s2's address is %p\n",s2.c_str()); 
    cout<<" s3= "<<s3.c_str()<<endl;
    cout<<" s3.getRefcount "<<s3.getRefcount()<<endl;
    printf("s3's address is %p\n",s3.c_str());

}

int main()
{
    test0();

    return 0;
}

