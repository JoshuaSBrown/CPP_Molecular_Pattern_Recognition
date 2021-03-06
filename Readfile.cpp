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
    int atom_id = 0;
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
          // cout << "line: " << line << endl;
          // cout << "line at 0: " << line.at(0) << endl;
          vector<int> idsList;
          for(string line2; iss >> line2;)
          {
            // cout << "line inside for loop: " << line << endl;
            // cout << "line2: " << line2 << endl;  //prints "CONECT" and connections
            // cout << "line at 0: "<<line2.at(0) <<  endl;
            if(line2 != "CONECT") //add only the ids of the connections to the bonds vector
            {
              idsList.push_back(stoi(line2));
              //cout << "if staetement " << endl;
              //bonds.push_back(stoi(line2)); //inserts IDs of connections into the bonds vector
            }
          }

          for (unsigned long i = 1; i < idsList.size(); i++){
            //cout << "idsList: " << idsList.at(i) << endl;
            bonds.push_back(idsList.at(i));
          }

          for (unsigned int i=0; i<bonds.size(); i++)
          {
            // cout << bonds[i] << endl; //prints content of bonds vector: IDs of atom's connections
            for (unsigned int j=0; j<atmV.size(); j++)
            {
              if (atmV.at(j).id == bonds[i])
              {
                //cout << atmV.at(j).atom_type << endl;
                neighbors.push_back(atmV.at(j).atom_type);
              }
            }
          }
          cout << "AllGoodSoFar1" << endl;

          atmV.at(atom_id).setConnections(bonds);
          atom_id++;


          atmV.at(bonds.at(0)-1).bonds = bonds.size()-1;
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
        }
      }
    }
    cout << "AllGoodSoFar2" << endl;
    auto molecules = sortAtoms(atmV); // get the molecules
    cout << "AllGoodSoFar3" << endl;
    vector<RigidFragmentMotif> Motifs; // store all the motifs here
    vector<RigidFragmentMotif> UniqueMotifs;  // store unique motifs here

    // loop through the molecules and get the motifs of each one
    for (unsigned long i = 0; i < molecules.size(); i++){
      cout << "inside for loop" << endl;
      auto tempMotif = molecules.at(i).getMotifs();
      cout << "after getMotifs " << endl;
      cout << "tempMotif: " << tempMotif.at(i) << endl;
      Motifs.insert(Motifs.end(), tempMotif.begin(), tempMotif.end());
    }

    cout << "Test to check motifs: " << endl;
    cout << "Motifs.size(): " << Motifs.size() << endl;
    for (unsigned long i = 0; i < Motifs.size(); i++){
      cout << Motifs.at(i) << endl;
    }

    // initialize the unique motifs vector with the first motif
    UniqueMotifs.push_back(Motifs.at(0));

    // cycle through the vector containing all the motifs starting at 1 because we already
    // made element 0 a unique motif
    for (unsigned long i = 1; i < Motifs.size(); i++){
      // initialize a local constant that determines if the motif is unique or not
      bool unique = true;

      // cycle through the motifs that are already stored in the unique motif vector.
      for (unsigned long j = 0; j < UniqueMotifs.size(); j++){
         // if motif(i) is already stored as a unique motif than motif(i) is not unique so break out of the loop.
          if (Motifs.at(i) == UniqueMotifs.at(j)){
           unique = false;
           break;
           }
       }
     // if the motif was found to be unique than add it to the unique motif vector.
     if(unique){
          UniqueMotifs.push_back(Motifs.at(i));
      }

      for (unsigned long i = 0; i < UniqueMotifs.size(); i++){
        cout << UniqueMotifs.at(i) << endl;
      }
    }

    File.close();
    return 0;
  }
}
