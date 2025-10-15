#ifndef CTITLEBAR_H
#define CTITLEBAR_H

#include <QWidget>

class CTitleBar : public QWidget
{
    Q_OBJECT
public:
    explicit CTitleBar(QWidget *parent = nullptr);
    ~CTitleBar(){};
#if 0
signals:
    void sig_close();          // 给主窗口接收关闭信号

private slots:
    void onClicked();          // 内部槽：处理最小化、最大化、关闭

private:
    void initUI();
    void mousePressEvent(QMouseEvent *) override;      // 按住拖动
    void mouseDoubleClickEvent(QMouseEvent *) override;// 双击最大化

    QLabel *m_pLogo;
    QLabel *m_pTitleText;
    QPushButton *m_pMinBtn;
    QPushButton *m_pMaxBtn;
    QPushButton *m_pCloseBtn;

#endif

};

#endif // CTITLEBAR_H
