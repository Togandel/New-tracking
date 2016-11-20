#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "trackedPoint.h"
#include "traitement.h"



using namespace std;
using namespace cv;


//callback gerant la souris
void souris1(int event, int x, int y, int flags, void* param){

    if (event==EVENT_LBUTTONDOWN){
    //si l'utilisateur clique sur un point de l'image, le point que l'on suit devient celui ci.
        trackedPoint* point = (trackedPoint*) param;
        point->changeX(x);
        point->changeY(y);
        //cout<<point->getPointCentre()<<" "<<point->getAnnotation()<<endl;

    }

}

int main(){

    //initialisation
    Mat image1;
    Mat image2;
    VideoCapture cam(-1);
    namedWindow("image");
    namedWindow("image1");
    //init du point que l'on va suivre
    trackedPoint* pointSuivi= new trackedPoint();
    //callback
    setMouseCallback("image1", souris1, pointSuivi);



    //test si la cam est ouverte
    if (!cam.isOpened()){
        cout<<"Cam non ouverte !";
        return 1;
    }



    int pause =0;

    char key =cvWaitKey(5);
    //on lit une image
    cam.read(image1);



    //boucle d'execution du programme
    while(key != 'q' && key != 'Q') { //La boucle s'execute tans qu'on n'appuie pas sur q

        if (key=='p') {
            pause=(pause+1); // le bouton p permet de faire pause sur l'image pour sélectionner un point
        }

        if (pause==0)
        {
            //on lit une image
            cam.read(image1);
            //on test si l'image est vide
            if (image1.empty())
                cout<<"image vide !!"<<endl;
            circle(image1,pointSuivi->getPointCercle(),5,CV_RGB(0,0,255),5,8,0);
            putText(image1,pointSuivi->getAnnotation(),pointSuivi->getPointCentre(),FONT_HERSHEY_COMPLEX,0.8,CV_RGB(255,0,0),3,8,false);
            imshow("image1",image1);
        }


        key = cvWaitKey(5);

    }



   /* Mat descripteur1,descripteur2;
    std::vector<KeyPoint> pointcle1,pointcle2;
    pointcle1=getPointCle(image1);
    pointcle2=getPointCle(image2);
    descripteur1=detectionFeature(image1);
    descripteur2=detectionFeature(image2);
    std::vector<DMatch> pointsCommuns =matcher(descripteur1,descripteur2);
    */





    key=cvWaitKey(5);
    while (key!='q') {
        key=cvWaitKey(5);
    }

    //destruction des fenetres et des cameras
    destroyAllWindows();
    cam.release();


    return 0;
}
