#include "parabola.h"

Parabola::Parabola()
{

}
double Parabola::eq(double x){

   return (pow(x-this->focus.x(),2)/2*(this->focus.y()-yd))+((this->focus.y()+yd)/2);

}
QPoint Parabola::GetSecondIntersection( Parabola & second_arch, double line_pos){
yd=line_pos;
    QPoint intersect_points(0,0);
            double p1 = 2 * (line_pos - this->focus.y());
            double p2 = 2 * (line_pos - second_arch.focus.y()); // is not 0.0, because line moved down
            if (fabs(p1) <=0.000001||fabs(p2) <=0.000001) {
          intersect_points.setX(this->focus.x());  intersect_points.setY(this->eq(this->focus.x()));
            } else {
                // solving the equation

                double a1 = 1 / p1;
                double a2 = 1 / p2;
                double a = a2 - a1;
                double b1 = -this->focus.x() / p1;
                double b2 = -second_arch.focus.x() / p2;
                double b = b2 - b1;
                double c1 = pow(this->focus.x(), 2) + pow(this->focus.y(), 2) - pow(line_pos, 2) / p1;
                double c2 = pow(second_arch.focus.x(), 2) + pow(second_arch.focus.y(), 2) - pow(line_pos, 2) / p1;
                double c = c2 - c1;
                double D = pow(b, 2) - 4 * a * c;
                if (D < 0) {
                     intersect_points.setX(0);  intersect_points.setY(0);
                    return intersect_points;
                } else if (fabs(D) <= 0.00001) {
                    double x = -b / (2 * a);
                    double y = a1 * pow(x, 2) + b1 * x + c1;
                     intersect_points.setX(x);
                     intersect_points.setY(y);
                } else {
                    double x2 = (-b + sqrt(D)) / (2 * a);
                    double y2 = a1 * pow(x2, 2) + b1 * x2 + c1;
                    intersect_points.setX(x2);
                    intersect_points.setY(y2);
                           }
            }
            return intersect_points;

}
QPoint Parabola::GetFirstIntersection(Parabola & second_arch, double line_pos){
yd=line_pos;
    QPoint intersect_points(0,0);
            double p1 = 2 * (line_pos - this->focus.y());
            double p2 = 2 * (line_pos - second_arch.focus.y()); // is not 0.0, because line moved down
            if (fabs(p1) <=0.000001||fabs(p2) <=0.000001) {
          intersect_points.setX(this->focus.x());  intersect_points.setY(this->eq(this->focus.x()));
            } else {
                // solving the equation
                double a1 = 1 / p1;
                double a2 = 1 / p2;
                double a = a2 - a1;
                double b1 = -this->focus.x() / p1;
                double b2 = -second_arch.focus.x() / p2;
                double b = b2 - b1;
                double c1 = pow(this->focus.x(), 2) + pow(this->focus.y(), 2) - pow(line_pos, 2) / p1;
                double c2 = pow(second_arch.focus.x(), 2) + pow(second_arch.focus.y(), 2) - pow(line_pos, 2) / p1;
                double c = c2 - c1;
                double D = pow(b, 2) - 4 * a * c;
                if (D < 0) {
                     intersect_points.setX(0);  intersect_points.setY(0);
                    return intersect_points;
                } else if (fabs(D) <= 0.00001) {
                    double x = -b / (2 * a);
                    double y = a1 * pow(x, 2) + b1 * x + c1;
                     intersect_points.setX(x);
                     intersect_points.setY(y);
                } else {
                    double x1 = (-b - sqrt(D)) / (2 * a);
                    double y1 = a1 * pow(x1, 2) + b1 * x1 + c1;
                    intersect_points.setX(x1);
                    intersect_points.setY(y1);
                           }
            }
            return intersect_points;

}
