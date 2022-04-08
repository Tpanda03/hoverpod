//#include "IMU.hpp"
#include "Kinematics.hpp"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

struct acceleration { //three acceleration vectors
  double Ax,Ay,Az = 0;
};
struct velocity { //three velocity vectors
  double Vx,Vy,Vz = 0;
};
struct position { //three position vectors
  double Px,Py,Pz = 0;
};


int main() {
  Kinematics temp;
  //parse measures.txt
  string line;
  ifstream readFile ("measures.txt");
  ofstream writeFile ("accel.txt");
  if (readFile.is_open() && writeFile.is_open())
  {
    int count = 0;
    int time = 0;
    while ( getline (readFile,line) )
    {
      if (count == 4) {
        for (int i = 0; i < line.length(); i++) {
          if (isdigit(line[i]) || line[i] == '-' || line[i] == '.') {
            line[i] = line[i];
          }
          else {
            line[i] = ' ';
          }
        }
        writeFile << line << " " << time << '\n';
        count = 0;
        time++;
      }
      count++;
    }
    readFile.close();
    writeFile.close();
  }

  else cout << "Unable to open file";

  //from current and previous acceleration, find current and previous velocity and current position
  ifstream accelFile ("accel.txt");
  if (accelFile.is_open()) {
    while (getline(accelFile, line)) {
      cout << line << endl;
      istringstream iss (line);
      //get Ax, Ay, Az from t0 and Ax, Ay, Az from t1
      //Ax Ay Az t
      //from t0 and t1 find velocity at t1
      //update to velocity text file as Vx Vy Vz td

    }
  }

  //Finding current and previous velocities and using it to find position at time t

  //create a running total sum of averages throughout runtime


  //my tests

  /*
  essentially, the kinematics class focuses on getting acceleration data, and finding velocity and position
  from recieved acceleration data,
  */
  return 0;
}
