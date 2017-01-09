TEMPLATE = subdirs

SUBDIRS += \
    UnitTests \
    Scrambler \
    ScramblerGUI

ScramblerGUI.depends = Scrambler
UnitTests.depends = Scrambler ScramblerGUI
