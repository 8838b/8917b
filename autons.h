#pragma once
#include "JAR-Template/drive.h"

class Drive;

extern Drive chassis;

void default_constants();

void FEIN(); 
void solo_awp(); 
void half_awp(); 
void right_control(); 
void left_control(); 
void right_elims(); 
void left_elims(); 
void feinious(); 

void midPiston();
void doinkerPiston();
void armPiston();
void ptoPiston();

// Declare task functions
int detectRedTask();
int detectBlueTask();

// Declare task objects
extern vex::task redTask;
extern vex::task blueTask;



#include <iostream>
#include "vex.h"

