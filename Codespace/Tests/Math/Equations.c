#include "../../Congro/Modules/Math/Equation/Linear.h"
#include "../../Congro/Modules/Math/Equation/Quadratic.h"
#include <math.h>

int main(void) {
  double a=0,b=0;
  TMathSolution sol=MATH_CONST(SOLUTION_NONE);
  if (Math_Equation_Linear_F64(2.0,-8.0,&a,&sol)!=STATUS_CONST(SUCCESS) || sol!=MATH_CONST(SOLUTION_ONE) || fabs(a-4.0)>1e-12) return 1;
  if (Math_Equation_Linear_F64(0.0,0.0,&a,&sol)!=STATUS_CONST(SUCCESS) || sol!=MATH_CONST(SOLUTION_INFINITE)) return 2;
  if (Math_Equation_QuadraticDiscriminant_F64(1.0,0.0,-4.0)!=16.0) return 3;
  if (Math_Equation_Quadratic_F64(1.0,-3.0,2.0,&a,&b,&sol)!=STATUS_CONST(SUCCESS) || sol!=MATH_CONST(SOLUTION_MULTIPLE)) return 4;
  if (!((fabs(a-1.0)<1e-12 && fabs(b-2.0)<1e-12) || (fabs(a-2.0)<1e-12 && fabs(b-1.0)<1e-12))) return 5;
  return 0;
}
