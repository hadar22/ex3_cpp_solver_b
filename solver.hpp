#pragma once

#include <iostream>
#include <complex>
#include <cmath>

 namespace solver{

   


    class RealVariable{
     private :  
                               //ax^2+bx+c
            
 public:
    double _a,_b,_c;
    RealVariable():_a(0),_b(1),_c(0){};
    RealVariable(double a,double b, double c): _a(a), _b(b),_c(c){};
   // RealVariable(double a):_a(a),_b(0),_c(0){};

    RealVariable& operator+(  double y);
    RealVariable& operator+(const RealVariable& x);
    friend RealVariable& operator+( double x,const RealVariable& y);

    RealVariable& operator-( double y);
    RealVariable& operator-(const RealVariable& x);
    friend RealVariable& operator-(double x, const RealVariable& y);


    RealVariable& operator/(  double y);
    RealVariable& operator/(const RealVariable& x);
    friend RealVariable& operator/(double x,const RealVariable& y);

    RealVariable& operator*( double y);
    RealVariable& operator*(const RealVariable& x);
    friend RealVariable& operator*(double x,const RealVariable& y);

    RealVariable& operator==( double y);
    RealVariable& operator==(const RealVariable& x);
    friend RealVariable& operator==(double x, const RealVariable& y);

    
    RealVariable& operator^( const int y);

    

    };
    class ComplexVariable{
        private:
           

    public: 
    std::complex<double> c_a,c_b,c_c;   
    ComplexVariable():c_a(std::complex<double>(0,0)),c_b(std::complex<double>(1,0)),c_c(std::complex<double>(0,0)){};
    ComplexVariable(std::complex<double> x, std::complex<double> y, std::complex<double> z):c_a(x),c_b(y),c_c(z){};

    ComplexVariable& operator+(const double z);
     ComplexVariable& operator+(const ComplexVariable& x);
    ComplexVariable& operator+(std::complex<double> y);
    friend ComplexVariable& operator+(const double z, ComplexVariable& x);
    friend ComplexVariable& operator+(std::complex<double> y, ComplexVariable& x);


    ComplexVariable& operator-(const double z);
     ComplexVariable& operator-(const ComplexVariable& x);
    ComplexVariable& operator-(std::complex<double> y);
    friend ComplexVariable& operator-(const double z, ComplexVariable& x);
    friend ComplexVariable& operator-(std::complex<double> y, ComplexVariable& x);


    ComplexVariable& operator/(const double z);
     ComplexVariable& operator/(const ComplexVariable& x);
    ComplexVariable& operator/(std::complex<double> y);
    friend ComplexVariable& operator/(const double z, ComplexVariable& x);
    friend ComplexVariable& operator/(std::complex<double> y, ComplexVariable& x);

     ComplexVariable& operator*(const double z);
     ComplexVariable& operator*(const ComplexVariable& x);
    ComplexVariable& operator*(std::complex<double> y);
    friend ComplexVariable& operator*(const double z, ComplexVariable& x);
    friend ComplexVariable& operator*(std::complex<double> y, ComplexVariable& x);

    ComplexVariable& operator==(const double z);
     ComplexVariable& operator==(const ComplexVariable& x);
    ComplexVariable& operator==(std::complex<double> y);
    friend ComplexVariable& operator==(const double z, ComplexVariable& x);
    friend ComplexVariable& operator==(std::complex<double> y, ComplexVariable& x);

    ComplexVariable& operator^(const int y);

    
};
     double solve(RealVariable& x);
    std::complex<double> solve (ComplexVariable& x);

};




