/*
 * Cell.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Tyler
 */

#include "Cell.h"

Cell::Cell() {
	alive = false;
}

Cell::~Cell() {
}

void Cell::setLiving(bool alive) {
	this->alive = alive;
}

bool Cell::isAlive() {
	return alive;
}

void Cell::toggleLife() {
	alive = !alive;
}
