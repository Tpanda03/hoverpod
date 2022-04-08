#include "Kinematics.hpp"
//#include "IMU.hpp"

Kinematics::Kinematics() {
  struct acceleration { //three acceleration vectors
    double Ax,Ay,Az = 0;
  };
  struct velocity { //three velocity vectors
    double Vx,Vy,Vz = 0;
  };
  struct position { //three position vectors
    double Px,Py,Pz = 0;
  };
}

acceleration input() {
  //get From IMU class
  //Not really sure how this IMU class works, my input for acceleration is from accel.txt ( a parsed list of acceleration that was made from measurements.txt)
  //return IMU_data.get_acel_values();
}

velocity calculateVelocity(acceleration prev, acceleration curr, double timeStart, double timeStop) {
  double timestep = timeStop - timeStart;
  Velocity V;
  //((curr - prev)/2)*timestep
  V.Vx = timestep*((curr.Ax + prev.Ax)/2)
  V.Vy = timestep*((curr.Ay + prev.Ay)/2)
  V.Vz = timestep*((curr.Az + prev.Az)/2)
  //return Vx,Vy,Vz
  return V;
}

position calculatePosition(velocity prev, velocity curr, double timeStart, double timeStop) {
  double timestep = timeStop - timeStart;
  postion P;
  //((curr + prev)/2)*timestep
  P.Px = timestep*((curr.Vx + prev.Vx)/2)
  P.Py = timestep*((curr.Vy + prev.Vy)/2)
  P.Pz = timestep*((curr.Vz + prev.Vz)/2)
  //return Px,Py,Pz
  return P;
}

/*
Issue:
can only determine velocity after 1 cycle
can only determine position after 2 cycles
Keeping track of running total of integeration,
current suggested solution:
  Calculate, based on prev and current data type, the integrated data datatype
  /return area within delta x (timestep) and sum in main class
*/
