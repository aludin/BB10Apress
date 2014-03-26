#ifndef ApplicationUI_HPP_
#define ApplicationUI_HPP_

#include <QObject>
#include <Option.h>
#include <CompositeInstrument.h>
#include <QSharedPointer>

namespace bb
{
    namespace cascades
    {
        class Application;
        class LocaleHandler;
    }
}


/*!
 * @brief Application object
 *
 *
 */

#include "Stock.h"
#include "Option.h"
#include "CompositeInstrument.h"


class ApplicationUI : public QObject
{
    // used for displaying  instruments in ListView
	Q_PROPERTY(bb::cascades::ArrayDataModel* READ instrumentsModel CONSTANT)

    Q_PROPERTY(QList<CompositeInstrument*> READ composites NOTIFY compositesChanged)
    Q_PROPERTY(QList<Option*> options READ options NOTIFY optionsChanged)
    Q_PROPERTY(QList<Stocks*> stocks READ stocks NOTIFY stocksChanged)

public:
    ApplicationUI(bb::cascades::Application *app);
    virtual ~ApplicationUI() { }

    // loads financial instruments in ArrayDataModel
    Q_INVOKABLE void loadInstruments();

private:
    CompositeInstrument* composite();

    Option* m_option;
    CompositeInstrument* m_composite;

};

#endif /* ApplicationUI_HPP_ */
