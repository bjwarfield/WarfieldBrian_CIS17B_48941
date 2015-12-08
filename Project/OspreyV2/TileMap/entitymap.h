#ifndef ENTITYMAP_H
#define ENTITYMAP_H

#include "TileMap/tilemap.h"
#include "GameState/gamestate.h"
#include "Entity/entity.h"
#include "Entity/enemyentity.h"


struct EnemyEntry{
    int             spawnTrigger;
    QString         enemyClass;
    polarType       polarity;
    int             spawnX;
    int             spawnY;
    QVector<Point>  paths;
    QString         spawnRef;
};

class EntityMap
{
public:
    EntityMap(GameState *game, TileMap *map, QString ref);

    void update(double delta);

    float getX() const;
    float getY() const;
    GameState *getGame();
    int getMapHeight() const { return map->getHeight(); }
    int getMapWidth() const { return map->getWidth(); }


private:
    GameState *game;
    TileMap *map;
    float x;
    float y;
    QMultiMap<int, QSharedPointer<EnemyEntry> > enemies;
    QJsonObject json;

    QJsonObject parseJSON(QString ref);
    void loadData(QString ref);


};


#endif // ENTITYMAP_H
