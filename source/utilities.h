//
// Created by Mrinal Rawool on 5/21/19.
//

#ifndef PROJECT_UTILITIES_H
#define PROJECT_UTILITIES_H

#include "headers.h"

extern ostringstream err;

void info();
void help(int required, int actual);
void display(string windowName, Mat& image, bool save=false);

#endif //PROJECT_UTILITIES_H
