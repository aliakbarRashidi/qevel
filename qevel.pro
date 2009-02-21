TARGET   = qevel
TEMPLATE = app

HEADERS += sources/main_window.h
SOURCES += sources/main_window.cpp \
           sources/main.cpp
FORMS   += dialogs/main_window.ui

RESOURCES += resources/qevel.qrc

TRANSLATIONS += translations/qevel_en.ts  \
                translations/qevel_fr.ts
