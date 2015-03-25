//
//  MenuScene.cpp
//  Richer
//
//  Created by hower on 3/20/15.
//
//

#include "MenuScene.h"
#include "ui/UIScale9Sprite.h"


Scene* MenuScene::createScene()
{
    // 'scene' is an autorelease object
    auto scene = Scene::create();
    
    // 'layer' is an autorelease object
    auto layer = MenuScene::create();
    
    // add layer as a child to scene
    scene->addChild(layer);
    
    // return the scene
    return scene;
}


bool MenuScene::init()
{
    if (!LayerColor::create(Color4B(255, 255, 255, 255))) {
        return false;
    }
    
    visibleSize=Director::getInstance()->getVisibleSize();
    addBackgroudSprite();
    addMenuSprites();
    
    return true;
}

void MenuScene::addBackgroudSprite()
{
    Sprite *menuSpriteLogo=Sprite::create(MENU_LOGO);
    menuSpriteLogo->setPosition(Vec2(visibleSize.width/2.0, visibleSize.height));
    menuSpriteLogo->setAnchorPoint(Vec2(0.5, 1));
    menuSpriteLogo->setScale(0.6f);
    addChild(menuSpriteLogo);
    
    Sprite *rainBowSprite=Sprite::create(RAINBOW);
    rainBowSprite->setPosition(Vec2(5,visibleSize.height-20));
    rainBowSprite->setAnchorPoint(Vec2(0, 1));
    rainBowSprite->setScale(0.3f);
    addChild(rainBowSprite);
    
    MoveBy *rainBowMove=MoveBy::create(1, Vec2(20,0));
    MoveBy *rainBowMoveReverse=rainBowMove->reverse();
    Sequence *rainBowAction=Sequence::create(rainBowMove,rainBowMoveReverse, NULL);
    rainBowSprite->runAction(rainBowAction);
    
    
    
}

void MenuScene::addMenuSprites()
{

    
    {
        ui::Scale9Sprite *btnNormal=ui::Scale9Sprite::create(NORMAL_MENU);
        ui::Scale9Sprite *btnPress=ui::Scale9Sprite::create(PRESS_MENU);
        
        LabelTTF *singleGameTTF=LabelTTF::create(SINGLE_GAME, FONT_MENU, Btn_FontSize);
        ControlButton *singleGameBtn=ControlButton::create(singleGameTTF, btnNormal);
        singleGameBtn->setBackgroundSpriteForState(btnPress,Control::State::SELECTED);
        
        singleGameBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height-180));
        singleGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
        singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
        singleGameBtn->setTag(Btn_Single_Game_TAG);
        addChild(singleGameBtn);
        
    }
    
    
    {
        ui::Scale9Sprite *btnNormal=ui::Scale9Sprite::create(NORMAL_MENU);
        ui::Scale9Sprite *btnPress=ui::Scale9Sprite::create(PRESS_MENU);
        
        LabelTTF *singleGameTTF=LabelTTF::create(MULTI_GAME, FONT_MENU, Btn_FontSize);
        ControlButton *singleGameBtn=ControlButton::create(singleGameTTF, btnNormal);
        singleGameBtn->setBackgroundSpriteForState(btnPress,Control::State::HIGH_LIGHTED);
        
        singleGameBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height-240));
        singleGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
        singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
        singleGameBtn->setTag(Btn_Multi_Game_TAG);
        addChild(singleGameBtn);
        
    }
    
    
    
    
    {
        ui::Scale9Sprite *btnNormal=ui::Scale9Sprite::create(NORMAL_MENU);
        ui::Scale9Sprite *btnPress=ui::Scale9Sprite::create(PRESS_MENU);
        
        
        LabelTTF *singleGameTTF;

        bool music_on =  UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY,true);
        if (music_on) {
            singleGameTTF=LabelTTF::create(MUSIC_ON, FONT_MENU, Btn_FontSize);

        }else{
            singleGameTTF=LabelTTF::create(MUSIC_OFF, FONT_MENU, Btn_FontSize);
        }
        
        ControlButton *singleGameBtn=ControlButton::create(singleGameTTF, btnNormal);
        singleGameBtn->setBackgroundSpriteForState(btnPress,Control::State::SELECTED);
        
        singleGameBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height-300));
        singleGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
        singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
        singleGameBtn->setTag(Btn_Music_TAG);
        addChild(singleGameBtn);
        
    }
    
    {
        ui::Scale9Sprite *btnNormal=ui::Scale9Sprite::create(NORMAL_MENU);
        ui::Scale9Sprite *btnPress=ui::Scale9Sprite::create(PRESS_MENU);
        
        LabelTTF *singleGameTTF=LabelTTF::create(LOAD_GAME, FONT_MENU, Btn_FontSize);
        ControlButton *singleGameBtn=ControlButton::create(singleGameTTF, btnNormal);
        singleGameBtn->setBackgroundSpriteForState(btnPress,Control::State::SELECTED);
        
        singleGameBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height-360));
        singleGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
        singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
        singleGameBtn->setTag(Btn_Load_Game_TAG);
        addChild(singleGameBtn);
        
    }
    
    {
        ui::Scale9Sprite *btnNormal=ui::Scale9Sprite::create(NORMAL_MENU);
        ui::Scale9Sprite *btnPress=ui::Scale9Sprite::create(PRESS_MENU);
        
        LabelTTF *singleGameTTF=LabelTTF::create(LOAD_GAME, FONT_MENU, Btn_FontSize);
        ControlButton *singleGameBtn=ControlButton::create(singleGameTTF, btnNormal);
        singleGameBtn->setBackgroundSpriteForState(btnPress,Control::State::SELECTED);
        
        singleGameBtn->setPosition(Vec2(visibleSize.width/2, visibleSize.height-420));
        singleGameBtn->setPreferredSize(Size(Btn_Width,Btn_Height));
        singleGameBtn->addTargetWithActionForControlEvents(this, cccontrol_selector(MenuScene::menuTouchDown), Control::EventType::TOUCH_DOWN);
        singleGameBtn->setTag(Btn_Quit_Game_TAG);
        addChild(singleGameBtn);
        
    }
    
}


void MenuScene::menuTouchDown(Ref *pSender,Control::EventType)
{
    ControlButton* button = (ControlButton*)pSender;
    int tag=button->getTag();
    switch (tag) {
        case Btn_Single_Game_TAG:
        {
        
        }
            break;
        case Btn_Multi_Game_TAG:
        {
            
        }
            break;
        case Btn_Music_TAG:
        {
            bool music_on=UserDefault::getInstance()->getBoolForKey(MUSIC_ON_KEY, false);
            UserDefault::getInstance()->setBoolForKey(MUSIC_ON_KEY, !music_on);

            if (music_on) {
                
                button->setTitleForState(MUSIC_OFF, Control::State::NORMAL);
            }else{
                button->setTitleForState(MUSIC_ON, Control::State::NORMAL);
            }
        }
            break;
        case Btn_Quit_Game_TAG:
        {
            
        }
            break;
        case Btn_Load_Game_TAG:
        {
            
        }
            break;
            
        default:
            break;
    }
}

