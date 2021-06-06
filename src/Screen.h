#pragma once
#include <SFML/Graphics.hpp>
#include "Game.h"
#include "Element.h"
#include "EventHandler.h"
#include "UpdateStrategy.h"

class Screen {

public:

	/* Affiche l'�cran.
	Cette m�thode appelle successivement les m�thodes 
	Element::render(...) de tous les �l�ments constituant 
	l'�cran.
	*/
	void render(sf::RenderWindow& window);

	/* G�re les �v�nements utilisateur sur l'�cran 
	courant.
	Comme chaque �cran doit g�rer ces �v�nements diff�remment,
	cette m�thode utilise une strat�gie h�ritant de 
	l'interface EventHandler.
	Cette strat�gie est contenue dans Screen::eventHandler.
	*/
	void handleEvent(sf::Event);

	/* G�re les mises-�-jour "spontan�es" (ne d�pendant 
	pas d'�v�nements utilisateurs) de l'�cran.
	Comme chaque �cran poss�de des processus de mise-�-jour diff�rents,
	cette m�thode utilise une strat�gie h�ritant de
	l'interface UpdateStrategy.
	Cette strat�gie est contenue dans Screen::updateStrategy.
	Cette m�thode teste �galement la condition de transition de 
	l'�cran courant vers son successeur ("condition de victoire"
	pour les niveaux).
	Dans le cas o� cette condition est v�rifi�e, cette m�thode 
	renvoie un pointeur vers l'�cran suivant.
	Dans le cas contraire, elle renvoie un pointeur vers l'�cran
	sur laquelle elle est appel�e.
	*/
	Screen* update();

private:

	/* Le jeu auquel appartient le niveau.
	*/
	Game* game;

	/* Le gestionnaire d'�v�nements utilisateur � 
	utiliser pour l'�cran
	(cf. Screen::handleEvent(...)).
	*/
	EventHandler eventHandler;

	/* La strat�gie de mise-�-jour spontan�e de 
	l'�cran 
	(cf. Screen::update()).
	*/
	UpdateStrategy updateStrategy;

	/* Les �l�ments constituant l'�cran.
	*/
	std::vector<Element> elements;

	/* La couleur de fond de l'�cran.
	*/
	sf::Color backgroundColor;

};
