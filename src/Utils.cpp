#include "Utils.hpp"
#include "iostream"
#include "fstream"
#include "sstream"
#include "algorithm"
#include "iomanip"


using namespace std;

bool ImportAll(string& inputFilePath, double &Sum, size_t& n,
               double*& w, double*& r)
{

    //Apertura file 

    ifstream file;
    file.open(inputFilePath);

    if (file.fail())
    {
        cerr << "file open failed" << endl;
        return false;
    }


    //Lettura file
    string line;
    for(unsigned int i = 0; i < 3; i++)
    {
        getline(file,line);

        if(line[0]=='S')
        {
            istringstream Sconverter(line);
            char tmp;
            Sconverter >> tmp >> tmp >> Sum;

        }

        if(line[0]=='n')
        {
            istringstream Sconverter(line);
            char tmp;
            Sconverter >> tmp >> tmp >> n;

        }

        if(line[0]=='w')
        {
            break;
        }

    }

    //Costruzione dei vettori

    w = new double [n];
    r = new double [n];
    unsigned int j = 0;

    while (!file.eof())
    {

        getline(file,line);
        istringstream Sconverter(line);
        char tmp;
        Sconverter >> w[j] >> tmp >> r[j];
        j++;

    }

    return true;


}

// Calcolo del Portfolio

double PortFolioReturn(double &Sum, size_t& n,
                       const double* const& w, const double* const& r, double &portfolioreturn, double &rate)
{

    for(unsigned int i = 0; i < n; i++)
    {
        rate += w[i] * r[i];
    }

    PortfolioReturn = Sum * ( 1 + rate);


    return PortfolioReturn;


}

// Stampa dei risultati

bool ExportResult(string &outputFilePath,size_t &n, const double * const &w,
                  const double * const &r, double &PortfolioSeturn, double &Sum, double &rate)

{

   ofstream file;
   file.open(outputFilePath);

    if (file.fail())
    {
        cerr<< "file open failed"<< endl;
        return false;
    }

    file << "S = " << fixed << setprecision(2) << Sum;
    file.unsetf(ios_base::fixed);
    file.precision(6);
    file << ", n = " << n << endl;

    file << "w = [ ";
    for(unsigned int i = 0; i < n; i++)
    {
        file << w[i] << " ";
    }
    file << "]" << endl;

    file << "r = [ ";
    for(unsigned int i = 0; i < n; i++)
    {
        file << r[i] << " ";
    }
    file << "]" << endl;

    file << "Rate of return of the portfolio: " << rate << endl;
    file << "V: " << fixed << setprecision(2) << PortFolioReturn << endl;
    file.unsetf(ios_base::fixed);
    file.precision(6);
    file.close();
    return true;

}
