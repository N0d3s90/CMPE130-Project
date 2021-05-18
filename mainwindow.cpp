#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include "md5.h"
#include "sha256.h"
#include <QElapsedTimer>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Submit_clicked()
{
    QString string = ui->lineEdit_string->text();
    std::string text = string.toUtf8().constData();

    QElapsedTimer temp1;
    temp1.start();
    QString string1 = QString::fromStdString(md5(text));
    QString k1 = QString::number(temp1.nsecsElapsed());

    QElapsedTimer temp2;
    temp2.start();
    QString string2 = QString::fromStdString(sha256(text));
    QString k2 = QString::number(temp2.nsecsElapsed());

    QString string3 = "MD5: " + string1 + "\nTime: " + k1 + " nanoseconds\n\n"
             + "SHA256: " + string2 + "\nTime: " + k2 + " nanoseconds\n\n";

    QMessageBox::information(this, string, string3);
}

