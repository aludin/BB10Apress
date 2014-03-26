/*
 * MyDataModel.h
 *
 *  Created on: Jan 9, 2014
 *      Author: aludin
 */

#ifndef MYDATAMODEL_H_
#define MYDATAMODEL_H_

#include <QObject>
#include <bb/cascades/DataModel>
#include <bb/cascades/ArrayDataModel>
#include <bb/data/JsonDataAccess>

class MyDataModel: public bb::cascades::DataModel {
Q_OBJECT

Q_PROPERTY(QString source READ source WRITE setSource NOTIFY sourceChanged);
public:

	MyDataModel(QObject* parent = 0);
	virtual ~MyDataModel();

	Q_INVOKABLE int childCount(const QVariantList &indexPath);
	Q_INVOKABLE QVariant data(const QVariantList &indexPath);
	Q_INVOKABLE bool hasChildren(const QVariantList &indexPath);
	Q_INVOKABLE QString itemType(const QVariantList &indexPath);
	Q_INVOKABLE void removeItem(const QVariantList& indexPath);


signals:
	void sourceChanged();

private:
	void load(QString filename);
	QString source();
	void setSource(QString source);

	QString m_source;
	QVariantList m_presidents;
	QVariantList m_actors;

};

#endif /* MYDATAMODEL_H_ */
