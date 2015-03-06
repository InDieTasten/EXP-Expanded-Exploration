//includes
#include <Utilities/VERSION.hpp>
#include <Utilities/Logger.hpp>
#include <iostream>
#include <conio.h>
#include <SFML\System.hpp>
#include <SFML\Graphics.hpp>

#include <Core\Databank.hpp>

extern void ug::log(std::string);

extern "C" {
#include <lua.h>
#include <lualib.h>
#include <lauxlib.h>
}



int main(int argc, char *argv[])
{
	ug::log("Game is launching");
	sf::RenderWindow App(sf::VideoMode(1280, 720, 32), VERSION::name + " " + VERSION::version, sf::Style::Titlebar | sf::Style::Resize | sf::Style::Close);
	
	Databank* databank = new Databank(&App);

	while (App.isOpen())
	{
		sf::Event Event;
		while (App.pollEvent(Event))
		{
			
		}
	}

	ug::log("Game is done");
	getchar();
	return EXIT_SUCCESS;
}
