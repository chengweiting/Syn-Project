#ifndef WIDGET_H
#define WIDGET_H
#include <vlc/vlc.h>
#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private slots:
    void on_open_clicked();

private:
    Ui::Widget *ui;
    //由于子函数中用到以下对象，因此需要创建为数据成员
    libvlc_instance_t *     _pinstance = nullptr;
    libvlc_media_player_t * _pmediaPlayer = nullptr;
    libvlc_media_t *        _pmedia = nullptr;
};
#endif // WIDGET_H
