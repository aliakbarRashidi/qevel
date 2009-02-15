#ifndef MAIN_WINDOW_H
#define MAIN_WINDOW_H

#include <QtGui/QMainWindow>


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

private:
    Ui::MainWindow * m_ui;

};

#endif // MAIN_WINDOW_H
