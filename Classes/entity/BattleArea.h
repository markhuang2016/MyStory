//
// Created by mark on 2020/2/18.
//

#ifndef MYSTORY_BATTLEAREA_H
#define MYSTORY_BATTLEAREA_H

#include <cocos2d.h>
USING_NS_CC;

class BattleArea :public Node {
public:
    int row;
    int column;
public:
    BattleArea();

    virtual ~BattleArea();

    virtual bool init(Vec2 vec2);

    static BattleArea *create(Vec2 vec2);
};


#endif //MYSTORY_BATTLEAREA_H
