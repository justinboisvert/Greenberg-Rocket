#include "GSWindow.h"

GSWindow::GSWindow() : sf::RenderWindow(sf::VideoMode(850,600),"Greenberg Rocket"){
    Scenes::addScene(new Menu(), "menu");
    Scenes::addScene(new Game(), "game");
    Scenes::setScene("menu");
    setFramerateLimit(60);
    while(isOpen()){
        sf::Clock clock;
        sf::Event event;
        while(pollEvent(event)){
            if(event.type == sf::Event::Closed){
                close();
            }
            Scenes::getCurrScene()->pollEvent(event);
            }
        sf::Vector2<int> mousec = sf::Mouse::getPosition(*this);
        Scenes::getCurrScene()->mouseCoords = mousec;
        clear(sf::Color(0,0,0));
        Scenes::getCurrScene()->update(clock.getElapsedTime().asSeconds());

        Scenes::getCurrScene()->display();
        sf::Sprite s(Scenes::getCurrScene()->getTexture());
        draw(s);
        display();
    }
}



int main(int argc, char* argv[]){
    new GSWindow();
    return 0;
}