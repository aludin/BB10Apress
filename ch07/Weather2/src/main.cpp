#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"

#include <Qt/qdeclarativedebug.h>
#include "CityInfo.h"
#include "WeatherClient.h"
#include "GoogleMapClient.h"
using namespace bb::cascades;

Q_DECL_EXPORT int main(int argc, char **argv)
{
    qmlRegisterType<CityInfo>("ludin.utils", 1, 0, "CityInfo");
    qmlRegisterType<WeatherClient>("ludin.utils", 1, 0, "WeatherClient");
    qmlRegisterType<GoogleMapClient>("ludin.utils", 1, 0, "GoogleMapClient");

	Application app(argc, argv);

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    new ApplicationUI(&app);

    // Enter the application main event loop.
    return Application::exec();
}
