/**
 * @file mainwindow.cpp
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

#include <exception>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "datagraph.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l_lcdnumber = this->findChild<QLCDNumber *>("lcdNumberL");
    r_lcdnumber = this->findChild<QLCDNumber *>("lcdNumberR");

    l_adv_slider = this->findChild<QAdvSlider *>("LImageSizeSlider");
    r_adv_slider = this->findChild<QAdvSlider *>("RImageSizeSlider");

    // Left Image & Label
    left_image_label = findChild<QLabel *>("LImageLabel");
    left_image_label->setAlignment(Qt::AlignCenter);
    if (left_image_label == NULL)
    {
        throw std::runtime_error("Left image label is NULL: unable to find.");
    }
//    left_image_label->setFixedSize(371, 371);
    QPixmap lpixmap("C:/Users/Mit/Desktop/SCREENSHOT.png");
    left_pixmap = lpixmap;

    left_image_label->setPixmap(lpixmap.scaled(left_image_label->width(), left_image_label->height(), Qt::KeepAspectRatio));

    // Right Image & Label
    right_image_label = findChild<QLabel *>("RImageLabel");
    right_image_label->setAlignment(Qt::AlignCenter);
    if (right_image_label == NULL)
    {
        throw std::runtime_error("Right image label is NULL: unable to find.");
    }
//    right_image_label->setFixedSize(371, 371);
    QPixmap rpixmap("C:/Users/Mit/Desktop/SCREENSHOT2.png");
    right_pixmap = rpixmap;

    right_image_label->setPixmap(rpixmap.scaled(right_image_label->width(), right_image_label->height(), Qt::KeepAspectRatio));

    connect(this, SIGNAL(leftValueUpdated(double)), l_lcdnumber, SLOT(display(double)));
    connect(this, SIGNAL(rightValueUpdated(double)), r_lcdnumber, SLOT(display(double)));

    connect(l_adv_slider, SIGNAL(mouseReleased()), this, SLOT(receive_from_left_adv_slider()));
    connect(r_adv_slider, SIGNAL(mouseReleased()), this, SLOT(receive_from_right_adv_slider()));

    // Create datagraph example.
    DataGraph *graph_1 = new DataGraph(/*this->findChild<QGraphicsView *>("DataGraphParent")*/);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::update_scaling(int value, bool right)
{
    if (right)
    {
        if (value > 50)
        {
            r_scaling = 1.0 + ((value - 50.0) / 5.0);
        }
        else
        {
            r_scaling = value / 50.0;
        }

        emit rightValueUpdated(r_scaling);
    }
    else
    {
        if (value > 50)
        {
            l_scaling = 1.0 + ((value - 50.0) / 5.0);
        }
        else
        {
            l_scaling = value / 50.0;
        }

        emit leftValueUpdated(l_scaling);
    }
}

void MainWindow::receive_from_left_adv_slider()
{
    update_scaling(l_adv_slider->value(), false);

    left_image_label->setPixmap(left_pixmap.scaled(left_image_label->width() * l_scaling, left_image_label->height() * l_scaling, Qt::KeepAspectRatio));
}

void MainWindow::receive_from_right_adv_slider()
{
    update_scaling(r_adv_slider->value(), true);

    right_image_label->setPixmap(right_pixmap.scaled(right_image_label->width() * r_scaling, right_image_label->height() * r_scaling, Qt::KeepAspectRatio));
}


