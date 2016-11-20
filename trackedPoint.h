#ifndef TRACKEDPOINT_H
#define TRACKEDPOINT_H


#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <iostream>
#include <opencv2/core/core.hpp>

using namespace std;
using namespace cv;
//class that will contain the coordinates of the point and the annotation
//this class will also contain the coordinate of the center of the annotation
class trackedPoint{

private :
   // double x,y;
    Point2f pointCercle;
    Point2f pointCentre;
    string annotation;
    //double xCenter,yCenter;//center of the annotation

public :

    double getX();
    double getY();
    double getXCenter();
    double getYCenter();
    string getAnnotation();
    void changeX(double);
    void changeY(double);
    void changeCenter();//change the center

    Point2f getPointCercle();
    Point2f getPointCentre();

    //constructor
    trackedPoint();
    trackedPoint(double,double,string);

    void setPoint(double,double,string);



};


#endif // TRACKEDPOINT_H
