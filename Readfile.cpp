#include <iostream>
#include <cstdlib>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../CPP_AtomClass/AtomClass.hpp"

using namespace std;

int main() {
  ifstream File;
  File.open("Examples/carbonmolecule2.pdb");
  string line;

  if(File.is_open())
  {
    int lineNo = 0;
    while(!File.eof())
    {
      getline(File,line);
      lineNo++;
      if (lineNo > 2 && lineNo < 15)
      {
        char str[100];
        char str1[100];
        int j;
        char atm[3];
        double tempX;
        double tempY;
        double tempZ;
        int i;
        sscanf(line.c_str(),"%s %d %s %s %d %lf %lf %lf",str, &i, atm, str1, &j, &tempX, &tempY, &tempZ);
        Atom a = Atom(atm, i, tempX, tempY, tempZ);
        a.print();
      }
    }

  }

  File.close();
  return 0;
}
