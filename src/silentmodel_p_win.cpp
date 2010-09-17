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

// User includes
#include "silentmodel_p.h"

/*!
    \class SilentModelPrivate
    \Silent widget model class

    This class is used to create silent widget model
*/

// ======== MEMBER FUNCTIONS ========

/*!
    NewL
*/
SilentModelPrivate *SilentModelPrivate::NewL()
{
}

/*!
    Constructor
*/
SilentModelPrivate::SilentModelPrivate()
{
}

/*!
    ConstructL
*/
void SilentModelPrivate::ConstructL()
{
}

/*!
    Destroyer
*/
SilentModelPrivate::~SilentModelPrivate()
{

}

/*
    Get silent status in master volume
 */
bool SilentModelPrivate::silenceMode() const
{
    return true;
}

/*
    Set silent status in master volume
 */
void SilentModelPrivate::setSilenceMode(bool isSilence)
{
}
