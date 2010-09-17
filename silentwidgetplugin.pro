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

TEMPLATE = lib
CONFIG += plugin mobility hb
MOBILITY = serviceframework

include(../../common.pri)
include(silentwidgetplugin.pri)
include (rom/silentwidgetplugin_rom.pri)

INCLUDEPATH += ./inc

RESOURCES += silentwidgetplugin.qrc

TRANSLATIONS = silent_widget.ts

symbian: {

    PLUGIN_SUBDIR = /private/20022F35/import/widgetregistry/2002EAD3
    
    INCLUDEPATH += $$APP_LAYER_SYSTEMINCLUDE
    TARGET.UID3 = 0x2002EAD3
    TARGET.EPOCALLOWDLLDATA=1
    TARGET.CAPABILITY = ALL -TCB

    LIBS += -lprofileeng -lxqsettingsmanager
    
    plugins.path = $${PLUGIN_SUBDIR}
    plugins.sources = $${TARGET}.dll 
    
    widgetResources.path = $${PLUGIN_SUBDIR}
    widgetResources.sources += resource/$${TARGET}.xml    
    widgetResources.sources += resource/$${TARGET}.manifest
    widgetResources.sources += resource/$${TARGET}.png

    DEPLOYMENT += plugins \
                  widgetResources
}

win32: {

    CONFIG(debug, debug|release) {
      SUBDIRPART = debug
    } else {
      SUBDIRPART = release
    }    
    
    PLUGIN_SUBDIR = /hsresources/import/widgetregistry/2002EAD3
    
    DESTDIR = $$PWD/../../../../../bin/$${SUBDIRPART}/$${PLUGIN_SUBDIR}

    manifest.path = $${DESTDIR}
    manifest.files = ./resource/*.manifest ./resource/*.xml ./resource/*.png
    
    INSTALLS += manifest
    
}
