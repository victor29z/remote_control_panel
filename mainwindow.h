#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>
#include <QString>
#include <QFileDialog>
#include <QTimer>
#include "networks.h"

#define PACK_SET_POSE 0xf1
#define PACK_SET_MODE 0xf2
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
    void on_pb_openhandle_clicked();
    void timer_out(void);
private:
    Ui::MainWindow *ui;
    QProcess *handle_utility;
    networks *pnet;
    QTimer *timer;
    int post_data[8];
};

#endif // MAINWINDOW_H
