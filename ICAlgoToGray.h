#ifndef ICALGOTOGRAY_H
#define ICALGOTOGRAY_H

#include "ICAlgo.h"

class ICAlgoToGray : public ICAlgo
{
public:
    ICAlgoToGray(QObject* parent = nullptr);

    virtual QImage convert(QImage original);
};

#endif // ICALGOTOGRAY_H
