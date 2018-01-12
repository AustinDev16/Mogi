//
//  MogiPoint.cpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#include "MogiPoint.hpp"

// Public
MogiPoint::MogiPoint(MogiPointConfig config) {
    configuration = config;
}

double MogiPoint::calculateDeformation(double deltaP, double radialDistance) {
    double value = mogiPointEngine(radialDistance, deltaP);
    return value;
}

double MogiPoint::calculateDeformation(double deltaP, double x, double y) {
    double k = convertCartesianToRadial(x, y);
    return mogiPointEngine(k, deltaP);
}

// Private
double MogiPoint::mogiPointEngine(double k, double dP) {
    assert(k > 0);
    MogiPointConfig c = configuration;
    return ( ((1-c.poissonRatio) * dP * pow(c.chamberRadius, 3.0) )/(c.mu) ) * ((c.chamberCenterDepth)/(pow((pow(k, 2.0) + pow(c.chamberCenterDepth, 2.0)), 1.5)));
}

double MogiPoint::convertCartesianToRadial(double x, double y) {
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}
