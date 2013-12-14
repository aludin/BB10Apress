#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/LocaleHandler>

using namespace bb::cascades;

ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
		QObject(app), m_weatherClient(new WeatherClient(this)) {

	// Create scene document from main.qml asset, the parent is set
	// to ensure the document gets destroyed properly at shut down.
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);
	qml->documentContext()->setContextProperty("_app", this);

	m_weatherClient->setNetworkManager(QmlDocument::defaultDeclarativeEngine()->networkAccessManager());

	// Create root object for the UI
	AbstractPane *root = qml->createRootObject<AbstractPane>();

	// Set created root object as the application scene
	app->setScene(root);
}

WeatherClient* ApplicationUI::weatherClient() {
	return m_weatherClient;
}



