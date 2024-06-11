#ifndef PROCESSEVERYTHING_H
#define PROCESSEVERYTHING_H




#define _CRT_SECURE_NO_WARNINGS
#include<vector>
#include <cstdint>
#include "tables.h" 
#include <cstdio>
#include <iostream>
#include "OscPoly.h"
#include <sndfile.h>
#include <string>
#include <cmath>
#include "selectAvailableBuff.h"
#include <list>  // to create a list of objects
#include "selectOsc.h"
#include "Envelope.h"
#include <random>
#include "NewNote.h"

void processEverything(const char* outputFileName);
extern std::string waveName;
extern int LenghtInSeconds; 

System::String^ testFunction();

#endif // PROCESSEVERYTHING_H