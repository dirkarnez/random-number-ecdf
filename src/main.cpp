#include <iostream>
#include <armadillo>

using namespace arma;

int main() {
  vec v = randu<vec>(10);
  // interp1(myECDF, xi, u, 'linear');
  // Next, evaluate v at xq using the 'linear' method.
  //  interp1(x,v,xq,'linear')

  // xq is for rand
  // v is for xi param
  // x is for ecds




  // x and y should be cdf
  vec yy;
  interp1(x, y, xi, yy); 
  std::cout << v <<std::endl;
  return 0;
}