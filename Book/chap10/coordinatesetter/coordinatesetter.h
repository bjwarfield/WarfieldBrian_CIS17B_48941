#ifndef COORDINATESETTER_H
#define COORDINATESETTER_H

#include <QDialog>
#include <QDialogButtonBox>
#include <QList>
#include <QPointF>
#include <qtablewidget.h>

//class QDialogButtonBox;
//class QTableWidget;

class CoordinateSetter : public QDialog
{
    Q_OBJECT

public:
    CoordinateSetter(QList<QPointF> *coords, QWidget *parent = 0);

    void done(int result);

private slots:
    void addRow();

private:
    QTableWidget *tableWidget;
    QDialogButtonBox *buttonBox;
    QList<QPointF> *coordinates;
};

#endif
