#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "trackedPoint.h"




trackedPoint::trackedPoint(){

    setPoint(50,50,"test");
}

trackedPoint::trackedPoint(double x ,double y,string annotation){

    setPoint(x,y,annotation);
}

void trackedPoint::setPoint(double a,double b,string s){

    pointCercle.x=a;
    pointCercle.y=b;
    annotation=s;
    changeCenter();
}


void trackedPoint::changeX(double a){

    pointCercle.x=a;
    changeCenter();
}

void trackedPoint::changeY(double a){

    pointCercle.y=a;
    changeCenter();
}

void trackedPoint::changeCenter(){

    if ((pointCercle.x<620)&&(pointCercle.y<400)){
        pointCentre.x=pointCercle.x+10;
        pointCentre.y=pointCercle.y+10;
    }
    else{
        pointCentre.x=pointCercle.x-10;
        pointCentre.y=pointCercle.y-10;
    }

}

double trackedPoint::getX(){

    return pointCercle.x;
}


double trackedPoint::getY(){

    return pointCercle.y;
}

string trackedPoint::getAnnotation(){

    return annotation;
}


double trackedPoint::getXCenter(){

    return pointCentre.x;
}

double trackedPoint::getYCenter(){

    return pointCentre.y;
}

Point2f trackedPoint::getPointCentre(){

    return pointCentre;
}

Point2f trackedPoint::getPointCercle(){

    return pointCercle;
}





