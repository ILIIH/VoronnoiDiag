#include "graphick.h"
#include "arc.h"
#include <QPoint>
#include <QPair>
#include <QTimer>
#include <QTime>
Graphick::Graphick()
{


}
int rando(int low, int high)
{
   return (qrand() % ((high + 1) - low) + low);
}
void Graphick::setRandSite(){
    QPoint temp;int i=0;
    while(i<1000){
    temp.setX(rando(0,1000));
    temp.setY(rando(0,800));
    Diag.setPriorityQueue(temp);
    i++;
    }
}
void Graphick::clear(){

    qglClearColor(Qt::white);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка буфера цвета & буфера глубины
    Diag.priority_queue.clear();
    QPoint temp(-20000,-20000);
    Diag.priority_queue.push_back(temp);
            update();
}
void Graphick::initializeGL()
{

  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  glOrtho(0, 1000, 800, 0, 0, 1);
  resize(1000,800);


}
//------------------------------------------------------------------------------
void Graphick::resizeGL(int w, int h)
{
  glViewport(0, 0, w, h);
  mScaleFactorX = 1000 / (float)w;
    mScaleFactorY = 800 / (float)h;
}

QString Graphick::PaintPerebor(int metric){


    QTime timer;
    timer.start();
 qglClearColor(Qt::white);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка буфера цвета & буфера глубины

   for(double i=0;i<800;i++){
        for(int j=0;j<1000;j++){

QColor col =Diag.Perebor(i,j,metric);



                qglColor( col );
                glPointSize(5);
                glBegin(GL_POINTS);
                glVertex2d(  j,i);
                glEnd();}


}
   qglColor(Qt::black);
   glPointSize(5);
    list <QPoint> * tem; tem = Diag.getlist();

   glBegin(GL_POINTS);
   list <QPoint> :: iterator site = tem->begin();
    for(;site!=tem->end();site++){
       glVertex2d(  site->x()*mScaleFactorX,   site->y()*mScaleFactorY);
    }
   glEnd();

if(Granici_Est)PaintGranici();
update();

return QString::number(timer.elapsed ());
}
//------------------------------------------------------------------------------
void Graphick::PaintFortune(){

    for(int i=0;i<900;i++){
        Diag.Sweepline(i);

    }
    qglClearColor(Qt::white);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка буфера цвета & буфера глубины
       qglColor(Qt::red);
       glPointSize(5);
       glBegin(GL_POINTS);

           glVertex2d(  11,   23);

       glEnd();
       update();

}
//------------------------------------------------------------------------------
void Graphick::paintGL()
{

if(its_firs){
    qglClearColor(Qt::white);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка буфера цвета & буфера глубины

    its_firs=0;
}


}
void Graphick:: mousePressEvent(QMouseEvent *apEvent){

   mPos= apEvent->pos();

  if(mPos.x()!=0&&mPos.y()!=0){ QPoint temp(mPos.x(),mPos.y() );
   Diag.setPriorityQueue(temp);}




 qglClearColor(Qt::white);
 glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);//очистка буфера цвета & буфера глубины
  qglColor(Qt::black);
  glPointSize(5);
   list <QPoint> * tem; tem = Diag.getlist();

  glBegin(GL_POINTS);
  list <QPoint> :: iterator site = tem->begin();
   for(;site!=tem->end();site++){
      glVertex2d(  site->x()*mScaleFactorX,   site->y()*mScaleFactorY);
   }
  glEnd();

   Diagram::numP++;
  update();

}
void Graphick::PaintGranici(){
    glLineWidth(3);
    qglColor(Qt::black);
    glBegin(GL_LINES);
    for(int i=0;i<Granici.size();i++){
    glVertex2d(Granici[i].x(),Granici[i].y());
    if(i+1<Granici.size())  glVertex2d(Granici[i+1].x(),Granici[i+1].y());
    else  glVertex2d(Granici[0].x(),Granici[0].y());
    }
     glEnd();

}
void Graphick::paintSite(QPoint s){


     qglColor(Qt::black);
     glPointSize(5);
     glBegin(GL_POINTS);
     glVertex2d( s.x()*mScaleFactorX,s.y()*mScaleFactorY);
       glEnd();
       Diagram::numP++;
      update();
}
