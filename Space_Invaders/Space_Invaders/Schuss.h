#pragma once

#include <QtWidgets/QMainWindow>
#include <QLabel>
#include <QKeyEvent>
#include <QPainter>
#include <QTimer>
#include "ui_Space_Invaders.h"

#define Shootingposition_X 
#define Shootingsize_X 3
#define Shootingsize_Y 3
#define Shootingspeed 6

using namespace std;

class Schuss :public QMainWindow {

	Q_OBJECT;                            //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!Hier muss noch ein anderes Q_Objekt gewählt werden, vielleicht

public:
	int Schuss_Funktion(); //!!!!!!!!!!!!!!!!!!!!!!!!!!Schussfunktionen müssen noch erstellt werden in Gegner.cpp

private:
	Ui::Space_InvadersClass ui;
	QLabel *myLabel;
public:
	int Shot = Shootingspeed; //Geschwindigkeit des Schusses
	int Schussposition_X = Windowsize_X / 2;
	int Schussposition_Y = 760;

	QTimer *myTimer; //instanzieren des Timers

	public slots :
	void SchusstimerTimerSlot();
};


class Schuss {
public:
	//Konstruktor für den Schuss
	Schuss(int x_, int y_, int w_, int h_) {

	int Shot = Shootingspeed; //Geschwindigkeit des Schusses
	int Schussposition_X = Windowsize_X / 2;
	int Schussposition_Y = 760;
	}

};
