#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QStringList>
#include <QMessageBox>

char hostaddr[20] = "192.168.3.4";

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    handle_utility = new QProcess(this);
    pnet = new networks();
    timer = new QTimer(this);
    timer->start(50);

    connect(timer,SIGNAL(timeout()),this,SLOT(timer_out()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pb_openhandle_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this,
                                                        tr("Open File"),
                                                        "/",
                                                        tr("All Files (*.*)"));

    handle_utility->start(fileName);
    //handle_utility->start("cmd.exe");
    //system(fileName.toLatin1());
}

void MainWindow::timer_out(){

    post_data[0] = PACK_SET_MODE;
    if(ui->pb_mode_pos->isDown())
        post_data[1] = 1;
    else if(ui->pb_mode_angle->isDown())
        post_data[1] = 2;
    else if(ui->pb_mode_all->isDown())
        post_data[1] = 3;
    else
        post_data[1] = 0;

    if(ui->pbBackFast->isDown())
        post_data[2] = 1;
    else if(ui->pbBackStep->isDown())
        post_data[2] = 2;
    else if(ui->pbFWDStep->isDown())
        post_data[2] = 3;
    else if(ui->pbFWDFast->isDown())
        post_data[2] = 4;
    else post_data[2] = 0;


    //post_data[2] = 0;
    pnet->mode_poster->writeDatagram((char*)post_data , sizeof(int) * 8, QHostAddress(hostaddr),18888);
    qDebug()<<"mode:"<< post_data[1]<<"sld:"<<post_data[2];
}
