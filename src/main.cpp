#include <iostream>
#include <armadillo>
#include <vector>

#include <boost/math/distributions/empirical_cumulative_distribution_function.hpp>

using boost::math::empirical_cumulative_distribution_function;
using namespace boost::math;
using namespace arma;

void demo() {
  vec x = linspace<vec>(0, 3, 20); // generate 20 numbers evenly between 0 to 3
  vec y = square(x); // y = x^2

  vec xx = linspace<vec>(0, 3, 100);

  vec yy;

  interp1(x, y, xx, yy);  // use linear interpolation by default
  std::cout << x <<std::endl;
  std::cout << y <<std::endl;
}

int main() {
  //demo();
  vec random = randu<vec>(50);
 
	std::vector<double> num_of_heads_for_fair_coin_tossed_twice = {0.0, 1.0, 1.0, 2.0};
	auto ecdf = empirical_cumulative_distribution_function(std::move(num_of_heads_for_fair_coin_tossed_twice));

  vec ecdf_samples = {0.0, 1.0, 2.0}; // source x

  vec y = {ecdf(ecdf_samples[0]), ecdf(ecdf_samples[1]), ecdf(ecdf_samples[2])};
  // ecdf(0) = 0.25
  // ecdf(1) = 0.75
  // ecdf(2) = 1
 

  vec yy;
  // interp1( X, Y, XI, YI )
  // Given a 1D function specified in vectors X and Y (where X specifies locations and Y specifies the corresponding values),
  interp1(y, ecdf_samples, random, yy, "linear");  // use linear interpolation by default
  
  std::cout << random <<std::endl;
  std::cout << ecdf_samples <<std::endl;
  std::cout << yy <<std::endl;

  std::cin.get();

  return 0;
}
// target y = interp1(source x, target x, )
/**

function my_x = my_random(myECDF, xi, N)
    % Generate N uniformly distributed samples between 0 and 1.
    u = rand(N,1);
    % Map these to the points on the empirical CDF.
    my_x = interp1(myECDF, xi, u, 'linear');
end

vq = interp1(x,v,xq) returns interpolated values of a 1-D function at specific query points using linear interpolation. 
Vector x contains the sample points, and 
v contains the corresponding values, v(x). 
Vector xq contains the coordinates of the query points.

If you have multiple sets of data that are sampled at the same point coordinates, then you can pass v as an array. Each column of array v contains a different set of 1-D sample values.

 */
