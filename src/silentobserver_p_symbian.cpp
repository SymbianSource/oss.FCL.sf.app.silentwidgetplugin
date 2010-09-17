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
* Description: Silent widget observer
*
*/

// System includes
#include <CProfileChangeNotifyHandler.h>

// User includes
#include "silentobserver_p.h"
#include "silentwidget.h"

/*!
    \class SilentObserverPrivate
    \Silent observer class

    This class is used to create silent widget observer
*/

// ======== MEMBER FUNCTIONS ========

/*!
    NewL
*/
SilentObserverPrivate *SilentObserverPrivate::NewL(QObject *parent)
{
    SilentObserverPrivate *self = new (ELeave)SilentObserverPrivate();
    CleanupStack::PushL(self);
    self->ConstructL(parent);
    CleanupStack::Pop(); //self
    return self;
}

/*!
    Constructor
*/
SilentObserverPrivate::SilentObserverPrivate()
{
}

/*!
    ConstructL
*/
void SilentObserverPrivate::ConstructL(QObject *parent)
{
    iHandler = CProfileChangeNotifyHandler::NewL( this );
    iParent = parent;
}

/*!
    Destroyer
*/
SilentObserverPrivate::~SilentObserverPrivate()
{
    if (iHandler) {
        delete iHandler;
        iHandler = NULL;
    }
}

/*!
    Handle active profile events
*/
void SilentObserverPrivate::HandleActiveProfileEventL(
        TProfileEvent /*aProfileEvent*/,
        TInt /*aProfileId*/ )
{
    // handle event
    (reinterpret_cast<SilentWidget*>(iParent))->changeIcon();
    
}
