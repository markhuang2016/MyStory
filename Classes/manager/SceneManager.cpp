//
// Created by mark on 2020/2/15.
//

#include "SceneManager.h"
SceneManager* SceneManager::instance = nullptr;

SceneManager* SceneManager::getInstance() {
    if (instance == nullptr) {
        instance = new SceneManager();
    }
    return instance;
}

void SceneManager::gotoStartScene() {
    gotoScene(StartScene::createScene());
}

void SceneManager::gotoDemoScene() {
    gotoScene (DemoScene::createScene());
}

void SceneManager::gotoBattleScene() {
    gotoScene(BattleScene::createScene());
}

void SceneManager::gotoScene(Scene *target) {
    Director::getInstance()->replaceScene(target);
}


