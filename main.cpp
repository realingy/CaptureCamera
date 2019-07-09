#include <QApplication>
#include "widget.h"
#include "camaraget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    camaraGet w;
    w.show();

    /*CvCapture * cam = cvCaptureFromCAM(0);

    while(cam)
    {
        IplImage *frame =  cvQueryFrame(cam);
        IplImage * f = w.downsample(frame);
        cvNamedWindow("hello",1);
        cvShowImage("hello",f);
        cvWaitKey(30);
    }
*/
    return a.exec();
}
