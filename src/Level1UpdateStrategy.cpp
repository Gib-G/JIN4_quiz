#include "Level1UpdateStrategy.h"
#include "Screen.h"
Screen* Level1UpdateStrategy::update(Screen &screen) {

	/* V�rifier la condition de victoire du niveau 1 ici. */
	if (screen.isCompleted() ) {

	}
	return &screen;

	/* Mises-�-jour spontan�es du niveau 1 ici. */

}