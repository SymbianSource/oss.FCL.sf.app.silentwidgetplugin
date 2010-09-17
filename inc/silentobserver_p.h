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
* Description: Silent profiles observer
*
*/

#ifndef SILENTOBSERVER_P_H
#define SILENTOBSERVER_P_H

// System includes
#include <e32base.h>
#include <QObject>
#include <MProfileChangeObserver.h>

// Forward declarations
class CProfileChangeNotifyHandler;

// Class declaration
class SilentObserverPrivate : public CBase, public MProfileChangeObserver
{
public:
    static SilentObserverPrivate *NewL(QObject *parent);
    SilentObserverPrivate();
    ~SilentObserverPrivate();
    
private:
    void ConstructL(QObject *parent);
    virtual void HandleActiveProfileEventL(
        TProfileEvent aProfileEvent,
        TInt aProfileId );

private:
    CProfileChangeNotifyHandler *iHandler;
    QObject *iParent;
};

#endif  //SILENTOBSERVER_P_H
