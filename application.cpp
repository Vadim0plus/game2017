//========================================================================
// application.cpp : Driver program for "GameCode2017" project
//
// Part of the "GameCode2017"
//
// DESCRIPTION
//
// (c) Copyright 2017 Mendeleev University of Chemical Technology
//
// This program is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser GPL v3
// as published by the Free Software Foundation.
//
//========================================================================

#include <QApplication>
#include "view/mainwindow.h"

/* Entry Point */
int main(int argc, char *argv[])
{
    /*Window Initialization */
    QApplication app(argc, argv);
    MainWindow window;
    window.show();

    /* Render Image of World */
    window.renderImage();

    return app.exec();
}
