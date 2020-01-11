#ifndef __LINE_H__
#define __LINE_H__

class Line
{
public:
    Line(int ,int ,int ,int );
    ~Line();
    
    void printLine() const;
    class LineImple;

private:
    LineImple * _pImple;
};

#endif
