#include "SoundCardHelper.h"
#include "gaiaV3/GAIARfcommClient.h"

using namespace Qt::Literals::StringLiterals;

SoundCardHelper::SoundCardHelper(QObject *parent) :
        QObject(parent),
        audio_mode(GAIARfcommClient::getInstance().getManager()->getProperty("\x04\x95\x09\x04"_ba)),
        eq_preset(GAIARfcommClient::getInstance().getManager()->getProperty("\x04\x95\x11\x02"_ba)),
        m_audioMode(0),
        m_eqPreset(0)
{
    if (audio_mode != nullptr){
        connect(audio_mode, &GAIAPropertyBase::valueChanged, this, &SoundCardHelper::setAudioModeValue);
        audio_mode->sendGet();
    }
    if (eq_preset != nullptr){
        connect(eq_preset, &GAIAPropertyBase::valueChanged, this, &SoundCardHelper::setEqPresetValue);
        eq_preset->sendGet();
    }
}

void SoundCardHelper::setAudioModeValue() {
    const auto &amv = audio_mode->getValue();
    if (amv.length() < 1){
        return;
    }
    m_audioMode = amv.at(0).toInt();
    Q_EMIT audioModeChanged();
}

void SoundCardHelper::setEqPresetValue() {
    const auto &epv = eq_preset->getValue();
    if (epv.length() < 1){
        return;
    }
    m_eqPreset = epv.at(0).toInt();
    Q_EMIT eqPresetChanged();
}

int SoundCardHelper::getAudioMode() const {
    return m_audioMode;
}

int SoundCardHelper::getEqPreset() const {
    return m_eqPreset;
}

void SoundCardHelper::setAudioMode(const int &value) {
    qDebug() << "SoundCardHelper::setAudioMode" << value;
    audio_mode->sendSet({
        {static_cast<uint16_t>(value)},
    });
}

void SoundCardHelper::setEqPreset(const int &value) {
    qDebug() << "SoundCardHelper::setEqPreset" << value;
    eq_preset->sendSet({
        {static_cast<uint8_t>(value)},
    });
}
