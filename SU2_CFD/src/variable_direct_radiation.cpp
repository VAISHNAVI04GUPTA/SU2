/*!
 * \file variable_direct_transition.cpp
 * \brief Definition of the radiation variables
 * \author R. Sanchez
 * \version 6.1.0 "Falcon"
 *
 * The current SU2 release has been coordinated by the
 * SU2 International Developers Society <www.su2devsociety.org>
 * with selected contributions from the open-source community.
 *
 * The main research teams contributing to the current release are:
 *  - Prof. Juan J. Alonso's group at Stanford University.
 *  - Prof. Piero Colonna's group at Delft University of Technology.
 *  - Prof. Nicolas R. Gauger's group at Kaiserslautern University of Technology.
 *  - Prof. Alberto Guardone's group at Polytechnic University of Milan.
 *  - Prof. Rafael Palacios' group at Imperial College London.
 *  - Prof. Vincent Terrapon's group at the University of Liege.
 *  - Prof. Edwin van der Weide's group at the University of Twente.
 *  - Lab. of New Concepts in Aeronautics at Tech. Institute of Aeronautics.
 *
 * Copyright 2012-2018, Francisco D. Palacios, Thomas D. Economon,
 *                      Tim Albring, and the SU2 contributors.
 *
 * SU2 is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * SU2 is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with SU2. If not, see <http://www.gnu.org/licenses/>.
 */

#include "../include/variable_structure.hpp"

CRadVariable::CRadVariable(void) : CVariable() {

}

CRadVariable::CRadVariable(unsigned short val_nDim, unsigned short val_nvar, CConfig *config)
: CVariable(val_nDim, val_nvar, config) {

  Radiative_SourceTerm = new su2double[2];

  Radiative_SourceTerm[0] = 0.0; // The first term is the source term
  Radiative_SourceTerm[1] = 0.0; // The second term is the Jacobian

}

CRadVariable::~CRadVariable(void) { }

CRadP1Variable::CRadP1Variable(void) : CRadVariable() { }

CRadP1Variable::CRadP1Variable(su2double val_energy, unsigned short val_nDim, unsigned short val_nvar, CConfig *config)
: CRadVariable(val_nDim, val_nvar, config) {

  /*--- Initialization of variables ---*/

  Solution[0] = val_energy;

}

CRadP1Variable::~CRadP1Variable(void) {

}
