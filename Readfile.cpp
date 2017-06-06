#include <iostream>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include <string>
#include <stdio.h>
#include <vector>
#include <memory>

#include "../CPP_AtomClass/AtomClass.hpp"
#include "../CPP_MoleculeClass/MoleculeClass.hpp"

using namespace std;

int main() {
  ifstream File;
  File.open("Examples/carbonmolecule.pdb");
  string line;
  std::vector<Atom> atmV;

  if(File.is_open())
  {
    while(!File.eof())
    {
      getline(File,line);
      //cout << line << endl; //prints the entire pdb file
      //cout << line[0] << endl; //prints the first char of each line

      vector<int> bonds;  //stores the IDs of the connected atoms
      vector<string> neighbors; //stores the atom types of the connected atoms
      if (line.size())
      {
        if ((line.at(0) == 'C') and (line.at(5) == 'T'))
        {
          istringstream iss(line);
          for(string line2; iss >> line2;)
          {
            //cout << line2 << endl;  //prints "CONECT" and connections
            if(line2 != "CONECT")
            {
              bonds.push_back(stoi(line2)); //inserts IDs of connections into the bonds vector
            }
          }

          for (unsigned int i=0; i<bonds.size(); i++)
          {
            //cout << bonds[i] << endl; //prints content of bonds vector: IDs of atom and its connections
            for (unsigned int j=0; j<atmV.size(); j++)
            {
              if (atmV.at(j).id == bonds[i])
              {
                //cout << atmV.at(j).atom_type << endl;
                neighbors.push_back(atmV.at(j).atom_type);
              }
            }
          }

          for (unsigned int i=0; i<atmV.size();i++){
              atmV.at(i).setConnections(bonds);
          }

          atmV.at(bonds.at(0)-1).bonds = bonds.size()-1;
          atmV.at(bonds.at(0)-1).print();
        }

        else if (line.at(0) == 'H')
        {
          string str;
          string str1;
          int j;
          string atm;
          double tempX;
          double tempY;
          double tempZ;
          int i;
          istringstream some_string(line);
          some_string >> str >> i >> atm >> str1 >> j >> tempX >> tempY >> tempZ;
          Atom a = Atom(atm, i, tempX, tempY, tempZ);  //builds an atom with its type, ID and position.
          atmV.push_back(a);                       //inserts the atom in the vecor of atom structs
          //cout << a << endl;
        }
      }
    }
    auto molecules = sortAtoms(atmV);
    //molecules.at(0).get()->print();
    for (auto i=0; i<molecules.size(); i++){
      //molecules.at(i)->print();
    }
  }

  File.close();
  return 0;
}
