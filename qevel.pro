#######################################################################
## This file is part of Qevel, a cross-platform file manager.
## Copyright (C) 2009 qevel.org
##
## Qevel is free software: you can redistribute it and/or modify
## it under the terms of the GNU General Public License as published by
## the Free Software Foundation, either version 3 of the License, or
## (at your option) any later version.
##
## Qevel is distributed in the hope that it will be useful,
## but WITHOUT ANY WARRANTY; without even the implied warranty of
## MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
## GNU General Public License for more details.
##
## You should have received a copy of the GNU General Public License
## along with Qevel. If not, see <http://www.gnu.org/licenses/>.
#######################################################################

LANGUAGES = en fr


TARGET   = qevel
TEMPLATE = app

DEPENDPATH  += sources
INCLUDEPATH += sources
HEADERS += about_dialog.h            \
           magic_number_registry.h   \
           main_window.h             \
           mime_type.h               \
           mime_type_registry.h
SOURCES += about_dialog.cpp          \
           magic_number_registry.cpp \
           main.cpp                  \
           main_window.cpp           \
           mime_type.cpp             \
           mime_type_registry.cpp

FORMS += dialogs/about_dialog.ui \
         dialogs/main_window.ui

LIBS += -lmagic

RESOURCES += resources/qevel.qrc

for(language, LANGUAGES): TRANSLATIONS += translations/qevel_$${language}.ts


# Copy COPYING file in resources directory.
copying_resource.target   = "$${PWD}/resources/COPYING"
copying_resource.commands = $$QMAKE_COPY "$${PWD}/COPYING" "$${PWD}/resources/COPYING"
copying_resource.depends  = "$${PWD}/COPYING"
QMAKE_EXTRA_TARGETS += copying_resource
PRE_TARGETDEPS      += "$${PWD}/resources/COPYING"
QMAKE_CLEAN         += "$${PWD}/resources/COPYING"

# Create runtime translation files.
for(language, LANGUAGES) {
    ts_file = "$${PWD}/translations/qevel_$${language}.ts"
    qm_file = "$${PWD}/resources/translations/qevel_$${language}.qm"
    qm_target_name = update_$${language}_qm

    eval($${qm_target_name}.target   = "$$qm_file")
    eval($${qm_target_name}.commands = lrelease "$$ts_file" -qm "$$qm_file")
    eval($${qm_target_name}.depends  = "$$ts_file")

    QMAKE_EXTRA_TARGETS += $${qm_target_name}
    PRE_TARGETDEPS      += $$qm_file
    QMAKE_CLEAN         += $$qm_file
}
