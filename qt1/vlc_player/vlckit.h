#ifndef VLCKIT_H
#define VLCKIT_H

#include <vlc/vlc.h>
#include <QObject>

class VLCkit : public QObject
{
    Q_OBJECT
public:
    explicit VLCkit(QObject *parent = nullptr);
    ~VLCkit();

    bool initVLC();
    bool play(const QString & name, void * hwnd);
    void play();
    void pause();
    void stop();
    void setVolume(int value);
    void setPosition(int value);
    libvlc_media_player_t * mediaPlayer() const { return _pMediaPlayer; }
    libvlc_time_t durations() const { return _totalSec; }
    //当需要修改UI界面的显示时，通过信号来触发，以下三个函数调用时就触发信号
    void setTimeSliderPos(int value);
    void setTimeText(const QString & str);
    void setVolumePos(int value);

signals:
    void sigTimeSliderPos(int value);
    void sigTimeText(const QString & str);
    void sigVolumeSliderPos(int value);

private:
    libvlc_instance_t * _pInstance = nullptr;
    libvlc_media_t * _pMedia = nullptr;
    libvlc_media_player_t * _pMediaPlayer = nullptr;
    libvlc_event_manager_t * _pEventManager = nullptr;
    libvlc_time_t _totalSec = 0;//一个文件的总时间

};

#endif // VLCKIT_H
