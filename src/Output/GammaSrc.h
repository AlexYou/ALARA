/* $Id: GammaSrc.h,v 1.4 2000-07-07 02:28:22 wilson Exp $ */
#include "alara.h"
#include <set>

/* ******* Class Description ************

 */

#ifndef _GAMMASRC_H
#define _GAMMASRC_H


class GammaSrc
{
protected:
  
  DataLib *dataLib;

  int nGroups;
  double *grpBnds;
  char *fileName;
  ofstream gSrcFile;

  VectorCache gammaMultCache;

  int findGroup(float);
  double subIntegral(int,int,float*,float*,double,double);

public:

  GammaSrc(istream&);
  ~GammaSrc();

  double* getGammaMult(int,double);
  char* getFileName()
    { return fileName; };
  void setData(int,int,int*,int*,int*,int**,int**,float**,float**,float**,float**);
  void writeIsoName(char *isoName)
    { gSrcFile << "\t" << isoName << endl;};
  void writeIsotope(double*,double);
  void writeTotal(double*,int);

  int getNumGrps()
    { return nGroups; };

};

#endif







