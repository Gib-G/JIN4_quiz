#pragma once
#include "EventHandler.h"

class CutToWinOnClickHandleEvent : public EventHandler {
	/*Cette strategie concerne les �l�ments qui doivent �tre coup� de l'�cran pour gagner
	* Comme le niveau ou on doit d�placer le carr� en dehors de l'�cran.
	*/
public:

	void handle(std::unique_ptr<Element>& element, Screen &screen, sf::Event const &event, sf::RenderWindow const &window) override;

};