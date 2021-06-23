#pragma once
#include "Element.h"
#include <SFML/Graphics/Font.hpp>
#include <SFML/Graphics/Text.hpp>
#include <pugixml.hpp>

/* Cette classe repr�sente les �l�ments textuels d'un �cran.
*/
class Text : public Element {

public:

	explicit Text(pugi::xml_node const &node);

	explicit Text(const float x, const float y, std::string const &name, std::string const &content, sf::Font const &font, const int characterSize, sf::Color const &color, sf::Text::Style const &style);

	void render(sf::RenderWindow& window) override;

	bool verify() override { return false; };

	bool contains(const float x, const float y) const override;

private:

	sf::Text text;

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