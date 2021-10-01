#include "diagram.h"
#include <cmath>


int Diagram:: numP=0;

Diagram::Diagram()
{

}

vector <QPoint> Diagram::Sweepline(double Yd){

vector <QPoint> intercetion ;

    auto Vsite = priority_queue.begin();
    acrline* NewPointArcL=new acrline;
    acrline* temp=root;
 //ДОБАВЛЕНИЕ НОВОЙ АРКИ В АРКЛАЙН
if(Yd==Vsite->y()){
//СОБЫТИЕ ДОБАВЛЕНИЯ ТОЧКИ НАЧАЛО

    Parabola tempParab;
    tempParab.focus.setX(Vsite->x());
    tempParab.focus.setY(Vsite->y());tempParab.yd=Yd;
    QPoint FirstInst =temp->arc->GetFirstIntersection(tempParab,Yd);
    QPoint SecInst =temp->arc->GetSecondIntersection(tempParab,Yd);

    if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
     ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){
        //ЕСЛИ ЕСТЬ ПЕРЕСЕЧЕНИЕ С РУТОМ
if(temp->arc->focus.x()<Vsite->x()){
    while(temp!=nullptr){
        if(temp->right==nullptr){
            NewPointArcL->arc->focus.setX(Vsite->x());
            NewPointArcL->arc->focus.setY(Vsite->y());
            NewPointArcL->left=nullptr;
           NewPointArcL->right=nullptr;
           NewPointArcL->next=nullptr;
            temp->right=NewPointArcL;
             break;
        }
        else{
            //ПРОВЕРКА ЕСТЬ ЛИ ПЕРЕСЕЧЕНИЯ в пределах 1000 у 800 х ЕСЛИ НЕТ ТО ЗАПИСЬ В НЕКСТ
            Parabola tempParab;
            tempParab.focus.setX(Vsite->x());
            tempParab.focus.setY(Vsite->y());tempParab.yd=Yd;
            QPoint FirstInst =temp->arc->GetFirstIntersection(tempParab,Yd);
            QPoint SecInst =temp->arc->GetSecondIntersection(tempParab,Yd);
            if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
             ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){
            temp=temp->right;
            }
            else {
                while(temp!=nullptr){
                if(temp->next==nullptr){
                    NewPointArcL->arc->focus.setX(Vsite->x());
                    NewPointArcL->arc->focus.setY(Vsite->y());
                    NewPointArcL->left=nullptr;
                   NewPointArcL->right=nullptr;
                   NewPointArcL->next=nullptr;
                    temp->next=NewPointArcL;
                    break;
                }
                else temp=temp->next;}

            }
            }
}}
//
else {
    while(temp!=nullptr){
        if(temp->left==nullptr){
            NewPointArcL->arc->focus.setX(Vsite->x());
            NewPointArcL->arc->focus.setY(Vsite->y());
            NewPointArcL->left=nullptr;
            NewPointArcL->right=nullptr;
            NewPointArcL->next=nullptr;
            temp->left=NewPointArcL;
            break;
        }
        else{
            //ПРОВЕРКА ЕСТЬ ЛИ ПЕРЕСЕЧЕНИЯ в пределах 1000 у 800 х ЕСЛИ НЕТ ТО ЗАПИСЬ В НЕКСТ
            Parabola tempParab;
            tempParab.focus.setX(Vsite->x());
            tempParab.focus.setY(Vsite->y());tempParab.yd=Yd;
            QPoint FirstInst =temp->arc->GetFirstIntersection(tempParab,Yd);
            QPoint SecInst =temp->arc->GetSecondIntersection(tempParab,Yd);
            if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
             ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){
            temp=temp->right;
            }
            else {
                while(temp!=nullptr){
                if(temp->next==nullptr){
                    NewPointArcL->arc->focus.setX(Vsite->x());
                    NewPointArcL->arc->focus.setY(Vsite->y());
                    NewPointArcL->left=nullptr;
                   NewPointArcL->right=nullptr;
                   NewPointArcL->next=nullptr;
                    temp->next=NewPointArcL;
                    break;
                }
                else temp=temp->next;}

            }
            }}}

    }
