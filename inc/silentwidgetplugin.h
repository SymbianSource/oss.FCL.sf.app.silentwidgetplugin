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
* Description:  Silent widget plugin
*
*/

#ifndef SILENTWIDGETPLUGIN_H
#define SILENTWIDGETPLUGIN_H

// System includes
#include <QObject>
#include <qserviceplugininterface.h>

// Class declaration
QTM_USE_NAMESPACE
class SilentWidgetPlugin : public QObject, public QServicePluginInterface
{
    Q_OBJECT
    Q_INTERFACES(QtMobility::QServicePluginInterface)

public:
    QObject *createInstance(const QServiceInterfaceDescriptor &descriptor,
        QServiceContext *context, QAbstractSecuritySession *session);
};

#endif // SILENTWIDGETPLUGIN_H
