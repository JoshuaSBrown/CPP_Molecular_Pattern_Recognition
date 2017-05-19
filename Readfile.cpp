#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include "../CPP_AtomClass/AtomClass.hpp"

using namespace std;

int main() {
  ifstream File;
  File.open("Examples/carbonmolecule2.pdb");
  string line;
  std::vector<Atom> atmV;

  if(File.is_open())
  {
    int lineNo = 0;
    while(!File.eof())
    {
      getline(File,line);
      //cout << line << endl;
      //cout << line[0] << endl;
      lineNo++;
      vector<int> bonds;
      if (lineNo > 14 && lineNo < 26) //need to fix this, it also doesn't print the first atom (ID 1)
      //if ((line[0] == 'C') and (line[5] == 'T'))  //I was trying this, since the format (i.e CONECT , etc) should be
                                                    //the same for each pdf file, but the number of lines is not
      {
        istringstream iss(line);                    // do we need BOTH getline and istringstream?
        for(string line2; iss >> line2;){
          //cout << line2 << endl;
          if(line2 != "CONECT"){
            bonds.push_back(stoi(line2));
          }
        }
        atmV.at(bonds.at(0)).bonds = bonds.size()-1;
        atmV.at(bonds.at(0)).print();
        }

      //if (line[0] == 'H'){
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
        atmV.push_back(a);
      }
    }
  }

  File.close();
  return 0;
}
