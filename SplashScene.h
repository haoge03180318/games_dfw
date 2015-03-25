//
//  SplashScene.h
//  Richer
//
//  Created by hower on 3/19/15.
//
//

#ifndef __Richer__SplashScene__
#define __Richer__SplashScene__

#include "cocos2d.h"

#include "MenuScene.h"
#include "ConstUtil.h"
USING_NS_CC;


const double MOVE_SPLEED = 0.5;
const int ONE_SECOND = 1;

class SplashScene : public Layer
{

public:
    static Scene* createScene();
  
    virtual bool init();
    
    void moveKSpriteToLeft();
    void moveMSpriteToLeft();
    void initMoveSprite();
    void startMoveSprite(float dt);
    void gotoMenuScene();
    void spriteFadeOut();
    
    CREATE_FUNC(SplashScene);

    
private:
    Sprite *m_sprite;
    Sprite *c_sprite;
    Sprite *k_sprite;
    Sprite *j_sprite;
    
    Size visibleSize;
    Size spriteSize;
    
};


#endif /* defined(__Richer__SplashScene__) */
