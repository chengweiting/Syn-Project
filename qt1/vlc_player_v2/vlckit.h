#ifndef VLCKIT_H
#define VLCKIT_H

#include <vlc/vlc.h>
#include <QObject>
#include <QMouseEvent>
#include <vector>

using std::vector;

class VLCkit : public QObject
{
    Q_OBJECT
public:
    explicit VLCkit(QObject *parent = nullptr);
    ~VLCkit();

    bool initVLC();
    bool play(const QStringList &names, void *hwnd);
    bool play(const QString & name, void * hwnd);
    void play();
    void pause();
    void stop();
    void setVolume(int value);
    void setPosition(int value);
    void addMediaIndex();
    const vector<libvlc_time_t> & durationArr() const{
        return  _durationArr;
    }

    int currentIndex() const {  return _currentIndex;   }
    libvlc_media_player_t * mediaPlayer() const { return _pMediaPlayer; }
    libvlc_time_t durations() const { return _totalSec; }
    //当需要修改UI界面的显示时，通过信号来触发，以下三个函数调用时就触发信号
    void setTimeSliderPos(int value);
    void setTimeText(const QString & str);
    void setVolumePos(int value);

    //获取三对象
    libvlc_instance_t *getInstance(){return _pInstance;}
    libvlc_media_t * getMedia() {return _pMedia;}
    libvlc_media_player_t * getMediaPlayer(){return _pMediaPlayer;}


signals:
    void sigTimeSliderPos(int value);
    void sigTimeText(const QString & str);
    void sigVolumeSliderPos(int value);
private slots:



private:
    libvlc_instance_t * _pInstance = nullptr;
    libvlc_media_t * _pMedia = nullptr;
    libvlc_media_player_t * _pMediaPlayer = nullptr;
    libvlc_event_manager_t * _pEventManager = nullptr;
    libvlc_time_t _totalSec = 0;//一个文件的总时间


    //播放列表数据成员
    libvlc_media_list_player_t *    _pMediaListPlayer = nullptr;
    libvlc_media_list_t *           _pMediaList = nullptr;
    int                             _currentIndex = -1;     //当前播放视频的下标
    vector<libvlc_time_t>           _durationArr;

};

#endif // VLCKIT_H
