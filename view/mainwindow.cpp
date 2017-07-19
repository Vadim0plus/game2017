//========================================================================
// mainwindow.h : Window Implementation for program; View part of system
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

#include "imagemodel.h"
#include "mainwindow.h"
#include "pixeldelegate.h"

#include <QtWidgets>
#if defined(QT_PRINTSUPPORT_LIB)
#include <QtPrintSupport/qtprintsupportglobal.h>
#if QT_CONFIG(printdialog)
#include <QPrinter>
#include <QPrintDialog>
#endif
#endif
//! [0]

static const QStringList list_item = QStringList() << "Conway" << "Amoeba" << "Life34" << "Maze";
MainWindow::MainWindow()
{
//! [0]
    currentPath = QDir::homePath(); /* For future using */
    model = new ImageModel(this);

    QWidget *centralWidget = new QWidget;

//! [1]
    view = new QTableView;
    view->setShowGrid(false);
    view->horizontalHeader()->hide();
    view->verticalHeader()->hide();
    view->horizontalHeader()->setMinimumSectionSize(1);
    view->verticalHeader()->setMinimumSectionSize(1);
    view->setModel(model);
//! [1]
    QGridLayout *layout = new QGridLayout;

    //total groupbox
    gbox = new QGroupBox(tr("Settings"));
    layout->addWidget(gbox,0,0);
    gbox->setFixedWidth(250);

    //GROUPBOX1 ELEMENTS
    gbox_base = new QGroupBox(tr("Base"));
    gbox_base->setFixedSize(230,300);
    QVBoxLayout* laybox1 = new QVBoxLayout;
    //edits
    QLineEdit* edit1 = new QLineEdit;
    edit1->setFixedSize(100,20);
    edit1->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
    // connect(label_ed1, SIGNAL(returnPressed()),this,SLOT(keyPressEvent(QKeyEvent*)));
    QLineEdit* edit2 = new QLineEdit;
    edit2->setFixedSize(100,20);
    edit2->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
    QLineEdit* edit3 = new QLineEdit;
    edit3->setFixedSize(100,20);
    edit3->setValidator(new QRegExpValidator(QRegExp("[0-9]*"),this));
    //label
    QLabel* label_ed1 = new QLabel(tr("Width:"));
    label_ed1->setFixedSize(100,20);  
    QLabel* label_ed2 = new QLabel(tr("Height:"));
    label_ed2->setFixedSize(100,20);
    QLabel* label_ed3 = new QLabel(tr("Iteration time:"));
    label_ed3->setFixedSize(100,20);
    QLabel* label_ed4 = new QLabel(tr("Configuration:"));
    label_ed4->setFixedSize(100,20);
    //listwidget
    list = new QListWidget;
    list->addItems(list_item);
    list->setFixedHeight(80);

    //layer
    laybox1->addWidget(label_ed1); //add to groupbox
    laybox1->addWidget(edit1);
    laybox1->addWidget(label_ed2);
    laybox1->addWidget(edit2);
    laybox1->addWidget(label_ed3);
    laybox1->addWidget(edit3);
    laybox1->addWidget(label_ed4);
    laybox1->addWidget(list);
    laybox1->addStretch(1);
    gbox_base->setLayout(laybox1);

    //GROUPBOX2 ELEMENTS
    gbox_action = new QGroupBox(tr("Action"));
    gbox_action->setFixedWidth(230);
    QVBoxLayout* laybox2 = new QVBoxLayout;
    //button
    button1 = new QPushButton("Start");
    button1 -> setFixedSize(100,30);
    button2 = new QPushButton("Pause");
    button2 -> setFixedSize(100,30);
    button3 = new QPushButton("Restart");
    button3 -> setFixedSize(100,30);

    //layer
    laybox2->addWidget(button1);
    laybox2->addWidget(button2);
    laybox2->addWidget(button3);
    gbox_action->setLayout(laybox2);

    //total gbox and laayer
    QVBoxLayout* laybox = new QVBoxLayout;
    laybox->addWidget(gbox_base);
    laybox->addWidget(gbox_action);
    gbox->setLayout(laybox);
=======
    QPushButton *button1 = new QPushButton("One");
    QPushButton *button2 = new QPushButton("Two");
    QPushButton *button3 = new QPushButton("Three");
    QPushButton *button4 = new QPushButton("Four");
    QPushButton *button5 = new QPushButton("Five");

    layout->addWidget(button1,0,0);
    layout->addWidget(button2, 0, 1);
    layout->addWidget(button3, 1, 0, 1, 2);
    layout->addWidget(button4, 2, 0);
    layout->addWidget(button5, 2, 1);

   // centralWidget->setLayout(layout);

//! [2]
    PixelDelegate *delegate = new PixelDelegate(this);
    view->setItemDelegate(delegate);
//! [2]

//! [3]
    QLabel *pixelSizeLabel = new QLabel(tr("Pixel size:"));
    QSpinBox *pixelSizeSpinBox = new QSpinBox;
    pixelSizeSpinBox->setMinimum(4);
    pixelSizeSpinBox->setMaximum(32);
    pixelSizeSpinBox->setValue(12);
//! [3]

    QMenu *fileMenu = new QMenu(tr("&File"), this);
    QAction *openAction = fileMenu->addAction(tr("&Open..."));
    openAction->setShortcuts(QKeySequence::Open);

    printAction = fileMenu->addAction(tr("&Print..."));
    printAction->setEnabled(false);
    printAction->setShortcut(QKeySequence::Print);

    QAction *quitAction = fileMenu->addAction(tr("E&xit"));
    quitAction->setShortcuts(QKeySequence::Quit);

    QMenu *helpMenu = new QMenu(tr("&Help"), this);
    QAction *aboutAction = helpMenu->addAction(tr("&About"));

    menuBar()->addMenu(fileMenu);
    menuBar()->addSeparator();
    menuBar()->addMenu( helpMenu);

    connect(openAction, &QAction::triggered, this, &MainWindow::chooseImage);
    connect(printAction, &QAction::triggered, this, &MainWindow::printImage);
    connect(quitAction, &QAction::triggered, qApp, &QCoreApplication::quit);
    connect(aboutAction, &QAction::triggered, this, &MainWindow::showAboutBox);
//! [4]
    connect(pixelSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            delegate, &PixelDelegate::setPixelSize);
    connect(pixelSizeSpinBox, QOverload<int>::of(&QSpinBox::valueChanged),
            this, &MainWindow::updateView);
//! [4]

    QHBoxLayout *controlsLayout = new QHBoxLayout;
    controlsLayout->addWidget(pixelSizeLabel);
    controlsLayout->addWidget(pixelSizeSpinBox);
    controlsLayout->addStretch(1);

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(view);

    mainLayout->addLayout(controlsLayout,1,0);
    mainLayout->addLayout(layout,0,1);
    centralWidget->setLayout(mainLayout);

    setCentralWidget(centralWidget);

    setWindowTitle(tr("Game of Life"));
    resize(640, 480);

    tmr = new QTimer();
    tmr->setInterval(200);
    connect(tmr, SIGNAL(timeout()), this, SLOT(updateTime()));
    tmr->start();

    cells = new Cellular(20,12);
    cells->setup(1);

//! [5]
}
//! [5]



