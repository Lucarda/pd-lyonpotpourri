
#include "MSPd.h"
void atom_arg_getfloat(float *c, long idx, long ac, t_atom *av)
{
  if (c&&ac&&av&&(idx<ac)) {
    *c = atom_getfloat(av+idx);
  }
}
void atom_arg_getsym(t_symbol **c, long idx, long ac, t_atom *av)
{
  if (c&&ac&&av&&(idx<ac)) {
    *c = atom_getsymbol(av+idx);
  }
}
