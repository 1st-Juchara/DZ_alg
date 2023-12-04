#pragma once
#include <iostream>
#include <fstream>
#include <format>
#include <chrono>

void Dubenko(std::ifstream& fin);
void Kondarev(std::ifstream& fin);
void TimirbaevErnest(std::ifstream& fin);
void TimirbaevErik(std::ifstream& fin);
void Varligin(std::ifstream& fin);
void Zaharov(std::ifstream& fin);
int tryChoose(std::ifstream& fin, int min = -9999, int max = 9999);