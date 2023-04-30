
#ifndef _PRECOND_VIOLATED_EXCEP
#define _PRECOND_VIOLATED_EXCEP
#include<iostream>
#include <stdexcept>
#include <string>
using namespace std;

class PrecondViolatedExcep : public logic_error
{
public:
   PrecondViolatedExcep(const string& message = "");
}; // end PrecondViolatedExcep 
#include "PrecondViolatedExcep.h"
PrecondViolatedExcep::PrecondViolatedExcep(const string& message) : logic_error("Precondition Violated Exception: " + message)
{
	//cout << "Not Found Exception: " + message << endl;
}  // end constructor
#endif
