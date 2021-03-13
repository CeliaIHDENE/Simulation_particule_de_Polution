#include "Simulator.h"
#include "SteadySimulator.h"
#include "UnsteadySimulator.h"
#include <memory>
enum class SimulationType {SteadyState, UnsteadyState};

Simulator* createSimulator(SimulationType simulation_type) {
  //std::unique_ptr<Simulator>
    Simulator* simulator = nullptr;


  
  switch (simulation_type)
  {
  case SimulationType::SteadyState:
    simulator = new SteadySimulator{};

  // unique_ptr<simulator> make_unique( );

    break;
  case SimulationType::UnsteadyState:
    simulator = new UnsteadySimulator{};
    break;
  }
  return simulator;
}

int main(){

  auto simulation_type = SimulationType::SteadyState;
  /*std::unique_ptr <Simulator> simulator = createSimulator(simulation_type);
  simulator->compute() ; */
  
 Simulator* simulator = createSimulator(simulation_type);
  simulator->compute();

  return 0;
}
