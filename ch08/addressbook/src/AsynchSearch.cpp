/*
 * AsynchSearch.cpp
 *
 *  Created on: Mar 6, 2014
 *      Author: aludin
 */

#include "AsynchSearch.h"

void AsynchSearch::doSearch() {
	QList<Contact> contacts;
	QList<Contact> contactsDetails;
	if (m_filter.isEmpty()) {
		// No filter has been specified, so just list all contacts
		ContactListFilters filter;
		filter.setLimit(0);
		contacts = m_contactService.contacts(filter);
		foreach (Contact c, contacts)
		{
			// Fetch the complete details for this contact ID
			const Contact contact = m_contactService.contactDetails(c.id());
			contactsDetails.append(contact);

		}
		emit searchFinished(contactsDetails);
	} else {
		// Use the entered filter string as search value
		ContactSearchFilters filter;
		filter.setSearchValue(m_filter);
		contacts = m_contactService.searchContacts(filter);
		foreach (Contact c, contacts)
		{
			// Fetch the complete details for this contact ID
			const Contact contact = m_contactService.contactDetails(c.id());
			contactsDetails.append(contact);
		}
		emit searchFinished(contactsDetails);
	}
}

