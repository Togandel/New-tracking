#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "traitement.h"



using namespace std;
using namespace cv;







int main(){

    Mat image;
    Mat image1,image2;
    VideoCapture cam(-1);
    namedWindow("image");

    //test si la cam est ouverte
    if (!cam.isOpened()){
        cout<<"Cam non ouverte !";
        return 1;
    }

    int capture =0;

    char key =cvWaitKey(5);
    while(key!='q'){
        //on lit une image
        cam.read(image);
        //on test si l'image est vide
        if (image.empty())
            cout<<"image vide !!"<<endl;
        imshow("image",image);

        if (key =='p'){
            capture++;
        }

        if (capture==1)
            image1=image;

        if (capture==2)
            image2=image;

        key=cvWaitKey(5);
    }


    Mat descripteur1,descripteur2;
    std::vector<KeyPoint> pointcle1,pointcle2;
    pointcle1=getPointCle(image1);
    pointcle2=getPointCle(image2);
    descripteur1=detectionFeature(image1);
    descripteur2=detectionFeature(image2);

    std::vector<DMatch> pointsCommuns =matcher(descripteur1,descripteur2);

    Mat finalImage;
    drawMatches( image1, pointcle1, image2, pointcle2,pointsCommuns, finalImage, Scalar::all(-1), Scalar::all(-1),vector<char>(), DrawMatchesFlags::NOT_DRAW_SINGLE_POINTS );
    imshow ("bon matchs",finalImage);

    key=cvWaitKey(5);
    while (key!='q') {
        key=cvWaitKey(5);
    }

    //destruction des fenetres et des cameras
    destroyAllWindows();
    cam.release();


    return 0;
}
