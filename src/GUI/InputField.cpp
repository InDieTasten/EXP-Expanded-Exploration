#include <GUI\InputField.hpp>

InputField::InputField()
{
	type = ElementType::InputField;
	EXP::log("[Info]InputField has been constructed: " + utils::tostring(this));

	
	
}
InputField::~InputField()
{
	EXP::log("[Info]InputField has been destructed: " + utils::tostring(this));
}

void InputField::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::RectangleShape x(sf::Vector2f(300,300));
	

	sf::Text text(content, font);

	x.setFillColor(sf::Color::Blue);


	target.draw(x);
}
void InputField::handleEvent(sf::Event* _event)
{
	//WORK
}

void InputField::setWidth(int _width)
{
	width = _width;
}
void InputField::setHeight(int _height)
{
	height = _height;
}
void InputField::setContent(std::string _content)
{
	content = _content;
}
int InputField::getWidth()
{
	return width;
}
int InputField::getHeight()
{
	return height;
}
std::string InputField::getContent()
{
	return content;
}
