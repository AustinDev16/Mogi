//
//  MogiPoint.hpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#ifndef MogiPoint_hpp
#define MogiPoint_hpp

#include <stdio.h>
#include <math.h>
#include <assert.h>
struct MogiPointConfig {
    double poissonRatio; // v
    double mu; //
    double chamberRadius; // a, meters
    double chamberCenterDepth; // d, meters
    double centerXCoordinate; // meters
    double centerYCoordinate; // meters
};

struct Point {
    double x;
    double y;
};

class MogiPoint {
private:
    MogiPointConfig configuration;
    double mogiPointEngine(double k, double dP);
    double convertCartesianToRadial(double x, double y);
    Point sanitizeCartesian(double x, double y);
public:
    MogiPoint();
    MogiPoint(MogiPointConfig config);
    double calculateDeformation(double deltaP, double radialDistance);
    double calculateDeformation(double deltaP, double x, double y);
    void setCenterCoordinate(double centerX, double centerY);
};
#endif /* MogiPoint_hpp */
