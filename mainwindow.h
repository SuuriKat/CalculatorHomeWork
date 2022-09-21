#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_button_answer_clicked();

    void on_button_sin_toggled(bool checked);

    void on_button_arcsin_toggled(bool checked);

    void on_button_cos_toggled(bool checked);

    void on_button_arccos_toggled(bool checked);

    void on_button_tg_toggled(bool checked);

    void on_button_ctg_toggled(bool checked);

    void on_button_plus_clicked();

    void on_button_multi_clicked();

    void on_button_mins_clicked();

    void on_button_divide_clicked();

    void on_button_upper_clicked();

    void on_button_dupper_clicked();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
