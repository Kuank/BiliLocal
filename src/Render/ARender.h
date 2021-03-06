/*=======================================================================
*
*   Copyright (C) 2013-2015 Lysine.
*
*   Filename:    ARender.h
*   Time:        2013/12/27
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

#include <QtCore>
#include <QtGui>

class ARenderPrivate;
class ABuffer;
class ASprite;
class PFormat;

class ARender :public QObject
{
	Q_OBJECT
public:
	static QStringList getModules();
	static ARender *create(QObject *parent = nullptr, QString name = QString());

	virtual ~ARender();
	virtual void setup();

protected:
	ARenderPrivate *d_ptr;
	Q_DECLARE_PRIVATE(ARender);

	explicit ARender(QObject *parent);

public slots:
	void setBackground(QString path);
	void setMusic(bool music);
	void setDisplayTime(double t);

	void setVideoAspectRatio(double ratio);
	void setPixelAspectRatio(double ratio);

	virtual void setFormat(PFormat *format) = 0;
	virtual void setBuffer(ABuffer *buffer) = 0;

	virtual ASprite *getSprite() = 0;
	virtual QObject *getHandle() = 0;

	virtual void resize(QSize size) = 0;
	virtual QSize getBufferSize() = 0;
	virtual QSize getActualSize() = 0;
	virtual	QSize getPreferSize();
	virtual void setPreferSize(QSize size);

	void draw();
	virtual void draw(QRect rect) = 0;
};
