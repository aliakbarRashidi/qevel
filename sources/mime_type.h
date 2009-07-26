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

#ifndef MIME_TYPE_H
#define MIME_TYPE_H

#include <QtCore/QString>


class MimeType
{

public:
    const QString & name () const { return m_name; }
    QString name () { return m_name; }

    MimeType (const MimeType & other);
    MimeType & operator = (const MimeType & other);

    bool isDiscreteType () const;
    bool isCompositeType () const;

    bool isAudio () const;
    bool isImage () const;
    bool isText  () const;
    bool isVideo () const;
    bool isXml   () const;

private:
    MimeType (const QString & name);

    QString m_name;

    friend class MimeTypeRegistry;
    friend class MagicNumberRegistry;

};

#endif // MIME_TYPE_H
