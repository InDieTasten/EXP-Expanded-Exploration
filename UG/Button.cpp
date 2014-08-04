#include "Button.hpp"

//CONSTRUCTORS

//DESTRUCTORS

//METHODS
void Button::Setup()
{
    mouseHover = false;
}
void Button::Update(DataBank* _dataLink, int _x, int _y)
{
    if(!mouseHover)
    {
        rect.setPosition((float)_x,(float)_y);
        rect.setSize(sf::Vector2f((float)Width,(float)Height));
        rect.setFillColor(sf::Color(10,80,10,140));
        rect.setOutlineThickness(1.0f);
        rect.setOutlineColor(sf::Color(160,160,160,200));

        displayText.setColor(sf::Color(120,120,120,200));
    }
    else
    {
        if(isActive)
        {
            rect.setPosition((float)_x,(float)_y);
            rect.setSize(sf::Vector2f((float)Width,(float)Height));
            rect.setFillColor(sf::Color(50,50,50,200));
            rect.setOutlineThickness(1.0f);
            rect.setOutlineColor(sf::Color(0,255,0,255));
        }
        else
        {
            rect.setPosition((float)_x,(float)_y);
            rect.setSize(sf::Vector2f((float)Width,(float)Height));
            rect.setFillColor(sf::Color(50,50,50,200));
            rect.setOutlineThickness(1.0f);
            rect.setOutlineColor(sf::Color(200,200,200,255));
        }
        displayText.setColor(sf::Color(200,200,200,200));
    }
    displayText.setString(Text);
    displayText.setFont(*_dataLink->FontGet("$_menuTitle"));
    displayText.setScale(1.0,1.0);
    displayText.setOrigin(floorf(displayText.getLocalBounds().width/2), floorf(displayText.getLocalBounds().height/2));
    displayText.setPosition(floorf(_x+(Width/2.0)),floorf(_y+(Height/2.0)));
    displayText.setCharacterSize(12);
}
void Button::Render(DataBank* _dataLink)
{
    _dataLink->renderWindow->draw(rect);
    _dataLink->renderWindow->draw(displayText);
}
void Button::handleEvent(DataBank* datalink, sf::Event* _event, int _x, int _y, std::string _id)
{
    if(isActive)
    {
        if(_event->type == sf::Event::MouseMoved)
        {
            int mouseX = sf::Mouse::getPosition().x;
            int mouseY = sf::Mouse::getPosition().y;
            if(mouseX >= _x && mouseX <= _x+Width)
            {
                if(mouseY >= _y && mouseY <= _y+Height)
                {
                    if(!mouseHover)
                    {
                        std::list<std::string> x;
                        x.push_back("button_entered");
                        x.push_back(_id);
                        datalink->pushEvent(x);
                        mouseHover = true;
                    }
                }
                else
                {
                    if(mouseHover)
                    {
                        std::list<std::string> x;
                        x.push_back("button_leave");
                        x.push_back(_id);
                        datalink->pushEvent(x);
                        mouseHover = false;
                    }
                }
            }
        }
        if(_event->type == sf::Event::MouseButtonReleased && isActive)
        {
            if(mouseHover)
            {
                std::list<std::string> x;
                x.push_back("button_released");
                x.push_back(_id);
                datalink->pushEvent(x);
            }
        }
        if(_event->type == sf::Event::MouseButtonPressed && isActive)
        {
            if(mouseHover)
            {
                std::list<std::string> x;
                x.push_back("button_pressed");
                x.push_back(_id);
                datalink->pushEvent(x);
            }
        }
    }
}
