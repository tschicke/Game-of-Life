/*
 * main.cpp
 *
 *  Created on: Nov 22, 2013
 *      Author: Tyler
 */

#include <iostream>

#include <SFML/Window.hpp>
#include <gl/gl.h>
#include "Board.h"

void initGL(){
	glClearColor(0.5, 0.5, 0.5, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, 1280, 0, 720, -1, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main(){
	sf::Window window;
	window.create(sf::VideoMode(1280, 720, 32), "Game of Life");
	window.setFramerateLimit(30);

	initGL();

	Board board;

	bool running = true;
	bool paused = true;
	while(running){
		sf::Event event;
		while(window.pollEvent(event)){
			if(event.type == sf::Event::Closed){
				running = false;
			} else if(event.type == sf::Event::KeyPressed){
				if(event.key.code == sf::Keyboard::Space){
					paused = !paused;
				}
			} else if(event.type == sf::Event::MouseButtonPressed){
				board.toggleCell(event.mouseButton.x, 720 - event.mouseButton.y);
			}
		}

		if (!paused) {
			board.update();
		}

		glClear(GL_COLOR_BUFFER_BIT);

		board.draw();

		window.display();
	}

	return 0;
}


