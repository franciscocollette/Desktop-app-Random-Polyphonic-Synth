#ifndef SELECT_OSC_H
#define SELECT_OSC_H
#include <cmath>
#include <sndfile.h>
#include <vector>
#include "OscPoly.h";
#include<list>;


extern std::list<Osc*> oscList;
Osc* selectOsc(std::vector<double> availableBuff, std::vector<std::vector<double>*> buffFixedList, std::list<Osc*> oscList);


#endif // SELECT_OSC_H