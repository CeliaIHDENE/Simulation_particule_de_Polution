
#ifndef TD_UNSTEADYSIMULATOR_H
#define TD_UNSTEADYSIMULATOR_H

#include "Simulator.h"

#include "Particles.h"


class UnsteadySimulator : public Simulator {
  Particles m_particles;
  public : UnsteadyGasField  gas_feild ;
  
 // public : UnsteadyGasField gas_feild ;
public:
  void compute() override {  
  

    auto final_time = 1.0;
    auto initial_time = 0.;
    auto delta_t = 0.2;
    auto current_time = initial_time;
        m_particles.init(final_time);
   while (current_time < final_time) {
    
     current_time += delta_t;
      m_particles.computeEvolution(current_time,gas_feild);
      m_particles.print(current_time);
     
    }
  }
};

#endif // TD_UNSTEADYSIMULATOR_H
