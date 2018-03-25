#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QDebug>
#include "ICMain.h"
int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;
    //engine.load(QUrl(QLatin1String("qrc:/main.qml")));


    ICMain *icMain = ICMain::getInstance();
    icMain->setEngine(&engine);

    if (icMain->init() == false)
    {
        qCritical()<<"icMain init failed.";
        exit(-1);
    }

    if (icMain->start() == false)
    {
        qCritical()<<"icMain start failed.";
        exit(-2);
    }

    return app.exec();
}
