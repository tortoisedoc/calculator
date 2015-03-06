TEMPLATE = app
TARGET = calc
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


HEADERS += ../../../Tokenizer.h \
    ../../Errorclass.h \
    ../../../utils.h
HEADERS += ../../../Parser.h

SOURCES += ../../../calc.cpp \
    ../../../errorclass.cpp \
    ../../../utils.cpp
SOURCES += ../../../Tokenizer.cpp
SOURCES += ../../../Parser.cpp


OTHER_FILES += ../../../test/test_calc.py
