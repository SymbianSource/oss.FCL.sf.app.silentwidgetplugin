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
* Description: Silent widget plugin.
*
*/

// User includes
#include "silentobserver_p.h"

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
}

/*!
    Destroyer
*/
SilentObserverPrivate::~SilentObserverPrivate()
{
}

/*!
    Handle active profile events
*/
void SilentObserverPrivate::HandleActiveProfileEventL(
        TProfileEvent /*aProfileEvent*/,
        TInt /*aProfileId*/ )
{
}
