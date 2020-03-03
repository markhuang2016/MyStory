//
// Created by mark on 2020/2/18.
//

#ifndef MYSTORY_BATTLEBLOCK_H
#define MYSTORY_BATTLEBLOCK_H

#include <cocos2d.h>
USING_NS_CC;

class BattleBlock :public Node {
protected:
    Sprite *block;
public:
    CREATE_FUNC(BattleBlock);

    virtual bool init();
};


#endif //MYSTORY_BATTLEBLOCK_H
