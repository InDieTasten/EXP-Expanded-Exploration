#ifndef _Texture_hpp_
#define _Texture_hpp_

#include <Utilities\Logger.hpp>
#include <Assets\Asset.hpp>
#include <string>
#include <SFML\Graphics.hpp>

using namespace std;
extern void ug::log(std::string);

class Texture : public Asset
{
private:
	sf::Texture* data;

public:
	Texture(string* _id, string _path);
	~Texture();

	sf::Texture* getTexture();
	void load();
	void unload();
};

#endif // !_Texture_hpp_