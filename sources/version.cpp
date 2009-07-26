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

#include "version.h"

#include <QtCore/QString>


Version::Version ()
    : m_major (0), m_minor (0), m_patch (0)
{
    init ();
}

Version::Version (const char * string)
{
    init (QString::fromLatin1 (string));
}

Version::Version (const QString & string)
{
    init (string);
}

Version::Version (unsigned short major, unsigned short minor, unsigned short patch)
    : m_major (major), m_minor (minor), m_patch (patch)
{
    init ();
}

Version::~Version ()
{
    delete m_string;
}

Version::Version (const Version & other)
    : m_major (other.m_major), m_minor (other.m_minor), m_patch (other.m_patch)
{
    init ();
}

Version::Version & Version::operator = (const Version & other)
{
    m_major = other.m_major;
    m_minor = other.m_minor;
    m_patch = other.m_patch;
    init ();

    return *this;
}

void Version::init (const QString & string)
{
    m_major = string.section (QChar::fromLatin1 ('.'), 0, 0).toUShort ();
    m_minor = string.section (QChar::fromLatin1 ('.'), 1, 1).toUShort ();
    m_patch = string.section (QChar::fromLatin1 ('.'), 2, 2).toUShort ();
    init ();
}

void Version::init ()
{
    QString string = QString::fromLatin1 ("%1.%2.%3").arg (m_major).arg (m_minor).arg (m_patch);
    m_string = qstrdup (string.toLatin1 ().constData ());
    m_numeric = (m_major << 16) | (m_minor << 8) | (m_patch);
}
