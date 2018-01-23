//
//  main.cpp
//  Mogi
//
//  Created by Austin Blaser on 1/11/18.
//  Copyright © 2018 Austin Blaser. All rights reserved.
//

#include <iostream>
#include "MogiPoint.hpp"
using namespace std;

int main(int argc, const char * argv[]) {
    
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
    
    return 0;
}
