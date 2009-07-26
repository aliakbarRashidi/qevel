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

#include "mime_type.h"

#include <QtCore/QLatin1String>


MimeType::MimeType (const QString & name)
    : m_name (name)
{
}

MimeType::MimeType (const MimeType & other)
    : m_name (other.m_name)
{
}

MimeType::MimeType & MimeType::operator = (const MimeType & other)
{
    m_name = other.m_name;

    return *this;
}

bool MimeType::isDiscreteType () const
{
    return m_name.startsWith (QLatin1String ("text"))
        || m_name.startsWith (QLatin1String ("image"))
        || m_name.startsWith (QLatin1String ("audio"))
        || m_name.startsWith (QLatin1String ("video"))
        || m_name.startsWith (QLatin1String ("application"));
}

bool MimeType::isCompositeType () const
{
    return m_name.startsWith (QLatin1String ("message"))
        || m_name.startsWith (QLatin1String ("multipart"));
}

bool MimeType::isAudio () const
{
    return m_name.startsWith (QLatin1String ("audio/"));
}

bool MimeType::isImage () const
{
    return m_name.startsWith (QLatin1String ("image/"));
}

bool MimeType::isText () const
{
    return m_name == QLatin1String ("text/plain");
}

bool MimeType::isVideo () const
{
    return m_name.startsWith (QLatin1String ("video/"));
}

bool MimeType::isXml () const
{
    return m_name == QLatin1String ("text/xml")
        || m_name == QLatin1String ("application/xml")
        || m_name.endsWith (QLatin1String ("+xml"));
}
