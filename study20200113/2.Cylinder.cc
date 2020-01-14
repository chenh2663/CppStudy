#include <iostream>
using  std::cout;
using  std::endl;

#define PI 3.1415926
class Circle{
public:
    Circle(){
        cout<<"Circle()"<<endl;
    }
    Circle(double r)
    :_r(r)
    {
     cout<<"Circle(double)"<<endl;   
    }
    double getArea();
    double getPerimeter();
    void show();
private:
    double _r;
};

double Circle::getArea()
{
    return PI*_r*_r;
}

double Circle::getPerimeter()
{
    return 2*PI*_r;
}

void Circle::show()
{
    cout<<"圆的半径为:"<<_r<<endl;
    cout<<"圆的周长为:"<<getPerimeter()<<endl;
    cout<<"圆的面积为:"<<getArea()<<endl;
}

class Cylinder
:public Circle
{
public:
    Cylinder(double r,double h)
    :Circle(r)
    ,_h(h)
    {
        cout<<"Cylinder"<<endl;
    }
    double getVolume();
    void showVolume();
private:
    double _h;
};

double Cylinder::getVolume()
{
    return getArea()*_h;
}

void Cylinder::showVolume()
{
    cout<<"\n圆柱体底面圆"<<endl;
    show();
    cout<<"圆柱体的体积为："<<getVolume()<<endl;
}

void test0()
{
    Circle A(3);
    Cylinder B(3,3);
    A.show();
    B.showVolume();
}
int main()
{
    test0();
    return 0;
}

