#include "TileMap/entitymap.h"

#include <QFile>
#include <QtCore>

EntityMap::EntityMap(GameState *game, TileMap *map, QString ref):
    game(game), map(map)
{
    loadData(ref);
}

void EntityMap::update(double delta)
{
    x = map->getX();
    y = map->getY();

    if(!enemies.isEmpty()){
        while(enemies.firstKey() < y + map->getHeight()){
            EnemyEntry *entry = enemies.first().data();
            //TODO: Factory Constructor Pattern
            (void) entry;
            //game->getEnemyEntities().append( );//add constructed class to game
            enemies.remove(enemies.firstKey());

        }
    }

    (void) delta;
}

QJsonObject EntityMap::parseJSON(QString ref)
{
    QFile jsonFile(ref);
    if(!jsonFile.open(QFile::ReadOnly | QFile::Text)){
        qCritical() << "Unable to read File: "<< ref;
        qApp->exit(EXIT_FAILURE);
    }
    QByteArray data = jsonFile.readAll();
    QJsonDocument jsonData(QJsonDocument::fromJson(data));

    return jsonData.object();
}


void EntityMap::loadData(QString ref)
{
    json = parseJSON(ref);
    QJsonArray jsonEnemyArray = json["enemyList"].toArray();
    if(jsonEnemyArray.size() > 0){
        for(int i = 0; i < jsonEnemyArray.size(); i++){
            QJsonObject je = jsonEnemyArray[i].toObject();

            EnemyEntry entry;
            entry.enemyClass = je["enemyClassName"].toString();
            entry.polarity = je["polarity"].toInt() % 2 == 0 ?
                        WHITE : BLACK;
            entry.spawnX = je["spawnX"].toInt();
            entry.spawnY = je["spawnY"].toInt();

            QJsonArray pathList = je["paths"].toArray();
            for (int j = 0; j < pathList.size(); ++j) {
                QJsonArray path = pathList.at(j).toArray();
                entry.paths.append(Point(path.at(0).toInt(),path.at(1).toInt()));
            }

            entry.spawnRef = je["spawnRef"].toString();
            enemies.insert(je["spawnTrigger"].toInt(),
                    QSharedPointer<EnemyEntry>(&entry));
        }
    }
}


float EntityMap::getX() const
{
    return x;
}

float EntityMap::getY() const
{
    return y;
}

GameState *EntityMap::getGame()
{
    return game;
}





