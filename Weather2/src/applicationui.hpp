#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <bb/system/SystemUiResult>

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
        class Tab;
    }
    namespace system{
    	class SystemListDialog;
    	class SystemPrompt;
    	class SystemProgressDialog;
    }
}

class QFile;
class QAuthenticator;
class QNetworkAccessManager;
class QNetworkReply;

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }


private:
    void updateUI(const QVariantMap& data);
private slots:
	void onGetWeather();
	void onCitiesDialogFinished(bb::system::SystemUiResult::Type type);
	void onErrorPromptFinished(bb::system::SystemUiResult::Type type);
	void onProgressFinished(bb::system::SystemUiResult::Type type);
	void onGetWeatherIconFinished();
	void onGetCityMapFinished();
	void onRequestFinished();
	void onActiveTabChanged(bb::cascades::Tab* activeTab);


private:
	QNetworkAccessManager* m_networkAccessManager;
	bb::system::SystemListDialog* m_citiesDialog;
	bb::system::SystemProgressDialog* m_progress;
	bb::system::SystemPrompt* m_errorPrompt;
	QVariantList m_citiesList;
	QList<QNetworkReply*> m_networkReplies;
	QString m_key;

};

#endif /* ApplicationUI_HPP_ */
