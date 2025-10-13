/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnopen;
    QPushButton *btnplayer;
    QPushButton *btnpause;
    QPushButton *btnstop;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(800, 600);
        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(170, 500, 491, 71));
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        btnopen = new QPushButton(widget);
        btnopen->setObjectName(QString::fromUtf8("btnopen"));

        horizontalLayout->addWidget(btnopen);

        btnplayer = new QPushButton(widget);
        btnplayer->setObjectName(QString::fromUtf8("btnplayer"));

        horizontalLayout->addWidget(btnplayer);

        btnpause = new QPushButton(widget);
        btnpause->setObjectName(QString::fromUtf8("btnpause"));

        horizontalLayout->addWidget(btnpause);

        btnstop = new QPushButton(widget);
        btnstop->setObjectName(QString::fromUtf8("btnstop"));

        horizontalLayout->addWidget(btnstop);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        btnopen->setText(QCoreApplication::translate("Widget", "\346\211\223\345\274\200\350\247\206\351\242\221", nullptr));
        btnplayer->setText(QCoreApplication::translate("Widget", "\346\222\255\346\224\276", nullptr));
        btnpause->setText(QCoreApplication::translate("Widget", "\346\232\202\345\201\234", nullptr));
        btnstop->setText(QCoreApplication::translate("Widget", "\345\201\234\346\255\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
