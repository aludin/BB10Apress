/*
 * AsynchSearch.h
 *
 *  Created on: Mar 6, 2014
 *      Author: aludin
 */

#ifndef ASYNCHSEARCH_H_
#define ASYNCHSEARCH_H_

#include <QObject>
#include <QString>
#include <QList>

#include <bb/pim/contacts/ContactService>
#include <bb/pim/contacts/Contact>
#include <bb/pim/contacts/ContactSearchFilters>

using namespace bb::pim::contacts;

class AsynchSearch: public QObject {
	Q_OBJECT
public:
	AsynchSearch(QObject* parent = 0) :
			QObject(parent) {
	}
	;
	virtual ~AsynchSearch() {
	}
	;
public slots:
	void doSearch();
public:
	void setFilter(QString filter) {
		m_filter = filter;
	}
	QString filter() {
		return m_filter;
	}

	signals:
	void searchFinished(QList<Contact>);

private:
	QString m_filter;
	ContactService m_contactService;
};

#endif /* ASYNCHSEARCH_H_ */
