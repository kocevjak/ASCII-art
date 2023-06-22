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
    this->setValue((int)(log10(position)*this->scale));
}

void logSlider::setLogMinimum(double min){
    if(min > 0){
        this->setMinimum((int)(log10(min)*this->scale));
    }
}

void logSlider::setLogMaximum(double max){
    if(max > 0){
        this->setMaximum((int)(log10(max)*this->scale));
    }
}

void logSlider::setScale(int scale){
    this->scale = scale;
}
