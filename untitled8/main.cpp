#include <iostream>
#include <fstream>
#include <cstdlib>
#include <iomanip>

using namespace std;

struct row
{
    int row;
};

struct column
{
    int column;
};

int main() {
    char fileName[20];
    int row, col;

    cout<<"Enter File Name: "<<endl;
    cin>>fileName;
    ifstream  infile;
    infile.open(fileName);
    if(infile.fail())
    {
        cout<<"Input File Failed."<<endl;
        exit(1);
    }

    while(!infile.eof())
    {
        infile >> row >> col;
        int** mat = new int* [row];
        for (int i = 0; i < row; i++) {
            mat[i] = new int[col];
            for(int j = 0; j < col; i++)
            {
                mat[j] = new int[row];
            }
        }

        if(col<row)
        {

        }

    }

    infile.close();
    infile.open(fileName);

    /*  cout<<"<Original Matrix>"<<endl;
      cout<<"<Result Matrix>"<<endl;

      cout<<"Row: "<<endl;
      cout<<"Column: "<<endl;
      cout<<"Number of Lights: "<<endl;*/

}
