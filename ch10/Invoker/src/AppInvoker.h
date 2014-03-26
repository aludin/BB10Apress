/*
 * AppInvoker.h
 *
 *  Created on: Nov 15, 2013
 *      Author: aludin
 */

#ifndef APPINVOKER_H_
#define APPINVOKER_H_
#include <QObject>
#include <bb/system/InvokeManager>
#include <bb/system/CardDoneMessage>
#include <bb/pim/calendar/CalendarService>

class AppInvoker : public QObject{
	Q_OBJECT
	Q_PROPERTY(QStringList targets READ targets NOTIFY targetsChanged);

public slots:
	void viewImage(const QString& fileName);
	void openBrowser(const QString& url);
	void createEvent(const QString& subject, const QString& body, const QVariantList& participants);
	void takePicture();
	void queryTargets(const QString& mimeType, const QString& action, const QString& uri);
	void invokeTargetWithUri(const QString& targetId, const QString& action, const QString& uri);
Q_SIGNALS:
	void targetsChanged();

private slots:
	void onInvocationFinished();
	void onQueryTargetsResponse();
	void onCardDone(const bb::system::CardDoneMessage& message);
public:
	AppInvoker(QObject* parent = 0);
	virtual ~AppInvoker();

private:
	QStringList targets();

	bb::system::InvokeManager* m_invokeManager;
	bb::pim::calendar::CalendarService m_calendarService;
	QStringList m_targetIDs;
};

#endif /* APPINVOKER_H_ */
