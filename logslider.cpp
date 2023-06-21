#include "logslider.h"

logSlider::logSlider(QWidget* parent) : QSlider(parent)
{

}

double logSlider::logarithmicPosition() const
{
    int value = this->value();
    double min = this->minimum();
    double max = this->maximum();
    double logMin = log(min);
    double logMax = log(max);
    double position = (log(value) - logMin) / (logMax - logMin);
    return position;
}

void logSlider::setLogarithmicPosition(double position){
    double min = this->minimum();
    double max = this->maximum();
    double logMin = log(min);
    double logMax = log(max);
    double value = exp(logMin + position * (logMax - logMin));
    this->setValue(static_cast<int>(value));
}
