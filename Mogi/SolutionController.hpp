//
//  SolutionController.hpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#ifndef SolutionController_hpp
#define SolutionController_hpp

#include <stdio.h>
#include "MogiPoint.hpp"
#include <vector>
using namespace std;
class SolutionController {
private:
    MogiPoint mMogiSource;
public:
    SolutionController(double poissonRatio, double mu, double chamberRadius, double chamberCenterDepth);
    double computeSingle(double dP, double radialDistance);
    vector<double> computeRadialArray(double dP, vector<double> radialDistanceArray);
    vector<double> computeXYGrid(double dP, vector<double> xGrid, vector<double> yGrid);
    void formatForPlotting1D();
    void formatForPlotting2D();
};
#endif /* SolutionController_hpp */
