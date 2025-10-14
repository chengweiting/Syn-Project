#include "widget.h"
#include "ui_widget.h"
//#include ""
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    qDebug() << "widget()" << endl;
     ui->setupUi(this);

}

Widget::~Widget()
{
    delete ui;

    //主窗口关闭后，需要释放libvlc相关对象
    //Todo


    //打印日志
    qDebug () << "~Widget" << endl;

}


//open按钮的业务是，点击后打开文件对话框，选择和限定对应数据类型后打开文件
void Widget::on_btnopen_clicked()
{
    //openbtn test
    qDebug() << "点击open按钮" << endl;
    //错误1:   不同文件类型放一个字符串
    QString filename = QFileDialog::getOpenFileName(this,
                                                    "请选择对应视频文件",
                                                    "D:/AA-local_repository/media_sample/videos",
                                                    "视频文件(*.mp4);;"
                                                    "视频文件(*.avi);;");

    //文件打开失败
    if(filename.isEmpty()){
        return;
    }

    filename = QDir::toNativeSeparators(filename);      //将路径中的斜杠换成符合当前操作系统的版本
    const char * vlc_args[] = {
        //"--no-plugins-cache", // 禁用插件缓存（若问题仍存在则关闭）
        "--ignore-config", // 忽略全局配置文件
        "--quiet", // 静默模式（减少日志）
        "--no-video-title-show", // 禁用标题显示
        //"--avcodec-hw=any" // 启用硬件加速（可选）
        };

    //打开文件，处理完路径，开始进行使用vlc播放视频
    //1.初始化vlc实例
    _pinstance = libvlc_new(sizeof(vlc_args)/sizeof(vlc_args[0]), vlc_args);    //填入配置参数
    if(!_pinstance){
        //输出警报窗口
        QMessageBox::information(this, "警告", "libvlc_new error!!!");
        exit(EXIT_FAILURE);
    }
#if 0
#endif
    //2.设置媒体路径
    _pmedia = libvlc_media_new_path(_pinstance, filename.toStdString().c_str());

    //3.初始化mediaplayer
    _pmediaPlayer = libvlc_media_player_new_from_media(_pmedia);
    if(!_pmediaPlayer){
        libvlc_release(_pinstance);
        QMessageBox::information(this, "警告",
        "libvlc_media_player_new_from_media error!");
        exit(EXIT_FAILURE);
    }

    //4.设置播放器句柄
    //错误2 第二个参数是ui中Widget控件的名字
    libvlc_media_player_set_hwnd(_pmediaPlayer,
                                 (void*)ui->widget->winId());//把 VLC 的视频输出窗口绑定到给定的 Win32 窗口句柄
    QMessageBox::information(this, "已加载好文件", "请点击播放按钮");


}

#if 0
#endif
void Widget::on_btnpause_clicked()
{
    qDebug() << "pause clicked" << endl;
    libvlc_state_t vlc_state = libvlc_media_player_get_state(_pmediaPlayer);
    if(libvlc_Playing == vlc_state)
    {
        libvlc_media_player_pause(_pmediaPlayer);
    }

}

void Widget::on_btnplayer_clicked()
{
    qDebug() << "play clicked" << endl;
    libvlc_state_t vlc_state = libvlc_media_player_get_state(_pmediaPlayer);
    if(libvlc_Paused == vlc_state ||
            libvlc_Stopped == vlc_state ||
            libvlc_NothingSpecial == vlc_state)
    {
        //非异常状态
        libvlc_media_player_play(_pmediaPlayer);    //调用媒体播放器播放
    }
}

void Widget::on_btnstop_clicked()
{
    qDebug() << "stop clicked" << endl;
    libvlc_state_t vlc_state = libvlc_media_player_get_state(_pmediaPlayer);
    if(libvlc_Paused == vlc_state || libvlc_Playing == vlc_state){
        libvlc_media_player_stop(_pmediaPlayer);
    }
}


