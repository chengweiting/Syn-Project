#ifndef WIDGET_H
#define WIDGET_H

#include "vlckit.h"
#include <vlc/vlc.h>
#include <QWidget>
#include <QSlider>
#include <QLabel>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    libvlc_media_player_t * media_player() const { return _pmediaPlayer; }
    qint64 durationTime() const;            // 总时长 (ms)
    void   setTimeText(const QString &t);   // 显示 00:00:00/00:00:00
    void   setTimeSliderValue(int percent); // 0~100
    void   setVolumeSliderValue(int val);   // 0~100

    //void initUI();    //手动添加部件需要，显示定义父类

    //全屏播放
    void mouseDoubleClickEvent(QMouseEvent *event);
    void keyPressEvent(QKeyEvent *event);


private slots:
    //-------------------四个基本功能按键---------------
    void on_btnopen_clicked();
    void on_btnpause_clicked();
    void on_btnplayer_clicked();
    void on_btnstop_clicked();

#if 0
    //------------时间文本,播放位置，音量设置-------------
    void setPreQlable(const QString &str);
    void setPreTimeSlieder(int tm);
    void setPreVolumeSlider(int vlm);
#endif



private:
    Ui::Widget *ui;
    //由于子函数中用到以下对象，因此需要创建为数据成员
    libvlc_instance_t *     _pinstance = nullptr;
    libvlc_media_player_t * _pmediaPlayer = nullptr;
    libvlc_media_t *        _pmedia = nullptr;
    libvlc_event_manager_t* _peventManager = nullptr;
    libvlc_time_t           _durationSec = 0;
    VLCkit *                _vlckit = nullptr;

};
#endif // WIDGET_H
