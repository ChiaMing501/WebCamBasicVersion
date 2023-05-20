#ifndef BASICWEBCAM_H
#define BASICWEBCAM_H

#include <QMainWindow>

#include <QCamera>
#include <QCameraViewfinder>
#include <QVBoxLayout>
#include <QMessageBox>
#include <QCameraImageCapture>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class BasicWebCam; }
QT_END_NAMESPACE

class BasicWebCam : public QMainWindow
{
    Q_OBJECT

    public:
        BasicWebCam(QWidget *parent = nullptr);
        ~BasicWebCam();

    private slots:
        void on_btnCamStart_clicked();
        void on_btnCamStop_clicked();

        void displayImage(int id, QImage image);

private:
        Ui::BasicWebCam *ui;

        QCamera           *mCamera;
        QCameraViewfinder *mCameraViewfinder;
        QVBoxLayout       *mLayout;

}; //end of class BasicWebCam

#endif // BASICWEBCAM_H
