#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>

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
    void initNews();
    void initFitness();
    void addNewsItemComment(QString name, QString comment, QString time);
    void clearNewsItemComments();
    void addNewsItem(QString title, QString time);
    void updateLikings();

private slots:
    void newsItemSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void commentNewsItem();
    void likeNewsItem();
};

#endif // MAINWINDOW_H
