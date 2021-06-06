#include "Game.h"
#include "Menu.h"

void Game::init() {

	/* Cr�er les niveaux, les menus, et les ajouter au jeu ici. */

	/* Ne pas oublier d'ajouter l'�cran qui s'affiche (�cran d'erreur) quand un �cran particulier n'est pas trouv�. */
	/* Cet �cran doit �tre associ� � Menu::NOT_FOUND dans Game::menus.                                              */

	auto errorScreen = std::make_unique<Screen>();
	// Ajouter les �l�ments de l'�cran d'erreur ici.
	menus[Menu::NOT_FOUND] = move(errorScreen);
	
}

Screen* Game::getMenu(int id) const { 

	auto entry = menus.find(id);

	if (entry != menus.end()) {

		return entry->second.get();

	}

	return menus.find(Menu::NOT_FOUND)->second.get();

}

Screen* Game::getLevel(int id) const {

	if (id < 0 || id >= menus.size()) {

		return menus.find(Menu::NOT_FOUND)->second.get();

	}

	return levels[id].get();

}

void Game::addMenu(std::unique_ptr<Screen> menu) {

	levels.push_back(move(menu));

}

void Game::addLevel(std::unique_ptr<Screen> level) {

	levels.push_back(move(level));

}