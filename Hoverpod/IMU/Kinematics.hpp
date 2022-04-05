#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <math.h>
#include <tuple>
#include "IMU.h"

using namespace std;

/*
From acceleration data (x,y,z) we need to parse into three dimensions
so all data will be in terms of (Nx,Ny,Nz,t) where N is the given datatype (A,V,P) and t is current timestep.
<Ax,Ay,Az,t> --> for Acceleration
<Ax,Ay,Az,t> --> for Velocity
<Px,Py,Pz,t> --> for Position

From IMU Man Page Refresh Rate is 800Hz
*/

class Kinematics {
public:
    struct acceleration { //three acceleration vectors
      double Ax,Ay,Az;
    };
    struct velocity { //three velocity vectors
      double Vx,Vy,Vz;
    };
    struct position { //three position vectors
      double Px,Py,Pz;
    };

    //return current x y z acceleration with time
    acceleration input();
    //return current x y z velocities with time | v(t) = integral(a(t) dt) from 0->t
    velocity calculateVelocity(acceleration prev, acceleration curr);
    //returns current x y z positions with time | p(t) = integral(v(t) dt) from 0->t
    position calculatePosition(velocity prev, velocity curr);
    //a list of all kinematics data throughout time.
}
