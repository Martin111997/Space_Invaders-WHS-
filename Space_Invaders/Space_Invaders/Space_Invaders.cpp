#include "Space_Invaders.h"

using namespace std;

Space_Invaders::Space_Invaders(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setFixedSize(Fenstergröße_X, Fenstergröße_Y); //Größe des MainWindow setzten
	this->setWindowTitle("Space_Invaders");             //Fenstertitel

														//---Label----
	myLabel = new QLabel(this);
	myLabel->setGeometry(10, 160, 160, 20); //x,y,w,h

											// Größe der Schriftart auf dem Label setzen										
	QFont labelFont;
	labelFont.setPixelSize(14);
	myLabel->setFont(labelFont);

	//Timer 
	mytimer = new QTimer(this);
	connect(mytimer, SIGNAL(timeout()), this, SLOT(mytimerSlot()), Qt::UniqueConnection);
	mytimer->setInterval(10); //Timer wird alle 17ms erneuert => 60 Bilder pro Sekunde
	mytimer->start(); //Gibt an, wann der Timer gestartet wird

	//Gegnerkonstruktor                   
	for (int sp = 0; sp < Gegner_Spalten; sp++) {
		for (int ze = 0; ze < Gegner_Zeilen; ze++) {
			gegner[sp][ze] = new Gegner(sp*Fenstergröße_X / Gegner_Spalten, 100, Fenstergröße_X / Gegner_Spalten - 10, 20);
		}
	}


	//Hindernisskonstruktor
	for (int sp1 = 0; sp1 < H_Spalten; sp1++) {
		hindernisse[sp1] = new Hindernisse(sp1*Fenstergröße_X / H_Spalten, 600, 70, 30);
	}
}



void Space_Invaders::Spielerbewegung(QKeyEvent *event) {
	if (spieler_pos_x < 10)                       //verhindert das der Spieler aus dem Fenster geht 
	{
		spieler_geschw_x = 0;
	}
	else if (spieler_pos_x > 990)
	{
		spieler_geschw_x = 0;
	}

}

//Random Funktion, um zufälligen Schuss des Gegners auszulösen
void Space_Invaders::Gegner_Schussfunktion() {

}

//Erhöht den Zähler spieler_treffer, wenn dieser getroffen wird
int Space_Invaders::Spieler_Treffer() {
	if ((gegner_schuss_x > (spieler_pos_x - 15)) && (gegner_schuss_x < (spieler_pos_x + 15)) && (gegner_schuss_y > 970)) {
		spieler_treffer++;
	}
	return spieler_treffer;

}

//Erhöht die Punktzahl um 10 pro getroffenen Gegner
int Space_Invaders::Punkte_erhöhen() {
	if (spieler_treffer++) {
		punkte += 10;
	}
	return punkte;
}

//Wenn der Zähler Spieler_Treffer() größer oder gleich drei wird wird ein Label Game over gezeigt
int Space_Invaders::Game_Over() {
	if (spieler_treffer >= 3) {


		myLabel = new QLabel(this);
		myLabel->setGeometry(10, 160, 160, 20);
		myLabel->setText("Game Over");
	}
	return spieler_treffer;
}


void Space_Invaders::mytimerslot() {

	//Prüft,ob ein Gegner getroffen wurde
	for (int sp = 0; sp < Gegner_Spalten; sp++) {
		for (int ze = 0; ze < Gegner_Spalten; ze++) {
			if (gegner[sp][ze]->st == sichtbar && ((spieler_schuss_y <= (gegner[sp][ze]->y + gegner[sp][ze]->h)) && (spieler_schuss_x >= gegner[sp][ze]->x) && (spieler_schuss_x <= gegner[sp][ze]->x + gegner[sp][ze]->h)))

			{
				gegner[sp][ze]->st == unsichtbar;
			}
		}




		//Prüft, ob ein Hinderniss getroffen wurde
		for (int sp1 = 0; sp1 < H_Spalten; sp1++) {
			if (hindernisse[sp1]->st == sichtbar && (spieler_schuss_y <= (hindernisse[sp1]->y1 + hindernisse[sp1]->h1) && spieler_schuss_y >= hindernisse[sp1]->y1))
			{
				hindernisse[sp1]->st == unsichtbar;
			}

			repaint();
		}
		//Schuss löschen, wenn er das Fenster verlässt
		if (spieler_schuss_y <= 0)
		{
			delete(this);
		}

		//Spielerbewegung stoppen, wenn die Fensterränder erreicht werden
		if (spieler_pos_x <= 0) { spieler_geschw_x = 0; }
		else if (spieler_pos_x >= 1170) { spieler_geschw_x = 0; }


		spieler_pos_x += spieler_geschw_x;
		spieler_schuss_y -= Schussgeschwindigkeit;


	}
	repaint();
}

void Space_Invaders::keyPressEvent(QKeyEvent *event) {
	//Spieler bewegt sich nach rechts
	if (event->key() == Qt::Key_Right)
	{
		spieler_pos_x += Spielergeschwindigkeit;
	}
	//Spieler bewegt sich nach links
	if (event->key() == Qt::Key_Left)
	{
		spieler_pos_x -= Spielergeschwindigkeit;
	}
	//Spieler schießt
	if (event->key() == Qt::Key_Space)
	{
		spieler_schuss_y -= Schussgeschwindigkeit;
	}
}

void Space_Invaders::paintEvent(QPaintEvent *event) {

	QPainter p(this);
	//Spieler zeichnen
	p.setPen(Qt::black);
	p.setBrush(Qt::black);
	p.drawRect(spieler_pos_x, spieler_pos_y, Spielerhöhe, Spielerbreite);

	//Schuss zeichnen
	p.setPen(Qt::red);
	p.setBrush(Qt::red);
	p.drawRect(spieler_schuss_x, spieler_schuss_y, Schussbreite, Schusshöhe);

	//Gegner zeichnen(Spalten)
	for (int sp = 0; sp < Gegner_Spalten; sp++) {
		for (int ze = 0; ze < Gegner_Zeilen; ze++) {

			if (gegner[sp][ze]->st == sichtbar) {
				p.setBrush(Qt::green);
				p.drawRect(gegner[sp][ze]->x, gegner[sp][ze]->y, gegner[sp][ze]->w, gegner[sp][ze]->h);
			}
		}
	}



	//Hindernisse zeichnen (Spalten)
	for (int sp1 = 0; sp1 < H_Spalten; sp1++) {

		if (hindernisse[sp1]->st == sichtbar) {
			p.setBrush(Qt::green);
			p.drawRect(hindernisse[sp1]->x1, hindernisse[sp1]->y1, hindernisse[sp1]->w1, hindernisse[sp1]->h1);
		}
	}
	repaint();
}