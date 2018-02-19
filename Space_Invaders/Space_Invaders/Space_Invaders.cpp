
#include "Space_Invaders.h"
#include "Schuss.h"
#include "Gegner.h"
#include "Eigenes_Raumschiff.h"
#include "Barrieren.h"
#include <Windows.h>

Space_Invaders::Space_Invaders(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	this->setFixedSize(Windowsize_X, Windowsize_Y); //Festlegen der Fenstergröße
	this->setWindowTitle("Space Invaders");

	//Label erstellen
	myLabel = new QLabel(this);
	myLabel->setGeometry(10, 300, 300, 30); //x,y,w,h

	//Schriftgröße festlegen
	QFont labelFont;
	labelFont.setPixelSize(18);
	myLabel->setFont(labelFont); //Einfügen der Schriftgröße in das neue Label

	//Timer erstellen
	myTimer = new QTimer(this);
	connect(myTimer, SIGNAL(timeout()), this, SLOT(myTimerSlot()), Qt::UniqueConnection); //verbinden des Timers mit der Timerfunktion
	myTimer->setInterval(16); //alle 16 ms wird der Timer neu gestartet (entspricht 62,5 Bildern pro Sekunde)
	myTimer->start(500); //Start des Timers nach 0,5s
}
//Tastaturbelegung
void Space_Invaders::TastaturEvent(QKeyEvent *event) {

	//Schiff nach links bewegen
	if (event->key() == Qt::Key_Left) {
		(Schiff_X -= Shipspeed) && (Schussposition_X-= Shipspeed);
	}
	//Schiff nach rechts bewegen
	if (event->key() == Qt::Key_Right) {
		(Schiff_X += Shipspeed) && (Schussposition_X+=Shipspeed);
	}
	//Einen Schuss abfeuern
	if (event->key() == Qt::Key_Space) {
		Schuss -= Shootingspeed;
	}
	//Gegner wird getroffen
	if (((Enemyposition_X-15)<Schussposition_X)
		&&(Schussposition_X<(Enemyposition_X+15))
		&&((Enemyposition_Y-15)>Schussposition_Y)
		&& (Schussposition_Y < (Enemyposition_Y + 15))) {
		Enemy = unsichtbar;
	}                         //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Enemy noch nicht definiert

	//Definition eines Treffers des eigenen Raumschiffs
	if (((Schiff_X - 15) < Gegner_Schuss_X)
		&& (Gegner_Schuss_X< (Schiff_X + 15)) 
		&& ((Schiff_Y - 40) < Gegner_Schuss_Y)
		&& (Gegner_Schuss_Y< Windowsize_Y)) { Treffer++; }

	//Zähler für die Treffer des eigenen Raumschiffs
	do { Treffer++; }
	while (Treffer < 3);

	//Gameover prüfen
	if (Treffer = 3) {
		myLabel->setText("Game Over");
		Sleep(3000);
		exit(0);
	}                                                        //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! Label soll über den Spielbildschirm gehen

	repaint();
}
//Zeitäbhängige Events
void Space_Invaders::myTimerSlot() {
	//neue Position des Schusses
	Schussposition_Y -= Shootingspeed;

	if (Schussposition_Y < 0) {
		delete (this);
	}
	
	repaint();
}
void Space_Invaders::paintEvent(QPaintEvent*event) {
	QPainter p(this);
	//Raumschiff zeichnen
	p.setPen(Qt::black);
	p.setBrush(Qt::red);
	p.drawRect(Schiff_X, Schiff_Y - Shipsize_Y, Shipsize_X - 15, Shipsize_Y);

	//Schüsse zeichnen
	p.setBrush(Qt::blue);
	p.drawEllipse(Schussposition_X, Schussposition_Y, Shootingsize_X, Shootingsize_Y);

	//Gegner zeichnen
	p.setPen(Qt::black);
	p.setBrush(Qt::green);
	p.drawRect(Enemyposition_X, Enemyposition_Y, Enemysize_X, Enemysize_Y);
}
