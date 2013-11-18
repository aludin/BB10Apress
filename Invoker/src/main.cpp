#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"

#include <Qt/qdeclarativedebug.h>

using namespace bb::cascades;
#include "AppInvoker.h"

Q_DECL_EXPORT int main(int argc, char **argv)
{
	// test
	Application app(argc, argv);
	qmlRegisterType<AppInvoker>("com.ludin.utils", 1, 0, "AppInvoker");

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    new ApplicationUI(&app);

    // Enter the application main event loop.
    return Application::exec();
}
