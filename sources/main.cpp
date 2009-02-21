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
