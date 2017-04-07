#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>

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
    int lineNo = 0;
    while(!File.eof())
    {
      getline(File,line);
      //cout << line << endl;
      lineNo++;
      //cout << lineNo << endl;
      if (lineNo > 2 && lineNo < 15){
        cout << line << endl;
        char str[100];
        char str1[100];
        int j;
        char atm[3];
        double X[10];
        double Y[10];
        double Z[10];
        double tempX;
        double tempY;
        double tempZ;
        int i;
        sscanf(line.c_str(),"%s %d %s %s %d %lf %lf %lf",str, &i, atm, str1, &j, &tempX, &tempY, &tempZ);
        printf (" %s -> %d -> %g -> %g -> %g\n", atm ,i,tempX,tempY,tempZ);

      }
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
