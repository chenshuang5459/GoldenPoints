#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <string.h>
#include "rounds.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_submit_clicked();

    void on_pushButton_nextplayer_clicked();

    void on_pushButton_nextround_clicked();

private:
    Ui::MainWindow *ui;
    Rounds round;
};

#endif // MAINWINDOW_H
