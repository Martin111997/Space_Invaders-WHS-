#pragma once

#define Fenstergröße_X 1200
#define Fenstergröße_Y 800
#define Gegner_Spalten 12
#define Gegner_Spalten_2 12
#define Gegner_Spalten_3 12
#define Gegnerposition_X 20
#define Gegnerposition_Y 15
#define Gegnerbreite 40
#define Gegnerhöhe 20
#define Gegnergeschwindigkeit_X 10
#define Gegnergeschwindigkeit_Y 1
#define Schussposition_X = Fenstergröße_X/2
#define Schussposition_Y =Fenstergröße_Y-40
#define Schussbreite 4
#define Schusshöhe 4
#define Schussgeschwindigkeit 18
#define Spielerposition_X =Fenstergröße_X/2
#define Spielerposition_Y =Fenstergröße_Y-30
#define Spielerbreite 30
#define Spielerhöhe 20
#define Spielergeschwindigkeit 10
#define H_Spalten 4

#include <QtWidgets/QMainWindow>
#include <QPainter>
#include <QKeyEvent>
#include <QLabel>
#include <QTimer>
#include "ui_Space_Invaders.h"

enum Status { sichtbar, unsichtbar };
using namespace std;

//Konstruktor für die Gegner
class Gegner {
public:
	Gegner(int _x, int _y, int _w, int _h/*, int _v*/) {
		x = _x;
		y = _y;
		w = _w;
		h = _h;
		/*v = _v;*/
		st = sichtbar;
	}
	int x;
	int y;
	int w;
	int h;
	/*int v;*/
	Status st;

};

//Konstruktor für die Hindernisse
class Hindernisse {
public:
	Hindernisse(int _x1, int _y1, int _w1, int _h1) {
		x1 = _x1;
		y1 = _y1;
		w1 = _w1;
		h1 = _h1;
		st = sichtbar;
	}
	int x1;
	int y1;
	int w1;
	int h1;
	Status st;
};


class Space_Invaders : public QMainWindow
{
	Q_OBJECT

public:
	Space_Invaders(QWidget *parent = Q_NULLPTR);

private:
	Ui::Space_InvadersClass ui;
	QLabel *myLabel;

public:
	void keyPressEvent(QKeyEvent*);
	void paintEvent(QPaintEvent *);
	void Gegner_Schussfunktion();
	void Gegner_Bewegung(); //Muss in der Klasse noch eingfügt werden
	int Gegner_Getroffen(); //Muss in der Schussfunktion noch eingefügt werden
	int Spieler_Treffer();
	int Gegner_Treffer();   //Muss in der Klasse noch eingefügt werden
	int Game_Over();
	int Punkte_erhöhen();
	int Punkte_verringern();//soll durch längere Zeit und weniger Gesundheit verringert werden
	void Punkte_anzeigen(); //einfaches Label am Ende des Spiels (wird in die Gameover-Funktion eingebaut)
	int Schuss_trifft();
	void Schuss_trifft_nicht();
	void Schuss_position_Y();
	void Spielerbewegung(QKeyEvent *event);
	int Spieler_Schuss(QKeyEvent *event);

private:

	int spieler_schuss_x; //Position des Schusses auf der x-Achse
	int spieler_schuss_y;            //Position des Schusses auf der y-Achse
	int spieler_pos_x; //Position des Spielers auf der x-Achse
	int spieler_pos_y = 770;               //Position des Spielers auf der y-Achse
	int spieler_geschw_x;              //Geschwindigkeit des Spielers
	int schuss_x;                        //Position des gegnerischen Schusses auf der x-Achse
	int schuss_y;                        //Position des gegnerischen Schusses auf der y-Achse
	int gegner_geschw_x;
	int gegner_geschw_y;
	int gegner_treffer;
	int gegner_schuss_x;
	int gegner_schuss_y;
	int spieler_treffer;
	int punktestand;
	int punkte;
	int schuss_geschw_y;

public:
	QTimer * mytimer;

	Gegner *gegner[Gegner_Spalten];  //Pointer auf den Gegnerkonstruktor
	Gegner *gegner2[Gegner_Spalten_2]; //Pointer auf den Gegnerkonstruktor 2
	Gegner *gegner3[Gegner_Spalten_3]; //Pointer auf den Gegnerkonstruktor 3

	Hindernisse *hindernisse[H_Spalten];            //Pointer auf den Hindernisskonstruktor

public slots:
	void mytimerslot();
};
