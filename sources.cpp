#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
class Prime
{
public:
    bool isPrime(unsigned n)
    {
        if(n==1 || n==0) return false;
        for(unsigned i=2;i<=sqrt(n);i++)
        {
            if(n%i==0) return false;
            else continue;
        }
        return true;
    }

    vector<unsigned> Factorization(unsigned n)
    {
        vector<unsigned> res;
        if(isPrime(n))
        {
            res.push_back(n);
            return res;
        }
        unsigned a=n;
        for(unsigned i=2;i<=a;i++)
        {
            if(a%i==0)
            {
                if(isPrime(i))
                {
                    while(a%i==0)
                    {
                        a/=i;
                        res.push_back(i);
                    }
                }
            }
        }
        return res;
    }
};

class taylor{
public:
    taylor(){}
    double series(double x, double eps){
        double sum=x, h; int i=4;
        h=(-1)*(pow(x,3)/6);
        do{
            sum+=h;  //Формула очередного слагаемого
            h*=(-1)*((pow(x,2)/((i)*(i+1))));
            i+=2;}
        while( fabs(h)>eps );
        return sum;
    }
};

class Roots
{
public:
    vector<double> Disc(double a,double b,double c)
    {
        double x1, x2, d;
        vector<double> res;
        d = pow(b, 2) - 4 * a * c;
        if (d < 0)
        {
            return res;
        }
        x1 = (-b - sqrt(d)) / (2 * a);
        x2 = (-b + sqrt(d)) / (2 * a);
        res.push_back(x1);
        res.push_back(x2);
        return res;
    }
};
