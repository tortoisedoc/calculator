TEMPLATE = app
TARGET = calc
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt


HEADERS += ../../Tokenizer.h \
    ../../Errorclass.h
HEADERS += ../../Parser.h

SOURCES += ../../calc.cpp \
    ../../errorclass.cpp
SOURCES += ../../Tokenizer.cpp
SOURCES += ../../Parser.cpp


