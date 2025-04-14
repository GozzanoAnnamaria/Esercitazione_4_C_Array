#include <iostream>
#include <fstream>
#include <sstream>
#include "Utils.hpp"


using namespace std;


int main()
{
    string inputFileName = "data.txt";
    size_t n = 0;
    double* w = nullptr;
    double* r = nullptr;
    double Sum = 0;
    double PortfolioReturn = 0;
    double rate = 0;

    if (!ImportAll(inputFileName, Sum, n, w, r))
    {
        cerr<< "Something goes wrong with import"<< endl;
        return -1;
    }

    PortFolioReturn(Sum,n,w,r,PortfolioReturn,rate);

    string outputFileName = "result.txt";
    if (!ExportResult(outputFileName, n, w, r, PortfolioReturn,Sum,rate))
    {
        cerr<< "Something goes wrong with export"<< endl;
        return -1;
    }

}
