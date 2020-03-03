//
// Created by mark on 2020/2/15.
//

#ifndef MYSTORY_DEMOSCENE_H
#define MYSTORY_DEMOSCENE_H

#include <cocos2d.h>
USING_NS_CC;

class DemoScene :public Layer {
protected:
    void initUI();

public:
    DemoScene();

    virtual ~DemoScene();

    static Scene *createScene();

    CREATE_FUNC(DemoScene);

    virtual bool init();

};


#endif //MYSTORY_DEMOSCENE_H
