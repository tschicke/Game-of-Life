/*
 * Cell.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Tyler
 */

#ifndef CELL_H_
#define CELL_H_

class Cell {
public:
	Cell();
	virtual ~Cell();

	void setLiving(bool alive);
	bool isAlive();
	void toggleLife();

private:
	bool alive;
};

#endif /* CELL_H_ */
