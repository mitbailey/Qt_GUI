/**
 * @file qadvslider.h
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

#ifndef QADVSLIDER_H
#define QADVSLIDER_H

#include <QDebug>
#include <QMainWindow>
#include <QSlider>
#include <QLabel>

QT_BEGIN_NAMESPACE
namespace Ui { class QAdvSlider; }
QT_END_NAMESPACE

class QAdvSlider : public QSlider
{
    Q_OBJECT

    // Enables to usage of all QSlider constructors.
    using QSlider::QSlider;

public:
    // Overrides QSlider's mouseReleaseEvent to provide additional functionality - in this case, it emits a signal after the slider has been clicked (as opposed to being clicked-and-dragged, a feature absent from the original.
    void mouseReleaseEvent(QMouseEvent *ev) override;

signals:
    void mouseReleased();
    void valueUpdated(int val);
};

#endif // QADVSLIDER_H
