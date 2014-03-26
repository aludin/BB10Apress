#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"

#include <Qt/qdeclarativedebug.h>

#include <iostream>
#include "Instrument.h"
#include "CompositeInstrument.h"
#include "Option.h"
#include "Stock.h"

using namespace std;
using namespace bb::cascades;


void showInstrumentPrice(const Instrument& instrument) {
	std::cout << "Instrument symbol is: " << instrument.symbol().toStdString() <<
        " Instrument price is: " << instrument.price() << std::endl;
}






Q_DECL_EXPORT int main(int argc, char **argv)
{

	qmlRegisterType<Option>("ludin.instruments", 1, 0, "FinOption");
	Application app(argc, argv);

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    new ApplicationUI(&app);

    // Enter the application main event loop.
    return Application::exec();
}
