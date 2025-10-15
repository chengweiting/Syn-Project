#include "vlckit.h"
#include <QDebug>

VLCkit::VLCkit(QObject *parent) : QObject(parent)
{

}

VLCkit::~VLCkit()
{
    libvlc_media_player_release(_pMediaPlayer);
    libvlc_media_release(_pMedia);
    libvlc_release(_pInstance);
}


//三个回调函数实现
static void processPosition(VLCkit * pkits)
{
    //百分比
    float pos = libvlc_media_player_get_position(pkits->mediaPlayer());
    pkits->setTimeSliderPos(pos * 100);
    libvlc_time_t totalSecs = pkits->durations();
    //qDebug() << "durations(): " << pkits->durations();
    //qDebug() << "total secs: " << totalSecs;
    libvlc_time_t curSecs = libvlc_media_player_get_time(pkits->mediaPlayer()) / 1000;
    //qDebug() << "cur secs: " << curSecs;
    int hh = curSecs / 3600;
    int mm = curSecs % 3600 / 60;
    int ss = curSecs % 60;
    int HH = totalSecs / 3600;
    int MM = totalSecs % 3600 / 60;
    int SS = totalSecs % 60;
    char buff[64] = {0};
    sprintf(buff, "%02d:%02d:%02d/%02d:%02d:%02d",
            hh, mm, ss, HH, MM, SS);
    QString str(buff);
    pkits->setTimeText(str);    //将QString填入QLable组件

}

static void processVolume(VLCkit * pkits)
{
    int val = libvlc_audio_get_volume(pkits->mediaPlayer());
    qDebug() << "volume:" << val;
    if(val == -1) {
        return;
    }
    pkits->setVolumePos(val);
}

static void processMediaChanged(VLCkit* pkits)
{
    qDebug() << ">>>>> processMediaChanged()";
    pkits->addMediaIndex();
}

static void vlc_callback( const struct libvlc_event_t *p_event, void *p_data
                          )
{
    VLCkit * pkits = static_cast<VLCkit*>(p_data);
    if(pkits) {
        switch(p_event->type) {
        case libvlc_MediaPlayerPositionChanged://播放位置变化时
            processPosition(pkits); break;
        case libvlc_MediaPlayerAudioVolume://音量变化时
            processVolume(pkits); break;
        case libvlc_MediaPlayerMediaChanged:
             processMediaChanged(pkits); break;
        }
    }
}

//vlc 初始化时要完成回调函数的注册，三个相关对象初始化
bool VLCkit::initVLC()
{
    _pInstance = libvlc_new(0, nullptr);
    if(_pInstance) {
        _pMediaPlayer = libvlc_media_player_new(_pInstance);
        if(_pMediaPlayer) {
            _pEventManager =
                    libvlc_media_player_event_manager(_pMediaPlayer);
            if(_pEventManager) {
                //注册媒体播放器的事件处理器
                //1. 位置发生改变时
                libvlc_event_attach(_pEventManager,
                                    libvlc_MediaPlayerPositionChanged,
                                    vlc_callback, this);
                //2. 声音变化时
                libvlc_event_attach(_pEventManager,
                                    libvlc_MediaPlayerAudioVolume,
                                    vlc_callback, this);
                return true;
            }
            else {
                libvlc_media_player_release(_pMediaPlayer);
                libvlc_release(_pInstance);
                return false;
            }
        }
        else {
            libvlc_release(_pInstance);
            return false;
        }
    }
    else
    {
        return false;
    }

    //if(p)
}

//封装一下解析文件到播放视频的功能
bool VLCkit::play(const QString &name, void *hwnd)
{
    //1. 设置媒体
    _pMedia = libvlc_media_new_path(_pInstance, name.toStdString().c_str());
    if(!_pMedia) {
        return false;
    }
    //得到了媒体文件后
    //2. 解析文件
    libvlc_media_parse(_pMedia);
    _totalSec = libvlc_media_get_duration(_pMedia) / 1000;
    qDebug() << "总时长 = " << _totalSec << endl;
    //3. 设置媒体播放器
    libvlc_media_player_set_media(_pMediaPlayer, _pMedia);
    //4. 设置播放窗口句柄
    libvlc_media_player_set_hwnd(_pMediaPlayer, hwnd);
    //5. 播放视频
    int ret = libvlc_media_player_play(_pMediaPlayer);
    if(ret < 0) {
        return false;
    } else
        return true;
}

//封装的三个按钮的功能模块，通过_pMediaPlayer获取的状态判断

//暂停继续播放功能
void VLCkit::play()
{
    libvlc_state_t state = libvlc_media_player_get_state(_pMediaPlayer);
    if(state == libvlc_Paused ||
            state == libvlc_Stopped) {
        libvlc_media_player_play(_pMediaPlayer);
    }
}

//封装暂停正在播放的视频功能
void VLCkit::pause()
{
    libvlc_state_t state = libvlc_media_player_get_state(_pMediaPlayer);
    if(state == libvlc_Playing) {
        libvlc_media_player_pause(_pMediaPlayer);
    }
}

//封装关闭（暂停和正在播放）功能
void VLCkit::stop()
{
    libvlc_state_t state = libvlc_media_player_get_state(_pMediaPlayer);
    if(state == libvlc_Playing ||
            state == libvlc_Paused) {
        libvlc_media_player_stop(_pMediaPlayer);
        //重置进度条的位置
        emit sigTimeSliderPos(0);   //触发一下信号，重置信号条
    }
}

//------------------ 三个触发信号的函数 -------------------
void VLCkit::setTimeSliderPos(int value)
{ //发送信号
    emit sigTimeSliderPos(value);
}

void VLCkit::setTimeText(const QString &str)
{ //发送信号
    emit sigTimeText(str);
}

void VLCkit::setVolumePos(int value)
{
    emit sigVolumeSliderPos(value);
}


//------------封装调整音频音量，播放进度函数----------
void VLCkit::setVolume(int value)
{
    libvlc_audio_set_volume(_pMediaPlayer, value);
}
void VLCkit::setPosition(int value)
{
    libvlc_media_player_set_position(_pMediaPlayer, value / 100.0);
}


//-----------播放列表添加视频----------
void VLCkit::addMediaIndex()
{

}
