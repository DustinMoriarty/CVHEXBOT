#include "buffer.h"


using namespace cv;

buffer::buffer(QObject *parent) :
    QObject(parent)
{
    width = 300;
    height = 200;
    framesize = cvSize(width,height);



    frame = cv::Mat(framesize,CV_8UC1);

    Qframe = MatToQImage(frame);
}

QImage buffer::getqimage(void)
{

    return Qframe;

}

void buffer::updatebuffer(cv::Mat upstreamframe)
{
    resize(upstreamframe, frame, frame.size(), 0, 0, INTER_NEAREST);

    Qframe = MatToQImage(frame);

    emit updateframe(frame);
    emit Qupdateframe(Qframe);
}

int buffer::getwidth()
{
    return width;
}

int buffer::getheight()
{
    return height;
}
