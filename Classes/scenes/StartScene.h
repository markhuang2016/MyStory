//
// Created by mark on 2020/2/14.
//

#ifndef MYSTORY_STARTSCENE_H
#define MYSTORY_STARTSCENE_H

#include <cocos2d.h>

USING_NS_CC;

class StartScene : public Layer {
private:
    void initUI();

protected:
    Menu *menu;

public:
    StartScene();

    virtual ~StartScene();

    CREATE_FUNC(StartScene);

    virtual bool init();

    static Scene *createScene();
};


#endif //MYSTORY_STARTSCENE_H
