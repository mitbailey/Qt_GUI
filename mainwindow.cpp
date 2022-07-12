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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    l_adv_slider = this->findChild<QAdvSlider *>("LImageSizeSlider");
    r_adv_slider = this->findChild<QAdvSlider *>("RImageSizeSlider");

    // Left Image & Label
    left_image_label = findChild<QLabel *>("LImageLabel");
    left_image_label->setAlignment(Qt::AlignCenter);
    if (left_image_label == NULL)
    {
        throw std::runtime_error("Left image label is NULL: unable to find.");
    }
    left_image_label->setFixedSize(371, 371);
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
    right_image_label->setFixedSize(371, 371);
    QPixmap rpixmap("C:/Users/Mit/Desktop/SCREENSHOT2.png");
    right_pixmap = rpixmap;

    right_image_label->setPixmap(rpixmap.scaled(right_image_label->width(), right_image_label->height(), Qt::KeepAspectRatio));

//    connect(lslider, SIGNAL(sliderReleased()), this, SLOT(receive_from_left_slider()));
//    connect(rslider, SIGNAL(sliderReleased()), this, SLOT(receive_from_right_slider()));

    connect(l_adv_slider, SIGNAL(mouseReleased()), this, SLOT(receive_from_left_adv_slider()));
    connect(r_adv_slider, SIGNAL(mouseReleased()), this, SLOT(receive_from_right_adv_slider()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::receive_from_left_adv_slider()
{
    qDebug("Receive from left slider");
    double scaling = 0.0;
    double value = l_adv_slider->value();
    if (value > 50)
    {
        scaling = 1.0 + ((value - 50.0) / 5.0);
    }
    else
    {
        scaling = value / 50.0;
    }
    left_image_label->setPixmap(left_pixmap.scaled(left_image_label->width() * scaling, left_image_label->height() * scaling, Qt::KeepAspectRatio));
}

void MainWindow::receive_from_right_adv_slider()
{
    double scaling = 0.0;
    double value = r_adv_slider->value();
    if (value > 50)
    {
        scaling = 1.0 + ((value - 50.0) / 5.0);
    }
    else
    {
        scaling = value / 50.0;
    }
    right_image_label->setPixmap(right_pixmap.scaled(right_image_label->width() * scaling, right_image_label->height() * scaling, Qt::KeepAspectRatio));
}


