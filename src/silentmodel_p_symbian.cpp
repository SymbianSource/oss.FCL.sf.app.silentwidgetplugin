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
* Description: Silent widget model
*
*/

// System includes
#include <e32base.h>
#include <MProfileEngineExtended2.h>

// User includes
#include "silentmodel_p.h"
#include "silentwidgetconsts.h"

/*!
    \class SilentModelPrivate
    \silent widget model private class

    This class is used to create silent model
*/

// ======== MEMBER FUNCTIONS ========

/*!
    NewL
*/
SilentModelPrivate *SilentModelPrivate::NewL()
{
    SilentModelPrivate *self = new (ELeave) SilentModelPrivate();
    CleanupStack::PushL(self);
    self->ConstructL();
    CleanupStack::Pop(); //self
    return self;
}

/*!
    Constructor
*/
SilentModelPrivate::SilentModelPrivate()
{
    mEngine = NULL;
}

/*!
    ConstructL
*/
void SilentModelPrivate::ConstructL()
{
    mEngine = CreateProfileEngineExtended2L();
}

/*!
    Destroyer
*/
SilentModelPrivate::~SilentModelPrivate()
{
    if (mEngine!=0) {
        mEngine->Release();
    }
}

/*
    Get silent status in master volume
 */
bool SilentModelPrivate::silenceMode() const
{
    bool isSlience = false;
    TRAP_IGNORE(isSlience = mEngine->SilenceModeL();)
    return isSlience;
}

/*
    Set silent status in master volume
 */
void SilentModelPrivate::setSilenceMode(bool isSilence)
{
    TRAP_IGNORE(mEngine->SetSilenceModeL(isSilence);)    
}
