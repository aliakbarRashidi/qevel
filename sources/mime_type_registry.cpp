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

#include "mime_type_registry.h"

#include "magic_number_registry.h"


MimeTypeRegistry::MimeTypeRegistry * MimeTypeRegistry::s_defaultRegistry = 0;

MimeTypeRegistry::MimeTypeRegistry * MimeTypeRegistry::defaultRegistry ()
{
    if (s_defaultRegistry == 0)
        s_defaultRegistry = new MagicNumberRegistry ();
    return s_defaultRegistry;
}

void MimeTypeRegistry::setDefaultRegistry (MimeTypeRegistry * registry)
{
    if (s_defaultRegistry != 0)
        s_defaultRegistry->deleteLater ();
    s_defaultRegistry = registry;
}

MimeTypeRegistry::~MimeTypeRegistry ()
{
    if (this == s_defaultRegistry)
        s_defaultRegistry = 0;
}

MimeType MimeTypeRegistry::mimeType (const QFile & file) const
{
    Q_UNUSED(file);

    return MimeType (QString ("application/octet-stream"));
}
