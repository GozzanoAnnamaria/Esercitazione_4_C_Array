#pragma once
#include <iostream>

using namespace std;

bool ImportAll(string& inputFilePath, double &Sum, size_t& n,
               double*& w, double*& r);

double PortFolioReturn(double &Sum,size_t& n,
                       const double* const& w, const double* const& r,
                        double &portfolioreturn, double &rate);

bool ExportResult(string &outputFilePath, size_t& n,
                         const double* const &w, const double* const &r,
                           double &portfolioreturn, double &Sum, double &rate);




