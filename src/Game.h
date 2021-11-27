#pragma once
#include <map>
#include <memory>
#include <vector>
#include <SFML/Graphics.hpp>

class Screen;

class Game {

public:

	/* Initialise le jeu.
	Tous les niveaux et les menus du jeu sont
	construits dans cette m�thode.
	*/
	void init();

	/* Permet de r�cup�rer la fen�tre SFML 
	utilis�e par le jeu.
	*/
	sf::RenderWindow* getWindow() const;

	/* Permet de r�cup�rer les menu associ� � l'indentifiant
	id dans Game::menus.
	*/
	Screen* getMenu(const int id) const;

	/* Permet de r�cup�rer le niveau courant
	(Game::levels[Game::currentLevel]).
	*/
	Screen* getCurrentLevel() const;

	/* Ajoute un menu au jeu.
	* Utilis� dans la m�thode Game::init().
	*/
	void addMenu(std::unique_ptr<Screen> menu);

	/* Ajoute un niveau au jeu.
	* Utilis� dans la m�thode Game::init().
	*/
	void addLevel(std::unique_ptr<Screen> level);

	/* Incr�mente l'indice du niveau courant.
	Permet de passer au niveau suivant.
	*/
	void nextLevel();

private:

	/* La fen�tre SFML utilis�e par 
	le jeu.
	*/
	std::unique_ptr<sf::RenderWindow> window;

	/* Les menus du jeu.
	Les menus sont des �crans comme les
	niveaux.
	*/
	std::map<int, std::unique_ptr<Screen>> menus;

	/* Les niveaux du jeu.
	Les niveaux sont des �crans.
	Les niveaux sont rang�s dans levels
	par ordre de succession.
	Ainsi, levels[0] correspond au premier niveau, levels[1] au deuxi�me,
	et ainsi de suite.
	*/
	std::vector<std::unique_ptr<Screen>> levels;

	/* L'indice du niveau courrant dans levels.
	*/
	int currentLevel;

};
