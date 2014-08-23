#ifndef _CodeBox_hpp_
#define _CodeBox_hpp_

#include <string.h>
#include "DataBank.hpp"
#include <iostream>
#include <list>

class CodeBox
{
    //MEMBERS
private:
    sf::Text text1;
    char tmp;
    sf::RectangleShape rect;
    sf::RectangleShape c;
    int ViewY;
    int ViewX;
    int cursor_line;
    int cursor_char;
public:
    //std::string text;
    std::list<std::string> text;
    int X;
    int Y;
    int Height;
    int Width;
    float Textsize;
    bool isActive;
    int enter;

    //CONSTRUCTORS

    //DESTRUCTORS

    //METHODS
    void Setup();

    void Update(DataBank* _dataLink, int _x, int _y, std::string _id);

    void Render(DataBank* _dataLink, int _x, int _y, std::string _id);
    void handleEvent(DataBank* _dataLink, sf::Event* _event, int _x, int _y, std::string _id);

    char getInput(int Type,sf::Event* _event);

};

#endif
