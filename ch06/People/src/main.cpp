#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"

#include <Qt/qdeclarativedebug.h>

using namespace bb::cascades;
#include <MyDataModel.h>

Q_DECL_EXPORT int main(int argc, char **argv)
{
	qmlRegisterType<MyDataModel>("ludin.datamodels", 1, 0, "MyDataModel");


    Application app(argc, argv);

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    new ApplicationUI(&app);

    // Enter the application main event loop.
    return Application::exec();
}
