
#ifndef TD_UNSTEADYSIMULATOR_H
#define TD_UNSTEADYSIMULATOR_H

#include "Simulator.h"

#include "Particles.h"

class UnsteadySimulator : public Simulator {
  Particles m_particles;
public:
  void compute() override {  
  

    auto final_time = 1.0;
    auto initial_time = 0.;
    auto delta_t = 0.2;
    auto current_time = initial_time;
        m_particles.init(final_time);
    while (current_time < final_time) {
    
      m_particles.computeEvolution(current_time);
      m_particles.print(current_time);
      current_time += delta_t;
    }
  }
};

#endif // TD_UNSTEADYSIMULATOR_H
