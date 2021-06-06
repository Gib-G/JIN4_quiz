#include "Game.h"
#include "Menu.h"
#include "Screen.h"
#include "UpdateStrategy.h"
#include "EventHandler.h"

void Game::init() {

	/* Cr�er les niveaux, les menus, et les ajouter au jeu ici. */

	/* Ne pas oublier d'ajouter l'�cran qui s'affiche (�cran d'erreur) quand un �cran particulier n'est pas trouv�. */
	/* Cet �cran doit �tre associ� � Menu::NOT_FOUND dans Game::menus.                                              */

	auto errorScreen = std::make_unique<Screen>();
	// Ajouter les �l�ments de l'�cran d'erreur ici.
	menus[Menu::NOT_FOUND] = std::move(errorScreen);

	/* Premier niveau */
	auto level1 = std::make_unique<Screen>();

	//level1->addElement(std::move(std::make))

	levels.push_back(std::move(level1));

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

	levels.push_back(std::move(menu));

}

void Game::addLevel(std::unique_ptr<Screen> level) {

	levels.push_back(std::move(level));

}