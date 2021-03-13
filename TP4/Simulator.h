#ifndef TD_SIMULATOR_H
#define TD_SIMULATOR_H

class Simulator {
public:
   //destructeur 
  virtual ~Simulator() = default;
  
  //methode comput
  virtual void compute() = 0;
  //  virtual void compute(Particules& p ) = 0;
};

#endif // TD_SIMULATOR_H
