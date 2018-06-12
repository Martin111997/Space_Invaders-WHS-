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


	QFont labelFont;                        // Größe der Schriftart auf dem Label setzen
	labelFont.setPixelSize(14);
	myLabel->setFont(labelFont);

	//Timer 
	mytimer = new QTimer(this);
	connect(mytimer, SIGNAL(timeout()), this, SLOT(mytimerSlot()), Qt::UniqueConnection);
	mytimer->setInterval(10); //Timer wird alle 10ms erneuert => 100 Bilder pro Sekunde
	mytimer->start(); //Gibt an, wann der Timer gestartet wird

	//Gegnerkonstruktor 1                  
	for (int sp = 0; sp < Gegner_Spalten; sp++) {
		gegner[sp] = new Gegner(sp*(Fenstergröße_X / Gegner_Spalten) + 10, 100, 70, 20);	//x,y,b,h
	}

	//Gegnerkonstruktor 2
	for (int sp_1 = 0; sp_1 < Gegner_Spalten_2; sp_1++) {
		gegner2[sp_1] = new Gegner(sp_1*(Fenstergröße_X / Gegner_Spalten_2) + 10, 60, 70, 20);   //x,y,b,h
	}

	//Gegnerkonstruktor 3
	for (int sp_2 = 0; sp_2 < Gegner_Spalten_3; sp_2++) {
		gegner3[sp_2] = new Gegner(sp_2*(Fenstergröße_X / Gegner_Spalten_2) + 10, 30, 70, 20);     //x,y,b,h
	}


	//Hindernisskonstruktor
	for (int sp1 = 0; sp1 < H_Spalten; sp1++) {
		hindernisse[sp1] = new Hindernisse(sp1*(Fenstergröße_X / H_Spalten) + 95, 600, 70, 30);   //x,y,b,h
	}
}



//void Space_Invaders::Spielerbewegung(QKeyEvent *event) {
//	if (spieler_pos_x < 10)                       //verhindert das der Spieler aus dem Fenster geht, ist jetzt im KeyPressEvent
//	{
//		spieler_geschw_x = 0;
//	}
//	else if (spieler_pos_x > 990)
//	{
//		spieler_geschw_x = 0;
//	}
//
//}

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

//Erhöht die Punktzahl um 10 pro getroffenen Gegner, eventuell noch einen zeitabhängigen Wert einfügen, da sonst immer derselbe Highscore erreicht wird
int Space_Invaders::Punkte_erhöhen() {
	if (spieler_treffer++) {
		punkte += 10;
	}
	return punkte;
}

//Wenn der Zähler Spieler_Treffer() größer oder gleich drei wird wird ein Label Game over gezeigt(hoffentlich)
int Space_Invaders::Game_Over() {
	if (spieler_treffer >= 3) {


		myLabel = new QLabel(this);
		myLabel->setGeometry(10, 160, 160, 20);
		myLabel->setText("Game Over");
	}
	return spieler_treffer;
}


