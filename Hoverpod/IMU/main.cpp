//#include "IMU.hpp"
//#include "Kinematics.hpp"
#include <iostream>
#include <fstream>

using namespace std;

int main() {
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
        writeFile << line << "at time t = " << time << '\n';
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

  //create a running total sum of averages throughout runtime

  /*
  essentially, the kinematics class focuses on getting acceleration data, and finding velocity and position
  from recieved acceleration data,
  */
  return 0;
}
