# Target is the name of the exe
TARGET=ImageWrite
# where to put .o files
OBJECTS_DIR=$$PWD/obj
# now set some QMAKE     SETTING
# dont build against qt libs
CONFIG-=qt
#use C++
CONFIG+=c++11
#DEFINES+=NDEBUG
# add source file
SOURCES +=$$PWD/src/main.cpp \
        $$PWD/src/ImageWrite.cpp

HEADERS +=$$PWD/include/ImageWrite.h

INCLUDEPATH+= $$PWD/include
