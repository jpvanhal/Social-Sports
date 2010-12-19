#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QModelIndex>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    bool theUserLikes;
    void addNewsItemComment(QString name, QString comment, QString time);
    void clearNewsItemComments();
    void addNewsItem(QString title, QString time);
    void updateLikings();

private slots:
    void newsItemActivated(QModelIndex index);
    void commentNewsItem();
    void likeNewsItem();
};

#endif // MAINWINDOW_H
