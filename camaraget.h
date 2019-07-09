#ifndef CAMARAGET_H
#define CAMARAGET_H

#include <QWidget>
#include <QImage>
#include <QTimer>

#include "opencv2/highgui/highgui_c.h"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc_c.h"
#include "opencv2/imgproc/imgproc.hpp"
#include "opencv2/video/tracking.hpp"
#include "opencv2/features2d/features2d.hpp"
#include "opencv2/flann/flann.hpp"
#include "opencv2/calib3d/calib3d.hpp"
#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/legacy/compat.hpp"
#include "opencv2/core/core_c.h"
#include "opencv2/core/core.hpp"

#include <ui_widget.h>

namespace Ui
{
    class camaraGet;
}

class camaraGet : public QWidget,public Ui_Widget
{
    Q_OBJECT

public:
    explicit camaraGet(QWidget *parent = 0);
    ~camaraGet();
      IplImage *downsample( IplImage* img );

private slots:
    void openCamara();
    void readFarme();
    void closeCamara();
private:
    QTimer    *timer;
    QImage    *imag;
    CvCapture *cam;
    IplImage  *frame;
};

#endif // CAMARAGET_H
