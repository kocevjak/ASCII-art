#ifndef LOGSLIDER_H
#define LOGSLIDER_H

#include <QSlider>
#include <QWidget>


class logSlider : public QSlider
{
public:
    logSlider(QWidget* parent = nullptr);

    double logarithmicPosition() const;

    void setLogarithmicPosition(double position);
};

#endif // LOGSLIDER_H
