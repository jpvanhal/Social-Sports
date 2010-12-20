#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QItemSelection>
#include <QTreeWidgetItem>

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
    void initGroups();
    void initInvitations();
    void addNewsItemComment(QString name, QString comment, QString time);
    void clearNewsItemComments();
    void addNewsItem(QString title, QString time);
    void updateLikings();
    QTreeWidgetItem *addGroup(QTreeWidget *tree, QString groupName);
    void addUserToGroup(QTreeWidgetItem *group, QString username);

private slots:
    void groupSelectionChanged();
    void newsItemSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
    void commentNewsItem();
    void likeNewsItem();
    void leaveGroup();
    void acceptInvitation();
    void declineInvitation();
    void invitationItemSelectionChanged(const QItemSelection &selected, const QItemSelection &deselected);
};

#endif // MAINWINDOW_H
