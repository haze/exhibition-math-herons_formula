#include <iostream>
#include <tuple>
#include <math.h>


std::tuple<std::string, double, double, double, double> prompt_sides() {
  /*       _________________
   * a = \/ s(s-a)(s-b)(s-c)
   * s = (a + b + c) / 2
   */

  std::string unit;
  std::cout << "please enter the unit <leave empty for default: in>: ";
  std::getline(std::cin, unit);
  if(unit.empty())
    unit = std::string("in");

  float sides[3];
  for(int i=0;i < 3; i++) {
    std::cout << "please enter the " << i+1 << "'th term (size-wise): ";
    std::string temp;
    std::getline(std::cin, temp);
    sides[i] = std::stof(temp);
  }
  double s = (sides[0] + sides[1] + sides[2]) / 2;
  std::cout << "semiperim: " << s << std::endl;
  std::cout << "before sqrt: " << s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]) << std::endl;
  double area = sqrt( s * (s - sides[0]) * (s - sides[1]) * (s - sides[2]) );
  return std::make_tuple(unit, sides[0], sides[1], sides[2], area);
}

void print_trig_tuple(std::tuple<std::string, double, double, double, double> trig_tuple) {
  std::string unit = std::get<0>(trig_tuple);
  std::cout << "A: " << std::get<1>(trig_tuple) << unit
            << ", B: " << std::get<2>(trig_tuple) << unit
            << ", C: " << std::get<3>(trig_tuple) << unit
            << ", Area: " << std::get<4>(trig_tuple) << unit << std::endl;
}

int main(int argc, char ** argv) { 
  // disable precision
  std::cout.setf(std::ios::fixed, std::ios::floatfield);
  std::cout.setf(std::ios::showpoint);
  auto result = prompt_sides();
  print_trig_tuple(result);
  return EXIT_SUCCESS;
}
