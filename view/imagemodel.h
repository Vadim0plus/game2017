//========================================================================
// imagemodel.h : ImageModel Prototype for program; View part of system
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

#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QAbstractTableModel>
#include <QImage>

//! [0]
class ImageModel : public QAbstractTableModel
{
    Q_OBJECT

public:
    ImageModel(QObject *parent = 0);

    void setImage(const QImage &image);

    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

private:
    QImage modelImage;
};
//! [0]

#endif // IMAGEMODEL_H
