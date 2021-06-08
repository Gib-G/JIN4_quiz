#include "Level2EventHandler.h"
#include <iostream>

void Level2EventHandler::handle(Screen& screen, sf::Event const &event, sf::RenderWindow const &window) {

	/* Gestion des �v�nements utilisateur du niveau 2 ici. */
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {

        screen.getElement(2)->setX(sf::Mouse::getPosition(window).x);
        screen.getElement(2)->setY(sf::Mouse::getPosition(window).y);

        if (screen.getElement(2)->getX() < 0 || screen.getElement(2)->getX() > (window.getSize().x - 95)) {

            screen.setCompleted(true);
            std::cout << "YES\n";

        }
        if (screen.getElement(2)->getY() < 0 || screen.getElement(2)->getY() > (window.getSize().y - 95)) {

            screen.setCompleted(true);
            std::cout << "YES\n";

        }

    }

}
