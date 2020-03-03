//
// Created by mark on 2020/2/18.
//

#include "BattleBlock.h"
bool BattleBlock::init() {
    if (Node::init() == false) {
        return false;
    }

    block = Sprite::create("block.png");
    addChild(block);
    auto listener = EventListenerTouchOneByOne::create();
    listener->onTouchBegan = [&](Touch *touch, Event *event) {
        auto target = static_cast<Sprite *>(event->getCurrentTarget());
        auto pointInNode = target->convertToNodeSpace(touch->getLocation());
        auto size = target->getContentSize();
        Rect rect = Rect(0, 0, size.width, size.height);
        if (rect.containsPoint(pointInNode)) {
            target->setOpacity(180);
            return true;
        }
        return false;
    };

    listener->onTouchMoved=[=](Touch *touch, Event *event){
        auto target = static_cast<Sprite *>(event->getCurrentTarget());

//        target->setPosition(target->getPosition() + touch->getDelta());
        auto TarPos = target->getPosition();
        CCLOG("TarPos.x:%d,Tarpos.y:%d",TarPos.x,TarPos.y);
        auto touchDel = touch->getDelta();
        CCLOG("TouchDel.x:%d,Touchdel.y:%d",touchDel.x,touchDel.y);

        auto touchPos = touch->getLocation();
        CCLOG("Touchpos.x:%d,Touchpox.y:%d",touchPos.x,touchPos.y);
        auto touchLocInNode=convertToNodeSpace(touch->getLocation());
        auto pos = Director::getInstance()->convertToGL(target->getPosition() + touch->getDelta());
        CCLOG("pos.x:%d,pox.y:%d",pos.x,pos.y);
        target->setPosition(touchLocInNode);
//        return true;
    };

    Director::getInstance()->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, block);

    return true;
}