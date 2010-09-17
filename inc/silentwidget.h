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
* Description: Silent widget
*
*/

#ifndef SILENTWIDGET_H
#define SILENTWIDGET_H

// System includes
#include <HbWidget>

// Forward declarations
class HbPushButton;
class SilentModel;
class SilentObserver;
class XQSettingsManager;
class XQSettingsKey;

// Class declaration
class SilentWidget : public HbWidget
{
    Q_OBJECT

public:
    SilentWidget(QGraphicsItem *parent = 0, Qt::WindowFlags flags = 0);
    ~SilentWidget();
    QRectF boundingRect() const;
    QPainterPath shape() const;
    void changeIcon();
    
public slots:
    void onShow();
    void onHide();
    void settingValueChanged(const XQSettingsKey &key, const QVariant &value);
    
private slots:
    void handleClickEvent(bool state);
    
private:
    Q_DISABLE_COPY(SilentWidget)
    HbPushButton *mButton;
    SilentModel *mModel;
    SilentObserver *mObserver;
    XQSettingsManager *mSettingManager;
};

#endif // SILENTWIDGET_H
