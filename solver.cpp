#include <iostream>
#include <complex>

#include "solver.hpp"


using namespace std;
using solver::solve, solver::RealVariable, solver::ComplexVariable;




    RealVariable& RealVariable::operator+( double y){
        RealVariable *ans =new RealVariable(_a,_b,_c+y);
        return *ans;
    }
    RealVariable& RealVariable::operator+(const RealVariable& x){
        RealVariable *ans= new RealVariable(_a+x._a,_b+x._b,_c+x._c);
        return *ans;
    }
    RealVariable& solver::operator+( double x,const RealVariable& y){
         RealVariable *ans = new RealVariable(y._a,y._b,y._c+x);
    return *ans;
    }
    RealVariable& RealVariable::operator-( const double y){
         RealVariable *ans =new RealVariable(_a,_b,_c-y);
        return *ans;
    }
    RealVariable& RealVariable::operator-(const RealVariable& x){
         RealVariable *ans= new RealVariable(_a-x._a,_b-x._b,_c-x._c);
        return *ans;
    }
    RealVariable& solver::operator-( double x,const RealVariable& y){
     RealVariable *ans = new RealVariable(y._a,y._b,y._c-x);
    return *ans;
    }

    RealVariable& RealVariable::operator/( double y){
        if (y==0) throw exception();
        RealVariable *ans= new RealVariable(_a/y,_b/y,_c/y);
        return *ans;
    }
    

    RealVariable& RealVariable::operator*(double y){
        RealVariable *ans = new RealVariable(y*_a,y*_b,y*_c);
    return *ans;
    }
    RealVariable& RealVariable::operator*(const RealVariable& x){
        
        double new_a=_b*x._b;
        double new_b= _b*x._c+_c*x._b;
        double new_c= _c*x._c;
        RealVariable *ans = new RealVariable(new_a,new_b,new_c);
    return *ans; 

    }
    RealVariable& solver::operator*(double x,const RealVariable& y){
       RealVariable *ans = new RealVariable(x*y._a,x*y._b,x*y._c);
    return *ans;
    }

    RealVariable& RealVariable::operator==(double y){
         RealVariable *ans= new RealVariable(_a,_b,_c-y);
        return *ans;
    }
    RealVariable& RealVariable::operator==(const RealVariable& x){
        RealVariable *ans= new RealVariable(_a-x._a,_b-x._b,_c-x._c);
        return *ans;
    }
    RealVariable& solver::operator==(double x,const RealVariable& y){
         RealVariable *ans= new RealVariable(y._a, y._b, y._c-x);
        return *ans;
    }

    RealVariable& RealVariable::operator^( const int y){
        
        if (y>2 ){
            throw exception();
        }
        if (y==0){
            RealVariable *ans= new RealVariable(0,_b,_c+1);
        return *ans;
        }
         RealVariable *ans= new RealVariable(1,0,_c);
        return *ans;
    }
  
    ComplexVariable& ComplexVariable::operator+(const double z){
      ComplexVariable *ans = new ComplexVariable(c_a,c_b,c_c+z);
         return *ans;
    }
     ComplexVariable& ComplexVariable::operator+(const ComplexVariable& x){
         ComplexVariable *ans = new ComplexVariable(c_a+x.c_a, c_b+x.c_b, c_c+x.c_c);
          return *ans;
     }
    ComplexVariable& ComplexVariable::operator+(std::complex<double> y){
        ComplexVariable *ans = new ComplexVariable(c_a, c_b, c_c+y);
          return *ans;
    }
    ComplexVariable& solver::operator+(const double z, ComplexVariable& x){
        ComplexVariable *ans = new ComplexVariable(x.c_a, x.c_b, x.c_c+z);
         return *ans;
    }
    ComplexVariable& solver::operator+(std::complex<double> y, ComplexVariable& x){
       ComplexVariable *ans = new ComplexVariable(x.c_a, x.c_b, x.c_c+y);
         return *ans;
    }
    ComplexVariable& ComplexVariable::operator-(const double z){
     ComplexVariable *ans = new ComplexVariable(c_a,c_b,c_c-z);
         return *ans;
    }
     ComplexVariable& ComplexVariable::operator-(const ComplexVariable& x){
          ComplexVariable *ans = new ComplexVariable(c_a-x.c_a, c_b-x.c_b, c_c-x.c_c);
          return *ans;
     }
    ComplexVariable& ComplexVariable::operator-(std::complex<double> y){
        ComplexVariable *ans = new ComplexVariable(c_a, c_b, c_c-y);
          return *ans;

    }
     ComplexVariable& solver::operator-(const double z, ComplexVariable& x){
         ComplexVariable *ans = new ComplexVariable(x.c_a, x.c_b, x.c_c-z);
          return *ans;

    }
     ComplexVariable& solver::operator-(std::complex<double> y, ComplexVariable& x){
        ComplexVariable *ans = new ComplexVariable(x.c_a, x.c_b, x.c_c-y);
         return *ans;

    }


    ComplexVariable& ComplexVariable::operator/(const double z){
        
      ComplexVariable *ans = new ComplexVariable(c_a/z, c_b/z, c_c/z);
          return *ans;

    }
     

     ComplexVariable& ComplexVariable::operator*(const double z){
         std::complex<double> complx_z = std::complex<double>(z,0);
        ComplexVariable *ans = new ComplexVariable(c_a*complx_z, c_b*complx_z, c_c*complx_z);
          return *ans;
     }
     ComplexVariable& ComplexVariable::operator*(const ComplexVariable& x){
        std::complex<double> new_a=c_b*x.c_b;
        std::complex<double> new_b= c_b*x.c_c + c_c*x.c_b;
        std::complex<double> new_c= c_c*x.c_c;
        ComplexVariable *ans = new ComplexVariable(new_a,new_b,new_c);
    return *ans;
     }
    ComplexVariable& ComplexVariable::operator*(std::complex<double> y){
        ComplexVariable *ans = new ComplexVariable(c_a*y, c_b*y, c_c*y);
          return *ans;
    }
    ComplexVariable& solver::operator*(const double z, ComplexVariable& x){
      std::complex<double> complx_z = std::complex<double>(z,0);
        ComplexVariable *ans = new ComplexVariable(x.c_a*complx_z, x.c_b*complx_z, x.c_c*complx_z);
          return *ans;
    }
    ComplexVariable& solver::operator*(std::complex<double> y, ComplexVariable& x){
       ComplexVariable *ans = new ComplexVariable(x.c_a*y, x.c_b*y, x.c_c*y);
          return *ans;
    }

    ComplexVariable& ComplexVariable::operator==(const double z){
      ComplexVariable *ans = new ComplexVariable(c_a,c_b,c_c-z);
         return *ans;
    }
     ComplexVariable& ComplexVariable::operator==(const ComplexVariable& x){
          ComplexVariable *ans = new ComplexVariable(c_a-x.c_a ,c_b-x.c_b ,c_c-x.c_c);
         return *ans;
     }
    ComplexVariable& ComplexVariable::operator==(std::complex<double> y){
         ComplexVariable *ans = new ComplexVariable(c_a ,c_b ,c_c-y);
         return *ans;
    }
    ComplexVariable& solver::operator==(const double z, ComplexVariable& x){
        ComplexVariable *ans = new ComplexVariable(x.c_a, x.c_b, x.c_c-z);
         return *ans;
    }
    ComplexVariable& solver::operator==(std::complex<double> y, ComplexVariable& x){
         ComplexVariable *ans = new ComplexVariable(x.c_a,x.c_b,x.c_c-y);
         return *ans;
      
    }

    ComplexVariable& ComplexVariable::operator^(const int y){
       
    if (y>2 ){
            throw exception();
        }
        if (y==0){
            throw exception();
        }
         ComplexVariable *ans= new ComplexVariable(1,0,c_c);
        return *ans;
    }
    double solver::solve(RealVariable& x){
        double ans =0;
        if(x._a==0){
            if(x._b==0) {
                throw exception();
            }
            else{
                ans= ((-1)*x._c)/x._b;
                return ans;
            } 
             
        }
        else{
            double temp= x._b*x._b-(4*x._a*x._c);
            if (temp==0){
                ans=-1*x._b/2*x._a;
                return ans;
            }
            if (temp<0){
                 throw exception();
            }
            else{
               ans= (-1*x._b + sqrt(temp))/(2.0*x._a); // i do + but possible -
               return ans;

            }

        }
       
    }
std::complex<double> solver::solve (ComplexVariable& x){

    std::complex<double> ans;

    if(x.c_a==std::complex<double>(0,0)){
            if(x.c_b==std::complex<double>(0,0)) {
                throw exception();
            }
            else{
                ans= ((-1.0)*x.c_c)/x.c_b;
                return ans;
            } 
             
        }
        else{
            std::complex<double> temp= x.c_b*x.c_b-(4.0*x.c_a*x.c_c);
            if (temp==std::complex<double>(0,0)){
                ans=-1.0*x.c_b/2.0*x.c_a;
                return ans;
            }
            
            else{
               ans= (-1.0*x.c_b + sqrt(temp))/(2.0*x.c_a); // i do + but possible -
               return ans;

            }

        }
}