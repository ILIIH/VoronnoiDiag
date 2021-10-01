#ifndef PARABOLA_H
#define PARABOLA_H
#include <QPoint>

class Parabola
{
public:
    QPoint GetFirstIntersection(Parabola & second_arch, double line_pos);
    QPoint GetSecondIntersection( Parabola & second_arch, double line_pos);
    Parabola();
      double eq(double x);
       double yd;
       QPoint focus ;
};

#endif // PARABOLA_H
