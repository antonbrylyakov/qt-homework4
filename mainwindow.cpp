#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // задать имена обеим RadioButton, которые отображаются на форме;
    ui->rb1->setText("Опция 1");
    ui->rb2->setText("Опция 2");

    // добавить несколько элементов в выпадающий список, но не больше 10;
    ui->comboBox->addItem("(нет)");
    for (auto i = 0; i < 5; ++i)
    {
        ui->comboBox->addItem(QString("Опция %1").arg(i));
    }

    // изменить тип кнопки на Toggle;
    ui->pbProgressManage->setCheckable(true);

    // изменить надпись на кнопке;
    ui->pbProgressManage->setText("Увеличить прогресс");
    ui->pbProgressManage->setFixedWidth(150);

    // установить начальные значения прогресс-бара: минимум 0, максимум 10, текущее 0.
    ui->pbrProgress->setMinimum(ProgressMin);
    ui->pbrProgress->setMaximum(ProgressMax);
    ui->pbrProgress->setValue(ProgressStep);

    // Поэкспериментировал с запретом изменения размера окна
    setFixedSize(415, 210);
    this->statusBar()->setSizeGripEnabled(false);
    setWindowFlags(Qt::Dialog | Qt::MSWindowsFixedSizeDialogHint);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbProgressManage_clicked()
{
    auto progress = ui->pbrProgress->value();
    progress+=ProgressStep;
    if (progress > ProgressMax)
    {
        progress = ProgressMin;
    }

    ui->pbrProgress->setValue(progress);
}

