#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>
#include <bb/system/CardDoneMessage.hpp>

using namespace bb::cascades;
using namespace bb::system;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
		QObject(app), m_invokeManager(new InvokeManager(this)), m_uri("") {

	// Listen to incoming invocation requests
	bool result = connect(m_invokeManager,
			SIGNAL(invoked(const bb::system::InvokeRequest&)), this,
			SLOT(onInvokeRequest(const bb::system::InvokeRequest&)));
	Q_ASSERT(result);

	result = connect(m_invokeManager,
			SIGNAL(cardResizeRequested(const bb::system::CardResizeMessage&)),
			this, SLOT(onCardResized(const bb::system::CardResizeMessage&)));
	Q_ASSERT(result);
	result = connect(m_invokeManager,
			SIGNAL(cardPooled(const bb::system::CardDoneMessage&)), this,
			SLOT(onCardPooled(const bb::system::CardDoneMessage&)));
	Q_ASSERT(result);

	switch (m_invokeManager->startupMode()) {
	case ApplicationStartupMode::LaunchApplication:
		this->initFullUI();
		break;
	default:
		// Wait for the invoked signal to initialize UI
		break;
	}

}

void ApplicationUI::initFullUI() {
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->setContextProperty("_app", this);
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	Application::instance()->setScene(root);
}

void ApplicationUI::initPreviewerUI() {
	qDebug() << "initPreviewerUI";
	QmlDocument *qml = QmlDocument::create("asset:///previewer.qml").parent(
			this);
	qml->setContextProperty("_app", this);
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	Application::instance()->setScene(root);
}

void ApplicationUI::initPickerUI() {
	qDebug() << "initPickerUI";
	QmlDocument *qml = QmlDocument::create("asset:///picker.qml").parent(this);
	qml->setContextProperty("_app", this);
	AbstractPane *root = qml->createRootObject<AbstractPane>();
	Application::instance()->setScene(root);
}

QString ApplicationUI::uri() {
	return m_uri;
}

void ApplicationUI::setUri(const QString& uri) {
	m_uri = uri;
}

void ApplicationUI::onInvokeRequest(const bb::system::InvokeRequest& request) {
	QString target = request.target();
	QString action = request.action();
	QString mimeType = request.mimeType();
	if (target == "com.riskcetera.app.previewer") {
		this->initFullUI();
		this->m_uri = request.uri().toString();
		emit uriChanged();
	} else if (target == "com.riskcetera.card.previewer") {
		qDebug() << "com.riskcetera.card.previewer";
		this->initPreviewerUI();
		this->m_uri = request.uri().toString();
		emit uriChanged();
	} else if (target == "com.riskcetera.card.picker") {
		qDebug() << "com.riskcetera.card.picker";
		this->initPickerUI();
	}
}

void ApplicationUI::onPickDone(const QString& uri) {

	CardDoneMessage message;
	message.setData(uri);
	message.setDataType("text/plain");
	message.setReason("Success!");

	// Send message
	m_invokeManager->sendCardDone(message);
}

void ApplicationUI::onCardResized(
		const bb::system::CardResizeMessage& cardResizeMessage) {
	// handle resize here

}

void ApplicationUI::onCardPooled(
		const bb::system::CardDoneMessage& cardDoneMessage) {
	m_uri = "";
	emit uriChanged();
}

