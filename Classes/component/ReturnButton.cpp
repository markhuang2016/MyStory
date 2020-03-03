//
// Created by mark on 2020/2/16.
//

#include <manager/SceneManager.h>
#include "ReturnButton.h"

ui::Button* ReturnButton::create() {
    auto btn = ui::Button::create("return.png");
    auto visibleSize = Director::getInstance()->getVisibleSize();
    btn->setPosition(Vec2(visibleSize.width / 20, visibleSize.height - visibleSize.height / 20));
    btn->addClickEventListener([](Ref* ref){
        SceneManager::getInstance()->gotoStartScene();
    });

    return btn;
}
