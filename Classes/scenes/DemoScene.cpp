//
// Created by mark on 2020/2/15.
//

#include "DemoScene.h"
#include <ui/CocosGUI.h>
#include <constant/FontConstant.h>
#include <component/ReturnButton.h>
#include <entity/BattleBlock.h>
#include <entity/BattleArea.h>

DemoScene::DemoScene() {

}

DemoScene::~DemoScene() {

}

bool DemoScene::init() {
    if (Layer::init() == false) {
        return false;
    }

    initUI();

    return true;
}

Scene* DemoScene::createScene() {
    auto scene = Scene::create();
    auto layer = DemoScene::create();
    scene->addChild(layer);
    return scene;
}

void DemoScene::initUI() {
    auto visibleSize = Director::getInstance()->getVisibleSize();
    addChild(ReturnButton::create());
//
//    auto block = BattleBlock::create();
//    block->setPosition(visibleSize / 2);
//    addChild(block);
//
//    auto block2 = BattleBlock::create();
//    block2->setAnchorPoint(Vec2(0, 0));
//    block2->setPosition(visibleSize / 2);
//    block2->setScale(2);
//    addChild(block2);

//    auto node = Node::create();
//    auto block = BattleBlock::create();
//    node->addChild(block);
//    node->setPosition(visibleSize / 2);
//    addChild(node);

    auto battle = BattleArea::create(Vec2(8, 3));
    battle->setAnchorPoint(Vec2(0.5, 0.5));
    battle->setPosition(visibleSize/2);
    addChild(battle);

    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *event) {
        auto target = static_cast<BattleArea *>(event->getCurrentTarget());
        auto pointInNode = target->convertToNodeSpace(touch->getLocation());
        auto size = target->getContentSize();
        Rect rect = Rect(0, 0, size.width, size.height);
        if (rect.containsPoint(pointInNode)) {
            CCLOG("column:%d,row:%d", target->column, target->row);
            return true;
        }
        return false;
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, battle);



}
