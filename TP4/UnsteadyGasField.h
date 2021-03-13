#include <cmath>
class  UnsteadyGasField {
public : double vitessAIR ;
public : double PI = atan(1) * 4 ;


public :


double velocity(double position) { 
 	double  vitessAIR = sin(-1*PI*position)  ; 
   	return vitessAIR ;

  };

 




};


