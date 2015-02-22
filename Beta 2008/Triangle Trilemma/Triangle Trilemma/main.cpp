
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

string TestName = "/Beta 2008/Triangle Trilemma/Triangle Trilemma/";

#define PI 3.14159265359
#define epsilon 0.001

struct Vec2
{
    int x,y;
    Vec2(){x=0;y=0;}
    Vec2(int a, int b){x=a;y=b;}
    double magnitude()
    {
        return sqrt(double(x*x+y*y));
    }
};

double DotProd(const Vec2 &A, const Vec2 &B)
{
    return double(A.x*B.x + A.y*B.y);
}

double CrossProd(const Vec2 &A, const Vec2 &B)
{
    return double(A.x*B.y - A.y*B.x);
}

double limit(double a)
{
    a = max(a, -1.0);
    a = min(a, 1.0);
    return a;
}

bool InRange(double a, double b)
{
    if ( abs(a-b) < epsilon)
        return true;
    return false;
}

string Type1(int x1, int y1, int x2, int y2, int x3, int y3)
{
    string s = "acute";
    double alpha1, alpha2, alpha3;
    Vec2 AB(x2-x1, y2-y1), BC(x3-x2, y3-y2), CA(x1-x3, y1-y3);
    alpha1 = PI - acos(limit(DotProd(AB, BC)/(AB.magnitude()*BC.magnitude())));
    alpha2 = PI - acos(limit(DotProd(BC, CA)/(BC.magnitude()*CA.magnitude())));
    alpha3 = PI - acos(limit(DotProd(CA, AB)/(CA.magnitude()*AB.magnitude())));
    
    if ((InRange(alpha1, PI/2)) || (InRange(alpha2, PI/2)) || (InRange(alpha3, PI/2)))
        s = "right";
    else if ((alpha1 > PI/2) || (alpha2 > PI/2) || (alpha3 > PI/2))
        s = "obtuse";
    return s;
}

string Type2(int x1, int y1, int x2, int y2, int x3, int y3)
{
    string s = "scalene";
    int L1 = (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
    int L2 = (x3-x2)*(x3-x2) + (y3-y2)*(y3-y2);
    int L3 = (x1-x3)*(x1-x3) + (y1-y3)*(y1-y3);
    
    if ((L1 == L2) || (L2 == L3) || (L1 == L3))
        s = "isosceles";
    return s;
}

bool IsEmpty(int x1, int y1, int x2, int y2, int x3, int y3)
{
    double Area = x1*(y2 - y3) + x2*(y3 - y1) + x3*(y1 - y2);
    if (InRange(Area, 0.0))
        return true;
    return false;
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
    
    
    string line;
    int N, x1, y1, x2, y2, x3, y3;
    ifstream infile ( InFileName );
    ofstream outfile ( OutFileName );
    
    if (infile.is_open())
    {
        infile >> N;
        for (int i=0; i<N; i++)
        {
            infile >>x1 >> y1 >> x2 >> y2 >> x3 >> y3;
            if (IsEmpty(x1, y1, x2, y2, x3, y3))
            {
                outfile << "Case #" << i+1 << ": " << "not a triangle" << "\n";
            }
            else
            {
                outfile << "Case #" << i+1 << ": " << Type2(x1, y1, x2, y2, x3, y3) << " "
                << Type1(x1, y1, x2, y2, x3, y3) << " " << "triangle" << "\n";
            }
        }
        
        infile.close();
        outfile.close();
    }
    
    return 0;
}

