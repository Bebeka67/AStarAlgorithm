#ifndef BRIDGE_H
#define BRIDGE_H

#include <QObject>

class Bridge : public QObject
{
    Q_OBJECT
public:
    explicit Bridge(QObject *parent = nullptr);

    Q_PROPERTY(int column READ column WRITE setColumn NOTIFY columnChanged)
    Q_PROPERTY(int row READ row WRITE setRow NOTIFY rowChanged)


    int column() const;
    int row() const;


signals:

    void columnChanged(int column);
    void rowChanged(int row);

public slots:

    void setColumn(int column);
    void setRow(int row);

private:

    int m_column;
    int m_row;

};

#endif // BRIDGE_H
