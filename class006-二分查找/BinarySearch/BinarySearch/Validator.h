#pragma once
#include<vector>
#include<random>

int randint(int l, int r);
std::vector<int> randomArray(int n, int v);
std::vector<int> copyArray(std::vector<int>& arr);
bool sameArray(const std::vector<int>& arr1, const std::vector<int>& arr2);
void printArray(const std::vector<int>& arr);