#!/bin/bash
g++ -c TicTacToe.cpp
g++ TicTacToe.o -o sfml-app -lsfml-graphics -lsfml-window -lsfml-system
./sfml-app
