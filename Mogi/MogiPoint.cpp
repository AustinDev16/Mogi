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

MogiPoint::MogiPoint() {
    MogiPointConfig config = MogiPointConfig();
    config.poissonRatio = 0.5;
    config.mu = 1e6;
    config.chamberRadius = 1;
    config.chamberCenterDepth = 1e3;
    config.centerXCoordinate = 0;
    config.centerYCoordinate = 0;
    configuration = config;
}

void MogiPoint::setCenterCoordinate(double centerX, double centerY) {
    configuration.centerXCoordinate = centerX;
    configuration.centerYCoordinate = centerY;
}

double MogiPoint::calculateDeformation(const double deltaP, double radialDistance) {
    double value = mogiPointEngine(radialDistance, deltaP);
    return value;
}

double MogiPoint::calculateDeformation(double deltaP, double x, double y) {
    Point sp = sanitizeCartesian(x, y);
    double k = convertCartesianToRadial(sp.x, sp.y);
    return mogiPointEngine(k, deltaP);
}

// Private
double MogiPoint::mogiPointEngine(double k, double dP) {
    assert(k >= 0);
    MogiPointConfig c = configuration;
    return ( ((1-c.poissonRatio) * dP * pow(c.chamberRadius, 3.0) )/(c.mu) ) * ((c.chamberCenterDepth)/(pow((pow(k, 2.0) + pow(c.chamberCenterDepth, 2.0)), 1.5)));
}

double MogiPoint::convertCartesianToRadial(double x, double y) {
    return sqrt(pow(x, 2.0) + pow(y, 2.0));
}

Point MogiPoint::sanitizeCartesian(double x, double y) {
    
    Point sanitizedPoint;
    sanitizedPoint.x = x - configuration.centerXCoordinate;
    sanitizedPoint.y = y - configuration.centerYCoordinate;
    return sanitizedPoint;
}
