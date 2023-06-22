#ifndef LOGSLIDER_H
#define LOGSLIDER_H

#include <QSlider>
#include <QWidget>
#include <QDebug>

class logSlider : public QSlider
{
public:
    logSlider(QWidget* parent = nullptr);

    double logarithmicPosition() const;

    void setLogarithmicPosition(double position);

    void setLogMinimum(double min);

    void setLogMaximum(double max);
};

#endif // LOGSLIDER_H
