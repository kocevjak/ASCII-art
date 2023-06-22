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
    double logMin = log10(min);
    double logMax = log10(max);
    double value = pow(10,position);
    this->setValue(static_cast<int>(value));
}

void logSlider::setLogMinimum(double min){
    this->setMinimum((int)exp(min));
}

void logSlider::setLogMaximum(double max){
    this->setMinimum((int)exp(max));
}
