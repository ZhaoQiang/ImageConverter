#ifndef ICALGO_H
#define ICALGO_H

#include <QObject>
#include <QImage>

class ICAlgo : public QObject
{
    Q_OBJECT
public:
    explicit ICAlgo(QObject *parent = 0);

    virtual QImage convert(QImage image) = 0;

signals:

public slots:
};

#endif // ICALGO_H
