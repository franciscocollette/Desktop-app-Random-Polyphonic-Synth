#include "pch.h"

#include <cmath>
#include <sndfile.h>
#include <vector>
#include "OscPoly.h"
#include<list>
#include "selectOsc.h"
#include <algorithm>
#include <iostream>


bool compareVectors(const std::vector<double>& v1, const std::vector<double>& v2) {
    return std::equal(v1.begin(), v1.end(), v2.begin(), v2.end());
}

Osc* selectOsc(std::vector<double> availableBuff, std::vector<std::vector<double>*> buffFixedList, std::list<Osc*> oscList) {
    auto oscIterator = oscList.begin();
    for (int i = 0; i < buffFixedList.size(); i++) {
        if (compareVectors(availableBuff, *buffFixedList[i])) {
            return *oscIterator;
        }
        ++oscIterator;
    }
    std::cout << "error selecting Osc, returning first oscilator..." << std::endl;
    return *oscList.begin();
}