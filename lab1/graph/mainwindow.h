#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QFileDialog>
#include <QColorDialog>
#include "select_action.h"

#define CV_WIDTH 700
#define CV_HEIGHT 550

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
    void on_pushButton_load_clicked();
    void on_pushButton_save_clicked();
    void on_pushButton_spin_clicked();
    void on_pushButton_move_clicked();
    void on_pushButton_scale_clicked();

private:
    Ui::MainWindow *ui;
    QColor selectedColor;
};
#endif // MAINWINDOW_H
