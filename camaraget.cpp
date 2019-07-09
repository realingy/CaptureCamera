#include "camaraget.h"
#include <iostream>

camaraGet::camaraGet(QWidget *parent) :
    QWidget(parent)
{
    setupUi(this);
    cam     = NULL;
    timer   = new QTimer(this);
    imag    = new QImage();
    connect(timer, SIGNAL(timeout()), this, SLOT(readFarme()));
    connect(pushButton, SIGNAL(clicked()), this, SLOT(openCamara()));
    connect(pushButton_2, SIGNAL(clicked()), this, SLOT(closeCamara()));
}


void camaraGet::openCamara()
{
    cam = cvCreateCameraCapture(0);
    timer->start(1000/30);
}

IplImage * camaraGet::downsample( IplImage* img )
{
    IplImage* smaller = cvCreateImage( cvSize(img->width / 2, img->height / 2),
        img->depth, img->nChannels );
    cvResize( img, smaller, CV_INTER_NN );

    return smaller;
}

void camaraGet::readFarme()
{

     CvCapture* pCap = cvCaptureFromCAM(0);
     cvSetCaptureProperty(pCap,CV_CAP_PROP_FRAME_WIDTH,320);
     cvSetCaptureProperty(pCap,CV_CAP_PROP_FRAME_HEIGHT,240);

     IplImage *frame = NULL;
     frame = cvQueryFrame(pCap);
     QImage image = QImage((const uchar*)frame->imageData, frame->width, frame->height, QImage::Format_RGB888).rgbSwapped();
     this->label->setMinimumSize(320,240);
     this->label->setPixmap(QPixmap::fromImage(image));


      CvCapture* pCap2 = cvCaptureFromCAM(1);
      IplImage *frame2 = NULL;
      frame2 = cvQueryFrame(pCap2);
      QImage image2 = QImage((const uchar*)frame2->imageData, frame2->width, frame2->height, QImage::Format_RGB888).rgbSwapped();
      this->label_2->setMinimumSize(320,240);
      this->label_2->setPixmap(QPixmap::fromImage(image2));


}


void camaraGet::closeCamara()
{
    timer->stop();
    cvReleaseCapture(&cam);
}

camaraGet::~camaraGet()
{
    delete this;
}
