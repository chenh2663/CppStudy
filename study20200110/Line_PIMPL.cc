#include "Line.h"
#include <iostream>

using std::cout;
using std::endl;

class Line::LineImple{
public:
    LineImple(int x1,int y1,int x2,int y2);

    void  printLine() const;
private://不让直接访问Point类
    class Point
    {
    public:
        Point (int ix=0,int iy=0)
            :_ix(ix)
             ,_iy(iy)
        {
            cout <<"Point(int =0,int=0)"<<endl;


        }
        void print() const ;
    private:
        int _ix;
        int _iy;
    };
private:
    Point _pt1;
    Point _pt2;

};
Line::Line(int x1,int y1,int x2,int y2)
    :_pImple(new LineImple(x1,y1,x2,y2))
{
    cout<<"Line(int ,int ,int ,int)"<<endl;
};

Line::~Line()
{
    delete _pImple;
    cout<<"~Line()"<<endl;
}


Line:: LineImple::LineImple(int x1,int y1,int x2,int y2)
    :_pt1(x1,y1)
     ,_pt2(x2,y2)
{
    cout<<"Line::LineImple(int,int,int,int)"<<endl;
}
void Line::LineImple::printLine() const   
{
    _pt1.print();
    cout<<"---->";
    _pt2.print();
    cout<<endl;
}
void Line::LineImple::Point::print() const 
{
    cout << "(" << _ix
        << "," << _iy
        << ")" ;
}

int main()
{
    Line line(1,2,3,4);
    line.printLine();
    return 0;
}

void Line::printLine() const
{
    _pImple->printLine();
}
