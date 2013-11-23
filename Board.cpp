/*
 * Board.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Tyler
 */

#include "Board.h"
#include <gl/gl.h>
#include <iostream>
#include <stdlib.h>
#include <time.h>

Board::Board() {
	currentCells = new Cell[128 * 72];
	nextCells = new Cell[128 * 72];

	srand(time(0));
}

Board::~Board() {
}

void Board::update() {
	for (int x = 0; x < 128; ++x) {
		for (int y = 0; y < 72; ++y) {
			int cellIndex = getCellIndex(x, y);
			int liveNeighbors = 0;

			if (x > 0 && currentCells[getCellIndex(x - 1, y)].isAlive()) {
				liveNeighbors += 1;
			}
			if (x < 128 && currentCells[getCellIndex(x + 1, y)].isAlive()) {
				liveNeighbors += 1;
			}
			if (y > 0 && currentCells[getCellIndex(x, y - 1)].isAlive()) {
				liveNeighbors += 1;
			}
			if (y < 71 && currentCells[getCellIndex(x, y + 1)].isAlive()) {
				liveNeighbors += 1;
			}

			if (x > 0 && y > 0 && currentCells[getCellIndex(x - 1, y - 1)].isAlive()) {
				liveNeighbors += 1;
			}
			if (x > 0 && y < 71 && currentCells[getCellIndex(x - 1, y + 1)].isAlive()) {
				liveNeighbors += 1;
			}
			if (x < 128 && y > 0 && currentCells[getCellIndex(x + 1, y - 1)].isAlive()) {
				liveNeighbors += 1;
			}
			if (x < 128 && y < 71 && currentCells[getCellIndex(x + 1, y + 1)].isAlive()) {
				liveNeighbors += 1;
			}

			if (currentCells[cellIndex].isAlive()) {
				if (liveNeighbors <= 2) {
					nextCells[cellIndex].setLiving(false);
				} else if (liveNeighbors == 3) {
					nextCells[cellIndex].setLiving(true);
				} else if (liveNeighbors > 3) {
					nextCells[cellIndex].setLiving(false);
				} else {
					nextCells[cellIndex].setLiving(false);
				}
			} else {
				if (liveNeighbors == 3) {
					nextCells[cellIndex].setLiving(true);
				} else {
					nextCells[cellIndex].setLiving(false);
				}
			}
		}
	}

	for (int i = 0; i < 128 * 72; ++i) {
		currentCells[i].setLiving(nextCells[i].isAlive());
	}
}

void Board::draw() {
	glBegin(GL_TRIANGLES);
	for (int x = 0; x < 128; ++x) {
		for (int y = 0; y < 72; ++y) {
			if (currentCells[getCellIndex(x, y)].isAlive()) {
				glColor3f(1, 1, 1);
			} else {
				glColor3f(0, 0, 0);
			}

			int x1 = (x * 10) + 1, x2 = ((x + 1) * 10) - 1;
			int y1 = (y * 10) + 1, y2 = ((y + 1) * 10) - 1;
			glVertex2f(x1, y1);
			glVertex2f(x2, y1);
			glVertex2f(x2, y2);

			glVertex2f(x1, y1);
			glVertex2f(x2, y2);
			glVertex2f(x1, y2);
		}
	}
	glEnd();
}

void Board::toggleCell(int x, int y) {
	int cellX = x / 10;
	int cellY = y / 10;
	currentCells[getCellIndex(cellX, cellY)].toggleLife();
}

void Board::clear() {
	for (int x = 0; x < 128; ++x) {
		for (int y = 0; y < 72; ++y) {
			currentCells[getCellIndex(x, y)].setLiving(false);
		}
	}
}

void Board::randomize() {
	for (int x = 0; x < 128; ++x) {
		for (int y = 0; y < 72; ++y) {
			if (rand() > RAND_MAX / 2) {
				currentCells[getCellIndex(x, y)].setLiving(true);
			}
		}
	}
}

int Board::getCellIndex(int x, int y) {
	return (x * 72) + y;
}
