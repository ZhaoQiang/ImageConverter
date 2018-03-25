#ifndef ICMAIN_H
#define ICMAIN_H

#include <QObject>
#include <QQmlApplicationEngine>
#include <QSettings>

class ICImageProvider;
class ICController;
class ICMain : public QObject
{
    Q_OBJECT
public:
    explicit ICMain(QObject *parent = 0);
    static const QString APP_NAME;
    static const QString ORG_NAME;
    static const QString DOMAIN_NAME;

    bool init();
    bool start();
    void stop();

    static ICMain* getInstance();
    static QVariant getConfig(const QString &key, const QVariant &defaultValue = QVariant());
    static void setConfig(const QString &key, const QVariant &value);

signals:

public slots:

private:
    QQmlApplicationEngine* mp_engine;
    ICImageProvider* mp_imageProvider;
    ICController* mp_icController;

public:
    void setEngine(QQmlApplicationEngine* engine)
    {
        mp_engine = engine;
    }

    static ICController* getICController(){
        return ICMain::getInstance()->mp_icController;
    }

};

#endif // ICMAIN_H
