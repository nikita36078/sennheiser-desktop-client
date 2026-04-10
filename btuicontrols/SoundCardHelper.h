#ifndef SENNHEISERDESKTOPCLIENT_SOUNDCARDHELPER_H
#define SENNHEISERDESKTOPCLIENT_SOUNDCARDHELPER_H


#include <QObject>
#include <QtQmlIntegration>
#include "gaiaV3/GAIAPropertyBase.h"

class SoundCardHelper: public QObject{
    Q_OBJECT
    QML_ELEMENT
    Q_PROPERTY(int audioMode READ getAudioMode WRITE setAudioMode NOTIFY audioModeChanged)
    Q_PROPERTY(int eqPreset READ getEqPreset WRITE setEqPreset NOTIFY eqPresetChanged)

public:

    explicit SoundCardHelper(QObject *parent = nullptr);

private:
    GAIAPropertyBase *audio_mode;
    GAIAPropertyBase *eq_preset;

    int m_audioMode;
    int m_eqPreset;

public slots:
    int getAudioMode() const;
    int getEqPreset() const;
    void setAudioMode(const int &value);
    void setEqPreset(const int &value);

signals:
    void audioModeChanged();
    void eqPresetChanged();

private slots:
    void setAudioModeValue();
    void setEqPresetValue();

};


#endif //SENNHEISERDESKTOPCLIENT_SOUNDCARDHELPER_H
