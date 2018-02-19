#pragma once


#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "ui_Space_Invaders.h"

//Allgemeine Bedingungen (Fenstergröße,etc.)
#define Windowsize_X 1000
#define Windowsize_Y 800
#define Shipsize_X 30
#define Shipsize_Y 40
#define Shipposition (Windowsize_X/2)-15
#define Shootingposition_X 
#define Shootingsize_X 3
#define Shootingsize_Y 3
#define Shootingspeed 6
#define Shipspeed Windowsize_X/8
#define Enemyposition_X 5
#define Enemyposition_Y 5
#define Enemysize_X 30
#define Enemysize_Y 30
#define Enemyspeed_X 2 //muss wahrscheinlich geändert werden da die Bewegung in X-Richtung sprunghaft erfolgt
#define Enemyspeed_Y 1/10 //muss wahrscheinlich geändert werden, da die Bewegung in Y-Richtung sprunghaft erfolgt
#define Enemyreihen 4
#define Enemyspalten 12

enum Status {sichtbar,unsichtbar};

using namespace std;

class Space_Invaders : public QMainWindow
{
	Q_OBJECT

public:
	Space_Invaders(QWidget *parent = Q_NULLPTR);

private:
	Ui::Space_InvadersClass ui;
	QLabel *myLabel;

public:
	void TastaturEvent(QKeyEvent *);
	void paintEvent(QPaintEvent *);

	int Schiff_X = ((Windowsize_X / 2)-15); //Position des eigenen Raumschiffs auf der X-Achse
	int Schiff_Y = (Windowsize_Y - 40); //Position des eigenen Raumschiffs auf der Y-Achse
	int Schuss = Shootingspeed; //Geschwindigkeit des Schusses
	int Schussposition_X = Windowsize_X / 2;
	int Schussposition_Y = 760;
	int Treffer =0;
	int Gegner_Schuss_X = Enemyposition_X;
	int Gegner_Schuss_Y = Enemyposition_Y;
	int Enemy;

	Gegner *Enemy[Enemyreihen][Enemyspalten];    //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Klassennamen werden noch geändert

	QTimer *myTimer; //instanzieren des Timers

public slots:
	void myTimerSlot();
};

class Gegner {
public:
	//Konstruktor für die Gegner
	Gegner(int _x, int _y, int _w, int _h) {
		x = _x; //Position auf der X-Achse
		y = _y; //Position auf der Y-Achse
		w = _w; //Breite des Gegners
		h = _h; //Höhe des Gegners
		si = sichtbar; //Status sichtbar bzw. unsichtbar
	}
	int x;
	int y;
	int w;
	int h;
	Status si;
};
