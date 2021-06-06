#include "Game.h"
#include "Menu.h"

void Game::init() {

	/* Cr�er les niveaux, les menus, et les ajouter au jeu ici. */

	/* Ne pas oublier d'ajouter l'�cran qui s'affiche (�cran d'erreur) quand un �cran particulier n'est pas trouv�. */
	/* Cet �cran doit �tre associ� � Menu::NOT_FOUND dans Game::menus.                                              */

}

Screen* Game::getMenu(int id) const { 

	auto entry = menus.find(id);

	if (entry != menus.end()) {

		return entry->second;

	}

	return menus.find(Menu::NOT_FOUND)->second;

}

Screen* Game::getLevel(int id) const {

	if (id < 0 || id >= menus.size()) {

		return menus.find(Menu::NOT_FOUND)->second;

	}

	return levels[id];

}

void Game::addMenu(Screen* menu) {

	levels.push_back(menu);

}

void Game::addLevel(Screen *level) {

	levels.push_back(level);

}