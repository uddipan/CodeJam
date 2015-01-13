//
//  main.cpp
//  Minimum Scalar Product
//
//  Created by uddipan mukherjee on 1/12/15.
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
//#define SmallLargeInput


using namespace std;

string GenericName = "/GitHub/CodeJam";

string TestName = "/Round 1A 2008/Minimum Scalar Product/Minimum Scalar Product/";

bool MyFn(int a, int b){return (a>b); }

long MinScalarProd(vector<long> &A, vector<long>&B)
{
    sort(A.begin(), A.end());
    sort(B.begin(), B.end(), MyFn);
    
    long x = 0;
    for(unsigned u=0; u<A.size(); u++)
    {
        x += A[u]*B[u];
    }
    return x;
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
    
    int N, M;
    long tmp;
    vector<long> V1, V2;
    string line;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        infile >> N;
        
        for (int i=0; i<N; i++)
        {
            infile >> M;
            for(int j=0; j<M; j++)
            {
                infile >> tmp;
                V1.push_back(tmp);
            }
            for(int j=0; j<M; j++)
            {
                infile >> tmp;
                V2.push_back(tmp);
            }
            
            outfile << "Case #" << i+1 << ": " << MinScalarProd(V1, V2) <<"\n";
            V1.clear();
            V2.clear();
            
        }
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}

