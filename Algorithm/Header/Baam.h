#pragma once
#include <string>
#include <vector>
#include<iostream>
using namespace std;
class Baam
{
public:
    Baam();
    ~Baam();
    void Input();
    void Solve();
    void DoSelf();
private:
    vector<vector<int>> bMap;
    int N = 0, K = 0;
    vector<pair<int, int>> applePos;
    int L = 0;
    vector<pair<int, int>> actionQueue;
};

Baam::Baam()
{
}

Baam::~Baam()
{
}
