#include <QImage>
#include <QPainter>
#include <QImageReader>
#include <QDir>
#include <QDebug>
#include <QFileInfo>
#include "ICController.h"
#include "ICImageDisplay.h"
#include "ICAlgo.h"
#include "ICAlgoToGray.h"
ICController::ICController(QObject *parent) :
    QObject(parent),
    m_statusText("ready")
{

}

bool ICController::init()
{

    return true;
}

bool ICController::start()
{

    setOriginalImage(noImage());
    setConvertedImage(noImage());
    setSelectedAlgo(new ICAlgoToGray(this));
    return true;
}

void ICController::stop()
{
    return;
}

void ICController::update()
{
    mp_originalDisplay->setImage(getOriginalImage());
    mp_convertedDisplay->setImage(getConvertedImage());
}

void ICController::onOpenOriginalImage(QUrl fileUrl)
{
    QFileInfo fileInfo(fileUrl.toLocalFile());
    setOpenFolder(fileInfo.absolutePath());
    QImageReader reader(fileInfo.absoluteFilePath());
    reader.setAutoTransform(true);
    const QImage newImage = reader.read();
    if (newImage.isNull()) {
        setStatusText(tr("Cannot load %1: %2")
                      .arg(QDir::toNativeSeparators(fileInfo.absoluteFilePath()), reader.errorString()));

        return;
    }
    else
    {
        setOriginalImage(newImage);
    }
}

void ICController::onSaveConvertedImage(QUrl fileUrl)
{}

void ICController::onConvert()
{
    ICAlgo* algo = getSelectedAlgo();
    if (algo == nullptr)
    {
        qWarning()<<"no algo";
        setConvertedImage(failureImage());
    }

    setConvertedImage(algo->convert(m_originalImage));

}

void ICController::setOriginalImage(QImage image)
{
    m_originalImage = image;
    mp_originalDisplay->setImage(image);
}

void ICController::setConvertedImage(QImage image)
{
    m_convertedImage = image;
    mp_convertedDisplay->setImage(image);
}

QImage ICController::noImage()
{
    QImage image(300, 300, QImage::Format_Grayscale8);
    image.fill(Qt::black);
    QPainter p;
    if (p.begin(&image)){

        p.setPen(QPen(Qt::gray));
        p.setFont(QFont("Times", 12, QFont::Bold));
        p.drawText(image.rect(), Qt::AlignCenter, "no image");
        p.end();
    }
    return image;

}

QImage ICController::failureImage()
{
    QImage image(300, 300, QImage::Format_Grayscale8);
    image.fill(Qt::black);
    QPainter p;
    if (p.begin(&image)){

        p.setPen(QPen(Qt::gray));
        p.setFont(QFont("Times", 12, QFont::Bold));
        p.drawText(image.rect(), Qt::AlignCenter, "error");
        p.end();
    }
    return image;

}

