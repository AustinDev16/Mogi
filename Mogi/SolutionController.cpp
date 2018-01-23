//
//  SolutionController.cpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#include "SolutionController.hpp"

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

std::vector<double> SolutionController::computeRadialArray(double dP, std::vector<double> radialArray) {
    std::vector<double> solutionArray(radialArray.size());
    return solutionArray;
}

std::vector<double> SolutionController::computeXYGrid(double dP, std::vector<double> xGrid, std::vector<double> yGrid) {
    
    std::vector<double> solutionArray(0);
    return solutionArray;
}

void SolutionController::formatForPlotting1D(){
    
}

void SolutionController::formatForPlotting2D(){
    
}
