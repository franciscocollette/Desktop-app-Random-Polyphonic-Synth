
// selectAvailableBuff.h

#include <vector>
#include <iostream>

#ifndef SELECT_AVAILABLE_BUFF_H
#define SELECT_AVAILABLE_BUFF_H

// Function declaration
extern std::vector<std::vector<double>*> buffersInOrder;
std::vector<double>* selectAvailableBuff(std::vector<std::vector<double>*>& buffArray);

#endif // SELECT_AVAILABLE_BUFF_H