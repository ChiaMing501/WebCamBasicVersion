#include "BasicWebCam.h"
#include "ui_BasicWebCam.h"

BasicWebCam::BasicWebCam(QWidget *parent) : QMainWindow(parent), ui(new Ui::BasicWebCam)
{
    ui->setupUi(this);

    mCamera           = new QCamera(this);
    mCameraViewfinder = new QCameraViewfinder(this);
    mLayout           = new QVBoxLayout;

    mCamera->setViewfinder(mCameraViewfinder);
    mLayout->addWidget(mCameraViewfinder);
    mLayout->setMargin(0);

    ui->scrollArea->setLayout(mLayout);

} //end of constructor

BasicWebCam::~BasicWebCam()
{
    delete ui;

    if(mCamera != nullptr)
    {
        delete mCamera;
        mCamera = nullptr;
    }

    if(mCameraViewfinder != nullptr)
    {
        delete mCameraViewfinder;
        mCameraViewfinder = nullptr;
    }

    if(mLayout != nullptr)
    {
        delete mLayout;
        mLayout = nullptr;
    }

} //end of destructor

void BasicWebCam::displayImage(int id, QImage image)
{
    Q_UNUSED(id);

    QImage outputImage;

    int width  = 0;
    int height = 0;
    unsigned char rValue = 0;
    unsigned char gValue = 0;
    unsigned char bValue = 0;

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

} //end of function displayImage

void BasicWebCam::on_btnCamStart_clicked()
{
    mCamera->start();

    //QMessageBox::information(this, "Live View", "Start");

} //end of function on_btnCamStart_clicked

void BasicWebCam::on_btnCamStop_clicked()
{
    mCamera->stop();

} //end of function on_btnCamStop_clicked
