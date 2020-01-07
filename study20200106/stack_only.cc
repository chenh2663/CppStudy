#include <func.h>
#include <iostream>
using std::cout;
using std::endl;
class Phone{
public:

    Phone(const char *brand,int price)
        :_brand(new char[strlen(brand)+1]())
         ,_price(price){
             cout<< "Phone (const char *brand)"<<endl;
             strcpy(_brand,brand);
         }
    void print() const
    {
        cout<<"brand:"<<this->_brand<<endl;
        cout<<"price:"<<this->_price<<endl;

    }


    ~Phone()
    {
        delete []_brand;
        cout << "~Phone"<<endl;
    }




private:

    void  * operator new(size_t sz);
    void operator delete(void *p);


private:

    char * _brand;
    int _price;
};

int main()
{


    Phone p1("apple",8888);
//    Phone *p2=new Phone("apple",8888);

p1.print();
    return 0;
}

