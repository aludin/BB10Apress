/* Copyright (c) 2012, 2013  BlackBerry Limited.
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 * http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#include "AddressBook.hpp"

#include "ContactEditor.hpp"
#include "ContactViewer.hpp"

using namespace bb::cascades;
using namespace bb::pim::contacts;

#include <QThread>

//! [0]
AddressBook::AddressBook(QObject *parent) :
		QObject(parent), m_contactService(new ContactService(this)), m_model(
				new GroupDataModel(this)), m_contactViewer(
				new ContactViewer(m_contactService, this)), m_contactEditor(
				new ContactEditor(m_contactService, this)), m_currentContactId(
				-1) {
	// Disable grouping in data model
	m_model->setGrouping(ItemGrouping::None);

	// Ensure to invoke the filterContacts() method whenever a contact has been added, changed or removed
	bool ok = connect(m_contactService, SIGNAL(contactsAdded(QList<int>)),
			SLOT(filterContacts()));
	Q_ASSERT(ok);
	ok = connect(m_contactService, SIGNAL(contactsChanged(QList<int>)),
			SLOT(filterContacts()));
	Q_ASSERT(ok);
	ok = connect(m_contactService, SIGNAL(contactsDeleted(QList<int>)),
			SLOT(filterContacts()));
	Q_ASSERT(ok);

	// Fill the data model with contacts initially
	filterContacts();
}
//! [0]

//! [1]
void AddressBook::setCurrentContact(const QVariantList &indexPath) {
	// Extract the ID of the selected contact from the model
	if (indexPath.isEmpty()) {
		m_currentContactId = -1;
	} else {
		const QVariantMap entry = m_model->data(indexPath).toMap();
		m_currentContactId = entry.value("contactId").toInt();
	}
}
//! [1]

//! [2]
void AddressBook::createContact() {
	// Prepare the contact editor for creating a new contact
	m_contactEditor->reset();
	m_contactEditor->setMode(ContactEditor::CreateMode);
}
//! [2]

//! [3]
void AddressBook::editContact() {
	// Prepare the contact editor for editing the current contact
	m_contactEditor->loadContact(m_currentContactId);
	m_contactEditor->setMode(ContactEditor::EditMode);
}
//! [3]

//! [4]
void AddressBook::viewContact() {
	// Prepare the contact viewer for displaying the current contact
	m_contactViewer->setContactId(m_currentContactId);
}
//! [4]

//! [5]
void AddressBook::deleteContact() {
	m_contactService->deleteContact(m_currentContactId);
}
//! [5]

bb::cascades::GroupDataModel* AddressBook::model() const {
	return m_model;
}

QString AddressBook::filter() const {
	return m_filter;
}

//! [6]
void AddressBook::setFilter(const QString &filter) {
	if (m_filter == filter)
		return;

	m_filter = filter;
	emit filterChanged();

	// Update the model now that the filter criterion has changed
	filterContacts();
}
//! [6]

ContactViewer* AddressBook::contactViewer() const {
	return m_contactViewer;
}

ContactEditor* AddressBook::contactEditor() const {
	return m_contactEditor;
}

void AddressBook::filterContacts() {

	QThread* thread = new QThread;
	AsynchSearch* asynch = new AsynchSearch;
	asynch->setFilter(m_filter);
	asynch->moveToThread(thread);

	bool result = connect(thread, SIGNAL(started()), asynch, SLOT(doSearch()));
	Q_ASSERT(result);
	result = connect(asynch, SIGNAL(searchFinished(QList<Contact>)), this,
			SLOT(onSearchFinished(QList<Contact>)));
	Q_ASSERT(result);

	result = connect(asynch, SIGNAL(searchFinished(const QList<Contact>)),
			thread, SLOT(quit()));
	Q_ASSERT(result);
	result = connect(asynch, SIGNAL(searchFinished(const QList<Contact>)),
			asynch, SLOT(deleteLater()));
	Q_ASSERT(result);
	result = connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
	Q_ASSERT(result);

	thread->start();
}

void AddressBook::onSearchFinished(QList<Contact> contacts) {

	// Clear the old contact information from the model
	m_model->clear();

	// Iterate over the list of contact IDs
	foreach (Contact c, contacts)
	{
		// Copy the data into a model entry
		QVariantMap entry;
		entry["contactId"] = c.id();
		entry["firstName"] = c.firstName();
		entry["lastName"] = c.lastName();

		const QList<ContactAttribute> emails = c.emails();
		if (!emails.isEmpty())
			entry["email"] = emails.first().value();
		// Add the entry to the model
		m_model->insert(entry);
	}
}

