//
//  main.cpp
//  T9 Spelling
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

string TestName = "/Qual_africa_2010/T9 Spelling/T9 Spelling/";

void GetSeq(string &line, string &seq)
{
    char temp = NULL;
    for (unsigned u=0; u < line.size(); u++)
    {
        if (line[u] == ' ')
        {
            if (temp == '0')
            {
                seq.push_back(' ');
            }
            seq.push_back('0');
            temp = '0';
        }
        else if (line[u] < 'p')
        {
            int tmp = int(line[u] -'a');
            char c = char(50 + tmp/3);
            if (temp == c)
            {
                seq.push_back(' ');
            }
            
            for (int i=0; i<=(tmp%3); i++)
            {
                seq.push_back(c);
            }
            temp = c;
        }
        else if (line[u] < 't')
        {
            if (temp == '7')
            {
                seq.push_back(' ');
            }
            int tmp = int(line[u] -'p');
            for (int i=0; i<=(tmp%4); i++)
            {
                seq.push_back('7');
            }
            temp = '7';
        }
        else if (line[u] < 'w')
        {
            if (temp == '8')
            {
                seq.push_back(' ');
            }
            int tmp = int(line[u] -'t');
            for (int i=0; i<=(tmp%3); i++)
            {
                seq.push_back('8');
            }
            temp = '8';
        }
        else if (line[u] <= 'z')
        {
            if (temp == '9')
            {
                seq.push_back(' ');
            }
            int tmp = int(line[u] -'w');
            for (int i=0; i<=(tmp%4); i++)
            {
                seq.push_back('9');
            }
            temp = '9';
        }
        
    }
}

int main(int argc, const char * argv[]) {
    string InFileName, OutFileName;
    
#ifdef SmallLargeInput
    InFileName = GenericName + TestName + "C-small-practice.in";
    OutFileName = GenericName + TestName + "output-small.out";
#else
    InFileName = GenericName + TestName + "C-large-practice.in";
    OutFileName = GenericName + TestName + "output-large.out";
#endif
    
    int N;
    string line, Seq;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        getline(infile,line);
        N = atoi(line.c_str());
        
        for(int i=0; i < N; i++)
        {
            getline(infile, line);
            GetSeq(line, Seq);
            outfile << "Case #" << i+1 << ": " << Seq <<"\n";
            Seq.clear();
        }
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}


