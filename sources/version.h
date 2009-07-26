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

#ifndef VERSION_H
#define VERSION_H


class QString;

class Version
{

public:
    Version ();
    Version (const char * string);
    Version (const QString & string);
    Version (unsigned short major, unsigned short minor, unsigned short patch);
    ~Version ();

    Version (const Version & other);
    Version & operator = (const Version & other);

    inline unsigned short majorVersion () const { return m_major; }
    inline unsigned short minorVersion () const { return m_minor; }
    inline unsigned short patchLevel   () const { return m_patch; }

    inline operator const char * () const { return m_string; }
    inline operator int () const { return m_numeric; }

    inline bool operator == (const Version & other) const { return m_numeric == other.m_numeric; }
    inline bool operator != (const Version & other) const { return m_numeric != other.m_numeric; }
    inline bool operator <  (const Version & other) const { return m_numeric <  other.m_numeric; }
    inline bool operator <= (const Version & other) const { return m_numeric <= other.m_numeric; }
    inline bool operator >  (const Version & other) const { return m_numeric >  other.m_numeric; }
    inline bool operator >= (const Version & other) const { return m_numeric >= other.m_numeric; }

private:
    void init (const QString & string);
    void init ();

    const char * m_string;
    int m_numeric;
    unsigned short m_major;
    unsigned short m_minor;
    unsigned short m_patch;

};

#endif // VERSION_H
