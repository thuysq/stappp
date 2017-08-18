/*****************************************************************************/
/*  STAP++ : A C++ FEM code sharing the same input data file with STAP90     */
/*     Computational Dynamics Laboratory                                     */
/*     School of Aerospace Engineering, Tsinghua University                  */
/*                                                                           */
/*     http://www.comdyn.cn/                                                 */
/*****************************************************************************/

#pragma once

#include "Domain.h"

using namespace std;

//	Base class for a solver
//	New solver should be derived from this base class, and match the storage scheme 
//	of the global stiffness matrix employed in Domain class.
class Solver
{
protected:

	Domain* FEMData;

public:

	Solver(Domain* FEMData);

	virtual void Solve() = 0;
};

//	LDLT solver: A in core solver using skyline storage  and column reduction scheme
class LDLTSolver : public Solver
{
public:

//	Constructor
	LDLTSolver(Domain* FEMData) :Solver(FEMData) {};

//	Perform L*D*L(T) factorization of the stiffness matrix
	void LDLT();

//	Reduce right-hand-side load vector and back substitute
	void BackSubstitution(); 

//	Solve the equilibrium equations 
	virtual void Solve();
};