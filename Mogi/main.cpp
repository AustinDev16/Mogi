//
//  main.cpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#include <iostream>
#include "MogiPoint.hpp"
#include "SolutionController.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
    // Example with pointers and individual classes.
    MogiPointConfig *config = new MogiPointConfig;
    config->chamberCenterDepth = 4e3;
    config->chamberRadius = 500;
    config->mu = 1e6;
    config->poissonRatio = 0.5;
    
    MogiPoint *mogiSource = new MogiPoint(*config);
    
    double val = mogiSource->calculateDeformation(5e6, 5);
    cout << "Value: " << val << endl;
    
    double val2 = mogiSource->calculateDeformation(5e6, 30, 4);
    cout << "Value2: " << val2 << endl;
    // insert code here...
    std::cout << "Hello, World!\n";
    
    delete config;
    delete mogiSource;
    
    // Example using a helper class
    
    double poissonRatio = 0.5;
    double mu = 1e6;
    double chamberRadius = 500;
    double chamberDepth = 4e3;
    SolutionController solControl = SolutionController(poissonRatio, mu, chamberRadius, chamberDepth);
    
    cout << "Value3: " << solControl.computeSingle(5e6, 5) << endl;
    
    cout << "Value 4: " << solControl.computeSingle(5e6, 30, 4) << endl;
    
    // Radial Array test
    vector<double> grid(4);
    grid[0] = 0;
    grid[1] = 5.0;
    grid[2] = 1e3;
    grid[3] = 5e3;
    
    vector<double> solution = solControl.computeRadialArray(5e6, grid);
    
    cout << "Grid test" << endl;
    for (int j = 0; j < grid.size(); j++) {
        // cout << grid[j] << ":" << solution[j] << endl;
    }
    
    cout << "XY Grid test" << endl;
    cout << solControl.computeXYGrid(5e6, grid, grid) << endl;
    
    // Center coordinate test;
    solControl.setCenterCoordinate(10, 20);
//    cout << "Value3: " << solControl.computeSingle(5e6, 5) << endl;
    
    cout << "Value 4: " << solControl.computeSingle(5e6, 40, 20) << endl;
    
    return 0;
}
