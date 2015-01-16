//
//  main.cpp
//  Alien Numbers
//
//  Created by uddipan mukherjee on 1/14/15.
//  Copyright (c) 2015 uddipan mukherjee. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <cmath>

// MACRO for selecting the small/large input. Comment out for large input.
#define SmallLargeInput


using namespace std;

string GenericName = "/GitHub/CodeJam";

string TestName = "/Practice Problems/Alien Numbers/Alien Numbers/";

map<char,int> ToDec;
map<int,char> FromDec;

long SourceToDec(string S, int card)
{
    long N = 0;
    long k = S.size() - 1;
    for(unsigned u=0; u<S.size(); u++)
    {
        N += pow(card,k)*ToDec[S[u]];
        k--;
    }
    return N;
}

string DecToTarget(long N, int card)
{
    string S;
    long q = N/card, rem = N%card;
    S.insert(S.begin(), FromDec[int(rem)]);
    while(q)
    {
        N = q;
        q = N/card;
        rem = N%card;
        S.insert(S.begin(), FromDec[int(rem)]);
    }
    return S;
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
    
    
    int T;
    string alien, source, target;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        infile >> T;
        
        for(int i=0; i<T; i++)
        {
            infile >> alien >> source >> target;
            for(unsigned u=0; u<source.size(); u++)
            {
                ToDec[source[u]] = u;
            }
            for(unsigned u=0; u<target.size(); u++)
            {
                FromDec[u] = target[u];
            }
            outfile << "Case #" << i+1 << ": " <<DecToTarget(SourceToDec(alien,int(source.size())), int(target.size()))<<"\n";
            ToDec.clear();
            FromDec.clear();
        }
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}

