#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "ui_Space_Invaders.h"

//Allgemeine Definitionen für die Gegner
#define Enemyposition_X 5
#define Enemyposition_Y 5
#define Enemysize_X 30
#define Enemysize_Y 30
#define Enemyspeed_X 2 //muss wahrscheinlich geändert werden da die Bewegung in X-Richtung sprunghaft erfolgt
#define Enemyspeed_Y 1/10 //muss wahrscheinlich geändert werden, da die Bewegung in Y-Richtung sprunghaft erfolgt
#define Enemyreihen 4
#define Enemyspalten 12

enum Status { sichtbar, unsichtbar };

using namespace std;

class Gegner :public QMainWindow {

	Q_OBJECT;                            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Hier muss noch ein anderes Q_Objekt gewählt werden, vielleicht

public:
	Gegner(QWidget *parent = Q_NULLPTR); //!!!!!!!!!!!!!!!!!!!!!!!!!!Gegnerfunktionen müssen noch erstellt werden in Gegner.cpp

private:
	Ui::Space_InvadersClass ui;
	QLabel *myLabel;
public:
	int Gegner_Schuss_X = Enemyposition_X;
	int Gegner_Schuss_Y = Enemyposition_Y;

	QTimer *myTimer; //instanzieren des Timers

public slots :
		void GegnerTimerSlot();
};

class Gegner {
public:
	//Konstruktor für die Gegner
	Gegner(int _x, int _y, int _w, int _h) {
		x = _x; //Position auf der X-Achse
		y = _y; //Position auf der Y-Achse
		w = _w; //Breite des Gegners
		h = _h; //Höhe des Gegners
		si == sichtbar; //Status sichtbar bzw. unsichtbar
	}
	int x;
	int y;
	int w;
	int h;
	Status si;
};

