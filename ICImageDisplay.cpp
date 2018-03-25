#include "ICImageDisplay.h"

ICImageDisplay::ICImageDisplay()
{

}

void ICImageDisplay::setImage(QImage image)
{
    m_image = image;
    update();
}

void ICImageDisplay::paint(QPainter *painter)
{

    QRect targetRect = calAspectFit();
    painter->drawImage(targetRect, m_image);

}

QRect ICImageDisplay::calAspectFit()
{
    float srcWHRatio = ((float)m_image.width() / m_image.height());
    float targetWHRatio = ((float)width()) / height();
    float ratio = 0;
    if (srcWHRatio > targetWHRatio)
    {
        ratio = ((float)width() / m_image.width());
    }
    else
    {
        ratio = ((float)height() / m_image.height());
    }
    int targetWidth = m_image.width() * ratio;
    int targetHeight = m_image.height() * ratio;
    int targetX = (width() - targetWidth) / 2;
    int targetY = (height() - targetHeight) / 2;

    QRect targetRect = QRect(targetX, targetY, targetWidth, targetHeight);
    return targetRect;
}
