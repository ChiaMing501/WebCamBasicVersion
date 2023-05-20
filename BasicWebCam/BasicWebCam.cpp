#include "BasicWebCam.h"
#include "ui_BasicWebCam.h"

BasicWebCam::BasicWebCam(QWidget *parent) : QMainWindow(parent), ui(new Ui::BasicWebCam)
{
    ui->setupUi(this);

    mCamera           = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mLayout           = new QVBoxLayout;

    imageCapture = new QCameraImageCapture(mCamera);
    timer        = new QTimer(this);

    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);

    ui->scrollArea->setLayout(mLayout);

    //connect(timer, SIGNAL(timeout()), this , SLOT(videoFrameCapture()));
    //connect(imageCapture, SIGNAL(imageCaptured(int, QImage)), this, SLOT(displayImage(int, QImage)));

} //end of constructor

BasicWebCam::~BasicWebCam()
{
    delete ui;

} //end of destructor

void BasicWebCam::videoFrameCapture()
{
    imageCapture->capture();

} //end of function videoFrameCapture

void BasicWebCam::displayImage(int id, QImage image)
{
    Q_UNUSED(id);

    QImage outputImage;

    int width  = 0;
    int height = 0;
    unsigned char rValue = 0;
    unsigned char gValue = 0;
    unsigned char bValue = 0;

    //ui.lblShowImage2->clear();
    //ui.lblShowImage2->setPixmap(QPixmap::fromImage(image));

    width       = image.width();
    height      = image.height();
    outputImage = QImage(width, height, QImage::Format_ARGB32);

    for(int y = 0; y < height; y++)
    {
        for(int x = 0; x < width; x++)
        {
            QRgb rgbObject = image.pixel(x, y);

            rValue = qRed(rgbObject);
            gValue = qGreen(rgbObject);
            bValue = qBlue(rgbObject);


            rValue = 255 - rValue;
            gValue = 255 - gValue;
            bValue = 255 - bValue;

            outputImage.setPixel(x, y, qRgb(rValue, gValue, bValue));
        }
    }

    //ui.lblShowImage->clear();
    //ui.lblShowImage->setPixmap(QPixmap::fromImage(outputImage));

} //end of function displayImage

void BasicWebCam::on_btnCamStart_clicked()
{
    mCamera->start();

    timer->start(33);

} //end of function on_btnCamStart_clicked

void BasicWebCam::on_btnCamStop_clicked()
{
    mCamera->stop();

} //end of function on_btnCamStop_clicked
