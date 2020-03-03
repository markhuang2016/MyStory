//
// Created by mark on 2020/2/14.
//

#include "StartScene.h"
#include <constant/FontConstant.h>
#include <manager/SceneManager.h>

StartScene::StartScene() : menu(nullptr) {

}

StartScene::~StartScene() {

}

Scene* StartScene::createScene() {
    Scene* scene = Scene::create();
    auto layer = StartScene::create();
    scene->addChild(layer);
    return scene;
}

bool StartScene::init() {
    if (Layer::init() == false) {
        return false;
    }

    initUI();

    return true;
}

void StartScene::initUI() {
    auto menu = Menu::create();
    auto visibleSize = Director::getInstance()->getVisibleSize();

    auto title = CCLabelTTF::create("你的故事", fontPath, 60);
    title->setPosition(Vec2(visibleSize.width / 2, visibleSize.height - visibleSize.height / 4));
    addChild(title);

    auto slogan = CCLabelTTF::create("以吾之努力，成就你的故事", fontPath, 20);
    slogan->setPosition(Vec2(visibleSize.width / 2, visibleSize.height * 0.7));
    addChild(slogan);

    auto start = MenuItemLabel::create(CCLabelTTF::create("开始游戏", fontPath, 30));
    start->setColor(Color3B::MAGENTA);

    menu->addChild(start);

    auto demo = MenuItemLabel::create(CCLabelTTF::create("测试场景", fontPath, 30));
    demo->setCallback([](Ref *ref) {
        SceneManager::getInstance()->gotoDemoScene();
    });
    menu->addChild(demo);

    auto battle = MenuItemLabel::create(CCLabelTTF::create("战斗场景", fontPath, 30));
    battle->setCallback([](Ref *ref) {
        SceneManager::getInstance()->gotoBattleScene();
    });
    menu->addChild(battle);

    auto exit = MenuItemLabel::create(CCLabelTTF::create("退出游戏", fontPath, 30));
    exit->setCallback([](Ref *ref) {
        Director::getInstance()->end();
    });
    menu->addChild(exit);


    menu->setPosition(visibleSize / 2);
    menu->alignItemsVertically();
    addChild(menu);

}

