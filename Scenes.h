#ifndef SCENES_H
#define SCENES_H
#include "Scene.h"
#include <map>
class Scenes {
public:
    static void addScene(Scene* s, std::string n);
    static Scene* getCurrScene();
    static void setScene(std::string n);
private:
    static std::string curr_string;
    static std::map<std::string,Scene*> scenes;
};

#endif