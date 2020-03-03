//
// Created by mark on 2020/2/18.
//

#include "BattleArea.h"
#include "BattleBlock.h"

BattleArea::BattleArea() : row(0), column(0) {

};

BattleArea::~BattleArea() {

}

bool BattleArea::init(Vec2 vec2) {
    if (Node::init() == false) {
        return false;
    }
    row = vec2.x;
    column = vec2.y;

    int width = 1920;
    int height = 720;
    this->setContentSize(Size(width, height));
    this->setAnchorPoint(Vec2(0.5, 0.5));
    if (row > 0 && column > 0 &&width%row==0&&height%column==0 && width /  row ==  height / column) {
        float scale = (float) width /row /32;
        int pixel = width / row;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < column; ++j) {
                auto block = BattleBlock::create();
                block->setAnchorPoint(Vec2(0.5, 0.5));
                block->setPosition(i * pixel+pixel/2, j * pixel+pixel/2);
                block->setScale(scale);
                addChild(block);
            }
        }
    }

    return true;
}

BattleArea* BattleArea::create(Vec2 vec2) {
    BattleArea *battleArea = new(std::nothrow) BattleArea();
    if (battleArea && battleArea->init(vec2)) {
        battleArea->autorelease();
        return battleArea;
    } else {
        CC_SAFE_DELETE(battleArea);
        return nullptr;
    }
}