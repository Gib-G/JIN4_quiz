#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>
#include <vector>
#include "EventHandler.h"

class Element {

public:

	explicit Element(const float x, const float y, std::string const &name);
	virtual ~Element() = default;

	float getX() const;
	float getY() const;
	void setX(float X);
	void setY(float Y);

	void setName(std::string const& name);

	std::string getName() const;

	/* Affiche l'�l�ment.
	*/
	virtual void render(sf::RenderWindow& window) = 0;

	virtual bool verify() = 0;

	/* Permet de savoir si le point de coordonn�es
	(x, y, z) se trouve dans l'�l�ment.
	Pour les �l�ments 2D, la coordonn�e z est inutile.
	*/
	virtual bool contains(const float x, const float y) const;

	void setAngle(const float angle);

	std::vector<std::shared_ptr<EventHandler>> getEventHandler() const;

protected:

	/* Les coordonn�es de l'�l�ment.
	*/
	float x;
	float y;

	/* Le nom de l'�l�ment.
	*/
	std::string name;

	float angle = 0;

	/* Le gestionnaire d'�v�nements utilisateur �
	utiliser pour l'�cran
	(cf. Screen::handleEvent(...)).
	*/
	std::vector<std::shared_ptr<EventHandler>> eventHandler;

};

