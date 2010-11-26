/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created: Fri Nov 26 17:32:08 2010
**      by: Qt User Interface Compiler version 4.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtGui/QApplication>
#include <QtGui/QButtonGroup>
#include <QtGui/QHBoxLayout>
#include <QtGui/QHeaderView>
#include <QtGui/QLabel>
#include <QtGui/QLineEdit>
#include <QtGui/QMainWindow>
#include <QtGui/QPushButton>
#include <QtGui/QSpacerItem>
#include <QtGui/QTextEdit>
#include <QtGui/QVBoxLayout>
#include <QtGui/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionSend_Command;
    QAction *actionSimulateInvitation;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *lineEditCommand;
    QPushButton *buttonSend;
    QHBoxLayout *horizontalLayout_2;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnSimulateInvitation;
    QSpacerItem *horizontalSpacer_2;
    QLabel *label_2;
    QTextEdit *textEditResponse;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(516, 298);
        actionSend_Command = new QAction(MainWindow);
        actionSend_Command->setObjectName(QString::fromUtf8("actionSend_Command"));
        actionSimulateInvitation = new QAction(MainWindow);
        actionSimulateInvitation->setObjectName(QString::fromUtf8("actionSimulateInvitation"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout->addWidget(label);

        lineEditCommand = new QLineEdit(centralWidget);
        lineEditCommand->setObjectName(QString::fromUtf8("lineEditCommand"));

        horizontalLayout->addWidget(lineEditCommand);

        buttonSend = new QPushButton(centralWidget);
        buttonSend->setObjectName(QString::fromUtf8("buttonSend"));
        buttonSend->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout->addWidget(buttonSend);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        btnSimulateInvitation = new QPushButton(centralWidget);
        btnSimulateInvitation->setObjectName(QString::fromUtf8("btnSimulateInvitation"));
        btnSimulateInvitation->setEnabled(false);
        btnSimulateInvitation->setCursor(QCursor(Qt::PointingHandCursor));

        horizontalLayout_2->addWidget(btnSimulateInvitation);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout_2);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        verticalLayout->addWidget(label_2);

        textEditResponse = new QTextEdit(centralWidget);
        textEditResponse->setObjectName(QString::fromUtf8("textEditResponse"));
        textEditResponse->setReadOnly(true);

        verticalLayout->addWidget(textEditResponse);

        MainWindow->setCentralWidget(centralWidget);
#ifndef QT_NO_SHORTCUT
        label->setBuddy(lineEditCommand);
        label_2->setBuddy(textEditResponse);
#endif // QT_NO_SHORTCUT

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Social Sports CLI", 0, QApplication::UnicodeUTF8));
        actionSend_Command->setText(QApplication::translate("MainWindow", "Send Command", 0, QApplication::UnicodeUTF8));
        actionSimulateInvitation->setText(QApplication::translate("MainWindow", "simulateInvitation", 0, QApplication::UnicodeUTF8));
#ifndef QT_NO_TOOLTIP
        actionSimulateInvitation->setToolTip(QApplication::translate("MainWindow", "Simulate a group invitation", 0, QApplication::UnicodeUTF8));
#endif // QT_NO_TOOLTIP
        label->setText(QApplication::translate("MainWindow", "Message:", 0, QApplication::UnicodeUTF8));
        buttonSend->setText(QApplication::translate("MainWindow", "Send SMS", 0, QApplication::UnicodeUTF8));
        btnSimulateInvitation->setText(QApplication::translate("MainWindow", "Simulate group invitation", 0, QApplication::UnicodeUTF8));
        label_2->setText(QApplication::translate("MainWindow", "Service response:", 0, QApplication::UnicodeUTF8));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
