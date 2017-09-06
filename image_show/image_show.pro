#-------------------------------------------------
#
# Project created by QtCreator 2017-09-06T10:18:09
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = example
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp


INCLUDEPATH+=E:\opencv\include\opencv\
                    E:\opencv\include\opencv2\
                    E:\opencv\include
LIBS+=E:\opencv\lib\libopencv_calib3d248.dll.a\
        E:\opencv\lib\libopencv_contrib248.dll.a\
        E:\opencv\lib\libopencv_core248.dll.a\
        E:\opencv\lib\libopencv_features2d248.dll.a\
        E:\opencv\lib\libopencv_flann248.dll.a\
        E:\opencv\lib\libopencv_gpu248.dll.a\
        E:\opencv\lib\libopencv_highgui248.dll.a\
        E:\opencv\lib\libopencv_imgproc248.dll.a\
        E:\opencv\lib\libopencv_legacy248.dll.a\
        E:\opencv\lib\libopencv_ml248.dll.a\
        E:\opencv\lib\libopencv_objdetect248.dll.a\
        E:\opencv\lib\libopencv_video248.dll.a