void Space_Invaders::mytimerslot() {

	//Prüft,ob ein Gegnerreihe 1 getroffen wurde
	for (int sp = 0; sp < Gegner_Spalten; sp++) {

		if (gegner[sp]->st == sichtbar && ((spieler_schuss_y <= (gegner[sp]->y + gegner[sp]->h)) && (spieler_schuss_x >= gegner[sp]->x) && (spieler_schuss_x <= gegner[sp]->x + gegner[sp]->h)))

		{
			gegner[sp]->st == unsichtbar;
		}
	}

	//Prüft, ob Gegnerreihe 2 getroffen wurde
	for (int sp_1 = 0; sp_1 < Gegner_Spalten_2; sp_1++) {

		if (gegner2[sp_1]->st == sichtbar && ((spieler_schuss_y <= (gegner2[sp_1]->y + gegner2[sp_1]->h)) && (spieler_schuss_x >= gegner2[sp_1]->x) && (spieler_schuss_x <= gegner2[sp_1]->x + gegner2[sp_1]->h)))

		{
			gegner2[sp_1]->st == unsichtbar;
		}
	}

	//Prüft, ob Gegnerreihe 3 getroffen wurde
	for (int sp_2 = 0; sp_2 < Gegner_Spalten_3; sp_2++) {

		if (gegner3[sp_2]->st == sichtbar && ((spieler_schuss_y <= (gegner3[sp_2]->y + gegner3[sp_2]->h)) && (spieler_schuss_x >= gegner3[sp_2]->x) && (spieler_schuss_x <= gegner3[sp_2]->x + gegner3[sp_2]->h)))

		{
			gegner3[sp_2]->st == unsichtbar;
		}
	}



	//Prüft, ob ein Hinderniss getroffen wurde
	for (int sp1 = 0; sp1 < H_Spalten; sp1++) {
		if (hindernisse[sp1]->st == sichtbar && (spieler_schuss_y <= (hindernisse[sp1]->y1 + hindernisse[sp1]->h1) && spieler_schuss_y >= hindernisse[sp1]->y1))
		{
			hindernisse[sp1]->st == unsichtbar;
		}


	}

	//Schuss löschen, wenn er das Fenster verlässt
	if (spieler_schuss_y <= 0)
	{
		delete(this);
	}


	spieler_schuss_y -= Schussgeschwindigkeit;

	repaint();
}



void Space_Invaders::keyPressEvent(QKeyEvent *event) {
	//Spieler bewegt sich nach rechts

	if ((event->key() == Qt::Key_Right) && (spieler_pos_x > 0) && (spieler_pos_x < 1170))     //!!!!!!!!!!!!!Spieler lässt sich nicht mehr bewegen, wenn er die Wand erreicht
	{
		spieler_pos_x += Spielergeschwindigkeit;
	}
	//Spieler bewegt sich nach links
	if ((event->key() == Qt::Key_Left) && (spieler_pos_x > 0) && (spieler_pos_x < 1170))    //!!!!!!!!!!!!!Spieler lässt sich nicht mehr bewegen, wenn er die Wand erreicht
	{
		spieler_pos_x -= Spielergeschwindigkeit;
	}
	//Spieler schießt
	if (event->key() == Qt::Key_Space)
	{
		spieler_schuss_y -= Schussgeschwindigkeit;
	}
	repaint();
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

	//Gegnerreihe 1 zeichnen(Spalten)
	for (int sp = 0; sp < Gegner_Spalten; sp++) {
		if (gegner[sp]->st == sichtbar) {
			p.setBrush(Qt::green);
			p.drawRect(gegner[sp]->x, gegner[sp]->y, gegner[sp]->w, gegner[sp]->h);
		}
	}

	//Gegnerreihe 2 zeichenen(Spalten)
	for (int sp_1 = 0; sp_1 < Gegner_Spalten_2; sp_1++) {
		if (gegner2[sp_1]->st == sichtbar) {
			p.setBrush(Qt::red);
			p.drawRect(gegner2[sp_1]->x, gegner2[sp_1]->y, gegner2[sp_1]->w, gegner2[sp_1]->h);
		}
	}

	//Gegnerreihe 3 zeichnen(Spalten)
	for (int sp_2 = 0; sp_2 < Gegner_Spalten_3; sp_2++) {
		if (gegner3[sp_2]->st == sichtbar) {
			p.setBrush(Qt::blue);
			p.drawRect(gegner3[sp_2]->x, gegner3[sp_2]->y, gegner3[sp_2]->w, gegner3[sp_2]->h);
		}
	}


	//Hindernisse zeichnen (Spalten)
	for (int sp1 = 0; sp1 < H_Spalten; sp1++) {

		if (hindernisse[sp1]->st == sichtbar) {
			p.setBrush(Qt::green);
			p.drawRect(hindernisse[sp1]->x1, hindernisse[sp1]->y1, hindernisse[sp1]->w1, hindernisse[sp1]->h1);
		}
	}

}