#include "main_window.h"
#include "ui_main_window.h"


MainWindow::MainWindow (QWidget * parent /* = 0 */)
    : QMainWindow (parent), m_ui (new Ui::MainWindow)
{
    m_ui->setupUi (this);

    setWindowTitle (qApp->applicationName ());

    connect (m_ui->aboutQtAction, SIGNAL(triggered ()), qApp, SLOT(aboutQt ()));
}

MainWindow::~MainWindow ()
{
    delete m_ui;
}
