//
// Created by mark on 2020/2/15.
//

#include <component/ReturnButton.h>
#include "BattleScene.h"
bool BattleScene::init() {

    if (Layer::init() == false) {
        return false;
    }

    initUI();

    return true;
}

Scene* BattleScene::createScene() {
    auto scene = Scene::create();
    auto layer = BattleScene::create();
    scene->addChild(layer);
    return scene;
}

void BattleScene::initUI() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    auto back = Sprite::create("battleBack.png");
    back->setAnchorPoint(Vec2(0.5, 0.5));
    back->setPosition(visibleSize / 2);
    addChild(back);

    addChild(ReturnButton::create());
}