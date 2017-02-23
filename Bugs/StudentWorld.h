#ifndef STUDENTWORLD_H_
#define STUDENTWORLD_H_

#include "GameWorld.h"
#include "GameConstants.h"
#include "Actor.h"
#include <list>
#include <vector>
#include <string>

using namespace std;
// Students:  Add code to this file, StudentWorld.cpp, Actor.h, and Actor.cpp

class StudentWorld : public GameWorld
{
public:
    StudentWorld(std::string assetDir);

    virtual int init();

    virtual int move();

    virtual void cleanUp();
    
    ~StudentWorld();

    void displayGameText();
    std::string formatGameText(int ticks, int antsAnt0, int antsAnt1, int antsAnt2, int antsAnt3, int winningAntNumber);
    
    int getCurrentTicks() const;
    void updateTicks();
    int getWinningAntNumber();
    bool checkForCompilerError(Compiler* c);
    bool loadFieldFile(Compiler* c0, Compiler* c1, Compiler* c2, Compiler* c3);

    void removeObjectFromSimulation(Actor* object, int x, int y);
    list<Actor*>& getObjectsAt(int x, int y);
    
    bool hasPebbleAt(int x, int y, Actor::Direction curr);
    int consumableFood(int x, int y, int units);   //returns how much food is in the square that can be eaten by a specific insect (Ants: 100, Grasshoppers: 200)
    
    //Food
    int totalFood(int x, int y);
    Actor* getFoodObject(int x, int y);
    void addFoodToSquare(int x, int y);
    
    //Insect
    void becomeAdultGrassHopper(int x, int y);
    void bite(int strength, int x, int y, Insect* biter);
    void giveBirthToAnt(int x, int y, Compiler* c, int imageID);
    
    //Deterrents
    void harmInsect(int x, int y, bool isPool);
    
    void emitPheromone(int x, int y, int imageID, int colonyNumber);
    
private:
    int m_ticks;
    int m_numberOfAnthills;
    Anthill* m_anthill[4];
    list<Actor*> m_container[64][64];
};

#endif // STUDENTWORLD_H_
