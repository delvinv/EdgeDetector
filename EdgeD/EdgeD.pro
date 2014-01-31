TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp

win32 {
LIBS += -Lc:/OpenCV/bin -Lc:/OpenCV/lib -lopencv_core246 -lopencv_highgui246 \
-lopencv_imgproc246 -lopencv_features2d246 -lopencv_calib3d246
INCLUDEPATH += c:/OpenCV/include
}
