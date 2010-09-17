/*
* Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
* All rights reserved.
* This component and the accompanying materials are made available
* under the terms of "Eclipse Public License v1.0"
* which accompanies this distribution, and is available
* at the URL "http://www.eclipse.org/legal/epl-v10.html".
*
* Initial Contributors:
* Nokia Corporation - initial contribution.
*
* Contributors:
*
* Description:  Silent widget
*
*/

// System includes
#include <HbPushButton>
#include <QGraphicsLinearLayout>
#include <HbStyle>
#include <HbDocumentLoader>
#include <HbFrameItem>
#include <HbFrameDrawer>
#include <xqsettingsmanager.h>
#include <ProfileEngineInternalCRKeys.h>

// User includes
#include "silentwidget.h"
#include "silentwidgetconsts.h"
#include "silentmodel.h"
#include "silentobserver.h"

/*!
    \class SilentWidget
    \implementation for silent widget

    This class is used to create silent widget
*/

// ======== MEMBER FUNCTIONS ========

/*!
    Constructor
*/
SilentWidget::SilentWidget(QGraphicsItem* parent, Qt::WindowFlags flags)
    : HbWidget(parent, flags),
      mButton(0),
      mModel(new SilentModel),
      mObserver(new SilentObserver(this))
{
    QGraphicsLinearLayout *mainLayout = new QGraphicsLinearLayout(
        Qt::Vertical, this);
    
    // load the widget from .docml
    HbDocumentLoader loader; 
    bool ok = false; 
    loader.load(":/docml/silentdocml", &ok); 
    if (!ok) {
        // fail to load .docml file
        return;
    }
    mButton = (HbPushButton *) loader.findWidget("pushButton");
    if (!mButton) {
        // fail to find push button
        return;
    }
    
    // set icon and background
    HbFrameDrawer *background = new HbFrameDrawer("qtg_fr_hsshortcut_normal", 
            HbFrameDrawer::NinePieces);
    mButton->setFrameBackground(background);
    HbFrameDrawer *foreground;
    if (mModel->silenceMode()) {  
        foreground = new HbFrameDrawer("qtg_large_tone_off", 
                HbFrameDrawer::NinePieces);
    } else {
        foreground = new HbFrameDrawer("qtg_large_tone", 
                HbFrameDrawer::NinePieces);
    }
    HbFrameItem* frameItem = new HbFrameItem(foreground);
    mButton->setBackgroundItem(frameItem);
        
    mButton->setCheckable(true);
    mainLayout->addItem(mButton);
    
    connect(mButton, SIGNAL(toggled(bool)), this, SLOT(handleClickEvent(bool)));
    setLayout(mainLayout);
    
    // create XQSettingsManager, monitor KProEngSilenceMode
    mSettingManager = new XQSettingsManager();
    XQCentralRepositorySettingsKey silenceKey(KCRUidProfileEngine.iUid,
        KProEngSilenceMode);
    mSettingManager->startMonitoring(silenceKey, XQSettingsManager::TypeInt);
    connect(mSettingManager, SIGNAL(valueChanged(XQSettingsKey, QVariant)),
            this, SLOT(settingValueChanged(XQSettingsKey, QVariant)));
}

/*!
    Monitor KProEngSilenceMode
*/
void SilentWidget::settingValueChanged(const XQSettingsKey &key, 
        const QVariant &value)
{
    // change icon according to latest silence mode
    if (key.uid() == KCRUidProfileEngine.iUid && key.key() == KProEngSilenceMode) {      
        HbFrameDrawer *foreground;
        if (value.toBool()) {      
            foreground = new HbFrameDrawer("qtg_large_tone_off", 
                HbFrameDrawer::NinePieces);
        } else {
            foreground = new HbFrameDrawer("qtg_large_tone", 
                HbFrameDrawer::NinePieces);
        }
        HbFrameItem* frameItem = new HbFrameItem(foreground);
        mButton->setBackgroundItem(frameItem);
    }
}

/*!
    Handle click events
*/
void SilentWidget::handleClickEvent(bool /*state*/)
{
    // switch icon and activate silece state 
    HbFrameDrawer *foreground;
    if (!mModel->silenceMode()) {
        mModel->setSilenceMode(true);
        foreground = new HbFrameDrawer("qtg_large_tone_off", 
                        HbFrameDrawer::NinePieces);
    } else {
        mModel->setSilenceMode(false);
        foreground = new HbFrameDrawer("qtg_large_tone", 
                        HbFrameDrawer::NinePieces);
    }
    HbFrameItem* frameItem = new HbFrameItem(foreground);
    mButton->setBackgroundItem(frameItem);
}

/*!
    Change icon according to observer event
*/
void SilentWidget::changeIcon()
{
    HbFrameDrawer *foreground;
    if (mModel->silenceMode()) {
        foreground = new HbFrameDrawer("qtg_large_tone_off", 
                    HbFrameDrawer::NinePieces);
    } else {
        foreground = new HbFrameDrawer("qtg_large_tone", 
                            HbFrameDrawer::NinePieces);
    }
    HbFrameItem* frameItem = new HbFrameItem(foreground);
    mButton->setBackgroundItem(frameItem);
}

/*!
    Destructor
*/
SilentWidget::~SilentWidget()
{
    if (mModel) {
        delete mModel;
        mModel = NULL;
    }
    
    if (mSettingManager) {
        delete mSettingManager;
        mSettingManager = NULL;
    }
}

/*!
    Return bounding rect
*/
QRectF SilentWidget::boundingRect() const
{
    return childrenBoundingRect();
}

/*!
    Return shape
*/
QPainterPath SilentWidget::shape() const
{   
    QPainterPath path;
    path.addRect(boundingRect());
    return path;
}

/*!
    Called when widget is shown in the home screen
*/
void SilentWidget::onShow()
{
}

/*!
    Called when widget is hidden from the home screen
*/
void SilentWidget::onHide()
{
}
