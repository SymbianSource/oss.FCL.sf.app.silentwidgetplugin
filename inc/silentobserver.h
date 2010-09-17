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

#ifndef SILENTOBSERVER_H
#define SILENTOBSERVER_H

// System includes
#include <QObject>

// Forward declarations
class SilentObserverPrivate;

// Class declaration
class SilentObserver : public QObject
{
public:
    SilentObserver(QObject *parent = 0);
    ~SilentObserver();

private:
    Q_DISABLE_COPY(SilentObserver)
    
private:
    SilentObserverPrivate *dptr;
    };

#endif  //SILENTOBSERVER_H
