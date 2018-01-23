//
//  SolutionController.cpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#include "SolutionController.hpp"
// using namespace std;
// Public
SolutionController::SolutionController(double poissonRation, double mu, double chamberRadius, double chamberCenterDepth) {
    MogiPointConfig config = MogiPointConfig();
    config.poissonRatio = 0.5;
    config.mu = 1e6;
    config.chamberRadius = 1;
    config.chamberCenterDepth = 1e3;
    mMogiSource = MogiPoint(config);
}

double SolutionController::computeSingle(double dP, double radialDistance) {
    return mMogiSource.calculateDeformation(dP, radialDistance);
}

vector<double> SolutionController::computeRadialArray(double dP, vector<double> radialArray) {
    vector<double> solutionArray(radialArray.size());
    return solutionArray;
}

vector<double> SolutionController::computeXYGrid(double dP, vector<double> xGrid, vector<double> yGrid) {
    
    vector<double> solutionArray(0);
    return solutionArray;
}

void SolutionController::formatForPlotting1D(){
    
}

void SolutionController::formatForPlotting2D(){
    
}
