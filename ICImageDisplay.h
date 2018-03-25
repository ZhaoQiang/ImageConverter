#ifndef ICIMAGEDISPLAY_H
#define ICIMAGEDISPLAY_H
#include <QQuickPaintedItem>
#include <QPainter>
#include <QRect>
class ICImageDisplay : public QQuickPaintedItem
{
    Q_OBJECT
public:
    ICImageDisplay();

    void paint(QPainter *painter);
    QRect calAspectFit();

private:
    QImage m_image;

public:
    void setImage(QImage image);
    QImage getImage(){return m_image;}



};

#endif // ICIMAGEDISPLAY_H
