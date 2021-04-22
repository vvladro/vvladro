#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    //QTextEdit *text = new QTextEdit;    text->setMaximumSize(200,20);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    QWidget *window = new QWidget;
    window->setWindowTitle("Логин");
    QPushButton *nicki = new QPushButton("Ok");
    QPushButton *butt = new QPushButton("Cancel");
    nicki->setCheckable(true);   butt->setCheckable(true);
    //nicki->setChecked(true);

    QTextEdit *text = new QTextEdit("Администратор");    text->setMaximumSize(200,20);
    QTextEdit *text2 = new QTextEdit;    text2->setMaximumSize(200,20);
    QTextEdit *text3 = new QTextEdit("localhost:9999");    text3->setMaximumSize(200,20);

    QFormLayout *formlay = new QFormLayout(window);
    formlay->addRow(tr("Логин"),text);
    formlay->addRow(tr("Пароль"),text2);
    formlay->addRow(tr("адрес Сервера"),text3);
    formlay->addWidget(nicki);  formlay->addWidget(butt);
    setLayout(formlay);

    //QObject::connect(text,SIGNAL())
    nameAdm  =text->toPlainText(); passAdm = text2->toPlainText(); servAdm = text3->toPlainText();

    QObject::connect(nicki,SIGNAL(clicked()),this, SLOT(getInform()));
    QObject::connect(butt,SIGNAL(clicked()),this,SLOT(quitForm()));
    //QObject::connect(butt,SIGNAL(clicked()),this, SLOT(exitSlot(window)));//nw(:


    //window->setAttribute(Qt::WA_QuitOnClose,false);
    window->show();
}

void MainWindow::getInform()
{

    qDebug()<<nameAdm<<" "<<passAdm<<" "<<servAdm;
}

void MainWindow::exitSlot(QWidget *wind)
{
    qDebug()<<"quite!";
    //emit window_;


}

/*
void MainWindow::quitForm()
{
    qDebug()<<"quite!";
    //window()->hide();  close Main Window ^:)
    //this->close();
    emit window::close();
}
*/
