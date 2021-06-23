#pragma once
#include <string>
class ImguiElementInputFloat {
	/*Cette classe repr�sente un �lement de la window 
	* ImGui represantant un input de type Float
	*/
public:
	explicit ImguiElementInputFloat(std::string const& title, float expected);

	/*Cette fonction retourne la "reference" de result
	* pour qu'elle soit rempli apr�s avec ImGui
	*/
	float& getRefFloat();

	/*Cette fonction retourne la valeur de l'input
	*/
	float getInput() const;

	/*Retourne le titre de l'input Float
	*/
	std::string getTitle() const;
	
	/*Cette fonction v�rifie si la valeur de l'inpur est
	* �gale � la valeur attendue
	*/
	bool verify() const;

	/*Pour modifier le Titre*/
	void setTitle(std::string const& newTitle);

private:
	/*La valeur ou on stocke l'input*/
	float input= 0;

	/*La valeur except�e pour gagner*/
	float expected = -9999;

	/*Titre de l'input*/
	std::string title;
};