#include <QtGui/QApplication>
#include "mainwindow.h"
#include "signindialog.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    MainWindow w;
    /*SignInDialog dlgSignIn(&w);
    dlgSignIn.connect(&dlgSignIn, SIGNAL(rejected()), &a, SLOT(quit()));
    dlgSignIn.show();
*/
    w.show();
    return a.exec();
}
