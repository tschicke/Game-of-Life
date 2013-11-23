/*
 * Board.h
 *
 *  Created on: Nov 22, 2013
 *      Author: Tyler
 */

#ifndef BOARD_H_
#define BOARD_H_

#include "Cell.h"

class Board {
public:
	Board();
	virtual ~Board();

	void update();
	void draw();
	void toggleCell(int x, int y);

private:
	Cell * currentCells;
	Cell * nextCells;
	int getCellIndex(int x, int y);
};

#endif /* BOARD_H_ */
