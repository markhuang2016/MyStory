//
// Created by mark on 2020/2/15.
//

#ifndef MYSTORY_BATTLESCENE_H
#define MYSTORY_BATTLESCENE_H

#include <cocos2d.h>
USING_NS_CC;

class BattleScene :public Layer {
public:
    static Scene *createScene();

    CREATE_FUNC(BattleScene);

    virtual bool init();

    virtual void initUI();

};


#endif //MYSTORY_BATTLESCENE_H
