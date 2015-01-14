//
//  main.cpp
//  Numbers
//
//  Created by uddipan mukherjee on 1/13/15.
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

string TestName = "/Round 1A 2008/Numbers/Numbers/";

struct Mat22
{
    int row1[2];
    int row2[2];
};

Mat22 Mat22Prod(Mat22 &A, Mat22 &B)
{
    Mat22 X;
    X.row1[0] = (A.row1[0]*B.row1[0] + A.row1[1]*B.row2[0])%1000;
    X.row1[1] = (A.row1[0]*B.row1[1] + A.row1[1]*B.row2[1])%1000;

    X.row2[0] = (A.row2[0]*B.row1[0] + A.row2[1]*B.row2[0])%1000;
    X.row2[1] = (A.row2[0]*B.row1[1] + A.row2[1]*B.row2[1])%1000;

    return X;
}

Mat22 FastExp(Mat22 &M, int N)
{
    if(N ==1)
    {
        return M;
    }
    if(N%2 == 0)
    {
        Mat22 A = FastExp(M, N/2);
        return Mat22Prod(A, A);
    }
    else
    {
        Mat22 A = FastExp(M, N-1);
        return Mat22Prod(M, A);
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
    
    
    int N, T;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        infile >> T;
        
        Mat22 A;
        A.row1[0] = 3; A.row1[1] = 5;
        A.row2[0] = 1; A.row2[1] = 3;
        
        for(int i=0; i<T; i++)
        {
            infile >> N;
            Mat22 B = FastExp(A, N);
            int op = (2*B.row1[0] + 999)%1000;
            int k = 100;
            outfile << "Case #" << i+1 << ": " ;
            for (int j=0; j<3; j++)
            {
                outfile << op/k;
                op%=k;
                k/=10;
            }
            outfile << "\n";
        }
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}

