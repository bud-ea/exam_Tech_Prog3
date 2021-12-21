#include <iostream>

class Point
{
private:
    double m_x, m_y, m_z;
 
public:
    Point(double x=0.0, double y=0.0, double z=0.0): m_x(x), m_y(y), m_z(z)
    {
    }
 
    friend std::ostream& operator<< (std::ostream &out, const Point &point);
    friend std::istream& operator>> (std::istream &in, Point &point);
};
 
std::ostream& operator<< (std::ostream &out, const Point &point)
{
    // Поскольку operator<< является другом класса Point, то мы имеем прямой доступ к членам Point
    out << "Point(" << point.m_x << ", " << point.m_y << ", " << point.m_z << ")";
 
    return out;
}
 
std::istream& operator>> (std::istream &in, Point &point)
{
    // Поскольку operator>> является другом класса Point, то мы имеем прямой доступ к членам Point.
    // Обратите внимание, параметр point (объект класса Point) должен быть неконстантным, чтобы мы имели возможность изменить члены класса
    in >> point.m_x;
    in >> point.m_y;
    in >> point.m_z;
 
    return in;
}

class Mult
{
public:
    int d;

    Mult (int a)
    {
        d=a;
    }
    Mult operator *(int a)
    {
        d=d*a;
        return *this;
    }
    void Mult_out ()
    {
        std::cout << "Значение:" << d << std::endl;
    }
};
int main(int argc, const char * argv[]) {
    std::cout << "Введите значения: \n";
    
    Point point;
    std::cin >> point;
    std::cout << "Вы ввели: " << point << '\n';
    
    
    Mult g(6);
    g.Mult_out();
    g*7;
    g.Mult_out();
    
    return 0;
}
