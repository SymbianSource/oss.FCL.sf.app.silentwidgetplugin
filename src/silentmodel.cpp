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
#include "silentmodel.h"
#include "silentmodel_p.h"
#include "silentwidgetconsts.h"

/*!
    \class SilentModel
    \Silent widget model class

    This class is used to create silent widget model
*/

// ======== MEMBER FUNCTIONS ========

/*!
    Constructor
*/
SilentModel::SilentModel(QObject *parent/*= 0*/)
    : QObject(parent)
{
    QT_TRAP_THROWING(dptr = SilentModelPrivate::NewL());
}

/*!
    Destroyer
*/
SilentModel::~SilentModel()
{
    delete dptr;
}

/*
    Get silent status in master volume
 */
bool SilentModel::silenceMode() const
{
    return dptr->silenceMode();
}

/*
    Set silent status in master volume
 */
void SilentModel::setSilenceMode(bool isSilence)
{
    return dptr->setSilenceMode(isSilence);
}
