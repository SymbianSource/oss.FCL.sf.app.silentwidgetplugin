#
# Copyright (c) 2010 Nokia Corporation and/or its subsidiary(-ies).
# All rights reserved.
# This component and the accompanying materials are made available
# under the terms of "Eclipse Public License v1.0"
# which accompanies this distribution, and is available
# at the URL "http://www.eclipse.org/legal/epl-v10.html".
#
# Initial Contributors:
# Nokia Corporation - initial contribution.
#
# Contributors:
#
# Description: Silent widget
#

HEADERS += ./inc/*.h
SOURCES += src/silentwidgetplugin.cpp \
           src/silentwidget.cpp \
           src/silentmodel.cpp \
           src/silentobserver.cpp \
           
symbian : {
    SOURCES += src/silentmodel_p_symbian.cpp \
            src/silentobserver_p_symbian.cpp
}

win32 : {
    SOURCES += src/silentmodel_p_win.cpp \
            src/silentobserver_p_win.cpp
}