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
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with Qevel.  If not, see <http://www.gnu.org/licenses/>.
**********************************************************************/

#include    "main_window.h"
#include "ui_main_window.h"

#include "about_dialog.h"


MainWindow::MainWindow (QWidget * parent /* = 0 */)
    : QMainWindow (parent), m_ui (new Ui::MainWindow),
      m_aboutDialog (0)
{
    m_ui->setupUi (this);

    setWindowTitle (qApp->applicationName ());

    connect (m_ui->aboutAction, SIGNAL(triggered ()), SLOT(showAboutDialog ()));
    connect (m_ui->aboutQtAction, SIGNAL(triggered ()), qApp, SLOT(aboutQt ()));
}

MainWindow::~MainWindow ()
{
    delete m_ui;
}

void MainWindow::showAboutDialog ()
{
    if (! m_aboutDialog)
    {
        m_aboutDialog = new AboutDialog (this);
        connect (m_aboutDialog, SIGNAL(finished (int)), SLOT(destroyAboutDialog ()));
    }
    m_aboutDialog->show ();
}

void MainWindow::destroyAboutDialog ()
{
    if (m_aboutDialog)
    {
        m_aboutDialog->deleteLater ();
        m_aboutDialog = 0;
    }
}
