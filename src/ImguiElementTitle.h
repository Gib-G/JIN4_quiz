#pragma once
#include <string>
class ImguiElementTitle{
	/*Cette classe g�re le titre de la fen�tre ImGui*/
public:
	explicit ImguiElementTitle(std::string const & title);
	std::string getTitle();
	void setTitle(std::string const& newTitle);
private:
	std::string title;
};