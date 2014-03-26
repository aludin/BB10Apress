#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include "WeatherClient.h"

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}


class ApplicationUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(WeatherClient* weather READ weatherClient CONSTANT)
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }

private:
    WeatherClient* weatherClient();
    WeatherClient* m_weatherClient;
};

#endif /* ApplicationUI_HPP_ */
