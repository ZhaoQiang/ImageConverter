#include "ICAlgoToGray.h"

ICAlgoToGray::ICAlgoToGray(QObject* parent) :
    ICAlgo(parent)
{

}

QImage ICAlgoToGray::convert(QImage original)
{
    return original.convertToFormat(QImage::Format_Grayscale8);
}
