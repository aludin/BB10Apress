/*
 * Test.h
 *
 *  Created on: Mar 19, 2014
 *      Author: aludin
 */

#ifndef TEST_H_
#define TEST_H_
#include <QObject>
class Test : public QObject{
Q_OBJECT
public:
	Test(QObject* parent=0) : QObject(parent){};
	virtual ~Test();
};

#endif /* TEST_H_ */
