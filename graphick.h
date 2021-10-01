#ifndef GRAPHICK_H
#define GRAPHICK_H
#include <QGLWidget>
#include <QMouseEvent>
#include "diagram.h"

class Graphick : public QGLWidget
{
public:
    void paintSite(QPoint s);
    Graphick();
    void clear();
    void initializeGL() override;
      void resizeGL(int w, int h)override;
      void paintGL()override;
      void mousePressEvent(QMouseEvent *apEvent)override;
      void PaintFortune();
      QString PaintPerebor(int metric);
           std:: vector <QPoint> Granici;
             void setSite(QPoint temp){Diag.setPriorityQueue(temp);}
             void setRandSite();
      bool Bottonenebl=0;
      bool Granici_Est =    0;
      void PaintGranici();
protected:

      float mScaleFactorX;
       float mScaleFactorY;

     Diagram Diag;
      QPoint mPos;
      bool its_firs =1;


};

#endif // GRAPHICK_H
