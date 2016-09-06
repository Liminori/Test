/*
 *  GNU Lesser General Public License (LGPL):
 *
 *	Copyright (C) 2016  ProgSys
 *
 *	This program is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU Lesser General Public License as published by
 *	the Free Software Foundation, version 3 of the License.
 *
 *	This program is distributed in the hope that it will be useful,
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU Lesser General Public License for more details.
 *
 *	You should have received a copy of the GNU Lesser General Public License
 *	along with this program.  If not, see http://doc.qt.io/qt-5/lgpl.html
 *	or http://www.gnu.org/licenses/
 */
#ifndef INCLUDE_FILES_HOSPITALDAT_H_
#define INCLUDE_FILES_HOSPITALDAT_H_

#include <files/DataFile.h>
#include <QList>
#include <util/TreeItem.h>

class HospitalDAT: public DataFile  {
	Q_OBJECT
public:
	HospitalDAT(QObject *parent = 0);
	virtual ~HospitalDAT();

	Qt::ItemFlags flags(const QModelIndex &index) const final;
    bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) final;

public slots:
	bool open(const QString& filepath) final;
	bool save(const QString& filepath) final;

	bool insertFront() final;
	bool insertBack() final;
	bool insertAt(int index) final;
	bool removeAt(int index) final;

};

#endif /* INCLUDE_FILES_HOSPITALDAT_H_ */
