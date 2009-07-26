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

#ifndef MIME_TYPE_REGISTRY_H
#define MIME_TYPE_REGISTRY_H

#include "mime_type.h"

#include <QtCore/QObject>


class QFile;

class MimeTypeRegistry : public QObject
{
    Q_OBJECT

public:
    static MimeTypeRegistry * defaultRegistry ();
    static void setDefaultRegistry (MimeTypeRegistry * registry);

    virtual ~MimeTypeRegistry ();

    virtual MimeType mimeType (const QFile & file) const;

private:
    static MimeTypeRegistry * s_defaultRegistry;

};

#endif // MIME_TYPE_REGISTRY_H