else{
    //ЕСЛИ НЕТ ПЕРЕСЕЧЕНИЙ С РУТОМ
        acrline* newtemp = root->next;
        temp = newtemp;
        while (temp!=nullptr) {
if(temp->next==nullptr){NewPointArcL->arc->focus.setX(Vsite->x());
    NewPointArcL->arc->focus.setY(Vsite->y());
    NewPointArcL->left=nullptr;
   NewPointArcL->right=nullptr;
   NewPointArcL->next=nullptr;
    temp->next=NewPointArcL;
    break;}
else {

    if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
     ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){
        //ЕСЛИ ЕСТЬ ПЕРЕСЕЧЕНИЕ С НЕКСТОВІМ РУТОМ
if(temp->arc->focus.x()<Vsite->x()){
    while(temp!=nullptr){
        if(temp->right==nullptr){
            NewPointArcL->arc->focus.setX(Vsite->x());
            NewPointArcL->arc->focus.setY(Vsite->y());
            NewPointArcL->left=nullptr;
           NewPointArcL->right=nullptr;
           NewPointArcL->next=nullptr;
            temp->right=NewPointArcL;
             break;
        }
        else{
            //ПРОВЕРКА ЕСТЬ ЛИ ПЕРЕСЕЧЕНИЯ в пределах 1000 у 800 х ЕСЛИ НЕТ ТО ЗАПИСЬ В НЕКСТ
            Parabola tempParab;
            tempParab.focus.setX(Vsite->x());
            tempParab.focus.setY(Vsite->y());tempParab.yd=Yd;
            QPoint FirstInst =temp->arc->GetFirstIntersection(tempParab,Yd);
            QPoint SecInst =temp->arc->GetSecondIntersection(tempParab,Yd);
            if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
             ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){
            temp=temp->right;
            }
            else {
                while(temp!=nullptr){
                if(temp->next==nullptr){
                    NewPointArcL->arc->focus.setX(Vsite->x());
                    NewPointArcL->arc->focus.setY(Vsite->y());
                    NewPointArcL->left=nullptr;
                   NewPointArcL->right=nullptr;
                   NewPointArcL->next=nullptr;
                    temp->next=NewPointArcL;
                    break;
                }
                else temp=temp->next;}

            }
            }
}}
//
else {
    while(temp!=nullptr){
        if(temp->left==nullptr){
            NewPointArcL->arc->focus.setX(Vsite->x());
            NewPointArcL->arc->focus.setY(Vsite->y());
            NewPointArcL->left=nullptr;
            NewPointArcL->right=nullptr;
            NewPointArcL->next=nullptr;
            temp->left=NewPointArcL;
            break;
        }
        else{
            //ПРОВЕРКА ЕСТЬ ЛИ ПЕРЕСЕЧЕНИЯ в пределах 1000 у 800 х ЕСЛИ НЕТ ТО ЗАПИСЬ В НЕКСТ
            Parabola tempParab;
            tempParab.focus.setX(Vsite->x());
            tempParab.focus.setY(Vsite->y());tempParab.yd=Yd;
            QPoint FirstInst =temp->arc->GetFirstIntersection(tempParab,Yd);
            QPoint SecInst =temp->arc->GetSecondIntersection(tempParab,Yd);
            if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
             ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){
            temp=temp->right;
            }
            else {
                while(temp!=nullptr){
                if(temp->next==nullptr){
                    NewPointArcL->arc->focus.setX(Vsite->x());
                    NewPointArcL->arc->focus.setY(Vsite->y());
                    NewPointArcL->left=nullptr;
                   NewPointArcL->right=nullptr;
                   NewPointArcL->next=nullptr;
                    temp->next=NewPointArcL;
                    break;
                }
                else temp=temp->next;}

            }
            }}}

    }
   else newtemp=newtemp->next;

}
        }
}
// <КОНЕЦ> СОБЫТИЕ ДОБАВЛЕНИЯ ТОЧКИ
}
CombinationRoot ( Yd);

    return intercetion;
}

