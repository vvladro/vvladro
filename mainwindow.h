#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include <QFormLayout>
#include <QPushButton>
#include <QLineEdit>
#include <QTextEdit>
#include <QString>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    QString nameAdm, passAdm, servAdm;

private slots:
    void on_pushButton_clicked();
    void getInform();
    void exitSlot(QWidget *window);
    //void quitForm();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
