#include "Scenes.h"

std::map<std::string,Scene*> Scenes::scenes;
std::string Scenes::curr_string;

void Scenes::setScene(std::string n){
    curr_string = n;
}

Scene* Scenes::getCurrScene(){
    return scenes[curr_string];
}

void Scenes::addScene(Scene *s, std::string n){
    scenes[n] = s;
}