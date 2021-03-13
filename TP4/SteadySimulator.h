
#ifndef TD_STEADYSIMULATOR_H
#define TD_STEADYSIMULATOR_H

#include "Simulator.h"

#include "Particles.h"

class SteadySimulator : public Simulator {
  Particles m_particles;
public:
  void compute() override {
      auto final_time = 1.0;
    m_particles.init(final_time);

    m_particles.computeEvolution(final_time);
    m_particles.print(final_time);
  }
};

#endif // TD_STEADYSIMULATOR_H
