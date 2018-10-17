#pragma once
#include <iostream>
#include <vector>
#include <algorithm>
#include <time.h>
#include <memory>
#include <ctime>
#include "Figure.h"

int random(int a, int b);
std::vector<std::shared_ptr<Figure>> GenerateVectorFigure(int quantity);
void SplitFiguresIntoCircles(std::vector<std::shared_ptr<Figure>> &vecFigure, std::vector<std::shared_ptr<Circle>> &vecCircle);
double GetSumRadiusCircles(const std::vector<std::shared_ptr<Circle>> vecCircle);
int main(int argc, char** argv);
