#include "MyDataModel.h"

MyDataModel::MyDataModel(QObject* parent) :
		DataModel(parent) {

}

MyDataModel::~MyDataModel() {

}

QString MyDataModel::source() {
	return m_source;
}

void MyDataModel::setSource(QString source) {
	if (m_source == source)
		return;
	m_source = source;
	this->load(source);
	emit sourceChanged();
}

bool MyDataModel::hasChildren(const QVariantList &indexPath) {
	if ((indexPath.size() == 0) || (indexPath.size() == 1))
		return true;
	else
		return false;
}

int MyDataModel::childCount(const QVariantList &indexPath) {
	if (indexPath.size() == 0) {
		return 2; // for headers "Actors" and "US Presidents"
	} else {
		if (indexPath.size() == 1) {
			if (indexPath.at(0).toInt() == 0) {
				return m_actors.size();
			} else {
				return m_presidents.size();
			}
		} else {
			return 0;
		}
	}
}

QString MyDataModel::itemType(const QVariantList &indexPath) {

	if (indexPath.size() == 1)
		return "category";
	if (indexPath.size() == 2)
		return "person";
	return "";
}

QVariant MyDataModel::data(const QVariantList &indexPath) {
	if (indexPath.size() == 1) {
		if (indexPath.at(0).toInt() == 0) {
			QVariantMap actors;
			actors["value"] = "Actors";
			return actors;
		} else {
			QVariantMap presidents;
			presidents["value"] = "US Presidents";
			return presidents;
		}
	} else if (indexPath.size() == 2) {
		if (indexPath.at(0) == 0) {
			return m_actors.at(indexPath.at(1).toInt());
		} else {
			return m_presidents.at(indexPath.at(1).toInt());
		}
	}
	QVariant v;
	return v;
}

void MyDataModel::removeItem(const QVariantList& indexPath){
	if(indexPath.size() == 2){
		if(indexPath.at(0) == 0){
			m_actors.removeAt(indexPath.at(1).toInt());
		}else{
			m_presidents.removeAt(indexPath.at(1).toInt());
		}
		emit itemRemoved(indexPath);
	}
}

void MyDataModel::load(QString source) {
	bb::data::JsonDataAccess json;
	QVariantList entries = json.load(
			QDir::currentPath() + "/app/native/assets/" + source).toList();
	if (!json.hasError()) {
		for (int i = 0; i < entries.length(); i++) {
			QVariantMap entry = entries[i].toMap();
			if (entry["job"] == "actor") {
				m_actors.append(entry);
			} else {
				m_presidents.append(entry);
			}
		}
	}
}
