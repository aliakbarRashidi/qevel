/**********************************************************************
** This file is part of Qevel, a cross-platform file manager.
** Copyright (C) 2009 qevel.org
**
** Qevel is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** Qevel is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Qevel. If not, see <http://www.gnu.org/licenses/>.
**********************************************************************/

#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>


class AboutDialog;

namespace Ui
{
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow (QWidget * parent = 0);
    ~MainWindow ();

private slots:
    void showAboutDialog ();
    void destroyAboutDialog ();

private:
    Ui::MainWindow * m_ui;
    AboutDialog * m_aboutDialog;

};

#endif // MAIN_WINDOW_H
