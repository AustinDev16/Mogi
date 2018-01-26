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
SolutionController::SolutionController(double poissonRatio, double mu, double chamberRadius, double chamberCenterDepth) {
    MogiPointConfig config = MogiPointConfig();
    config.poissonRatio = poissonRatio;
    config.mu = mu;
    config.chamberRadius = chamberRadius;
    config.chamberCenterDepth = chamberCenterDepth;
    config.centerXCoordinate = 0;
    config.centerYCoordinate = 0;
    mMogiSource = MogiPoint(config);
}

void SolutionController::setCenterCoordinate(double centerX, double centerY){
    mMogiSource.setCenterCoordinate(centerX, centerY);
}

double SolutionController::computeSingle(double dP, double radialDistance) {
    assert(radialDistance >= 0);
    return mMogiSource.calculateDeformation(dP, radialDistance);
}

double SolutionController::computeSingle(double dP, double x, double y) {
    return mMogiSource.calculateDeformation(dP, x, y);
}

vector<double> SolutionController::computeRadialArray(double dP, vector<double> radialArray) {
    vector<double> solutionArray(radialArray.size());
    
    for (int i = 0; i < radialArray.size(); i++) {
        solutionArray[i] = mMogiSource.calculateDeformation(dP, radialArray[i]);
    }
    
    return solutionArray;
}

MatrixXd SolutionController::computeXYGrid(double dP, vector<double> xGrid, vector<double> yGrid) {
    
    MatrixXd solutionArray(xGrid.size(), yGrid.size());
    for (int i = 0; i < xGrid.size(); i++) {
        for (int j = 0; j < yGrid.size(); j++) {
            solutionArray(i,j) = mMogiSource.calculateDeformation(dP, xGrid[i], yGrid[j]);
        }
    }
    return solutionArray;
}

void SolutionController::formatForPlotting1D(){
    
}

void SolutionController::formatForPlotting2D(){
    
}
