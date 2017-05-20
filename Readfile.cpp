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
      vector<string> neighbors;
      if (lineNo > 14 && lineNo < 27)
      //if ((line[0] == 'C') and (line[5] == 'T'))  //I was trying this, since the format (i.e CONECT , etc) should be
                                                    //the same for each pdf file, but the number of lines is not
      {
        istringstream iss(line);                    // do we need BOTH getline and istringstream?
        for(string line2; iss >> line2;){
          //cout << line2 << endl;
          if(line2 != "CONECT"){
            bonds.push_back(stoi(line2));
            //cout << stoi(line2) << endl;
          }
        }

        for (unsigned int i=0; i<bonds.size(); i++){
          //cout << bonds[i] << endl;
          for (unsigned int j=0; j<atmV.size(); j++){
            if (atmV.at(j).id == bonds[i]){
              //cout << atmV.at(j).atom_type << endl;
              neighbors.push_back(atmV.at(j).atom_type);
            }
          }
        }
        for (unsigned int i=1; i<neighbors.size();i++){
          cout << neighbors[i] << endl;
        }
        atmV.at(bonds.at(0)).bonds = bonds.size()-1;
        atmV.at(bonds.at(0)).print();
        }

      //if (line[0] == 'H'){
      if (lineNo > 1 && lineNo < 15)
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
