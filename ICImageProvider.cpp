#include <QDebug>
#include "ICImageProvider.h"
#include "ICController.h"
#include "ICMain.h"
ICImageProvider::ICImageProvider() :
    QQuickImageProvider(ImageType::Image)
{

}

QImage ICImageProvider::requestImage(
        const QString &id, QSize *size, const QSize& requestedSize)
{
    QImage ret;
    ICController* icController = ICMain::getICController();
    qDebug()<<"request image: "<<id;
    if (id == "original")
    {
        ret = icController->getOriginalImage();
        qDebug()<<"request original image: "<<ret.byteCount();
    }
    else if (id == "converted")
    {
        ret = icController->getConvertedImage();
        qDebug()<<"request converted image: "<<ret.byteCount();

    }
    else
    {
        ret = icController->noImage();
    }


    return ret;
}
