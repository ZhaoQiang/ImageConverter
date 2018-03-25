#include "ICMain.h"
#include <QCoreApplication>
#include <QDebug>
#include "ICImageProvider.h"
#include "QQmlContext.h"
#include "ICController.h"
#include "ICImageDisplay.h"
const QString ICMain::APP_NAME = "ImageConverter";
const QString ICMain::ORG_NAME = "ReadAny";
const QString ICMain::DOMAIN_NAME = "readany.cn";

ICMain::ICMain(QObject *parent) : QObject(parent)
{
}

bool ICMain::init()
{
    mp_imageProvider = new ICImageProvider();
    mp_icController = new ICController(this);

    if (mp_icController->init() == false)
    {
        qCritical()<<"icController init failed.";
        return false;
    }

    qmlRegisterType<ICImageDisplay>("IC", 1, 0, "ICImageDisplay");

    mp_engine->addImageProvider(QLatin1String("icimg"),
                                mp_imageProvider);

    QQmlContext* context = mp_engine->rootContext();
    context->setContextProperty("icController", mp_icController);

    mp_engine->load(QUrl(QLatin1String("qrc:/main.qml")));

    return true;
}

bool ICMain::start()
{

    if (mp_icController->start() == false)
    {
        qCritical()<<"icController start failed.";
        return false;
    }

    return true;
}

void ICMain::stop()
{
    exit(0);
}

ICMain* ICMain::getInstance()
{
    static ICMain icMain;
    return &icMain;
}

QVariant getConfig(const QString &key, const QVariant &defaultValue)
{
    QSettings config(ICMain::ORG_NAME, ICMain::APP_NAME);
    return config.value(key, defaultValue);
}
void setConfig(const QString &key, const QVariant &value)
{
    QSettings config(ICMain::ORG_NAME, ICMain::APP_NAME);
    config.setValue(key, value);
}


