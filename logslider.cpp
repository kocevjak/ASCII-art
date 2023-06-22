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
    double value = log10(position)*100;
    this->setValue((int)((position) - pow(10,this->minimum())));
}

void logSlider::setLogMinimum(double min){
    if(min > 0){
        this->setMinimum((int)(log10(min)*100));
    }
}

void logSlider::setLogMaximum(double max){
    if(max > 0){
        this->setMaximum((int)(log10(max)*100));
    }
}
