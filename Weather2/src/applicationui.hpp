#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include "WeatherClient.h"
#include "GoogleMapClient.h"

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
    Q_PROPERTY(GoogleMapClient* googleMapClient READ googleMapClient CONSTANT)
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }

private:
    WeatherClient* weatherClient();
    GoogleMapClient* googleMapClient();
    WeatherClient* m_weatherClient;
    GoogleMapClient* m_googleMapClient;
};

#endif /* ApplicationUI_HPP_ */
