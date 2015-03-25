//
//  SplashScene.cpp
//  Richer
//
//  Created by hower on 3/19/15.
//
//

#include "SplashScene.h"


Scene* SplashScene::createScene()
{
    auto scene=Scene::create();
    auto layer=SplashScene::create();
    scene->addChild(layer);
    
    return scene;
}

bool SplashScene::init()
{
    if (!Layer::init()) {
        return false;
    }
    
    
    visibleSize=Director::getInstance()->getVisibleSize();
    Vec2 origin=Director::getInstance()->getVisibleOrigin();
    
    initMoveSprite();
    
    scheduleOnce(schedule_selector(SplashScene::startMoveSprite), ONE_SECOND);
    
    
    return true;
}

void SplashScene::initMoveSprite()
{
    m_sprite=Sprite::create(MAI_IMAGE);
    c_sprite=Sprite::create(CHENG_IMAGE);
    k_sprite=Sprite::create(KE_IMAGE);
    j_sprite=Sprite::create(JI_IMAGE);
    
    spriteSize=m_sprite->getContentSize();
    m_sprite->setPosition(Vec2(visibleSize.width/2-2*(spriteSize.width),visibleSize.height/2));
    k_sprite->setPosition(Vec2(visibleSize.width/2-(spriteSize.width),visibleSize.height/2));
    j_sprite->setPosition(Vec2(visibleSize.width/2,visibleSize.height/2));
    c_sprite->setPosition(Vec2(visibleSize.width/2+(spriteSize.width),visibleSize.height/2));
    
    m_sprite->setAnchorPoint(Vec2(0, 0.5));
    c_sprite->setAnchorPoint(Vec2(0, 0.5));
    k_sprite->setAnchorPoint(Vec2(0, 0.5));
    j_sprite->setAnchorPoint(Vec2(0, 0.5));
    
    this->addChild(m_sprite);
    this->addChild(c_sprite);
    this->addChild(k_sprite);
    this->addChild(j_sprite);


}

void SplashScene::startMoveSprite(float dt)
{
    MoveBy *moveCToLeft1=MoveBy::create(MOVE_SPLEED, Vec2(-spriteSize.width, 0));
    c_sprite->runAction(moveCToLeft1);
    
    MoveBy *moveJToright = MoveBy::create(MOVE_SPLEED, Vec2(spriteSize.width, 0));
    
    CallFunc *callFunc=CallFunc::create(CC_CALLBACK_0(SplashScene::moveKSpriteToLeft, this));
    
    j_sprite->runAction(Sequence::create(moveJToright,callFunc, NULL));
    
}

void SplashScene::moveKSpriteToLeft()
{
    MoveBy *moveCToLeft2=MoveBy::create(MOVE_SPLEED, Vec2(-spriteSize.width, 0));
    c_sprite->runAction(moveCToLeft2);
    
    MoveBy *k_sprite_moveby=MoveBy::create(MOVE_SPLEED, Vec2(spriteSize.width, 0));
    
    CallFunc *callFun2=CallFunc::create(CC_CALLBACK_0(SplashScene::moveMSpriteToLeft, this));
    
    k_sprite->runAction(Sequence::create(k_sprite_moveby,callFun2, NULL));
}

void SplashScene::moveMSpriteToLeft()
{
    MoveBy *moveCToLeft3=MoveBy::create(MOVE_SPLEED, Vec2(-spriteSize.width, 0));
    c_sprite->runAction(moveCToLeft3);
    
    MoveBy *m_sprite_moveby=MoveBy::create(MOVE_SPLEED, Vec2(spriteSize.width, 0));
    CallFunc *callFunc3=CallFunc::create(CC_CALLBACK_0(SplashScene::spriteFadeOut, this));
    m_sprite->runAction(Sequence::create(m_sprite_moveby,callFunc3, NULL));
    
}

void SplashScene::spriteFadeOut()
{
    FadeOut *fadeout1=FadeOut::create(ONE_SECOND*2);
    FadeOut *fadeout2=FadeOut::create(ONE_SECOND*2);
    FadeOut *fadeout3=FadeOut::create(ONE_SECOND*2);
    FadeOut *fadeout4=FadeOut::create(ONE_SECOND*2);
    
    c_sprite->runAction(fadeout1);
    m_sprite->runAction(fadeout2);
    k_sprite->runAction(fadeout3);
    j_sprite->runAction(fadeout4);
    
    CallFunc *callFun4=CallFunc::create(CC_CALLBACK_0(SplashScene::gotoMenuScene,this));
    c_sprite->runAction(Sequence::create(fadeout4,callFun4, NULL));


}

void SplashScene::gotoMenuScene()
{
    Director::getInstance()->replaceScene(MenuScene::createScene());
}



