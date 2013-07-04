#ifndef BUFFER_H
#define BUFFER_H

#include <QObject>
#include <opencv2/opencv.hpp>
#include <QImage>
#include <MatToQImage.h>
#include <opencv2/opencv.hpp>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <opencv2/core/types_c.h>

class buffer : public QObject
{
    Q_OBJECT
private:

    cv::Size framesize;
    int bufferwidth;
    QImage Qframe;
    int width;
    int height;

public:
    explicit buffer(QObject *parent = 0);
    QImage getqimage(void);
    void updatebuffer(cv::Mat upstreamframe);
    cv::Mat frame;
    int getwidth();
    int getheight();
    

signals:
    void updateframe(const cv::Mat& frame);
    void Qupdateframe(const QImage& frame);
    
public slots:
    
};

#endif // BUFFER_H
