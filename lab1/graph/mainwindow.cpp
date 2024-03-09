#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}


MainWindow::~MainWindow()
{
    user_interaction_t event;
    err_t rc = select_action(QUIT, event);

    if (rc != OK)
    {
        catch_error(rc);
        return;
    }

    delete ui;
}

void MainWindow::on_pushButton_load_clicked()
{
    QString filePath = QFileDialog::getOpenFileName(this, tr("Выберите файл"), "", tr("Текстовые файлы (*.txt);;Все файлы (*)"));

    if (filePath.isEmpty()) {
        return;
    }
    std::string fileName = filePath.toStdString();

    selectedColor = QColorDialog::getColor(Qt::red, this, tr("Выберите цвет"));

    if (!selectedColor.isValid()) {
        return;
    }

    user_interaction_t event = {.file_name = fileName.c_str()};

    err_t rc = select_action(LOAD, event);

    if (rc != OK)
    {
        catch_error(rc);
        return;
    }

    canvas_t canvas;
    canvas.field = new QGraphicsScene(this);
    ui->graphicsView->setScene(canvas.field);
    ui->graphicsView->setAlignment(Qt::AlignTop | Qt::AlignLeft);

    canvas.field->setSceneRect(0, 0, CV_WIDTH, CV_HEIGHT);
    canvas.height = ui->graphicsView->height();
    canvas.width = ui->graphicsView->width();

    canvas.pen = QPen(selectedColor, 3);

    event.canvas = canvas;

    rc = select_action(DRAW, event);

    if (rc != OK)
    {
        catch_error(rc);
    }
}


void MainWindow::on_pushButton_save_clicked()
{
    canvas_t canvas;

    canvas.field = ui->graphicsView->scene();
    canvas.height = ui->graphicsView->height();
    canvas.width = ui->graphicsView->width();
    canvas.pen = QPen(selectedColor, 3);

    user_interaction_t event = {.canvas = canvas};

    err_t rc = select_action(SAVE, event);

    if (rc != OK)
    {
        catch_error(rc);
    }
}

void MainWindow::on_pushButton_spin_clicked()
{
    canvas_t canvas;

    canvas.field = ui->graphicsView->scene();
    canvas.height = ui->graphicsView->height();
    canvas.width = ui->graphicsView->width();
    canvas.pen = QPen(selectedColor, 3);

    action_t spin_angles;

    spin_angles.chg_x = ui->doubleSpinBox_spin_x->value();
    spin_angles.chg_y = ui->doubleSpinBox_spin_y->value();
    spin_angles.chg_z = ui->doubleSpinBox_spin_z->value();

    user_interaction_t event = {.canvas = canvas, .change = spin_angles};

    err_t rc = select_action(SPIN, event);

    if (rc != OK)
    {
        catch_error(rc);
        return;
    }

    rc = select_action(DRAW, event);

    if (rc != OK)
    {
        catch_error(rc);
    }
}


void MainWindow::on_pushButton_move_clicked()
{
    canvas_t canvas;

    canvas.field = ui->graphicsView->scene();
    canvas.height = ui->graphicsView->height();
    canvas.width = ui->graphicsView->width();
    canvas.pen = QPen(selectedColor, 3);

    action_t movement;

    movement.chg_x = ui->doubleSpinBox_move_x->value();
    movement.chg_y = ui->doubleSpinBox_move_y->value();
    movement.chg_z = ui->doubleSpinBox_move_z->value();

    user_interaction_t event = {.canvas = canvas, .change = movement};

    err_t rc = select_action(MOVE, event);

    if (rc != OK)
    {
        catch_error(rc);
        return;
    }

    rc = select_action(DRAW, event);

    if (rc != OK)
    {
        catch_error(rc);
    }
}


void MainWindow::on_pushButton_scale_clicked()
{
    canvas_t canvas;

    canvas.field = ui->graphicsView->scene();
    canvas.height = ui->graphicsView->height();
    canvas.width = ui->graphicsView->width();
    canvas.pen = QPen(selectedColor, 3);

    action_t scale_koefs;

    scale_koefs.chg_x = ui->doubleSpinBox_scale_x->value();
    scale_koefs.chg_y = ui->doubleSpinBox_scale_y->value();
    scale_koefs.chg_z = ui->doubleSpinBox_scale_z->value();

    user_interaction_t event = {.canvas = canvas, .change = scale_koefs};

    err_t rc = select_action(SCALE, event);

    if (rc != OK)
    {
        catch_error(rc);
        return;
    }

    rc = select_action(DRAW, event);

    if (rc != OK)
    {
        catch_error(rc);
    }
}
