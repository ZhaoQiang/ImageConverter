#ifndef ICIMAGEPROVIDER_H
#define ICIMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>

class ICImageProvider : public QQuickImageProvider
{
public:
    ICImageProvider();

    QImage requestImage(const QString &id, QSize *size, const QSize& requestedSize);


};

#endif // ICIMAGEPROVIDER_H
