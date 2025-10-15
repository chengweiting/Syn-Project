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
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QVBoxLayout *verticalLayout;
    QWidget *widget_2;
    QSlider *_timeSlider;
    QWidget *widget;
    QHBoxLayout *horizontalLayout;
    QLabel *_labTime;
    QSpacerItem *horizontalSpacer_2;
    QPushButton *btnopen;
    QPushButton *btnplayer;
    QPushButton *btnpause;
    QPushButton *btnstop;
    QSpacerItem *horizontalSpacer;
    QSlider *_volumeSlider;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QString::fromUtf8("Widget"));
        Widget->resize(1104, 626);
        verticalLayout = new QVBoxLayout(Widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        widget_2 = new QWidget(Widget);
        widget_2->setObjectName(QString::fromUtf8("widget_2"));

        verticalLayout->addWidget(widget_2);

        _timeSlider = new QSlider(Widget);
        _timeSlider->setObjectName(QString::fromUtf8("_timeSlider"));
        _timeSlider->setOrientation(Qt::Horizontal);

        verticalLayout->addWidget(_timeSlider);

        widget = new QWidget(Widget);
        widget->setObjectName(QString::fromUtf8("widget"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(widget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        _labTime = new QLabel(widget);
        _labTime->setObjectName(QString::fromUtf8("_labTime"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(_labTime->sizePolicy().hasHeightForWidth());
        _labTime->setSizePolicy(sizePolicy1);

        horizontalLayout->addWidget(_labTime);

        horizontalSpacer_2 = new QSpacerItem(200, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);

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
        btnstop->setEnabled(true);

        horizontalLayout->addWidget(btnstop);

        horizontalSpacer = new QSpacerItem(300, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        _volumeSlider = new QSlider(widget);
        _volumeSlider->setObjectName(QString::fromUtf8("_volumeSlider"));
        QSizePolicy sizePolicy2(QSizePolicy::Maximum, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(_volumeSlider->sizePolicy().hasHeightForWidth());
        _volumeSlider->setSizePolicy(sizePolicy2);
        _volumeSlider->setMinimumSize(QSize(200, 0));
        _volumeSlider->setMaximumSize(QSize(500, 22));
        _volumeSlider->setMaximum(20);
        _volumeSlider->setSingleStep(10);
        _volumeSlider->setPageStep(10);
        _volumeSlider->setOrientation(Qt::Horizontal);
        _volumeSlider->setTickPosition(QSlider::NoTicks);

        horizontalLayout->addWidget(_volumeSlider);


        verticalLayout->addWidget(widget);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        _labTime->setText(QCoreApplication::translate("Widget", "00:00:00 / 00:00:00 ", nullptr));
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
