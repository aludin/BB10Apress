#include <bb/cascades/Application>

#include <QLocale>
#include <QTranslator>
#include "applicationui.hpp"

#include <Qt/qdeclarativedebug.h>

using namespace bb::cascades;


void myMessageOutput(QtMsgType type, const char* msg){
                fprintf(stdout, "%s\n", msg);
                fflush(stdout);
}

Q_DECL_EXPORT int main(int argc, char **argv)
{
    Application app(argc, argv);
    qInstallMsgHandler(myMessageOutput);

    // Create the Application UI object, this is where the main.qml file
    // is loaded and the application scene is set.
    new ApplicationUI(&app);

    // Enter the application main event loop.
    return Application::exec();
}
