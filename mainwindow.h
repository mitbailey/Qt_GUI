/**
 * @file mainwindow.h
 * @author Mit Bailey (mitbailey@outlook.com)
 * @brief 
 * @version See Git tags for version information.
 * @date 2022.07.12
 * 
 * @copyright Copyright (c) 2022
 * 
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 * 
 */

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <QMainWindow>
#include <QSlider>
#include <QLabel>
#include "qadvslider.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:
    void transmit_to_object(double value);

private slots:
    void receive_from_left_adv_slider();
    void receive_from_right_adv_slider();

private:
    Ui::MainWindow *ui;

    QLabel *left_image_label;
    QLabel *right_image_label;

    QPixmap left_pixmap;
    QPixmap right_pixmap;

//    QSlider *lslider;
//    QSlider *rslider;
    QAdvSlider *l_adv_slider;
    QAdvSlider *r_adv_slider;
};

#endif // MAINWINDOW_H
