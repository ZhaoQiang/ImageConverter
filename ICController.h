#ifndef ICCONTROLLER_H
#define ICCONTROLLER_H

#include <QObject>
#include <QImage>
#include <QUrl>

class ICImageDisplay;
class ICAlgo;
class ICController : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString statusText READ statusText WRITE setStatusText NOTIFY statusTextChanged)
public:
    explicit ICController(QObject *parent = 0);

    bool init();
    bool start();
    void stop();
    void update();

    QImage noImage();
    QImage failureImage();

    Q_INVOKABLE void onOpenOriginalImage(QUrl fileUrl);
    Q_INVOKABLE void onSaveConvertedImage(QUrl fileUrl);
    Q_INVOKABLE void onConvert();


signals:
    void originalImageChanged();
    void convertedImageChanged();
    void statusTextChanged();

public slots:

private:
    QImage m_originalImage;
    QImage m_convertedImage;
    QString m_statusText;
    ICAlgo* mp_selectedAlgo;

    ICImageDisplay* mp_originalDisplay;
    ICImageDisplay* mp_convertedDisplay;

    QString m_openFolder;
    QString m_saveFolder;

public:
    QString statusText()
    {
        return m_statusText;
    }

    void setStatusText(QString text)
    {
        m_statusText = text;
        emit statusTextChanged();
    }

    QImage getOriginalImage(){
        return m_originalImage;
    }

    void setOriginalImage(QImage img);

    QImage getConvertedImage(){
        return m_convertedImage;
    }

    void setConvertedImage(QImage img);


    ICAlgo* getSelectedAlgo(){return mp_selectedAlgo;}
    void setSelectedAlgo(ICAlgo* algo){mp_selectedAlgo = algo;}

    Q_INVOKABLE QString getOpenFolder(){return m_openFolder;}
    Q_INVOKABLE QString getSaveFolder(){return m_saveFolder;}
    void setOpenFolder(QString folder){m_openFolder = folder;}
    void setSaveFolder(QString folder){m_saveFolder = folder;}

    Q_INVOKABLE void setOriginalDisplay(ICImageDisplay* display){mp_originalDisplay = display;}
    Q_INVOKABLE void setConvertedDisplay(ICImageDisplay* display){mp_convertedDisplay = display;}


};

#endif // ICCONTROLLER_H
