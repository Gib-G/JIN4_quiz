#pragma once
#include "Element.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>

/* Cette classe repr�sente les �l�ments textuels d'un �cran.
*/
class Text : public Element {

public:

	explicit Text(float x, float y, std::string name, std::string content, sf::Font font, int characterSize, sf::Color color, sf::Text::Style style);

	void render(sf::RenderWindow& window) override;

	bool contains(const float x, const float y) const override;

private:

	/* Le contenu textuel de l'�l�ment.
	*/
	std::string content;

	/* La police d'�criture.
	*/
	sf::Font font;

	/* La taille d'�criture.
	*/
	int size;

	/* La couleur d'�criture.
	*/
	sf::Color color;

	/* La d�coration textuelle (gras, soulign�...)
	*/
	sf::Text::Style style;

};