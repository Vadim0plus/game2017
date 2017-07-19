QT += widgets
qtHaveModule(printsupport): QT += printsupport

HEADERS     = view/imagemodel.h \
              view/mainwindow.h \
              view/pixeldelegate.h \
              	model/cellular.h \
              	model/rules.h \
              	model/world.h \
    form.h
SOURCES     = view/imagemodel.cpp \
              view/mainwindow.cpp \
              view/pixeldelegate.cpp \
              	model/cellular.cpp \
              	model/rules.cpp \
              	model/world.cpp \
    application.cpp \
    form.cpp


# install
target.path = $$[QT_INSTALL_EXAMPLES]/widgets/itemviews/pixelator
INSTALLS += target

DISTFILES += \
    LICENSE \
    README

FORMS += \
    form.ui
