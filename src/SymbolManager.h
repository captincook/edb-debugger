/*
Copyright (C) 2006 - 2014 Evan Teran
                          eteran@alum.rit.edu

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef SYMBOLMANAGER_20060814_H_
#define SYMBOLMANAGER_20060814_H_

#include "ISymbolManager.h"
#include <QHash>
#include <QMap>
#include <QSet>
#include <QString>

class SymbolManager : public ISymbolManager {
public:
	SymbolManager();

public:
	virtual const QList<Symbol::pointer> symbols() const;
	virtual const Symbol::pointer find(const QString &name) const;
	virtual const Symbol::pointer find(edb::address_t address) const;
	virtual const Symbol::pointer find_near_symbol(edb::address_t address) const;
	virtual void add_symbol(const Symbol::pointer &symbol);
	virtual void clear();
	virtual void load_symbol_file(const QString &filename, edb::address_t base);
	virtual void set_symbol_generator(ISymbolGenerator *generator);
	virtual void set_symbol_path(const QString &symbol_directory);
	virtual void set_label(edb::address_t address, const QString &label);
	virtual QString find_address_name(edb::address_t address);
	virtual QHash<edb::address_t, QString> labels() const;

private:
	bool process_symbol_file(const QString &f, edb::address_t base, const QString &library_filename);

private:
	QString                               symbol_directory_;
	QSet<QString>                         symbol_files_;
	QList<Symbol::pointer>                symbols_;
	QMap<edb::address_t, Symbol::pointer> symbols_by_address_;
	QHash<QString, Symbol::pointer>       symbols_by_name_;
	ISymbolGenerator                     *symbol_generator_;
	bool                                  show_path_notice_;
	QHash<edb::address_t, QString>        labels_;
	QHash<QString, edb::address_t>        labels_by_name_;
	
};

#endif

