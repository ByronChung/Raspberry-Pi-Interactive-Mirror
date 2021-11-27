#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUI(this);

    resize(750, 450);
    layout = new QGridLayout();

    display_spotify = new QListWidget();
    layout -> addWidget(display_spotify, 2, 3, 1, 3);

    display_weather = new QListWidget();
    layout -> addWidget(display_weather, 2, 0, 1, 2);

    display_time = new QTextEdit(" ");
    layout -> addWidget(display_time, 0, 1);

    GUI = new QWidget();
    GUI -> setLayout(layout);

    setCentralWidget(GUI);
}

MainWindow::~MainWindow()
{
    delete ui;
}