TEMPLATE = subdirs

SUBDIRS += \
    UnitTests \
    Scrambler

UnitTests.depends = Scrambler