void Diagram::CombinationRoot (double Yd){
    //пРОВЕРКА СОБЫТИЯ ОБЬЕДЕНИЕИЯ ARCLINE
    if(root->next!=nullptr){
     acrline* Tempo= root;
       acrline* TempPointArc=new acrline;
    while(Tempo->next!=nullptr){
    ;
        acrline* righter= root;
         acrline* lefter= root;
        if(Tempo->arc->focus.x()>Tempo->next->arc->focus.x()){
            while(righter->right!=nullptr)righter=righter->right;
            //ЕСТЬ ЛИ ПЕРЕСЕЧЕНИЯ
            Parabola temporalParab;
            temporalParab.focus.setX(righter->arc->focus.x());
            temporalParab.focus.setY(righter->arc->focus.y());temporalParab.yd=Yd;
            QPoint FirstInst =Tempo->arc->GetFirstIntersection(temporalParab,Yd);
            QPoint SecInst =Tempo->arc->GetSecondIntersection(temporalParab,Yd);
            if((FirstInst.x()<800&&FirstInst.x()>0)&&(FirstInst.y()<1000&&FirstInst.y()>0)
             ||   (SecInst.x()<800&&SecInst.x()>0)&&(SecInst.y()<1000&&SecInst.y()>0)  ){


            }

        }
        else {
            while(lefter->left!=nullptr)lefter=lefter->left;

        }
    }

    }


}
QColor Diagram::Perebor(double Y,double X, int metric){



    int cou=0;
    list <QPoint> :: iterator iter2= priority_queue.begin();
double dist;
double mindist;
        list <QPoint> :: iterator iter= priority_queue.begin();
        QPoint Iter(iter->x(),iter->y());
   if(metric==1)mindist=sqrt(pow(iter->x()-X,2)+pow(iter->y()-Y,2));
   if(metric==2)mindist  = sqrt(pow(iter->x()-X,2)+pow(cos(iter->y()),2)-pow(cos(Y),2));
   if(metric==3)mindist  = abs(iter->x()-X)+abs(iter->y()-Y);
    if(metric==4)mindist = pow(pow(iter->x()-X,4)+pow(iter->y()-Y,4),0.25);

int posMinDist;
    for(;iter!=priority_queue.end();iter++){

        Iter.setX(iter->x());Iter.setY(iter->y());

    if(metric==1) dist = sqrt(pow(iter->x()-X,2)+pow(iter->y()-Y,2));
    if(metric==3)dist = abs(iter->x()-X)+abs(iter->y()-Y);
    if(metric==2)dist  = sqrt(pow(iter->x()-X,2)+pow(cos(iter->y()),2)-pow(cos(Y),2));
    if(metric==4)dist = pow(pow(iter->x()-X,4)+pow(iter->y()-Y,4),0.25); 
    if(mindist>=dist){mindist=dist;posMinDist=cou;}
     cou++;
    }
    if(posMinDist>Color.size())return Color[0];
  return Color[posMinDist];


}

int randomBetween(int low, int high)
{
   return (qrand() % ((high + 1) - low) + low);
}

void Diagram::setPriorityQueue(QPoint temp){
QColor t;
t.setRgb(randomBetween(0,255),randomBetween(100,200),randomBetween(50,120));
Color.push_back(t);
if(temp.x()!=0&&temp.y()!=0){
if(numP==0){
    root->arc->focus.setX(temp.x());
    root->arc->focus.setY(temp.y());
    root->next=nullptr;root->right=nullptr;root->left=nullptr;
    priority_queue.push_front(temp);return ;}
 list <QPoint> :: iterator i = priority_queue.begin();i++;
  for(;i!=priority_queue.end();i++){
      if(i->y()>=temp.y()){priority_queue.insert(i,temp);return ;}
  }
priority_queue.push_back(temp);
site = priority_queue.begin();

}}


