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

#include    "about_dialog.h"
#include "ui_about_dialog.h"

#include <QtCore/QFile>
#include <QtGui/QDialogButtonBox>
#include <QtGui/QMessageBox>
#include <QtGui/QTextBrowser>
#include <QtGui/QVBoxLayout>

#include <QtDebug>


AboutDialog::AboutDialog (QWidget * parent /* = 0 */)
    : QDialog (parent), m_ui (new Ui::AboutDialog)
{
    m_ui->setupUi (this);

    m_ui->descriptionLabel->setText (description ());
    adjustSize ();

    connect (m_ui->licenseButton, SIGNAL(clicked ()), SLOT(showLicense ()));
    connect (m_ui->closeButton,   SIGNAL(clicked ()), SLOT(accept      ()));
}

AboutDialog::~AboutDialog ()
{
    delete m_ui;
}

void AboutDialog::showLicense ()
{
    QString title = tr ("GNU General Public License");
    QString text;
    {
    QFile file (":/COPYING");
    if (file.open (QFile::ReadOnly | QFile::Text))
        text = file.readAll ();
    if (text.isEmpty ())
    {
        text = tr ("A copy of the GNU General Public License can be found at <a href=\"%1\">%1</a>.")
               .arg ("http://www.gnu.org/licenses/");
        QMessageBox::information (this, title, text);
        return;
    }
    }

    QDialog dialog (this);
    dialog.setWindowTitle (title);
    QVBoxLayout layout (& dialog);

    QTextBrowser browser;
    browser.setPlainText (text);
    browser.setMinimumSize (420, 300);
    layout.addWidget (& browser);

    QDialogButtonBox buttonBox (QDialogButtonBox::Close);
    connect (& buttonBox, SIGNAL(rejected ()), & dialog, SLOT(reject ()));
    layout.addWidget (& buttonBox);

    dialog.exec ();
}

const QString AboutDialog::description () const
{
    return tr ("<h2>%1 %2</h2>"
               "<p>%1 is a free cross-platform file manager.</p>"
               "<br/>Copyright 2009 <a href=\"%3\">%4</a>"
               "<p align=\"justify\">"
                 "%1 is free software: you can redistribute it and/or modify "
                 "it under the terms of the GNU General Public License as published by "
                 "the Free Software Foundation, either version 3 of the License, or "
                 "(at your option) any later version."
               "</p>"
               "<p align=\"justify\">"
                 "%1 is distributed in the hope that it will be useful but without any warranty; "
                 "without even the implied warranty of merchantability or fitness for a particular purpose. "
                 "See the GNU General Public License for more details."
               "</p>").arg (qApp->applicationName ())
                      .arg (qApp->applicationVersion ())
                      .arg ("http://qevel.org/")
                      .arg (qApp->organizationDomain ());
}
