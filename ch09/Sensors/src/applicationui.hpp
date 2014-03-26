#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include "HybridSensor.h"

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}

class QTranslator;


class ApplicationUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(HybridSensor* sensor READ sensor CONSTANT)
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }
private:
    HybridSensor* sensor();
    HybridSensor* m_hybridSensor;

    void checkForSensor(QByteArray type);


};

#endif /* ApplicationUI_HPP_ */
