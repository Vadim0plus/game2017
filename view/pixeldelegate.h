//========================================================================
// pixeldelegate.h : PixelTable Prototype for program; View part of system
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

#ifndef PIXELDELEGATE_H
#define PIXELDELEGATE_H

#include <QAbstractItemDelegate>
#include <QModelIndex>
#include <QSize>

QT_BEGIN_NAMESPACE
class QAbstractItemModel;
class QObject;
class QPainter;
QT_END_NAMESPACE

static const int ItemSize = 256;

//! [0]
class PixelDelegate : public QAbstractItemDelegate
{
    Q_OBJECT

public:
    PixelDelegate(QObject *parent = 0);

    void paint(QPainter *painter, const QStyleOptionViewItem &option,
               const QModelIndex &index) const override;

    QSize sizeHint(const QStyleOptionViewItem &option,
                   const QModelIndex &index ) const override;

public slots:
    void setPixelSize(int size);

private:
    int pixelSize;
};
//! [0]

#endif // PIXELDELEGATE_H
