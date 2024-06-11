#include "pch.h"


#include "Form1.h"  // i changed this to the top because #include <msclr/marshal_cppstd.h> was causing problems

using namespace System;

// int main(array<System::String ^> ^args)
// {
//    return 0;
// }



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
#include "processEverything.h"

using namespace System::Windows::Forms;

[STAThread]
int main()
{
  Application::EnableVisualStyles();
  Application::SetCompatibleTextRenderingDefault(false);

  int testing = 0; 
  testing = 42; 
  int test2 = testing + 100;

  Application::Run(gcnew CppCLRWinFormsProject::Form1());
  return 0;
}