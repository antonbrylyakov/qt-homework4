#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pbProgressManage_clicked();

private:
    Ui::MainWindow *ui;
    static const int ProgressMax = 10;
    static const int ProgressMin = 0;
    static const int ProgressStep = 1;
};
#endif // MAINWINDOW_H
