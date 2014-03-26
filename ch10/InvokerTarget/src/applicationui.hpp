#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <bb/system/InvokeManager>


namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}

class QTranslator;

/*!
 * @brief Application object
 *
 *
 */

class ApplicationUI : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString uri READ uri WRITE setUri NOTIFY uriChanged)
public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }
	//Q_INVOKABLE void pickDone(const QString& uri);

public slots:
	void onPickDone(const QString& uri);
signals:
	void uriChanged();

private slots:
    void onInvokeRequest(const bb::system::InvokeRequest& request);
    void onCardResized(const bb::system::CardResizeMessage& cardResizeMessage);
    void onCardPooled(const bb::system::CardDoneMessage& cardDoneMessage);

private:
    void initFullUI();
    void initPreviewerUI();
    void initPickerUI();
    QString uri();
    void setUri(const QString& uri);

    bb::system::InvokeManager* m_invokeManager;
    QString m_uri;
};

#endif /* ApplicationUI_HPP_ */
