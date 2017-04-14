#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
#include <vector>

using namespace std;

struct node{
  char molecule;
  int ID;
  double Xposition;
  double Yposition;
  double Zposition;
  node*next; //pointer to next node.
};

int main() {
  ifstream File;
  File.open("carbonmolecule2.pdb");
  string line;

  if(File.is_open())
  {
    vector<string> atom;
    vector<int> id;
    vector<double> X;
    vector<double> Y;
    vector<double> Z;
    int lineNo = 0;
    while(!File.eof())
    {
      getline(File,line);
      //cout << line << endl;
      lineNo++;
      //cout << lineNo << endl;
      if (lineNo > 2 && lineNo < 15)
      {
        cout << line << endl;
        char str[100];
        char str1[100];
        int j;
        char atm[3];
        double tempX;
        double tempY;
        double tempZ;
        int i;
        sscanf(line.c_str(),"%s %d %s %s %d %lf %lf %lf",str, &i, atm, str1, &j, &tempX, &tempY, &tempZ);
        printf ("molecule: %s -> id: %d -> X: %g -> Y: %g -> Z: %g\n", atm ,i,tempX,tempY,tempZ);
        atom.push_back (atm);
        id.push_back (i);
        X.push_back (tempX);
        Y.push_back (tempY);
        Z.push_back (tempZ);

      }
    }
    for (int i=0; i<atom.size(); i++){
      cout << atom[i] << endl;
    }
    for (int i=0; i<id.size(); i++){
      cout << id[i] << endl;
    }
  }


  //linked list code starts
  node *x;
  node *head;
  x = new node;
  head = x;

  /*

  x->molecule =
  x->Xposition =

*/
  //linked list code ends
  File.close();
  return 0;
}
