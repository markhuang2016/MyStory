//
// Created by mark on 2020/2/15.
//

#ifndef MYSTORY_SCENEMANAGER_H
#define MYSTORY_SCENEMANAGER_H

#include <cocos2d.h>
#include <scenes/StartScene.h>
#include <scenes/DemoScene.h>
#include <scenes/BattleScene.h>

USING_NS_CC;

class SceneManager {
protected:
    static SceneManager *instance;

    void gotoScene(Scene *target);

public:
    static SceneManager *getInstance();

    void gotoStartScene();

    void gotoDemoScene();

    void gotoBattleScene();

};


#endif //MYSTORY_SCENEMANAGER_H
