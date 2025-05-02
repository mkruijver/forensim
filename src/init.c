#include <R.h>
#include <Rinternals.h>
#include <R_ext/Rdynload.h>

// Declare the C routines
extern void recurs(int *r, int *c, int *matR, int *nbLigne, int *nbCol);
extern void evidenceC3(double *Repliste, int *lenRepliste,
                       double *T, int *lenT, double *V, int *lenV,
                       int *x, double *theta,
                       double *prDHet, int *lenHet,
                       double *prDHom, int *lenHom,
                       double *prC, char **allele,
                       double *frequence, int *lenFreq,
                       double *sortieR);

// Register the routines
static const R_CMethodDef CEntries[] = {
  {"recurs",     (DL_FUNC) &recurs,     5},
  {"evidenceC3", (DL_FUNC) &evidenceC3, 17},
  {NULL, NULL, 0}
};

void R_init_forensim(DllInfo *dll) {
  R_registerRoutines(dll, CEntries, NULL, NULL, NULL);
  R_useDynamicSymbols(dll, FALSE);
}
