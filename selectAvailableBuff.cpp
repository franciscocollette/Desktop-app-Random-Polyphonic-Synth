//tested and working well
#include "pch.h"
#include "selectAvailableBuff.h"
#include <vector>
#include <iostream>


std::vector<std::vector<double>*> buffersInOrder;   // a list of pointers 
//std::vector<std::vector<double>> buffersInOrder;
std::vector<double>* selectAvailableBuff(std::vector<std::vector<double>*>& buffArray) {



	std::vector<double>* emptyBuff = nullptr;
	double sampleSum = 0;
	for (int i = 0; i < buffArray.size(); i++) {
		sampleSum = 0;
		for (int j = 0; j < buffArray[i]->size(); j++) {
			sampleSum += (*buffArray[i])[j];
		}
		//	std::cout << sampleSum <<" are the values for the buff:"<< i << std::endl;
		if (sampleSum == 0) {
			//		std::cout << "found an array with all samples 0 " << i << std::endl;
			emptyBuff = buffArray[i];
			std::vector<double>* temp = buffArray[i];  // select the current buffer
			if (buffArray.size() >= buffersInOrder.size()) { buffersInOrder.erase(buffersInOrder.begin() + i); }  // delete the current buffer 
			buffersInOrder.insert(buffersInOrder.begin(), temp);      // put the current buff at the begining 
			return emptyBuff;
		}
		else {
			emptyBuff = buffersInOrder.back();   // returns the last buffer of the array
		}
		sampleSum = 0;

		//	std::cout << i << " in buffer Order:" << std::endl;
		//	for (int j = 0; j < buffersInOrder[i].size(); j++) {   // printing the buffersInOrder list
		//		std::cout << buffersInOrder[i][j] << std::endl;
		//	}
	}

	//	std::cout << "just throwin the last buff "  << std::endl;
	std::vector<double>* temporal = buffersInOrder.back();  // select the last buffer of the list 
	buffersInOrder.erase(buffersInOrder.begin() + buffArray.size() - 1); // deletes the last buffer in the list
	buffersInOrder.insert(buffersInOrder.begin(), temporal); // put the last element at the begining

	return emptyBuff;
}