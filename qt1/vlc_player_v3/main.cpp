#include "widget.h"

#include <QApplication>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    qDebug() <<"w运行结束" << endl;
     return a.exec();
}


//错误3 第三方库头文件引入了，但是无法链接
//清除一下之前生成的debug，重新生成
