//
//  main.cpp
//  Reverse Words
//
//  Created by uddipan mukherjee on 1/11/15.
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

string TestName = "/Qual_africa_2010/Reverse Words/Reverse Words/";

void ReverseWords(string &S, stack <string> &Srev)
{
    unsigned first = 0, last = 0;
    while (last < S.size())
    {
        if (S[last] == ' ')
        {
            Srev.push(S.substr(first, last-first));
            first = last + 1;
        }
        last++;
    }
    Srev.push(S.substr(first));
}

int main(int argc, const char * argv[]) {
    string InFileName, OutFileName;
    
#ifdef SmallLargeInput
    InFileName = GenericName + TestName + "B-small-practice.in";
    OutFileName = GenericName + TestName + "output-small.out";
#else
    InFileName = GenericName + TestName + "B-large-practice.in";
    OutFileName = GenericName + TestName + "output-large.out";
#endif
    
    int N;
    string line;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        getline(infile,line);
        N = atoi(line.c_str());
        
        for (int i=0; i < N; i++)
        {
            getline(infile,line);
            stack <string> Srev;

            ReverseWords(line, Srev);
            
            if (outfile.is_open())
            {
                outfile << "Case #" << i+1 << ": " ;
                while (!Srev.empty())
                {
                    outfile << Srev.top() << " ";
                    Srev.pop();
                }
                outfile << "\n";
            }
            
        }
        
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}

