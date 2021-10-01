#ifndef ARC_H
#define ARC_H
#include <QPoint>

//struct point;



class Arc
{
public:
Arc();
QPoint GetFirstIntersection( Arc& second_arch, double line_pos);
QPoint GetSecondIntersection( Arc& second_arch, double line_pos);
  double eq(double x,double yd);
 QPoint* focus ;


};

#endif // ARC_H
