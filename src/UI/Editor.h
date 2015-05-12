/*=======================================================================
*
*   Copyright (C) 2013-2015 Lysine.
*
*   Filename:    Editor.h
*   Time:        2013/06/30
*   Author:      Lysine
*
*   Lysine is a student majoring in Software Engineering
*   from the School of Software, SUN YAT-SEN UNIVERSITY.
*
*   This program is free software: you can redistribute it and/or modify
*   it under the terms of the GNU General Public License as published by
*   the Free Software Foundation, either version 3 of the License, or
*   (at your option) any later version.
*
*   This program is distributed in the hope that it will be useful,
*   but WITHOUT ANY WARRANTY; without even the implied warranty of
*   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*   GNU General Public License for more details.

*   You should have received a copy of the GNU General Public License
*   along with this program.  If not, see <http://www.gnu.org/licenses/>.
*
=========================================================================*/

#pragma once

#include <QtGui>
#include <QtCore>
#include <QtWidgets>
#include <QtNetwork>

namespace UI
{
	class Editor :public QDialog
	{
		Q_OBJECT
	public:
		enum Show
		{
			List = 0x1,
			Pool = 0x2,
			All = List | Pool
		};

		static void exec(QWidget *parent = 0, int show = All);

	private:
		QWidget *list;
		QWidget *pool;
		explicit Editor(QWidget *parent = 0);
	};
}
