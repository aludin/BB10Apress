/*
 * AppInvoker.cpp
 *
 *  Created on: Nov 15, 2013
 *      Author: aludin
 */

#include "AppInvoker.h"
#include <bb/system/InvokeRequest>
#include <bb/system/InvokeReply>
#include <bb/system/InvokeAction>
#include <bb/system/InvokeTarget>
#include <bb/system/InvokeTargetReply>
#include <bb/system/InvokeQueryTargetsRequest>
#include <bb/system/InvokeQueryTargetsReply>
#include <bb/PpsObject>

using namespace bb::system;
using namespace bb::pim::calendar;

AppInvoker::AppInvoker(QObject* parent) :
		QObject(parent), m_invokeManager(new InvokeManager(this)) {
	// TODO Auto-generated constructor stub

}

AppInvoker::~AppInvoker() {
	// TODO Auto-generated destructor stub
}

void AppInvoker::viewImage(const QString& fileName) {
	InvokeRequest request;
	request.setAction("bb.action.VIEW");
	request.setTarget("sys.pictures.card.previewer");
	request.setUri(fileName);

	InvokeTargetReply *reply = m_invokeManager->invoke(request);
	if (reply) {
		bool result = connect(reply, SIGNAL(finished()), this,
				SLOT(onInvocationFinished()));
		Q_ASSERT(result);
	} else {
		// error handling goes here
	}
}

void AppInvoker::openBrowser(const QString& url) {
	InvokeRequest request;
	request.setAction("bb.action.OPEN");
	request.setTarget("sys.browser");
	request.setUri(url);

	InvokeTargetReply* reply = m_invokeManager->invoke(request);
	if (reply) {
		bool result = connect(reply, SIGNAL(finished()), this,
				SLOT(onInvocationFinished()));
		Q_ASSERT(result);
	} else {
		// error handling goes here
	}
}

void AppInvoker::createEvent(const QString& subject, const QString& body,
		const QVariantList& participants) {
	QPair<AccountId, FolderId> defaultAccount =
			m_calendarService.defaultCalendarFolder();

	QVariantMap map;
	map.insert("accountid", defaultAccount.first);
	map.insert("folderid", defaultAccount.second);
	map.insert("participants", participants);
	map.insert("subject", subject);
	map.insert("body", body);

	QByteArray requestData = bb::PpsObject::encode(map, NULL);

	InvokeRequest request;
	request.setTarget("sys.pim.calendar.viewer.eventcreate");
	request.setAction("bb.action.CREATE");
	request.setMimeType("text/calendar");
	request.setData(requestData);

	InvokeTargetReply* reply = m_invokeManager->invoke(request);
	if (reply) {
		bool result = connect(reply, SIGNAL(finished()), this,
				SLOT(onInvocationFinished()));
		Q_ASSERT(result);
	} else {
		// error handling goes here
	}
}

void AppInvoker::onInvocationFinished() {
	InvokeTargetReply* reply = qobject_cast<InvokeTargetReply*>(sender());
	if (reply->error()) {
		// error handling goes here

	}
	reply->deleteLater();
}

QStringList AppInvoker::targets(){
	return m_targetIDs;
}

void AppInvoker::queryTargets(const QString& mimeType, const QString& action, const QString& uri) {
	InvokeQueryTargetsRequest request;
	request.setMimeType(mimeType);
	request.setAction(action);
	if(!uri.isEmpty()){
		request.setUri(uri);
	}
	InvokeQueryTargetsReply* reply = m_invokeManager->queryTargets(request);

	if (reply) {
		bool result = connect(reply, SIGNAL(finished()), this,
				SLOT(onQueryTargetsResponse()));
		Q_ASSERT(result);
	}

}

void AppInvoker::onQueryTargetsResponse() {

	InvokeQueryTargetsReply* reply = qobject_cast<InvokeQueryTargetsReply*>(sender());
	if(!reply->error()){
		m_targetIDs.clear();
		QList<InvokeAction> invokeActions = reply->actions();
		for(int i=0; i<invokeActions.size(); i++){
			QList<InvokeTarget> targets = invokeActions[i].targets();
			for (int j=0; j < targets.size(); j++){
				QString targetId = targets[j].name();
				m_targetIDs.append(targetId);
			}
		}
		emit targetsChanged();
	}
	reply->deleteLater();
}



