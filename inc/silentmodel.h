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
* Description: Silent model for silent widget
*
*/

#ifndef SILENTMODEL_H
#define SILENTMODEL_H

// System includes
#include <QObject>

// Forward declarations
class SilentModelPrivate;

// Class declaration
class SilentModel : public QObject
{
public:
    SilentModel(QObject *parent = 0);
    ~SilentModel();
    bool silenceMode() const;
    void setSilenceMode(bool isSlience);
    
private:
    Q_DISABLE_COPY(SilentModel)
    
private:
    SilentModelPrivate *dptr;
};

#endif  //SILENTMODEL_H
