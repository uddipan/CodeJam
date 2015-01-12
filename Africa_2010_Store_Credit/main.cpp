//
//  main.cpp
//  Store Credit
//
//  Created by uddipan mukherjee on 1/10/15.
//  Copyright (c) 2015 uddipan mukherjee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>

// MACRO for selecting the small/large input. Comment out for large input.
#define SmallLargeInput


using namespace std;

string GenericName = "/Users/uddipan/GitHub/GCodejam/";

string TestName = "/Qualification Round Africa 2010/Store Credit/Store Credit/";

bool myfunction (pair<int,int>p1, pair<int,int>p2)
{
    return (p1.first < p2.first);
}

void FindItems(vector<pair<int,int>> &Items, int *a, int *b, int C)
{
    sort(Items.begin(), Items.end(), myfunction);
    int First =0;
    int Last = int (Items.size() - 1);
    
    *a =0;
    *b =1;
    
    while ((First < Last))
    {
        int sum = Items[First].first + Items[Last].first;
        if (sum == C)
        {
            *a = min(Items[First].second, Items[Last].second);
            *b = max(Items[First].second, Items[Last].second);
            return;
        }
        else if (sum > C)
        {
            Last--;
        }
        else First++;
        
    }

    
}

int main(int argc, const char * argv[]) {
    string InFileName, OutFileName;
    
#ifdef SmallLargeInput
    InFileName = GenericName + TestName + "A-small-practice.in";
    OutFileName = GenericName + TestName + "output-small.out";
#else
    InFileName = GenericName + TestName + "A-large-practice.in";
    OutFileName = GenericName + TestName + "output-large.out";
#endif
    
    //Read from file-------------------------
    int N,C,I,tmp, Item1, Item2;
    vector <pair<int,int>> Items;
    
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        infile >> N;
        for (int i=0; i < N; i++)
        {
            infile >> C;
            infile >> I;
            for (int j=0; j < I; j++)
            {
                infile >> tmp;
                Items.push_back(make_pair(tmp,j+1));
            }
        
        
            if (outfile.is_open())
            {
                FindItems(Items, &Item1, &Item2, C);
                outfile << "Case #" << i+1 << ": " << Item1 << " " << Item2 <<"\n";
            }
            
            Items.clear();
        
        }
        infile.close();
        outfile.close();
    }

    return 0;
}
