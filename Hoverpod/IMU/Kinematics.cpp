#include "Kinematics.hpp"
#include "IMU.hpp"

acceleration input() {
  //get From IMU class
  IMU_data.get_acel_values();
}

velocity calculateVelocity(acceleration prev, acceleration curr) {
  double timestep;
  Velocity V;
  //((curr - prev)/2)*timestep
  V.Vx = (timestep)((curr.Ax - prev.Ax)/2)
  V.Vy = (timestep)((curr.Ay - prev.Ay)/2)
  V.Vz = (timestep)((curr.Az - prev.Az)/2)
  //return Vx,Vy,Vz
}

position calculatePosition(velocity prev, velocity curr) {
  double timestep;
  postion P;
  //((curr - prev)/2)*timestep
  P.Px = (timestep)((curr.Vx - prev.Vx)/2)
  P.Py = (timestep)((curr.Vy - prev.Vy)/2)
  P.Pz = (timestep)((curr.Vz - prev.Vz)/2)
  //return Px,Py,Pz
}

/*
Issue:
Keeping track of running total of integeration,
current suggested solution:
  Calculate, based on prev and current data type, the integrated data datatype
  /return area within delta x (timestep) and sum in main class
*/
