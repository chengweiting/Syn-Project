#include "widget.h"
#include "ui_widget.h"
#include "vlckit.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    qDebug() << "widget()" << endl;
    ui->setupUi(this);
    _vlckit = new VLCkit(); //手动分配堆空间

    //-----------通知mediaplayer通ui控件--------------
    connect(_vlckit,&VLCkit::sigTimeSliderPos, [=](int v){
        this->setTimeSliderValue(v);
    });
    connect(_vlckit, &VLCkit::sigTimeText, [=](QString str1){
        this->setTimeText(str1);
    });
    connect(_vlckit, &VLCkit::sigVolumeSliderPos, [=](int v){
        this->setVolumeSliderValue(v);
    });

    //--------------ui控件通知mediaplayer-------------
    connect(ui->_timeSlider, &QSlider::sliderMoved, [=](int value){
        float percent = value / 100.0;
        libvlc_media_player_set_position(_vlckit->getMediaPlayer(), percent);
    });

    connect(ui->_volumeSlider, &QSlider::sliderMoved, [=](int value){
        float percent = value ;
        if(_vlckit->getMediaPlayer()){
            libvlc_audio_set_volume(_vlckit->getMediaPlayer(), percent);
        }
        //libvlc_audio_set_volume(_vlckit->getMediaPlayer(), percent);
    });




}

Widget::~Widget()
{
    delete ui;
    delete _vlckit;
    //主窗口关闭后，需要释放libvlc相关对象
    //Todo


    //打印日志
    qDebug () << "~Widget" << endl;

}


qint64 Widget::durationTime() const
{
    //返回视频的总时长
    if (!_pmediaPlayer) return 0;
    return libvlc_media_player_get_length(_pmediaPlayer);   // 单位 ms
}

void Widget::setTimeText(const QString &t)
{
    //将QString用于设置时间
    ui->_labTime->setText(t);
}

void Widget::setTimeSliderValue(int percent)
{
    //让进度条滑块跟着视频播放自动走（0-100%）
    ui->_timeSlider->setValue(percent);

}

void Widget::setVolumeSliderValue(int val)
{
    //让音量滑块跟着当前音量自动走（0-100%）
    ui->_volumeSlider->setValue(val);
}

#if 0
static void vlc_callback( const struct libvlc_event_t *p_event, void *p_data )
{
    qDebug() << "vlc_callback...";
    Widget * p = static_cast<Widget*>(p_data);
    if(p) {
        //根据操作的枚举值分逻辑
        switch (p_event->type) {
        case libvlc_MediaPlayerPositionChanged:
        {
            //获取到的是一个百分比,再乘100送入滑动条中
            float pos = libvlc_media_player_get_position(p->media_player());
            p->setTimeSliderValue(pos * 100);
            //设置视频的时间
            qint64 totalSec = p->durationTime() /  1000;    //返回获取时间,ms单位
            qDebug() << "视频总时长: " << totalSec;
            int HH = totalSec / 3600;
            int MM = (totalSec - HH * 3600) / 60;
            int SS = totalSec - HH *3600 - MM * 60;

            //获取当前播放时间位置
            qint64 curSec = libvlc_media_player_get_time(p->media_player()) / 1000;
            int curHour = curSec / 3600;
            int curMinute = (curSec - curHour * 3600) / 60;
            int curSecs = curSec - curHour * 3600 - curMinute * 60;
            char buff[64] = {0};
            sprintf(buff, "%02d:%02d:%02d/%02d:%02d:%02d",
                    curHour, curMinute, curSecs,
                    HH, MM, SS);

            QString str(buff);
            p->setTimeText(str);
            break;
        }
        case libvlc_MediaPlayerAudioVolume:
        {
            //获取音量百分比，再传给音量滑动条
            int val = libvlc_audio_get_volume(p->media_player());
            //qDebug() <<  "line 109 , val = " << val << endl;
            p->setVolumeSliderValue(val);
            break;
        }
        }
    }
}
#endif

//open按钮的业务是，点击后打开文件对话框，选择和限定对应数据类型后打开文件
void Widget::on_btnopen_clicked()
{
    //openbtn test
    qDebug() << "点击open按钮" << endl;
    //错误1:   不同文件类型放一个字符串
    QString filename
            = QFileDialog::getOpenFileName(this,
                                           "请选择对应视频文件",
                                           "D:/AA-local_repository/media_sample/videos",
                                           "视频文件(*.mp4);;"
                                           "视频文件(*.avi);;");

    //文件打开失败
    if(filename.isEmpty()){
        return;
    }

    filename = QDir::toNativeSeparators(filename);      //将路径中的斜杠换成符合当前操作系统的版本

    bool f1 = _vlckit->initVLC();
    _vlckit->play(filename, (void*)ui->widget_2->winId());
    if(f1){
        qDebug() << "三个相关对象初始化成功" << endl;
    }else{
        qDebug() << "三个相关对象初始化失败" << endl;
    }




}



void Widget::on_btnpause_clicked()
{
    qDebug() << "pause clicked" << endl;
    _vlckit->pause();

}

void Widget::on_btnplayer_clicked()
{
    qDebug() << "play clicked" << endl;
    _vlckit->play();

}

void Widget::on_btnstop_clicked()
{
    qDebug() << "stop clicked" << endl;
    _vlckit->stop();
}

#if 0
void Widget::setPreQlable(const QString &str)
{

}

void Widget::setPreTimeSlieder(int tm)
{

}

void Widget::setPreVolumeSlider(int vlm)
{
    //获取音量百分比，再传给音量滑动条
    //int val = libvlc_audio_get_volume(p->media_player());
    this->setVolumeSliderValue(vlm);

}
#endif


