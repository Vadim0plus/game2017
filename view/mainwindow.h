//========================================================================
// mainwindow.h : Window Prototype for program; View part of system
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


#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "../model/cellular.h"
#include <QMainWindow>
#include <QTime>
#include <QTimer>
#include <QGroupBox>
#include <QPushButton>
#include <QLineEdit>
#include <QListWidget>

/* Prototypes */
class ImageModel;
QT_BEGIN_NAMESPACE
class QAction;
class QTableView;
QT_END_NAMESPACE

/* Define structure of window of program */
class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /* Constructor, allocating resources */
    MainWindow();

    /* Render image of World */
    void renderImage();

    /* Helper functions for RenderImage */
public slots:
    void chooseImage();
    void printImage();
    void showAboutBox();
    void updateView();
    void updateTime();
    void setMap();
    void setConfig(int, int, int); // установка Ширины width, Высоты height, Интервала обновления ячеек interval


private:
    ImageModel *model;
    QAction *printAction;
    QString currentPath;
    QTableView *view;
    QTimer *tmr;
    Cellular* cells;
    QGroupBox* gbox;
    QPushButton* button1;
    QPushButton* button2;
    QPushButton* button3;
    QGroupBox* gbox_base;
    QGroupBox* gbox_action;
    QListWidget* list;
};

#endif // MAINWINDOW_H
