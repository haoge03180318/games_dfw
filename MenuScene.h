//
//  MenuScene.h
//  Richer
//
//  Created by hower on 3/20/15.
//
//

#ifndef __Richer__MenuScene__
#define __Richer__MenuScene__

#include <stdio.h>

#include "cocos2d.h"
#include "ConstUtil.h"
#include "extensions/cocos-ext.h"

USING_NS_CC;
USING_NS_CC_EXT;

const int Btn_Width  = 222;
const int Btn_Height = 50;
const int Btn_FontSize = 20;
const int Quit_Dialog_Size_Width = 400;
const int Quit_Dialog_Size_Height = 220;
//const int Btn_Padding = 60;
const int Btn_Single_Game_TAG = 10001;
const int Btn_Multi_Game_TAG = 10002;
const int Btn_Music_TAG = 10003;
const int Btn_Quit_Game_TAG = 10004;
const int Btn_Quit_OK_TAG = 10005;
const int Btn_Quit_Cancel_TAG = 10006;
const int Btn_Load_Game_TAG = 10007;


class MenuScene : public Layer
{
public:
    static Scene* createScene();
    virtual bool init();
    CREATE_FUNC(MenuScene);
    
private:
    Size visibleSize;
    LabelTTF *settingsGameTTF;
    void menuTouchDown(Ref *pSender,Control::EventType);
    void addBackgroudSprite();
    void addMenuSprites();
    
};


#endif /* defined(__Richer__MenuScene__) */
