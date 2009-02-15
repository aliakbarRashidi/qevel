#include <QtGui/QApplication>
#include "main_window.h"


int main (int argc, char * argv [])
{
    QApplication app (argc, argv);
    app.setApplicationName    ("Qevel");
    app.setApplicationVersion ("0.0.0");
    app.setOrganizationName   ("Qevel");
    app.setOrganizationDomain ("qevel.org");

    MainWindow window;
    window.show ();

    return app.exec ();
}
