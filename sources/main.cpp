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

#include <QtCore/QLocale>
#include <QtCore/QLibraryInfo>
#include <QtCore/QTranslator>
#include <QtGui/QApplication>
#include "main_window.h"


int main (int argc, char * argv [])
{
    QApplication app (argc, argv);
    app.setApplicationName    ("Qevel");
    app.setApplicationVersion ("0.0.0");
    app.setOrganizationName   ("Qevel");
    app.setOrganizationDomain ("qevel.org");

    // Load translators.
    QTranslator qtTranslator;
    QTranslator appTranslator;
    if (qtTranslator.load ("qt_" + QLocale::system ().name (), QLibraryInfo::location (QLibraryInfo::TranslationsPath)) ||
        qtTranslator.load ("qt_" + QLocale::system ().name (), ":/translations"))
        app.installTranslator (& qtTranslator);
    if (appTranslator.load ("qevel_" + QLocale::system ().name (), ":/translations"))
        app.installTranslator (& appTranslator);

    MainWindow window;
    window.show ();

    return app.exec ();
}
