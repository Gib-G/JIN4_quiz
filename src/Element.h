#pragma once
#include <SFML/Graphics/RenderWindow.hpp>
#include <string>

class Element {

public:

	Element(float x, float y, std::string name);
	virtual ~Element() = default;

	float getX() const;
	float getY() const;
	void setX(float X);
	void setY(float Y);

	/* Affiche l'�l�ment.
	*/
	virtual void render(sf::RenderWindow& window) = 0;

	/* Permet de savoir si le point de coordonn�es
	(x, y, z) se trouve dans l'�l�ment.
	Pour les �l�ments 2D, la coordonn�e z est inutile.
	*/
	virtual bool contains(const float x, const float y) const = 0;

protected:

	/* Les coordonn�es de l'�l�ment.
	*/
	float x;
	float y;

	/* Le nom de l'�l�ment.
	*/
	std::string name;

};