void MainWindow::chooseImage()
{
    QString fileName = QFileDialog::getOpenFileName(this,
        tr("Choose an image"), currentPath, "*");

    if (!fileName.isEmpty())
        renderImage();
}

void MainWindow::renderImage()
{
    //QImage image;
    QImage image(12,20,QImage::Format_RGB32);
    QRgb value;

    int** m = cells->display_m();
    for(int i = 0; i < 12; i++)
        for(int j = 0; j < 20; j++)
            if(m[i][j] == 1)
            {
                value = qRgb(1, 1, 1);
                image.setPixel(i,j,value);
            }
            else
            {
                value = qRgb(200, 200, 200);
                image.setPixel(i,j,value);
            }
    //if (image.load(fileName)) {
        model->setImage(image);
       // if (!fileName.startsWith(":/")) {
            currentPath = "ddf";
            setWindowTitle(tr("%1 - Game of Life").arg(currentPath));


        printAction->setEnabled(true);
        updateView();

}


void MainWindow::updateTime()
{
    cells->generation();
    this->renderImage();
}

void MainWindow::printImage()
{
#if QT_CONFIG(printdialog)
    if (model->rowCount(QModelIndex())*model->columnCount(QModelIndex()) > 90000) {
        QMessageBox::StandardButton answer;
        answer = QMessageBox::question(this, tr("Large Image Size"),
                tr("The printed image may be very large. Are you sure that "
                   "you want to print it?"),
        QMessageBox::Yes | QMessageBox::No);
        if (answer == QMessageBox::No)
            return;
    }

    QPrinter printer(QPrinter::HighResolution);

    QPrintDialog dlg(&printer, this);
    dlg.setWindowTitle(tr("Print Image"));

    if (dlg.exec() != QDialog::Accepted) {
        return;
    }

    QPainter painter;
    painter.begin(&printer);

    int rows = model->rowCount(QModelIndex());
    int columns = model->columnCount(QModelIndex());
    int sourceWidth = (columns + 1) * ItemSize;
    int sourceHeight = (rows + 1) * ItemSize;

    painter.save();

    double xscale = printer.pageRect().width() / double(sourceWidth);
    double yscale = printer.pageRect().height() / double(sourceHeight);
    double scale = qMin(xscale, yscale);

    painter.translate(printer.paperRect().x() + printer.pageRect().width() / 2,
                      printer.paperRect().y() + printer.pageRect().height() / 2);
    painter.scale(scale, scale);
    painter.translate(-sourceWidth / 2, -sourceHeight / 2);

    QStyleOptionViewItem option;
    QModelIndex parent = QModelIndex();

    QProgressDialog progress(tr("Printing..."), tr("Cancel"), 0, rows, this);
    progress.setWindowModality(Qt::ApplicationModal);
    float y = ItemSize / 2;

    for (int row = 0; row < rows; ++row) {
        progress.setValue(row);
        qApp->processEvents();
        if (progress.wasCanceled())
            break;

        float x = ItemSize / 2;

        for (int column = 0; column < columns; ++column) {
            option.rect = QRect(int(x), int(y), ItemSize, ItemSize);
            view->itemDelegate()->paint(&painter, option,
                                        model->index(row, column, parent));
            x = x + ItemSize;
        }
        y = y + ItemSize;
    }
    progress.setValue(rows);

    painter.restore();
    painter.end();

    if (progress.wasCanceled()) {
        QMessageBox::information(this, tr("Printing canceled"),
            tr("The printing process was canceled."), QMessageBox::Cancel);
    }
#else
    QMessageBox::information(this, tr("Printing canceled"),
        tr("Printing is not supported on this Qt build"), QMessageBox::Cancel);
#endif
}

void MainWindow::showAboutBox()
{
    QMessageBox::about(this, tr("About the Pixelator example"),
        tr("This example demonstrates how a standard view and a custom\n"
           "delegate can be used to produce a specialized representation\n"
           "of data in a simple custom model."));
}

//! [6]
void MainWindow::updateView()
{
    view->resizeColumnsToContents();
    view->resizeRowsToContents();
}
//! [6]
