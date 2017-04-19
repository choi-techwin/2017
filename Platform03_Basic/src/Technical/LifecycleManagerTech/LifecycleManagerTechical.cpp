/*
 * LifecycleManagerTech.cpp
 *
 *  Created on: 2017. 4. 17.
 *      Author: choi.sungwoon
 */

#include "LifecycleManagerTechical.h"

LifecycleManagerTechical::LifecycleManagerTechical() {
}

LifecycleManagerTechical::~LifecycleManagerTechical() {
}

void LifecycleManagerTechical::registerSchedulersTechnical() {

}
void LifecycleManagerTechical::registerComponentsTechnical() {
	this->addComponent(&(this->timer));

}
void LifecycleManagerTechical::associateComponentsTechnical() {

}
