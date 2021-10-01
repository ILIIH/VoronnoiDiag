#ifndef DIAGRAM_H
#define DIAGRAM_H
#include "iostream"
#include <vector>
#include <list>
#include <queue>
#include <Qpoint>
#include "parabola.h"
#include <QPair>
#include <QColor>
using namespace std ;



struct acrline{
    Parabola* arc=new Parabola;
    acrline* left;
     acrline* right;
 acrline* next;
};



class Diagram
{
private :
    void CombinationRoot (double Yd);
    vector <QColor> Color;
   acrline* root=new acrline;
    bool its_first=true;
    list <QPoint> :: iterator site;
     static int   numP;
     list <QPoint> priority_queue;
     void siteEvent(QPoint Site);
     void circleEvent();
public:

    list <QPoint> * getlist(){return &priority_queue;}
    void setPriorityQueue(QPoint temp);
    vector <QPoint> Sweepline(double Yd);
    QColor Perebor(double Y,double X, int metric);
    friend class Graphick ;
    Diagram();
};


#endif // DIAGRAM_H
