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

// User includes
#include "silentobserver.h"
#include "silentobserver_p.h"

/*!
    \class SilentObserver
    \Silent observer class

    This class is used to create silent widget observer
*/

// ======== MEMBER FUNCTIONS ========

/*!
    Constructor
*/
SilentObserver::SilentObserver(QObject *parent/*= 0*/)
: QObject(parent)
{
    QT_TRAP_THROWING(dptr = SilentObserverPrivate::NewL(parent));
}

/*!
    Destroyer
*/
SilentObserver::~SilentObserver()
{
    delete dptr;
}
