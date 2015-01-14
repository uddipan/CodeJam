//
//  main.cpp
//  MilkShakes
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

string TestName = "/Round 1A 2008/MilkShakes/MilkShakes/";

struct Person
{
    vector<pair<int,int>> bubble;
    bool visited;
};

int main(int argc, const char * argv[]) {
    string InFileName, OutFileName;
    
#ifdef SmallLargeInput
    InFileName = GenericName + TestName + "B-small-practice.in";
    OutFileName = GenericName + TestName + "output-small.out";
#else
    InFileName = GenericName + TestName + "B-large-practice.in";
    OutFileName = GenericName + TestName + "output-large.out";
#endif
    
    
    int N, shakes, cust, types;
    pair<int,int>tmp;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        infile >> N;
        
        for(int i=0; i<N; i++)
        {
            infile >> shakes >> cust;
            vector<Person> AllCustomers(cust);
            queue<int> MaltOnly;
            
            for(int j=0; j<cust; j++)
            {
                infile >> types;
                for(int k=0; k<types; k++)
                {
                    infile >> tmp.first >> tmp.second;
                    AllCustomers[j].bubble.push_back(tmp);
                    AllCustomers[j].visited = false;
                }
                if((types == 1) && (tmp.second == 1))
                {
                    MaltOnly.push(j);
                    AllCustomers[j].visited = true;
                }
            }
            
            bool Impossible = false;
            while(!MaltOnly.empty())
            {
                int front = MaltOnly.front();
                MaltOnly.pop();
                int ShakeType = AllCustomers[front].bubble[0].first;
                
                for(unsigned u=0; u<AllCustomers.size(); u++)
                {
                    if (u == front)
                    {
                        continue;
                    }
                    for(unsigned v=0; v<AllCustomers[u].bubble.size(); v++)
                    {
                        if((AllCustomers[u].bubble[v].first == ShakeType)
                           && AllCustomers[u].bubble[v].second == 0)
                        {
                            AllCustomers[u].bubble.erase(AllCustomers[u].bubble.begin()+v);
                            break;
                        }
                    }
                    if(AllCustomers[u].bubble.size() == 1)
                    {
                        if((AllCustomers[u].bubble[0].second == 1)
                           && (AllCustomers[u].bubble[0].first != ShakeType)
                           && (AllCustomers[u].visited == false))
                        {
                            MaltOnly.push(u);
                            AllCustomers[u].visited = true;
                        }
                    }
                }
            }
            vector<int>seq(shakes,0);
            for(unsigned u=0; u<AllCustomers.size(); u++)
            {
                if(AllCustomers[u].bubble.empty())
                {
                    Impossible = true;
                    break;
                }
                if(AllCustomers[u].bubble.size() == 1)
                {
                    if(AllCustomers[u].bubble[0].second == 1)
                    {
                        seq[AllCustomers[u].bubble[0].first-1] = 1;
                    }
                }
            }
            
            if(Impossible)
            {
                outfile << "Case #" << i+1 << ": " << "IMPOSSIBLE" <<"\n";
            }
            else
            {
                outfile << "Case #" << i+1 << ": ";
                for(unsigned u=0; u<seq.size(); u++)
                {
                    outfile << seq[u]<<" ";
                }
                outfile << "\n";
            }
            
        }
        
        
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}


