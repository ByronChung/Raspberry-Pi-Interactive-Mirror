#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QPushButton>
#include <QListWidget>
#include <QFrame>
#include <QGridLayout>
#include <QTextEdit>

namespace Ui { class MainWindow; }

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    QListWidget *display_spotify;
    QListWidget *display_twitter;
    QListWidget *display_weather;
    QTextEdit *display_time;
    QGridLayout *layout;
    QWidget *GUI;
};
#endif // MAINWINDOW_H

/* Author: Byron and Pablo */
