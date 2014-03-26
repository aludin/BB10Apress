#include "applicationui.hpp"

#include <bb/cascades/Application>
#include <bb/cascades/QmlDocument>
#include <bb/cascades/AbstractPane>
#include <bb/cascades/ListItemTypeMapper>
#include <bb/cascades/ListView>
#include <bb/cascades/ListItemProvider>

using namespace bb::cascades;

class MyListItemTypeMapper : public ListItemTypeMapper, QObject{
public:
	MyListItemTypeMapper(QObject* parent) : QObject(parent){};
	~MyListItemTypeMapper(){};
	QString itemType(const QVariant& data, const QVariantList& indexPath){
		return (indexPath.length() == 1 ? "myheader" : "myitem");
	}
};


ApplicationUI::ApplicationUI(bb::cascades::Application *app) :
        QObject(app)
{
	QmlDocument *qml = QmlDocument::create("asset:///main.qml").parent(this);

    // Create root object for the UI
    AbstractPane *root = qml->createRootObject<AbstractPane>();
    ListView* listView = root->findChild<ListView*>("listview");
    MyListItemTypeMapper* mapper = new MyListItemTypeMapper(listView);
    listView->setListItemTypeMapper(mapper);

    // Set created root object as the application scene
    app->setScene(root);
}
