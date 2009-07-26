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

#include "magic_number_registry.h"

#include <QtCore/QFile>
#include <QtCore/QFileInfo>

#include <magic.h>


MagicNumberRegistry::MagicNumberRegistry ()
{
    m_cookie = magic_open (MAGIC_SYMLINK | MAGIC_MIME_TYPE | MAGIC_PRESERVE_ATIME | MAGIC_ERROR);
    if (m_cookie == NULL || magic_load (m_cookie, NULL) == -1)
        qWarning ("MagicNumberRegistry: %s", magic_error (m_cookie));
}

MagicNumberRegistry::~MagicNumberRegistry ()
{
    if (m_cookie != NULL)
        magic_close (m_cookie);
}

MimeType MagicNumberRegistry::mimeType (const QFile & file) const
{
    if (m_cookie != NULL)
    {
        const char * magicType = magic_file (m_cookie, QFileInfo (file).absoluteFilePath ().toLatin1 ());
        if (magicType != NULL)
            return MimeType (magicType);

        qWarning ("MagicNumberRegistry::mimeType: %s", magic_error (m_cookie));
    }

    return MimeTypeRegistry::mimeType (file);
}
