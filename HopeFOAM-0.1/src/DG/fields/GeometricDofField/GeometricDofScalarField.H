/*--------------------------------------------------------------------------------------
|     __  ______  ____  ______ |                                                       |
|    / / / / __ \/ __ \/ ____/ | HopeFOAM: High Order Parallel Extensible CFD Software |
|   / /_/ / / / / /_/ / __/    |                                                       |
|  / __  / /_/ / ____/ /___    |                                                       |
| /_/ /_/\____/_/   /_____/    | Copyright(c) 2017-2017 The Exercise Group, AMS, China.|
|                              |                                                       |
----------------------------------------------------------------------------------------

License
    This file is part of HopeFOAM, which is developed by Exercise Group, Innovation 
    Institute for Defence Science and Technology, the Academy of Military Science (AMS), China.

    HopeFOAM is free software: you can redistribute it and/or modify it
    under the terms of the GNU General Public License as published by the
    Free Software Foundation, either version 3 of the License, or (at your
    option) any later version.

    HopeFOAM is distributed in the hope that it will be useful, but
    WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
    General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with HopeFOAM.  If not, see <http://www.gnu.org/licenses/>.

InClass
    Foam::GeometricDofScalarField

Description
    Scalar specific part of the implementation of GeometricDofField.

SourceFiles
    GeometricDofScalarField.C

\*---------------------------------------------------------------------------*/

#ifndef GeometricDofScalarField_H
#define GeometricDofScalarField_H

#include "GeometricDofField.H"
#include "DimensionedScalarField.H"

#define TEMPLATE template<template<class> class PatchField, class GeoMesh>
#include "GeometricDofFieldFunctionsM.H"

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

namespace Foam
{

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

template<template<class> class PatchField, class GeoMesh>
void stabilise
(
    GeometricDofField<scalar, PatchField, GeoMesh>&,
    const GeometricDofField<scalar, PatchField, GeoMesh>&,
    const dimensioned<scalar>&
);

template<template<class> class PatchField, class GeoMesh>
tmp<GeometricDofField<scalar, PatchField, GeoMesh>> stabilise
(
    const GeometricDofField<scalar, PatchField, GeoMesh>&,
    const dimensioned<scalar>&
);

template<template<class> class PatchField, class GeoMesh>
tmp<GeometricDofField<scalar, PatchField, GeoMesh>> stabilise
(
    const tmp<GeometricDofField<scalar, PatchField, GeoMesh>>&,
    const dimensioned<scalar>&
);


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

BINARY_TYPE_OPERATOR(scalar, scalar, scalar, +, '+', add)
BINARY_TYPE_OPERATOR(scalar, scalar, scalar, -, '-', subtract)

BINARY_OPERATOR(scalar, scalar, scalar, *, '*', multiply)
BINARY_OPERATOR(scalar, scalar, scalar, /, '|', divide)

BINARY_TYPE_OPERATOR_SF(scalar, scalar, scalar, /, '|', divide)

BINARY_FUNCTION(scalar, scalar, scalar, pow)
BINARY_TYPE_FUNCTION(scalar, scalar, scalar, pow)

BINARY_FUNCTION(scalar, scalar, scalar, atan2)
BINARY_TYPE_FUNCTION(scalar, scalar, scalar, atan2)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

UNARY_FUNCTION(scalar, scalar, pow3, pow3)
UNARY_FUNCTION(scalar, scalar, pow4, pow4)
UNARY_FUNCTION(scalar, scalar, pow5, pow5)
UNARY_FUNCTION(scalar, scalar, pow6, pow6)
UNARY_FUNCTION(scalar, scalar, pow025, pow025)
UNARY_FUNCTION(scalar, scalar, sqrt, sqrt)
UNARY_FUNCTION(scalar, scalar, cbrt, cbrt)
UNARY_FUNCTION(scalar, scalar, sign, sign)
UNARY_FUNCTION(scalar, scalar, pos, pos)
UNARY_FUNCTION(scalar, scalar, neg, neg)
UNARY_FUNCTION(scalar, scalar, posPart, posPart)
UNARY_FUNCTION(scalar, scalar, negPart, negPart)

UNARY_FUNCTION(scalar, scalar, exp, trans)
UNARY_FUNCTION(scalar, scalar, log, trans)
UNARY_FUNCTION(scalar, scalar, log10, trans)
UNARY_FUNCTION(scalar, scalar, sin, trans)
UNARY_FUNCTION(scalar, scalar, cos, trans)
UNARY_FUNCTION(scalar, scalar, tan, trans)
UNARY_FUNCTION(scalar, scalar, asin, trans)
UNARY_FUNCTION(scalar, scalar, acos, trans)
UNARY_FUNCTION(scalar, scalar, atan, trans)
UNARY_FUNCTION(scalar, scalar, sinh, trans)
UNARY_FUNCTION(scalar, scalar, cosh, trans)
UNARY_FUNCTION(scalar, scalar, tanh, trans)
UNARY_FUNCTION(scalar, scalar, asinh, trans)
UNARY_FUNCTION(scalar, scalar, acosh, trans)
UNARY_FUNCTION(scalar, scalar, atanh, trans)
UNARY_FUNCTION(scalar, scalar, erf, trans)
UNARY_FUNCTION(scalar, scalar, erfc, trans)
UNARY_FUNCTION(scalar, scalar, lgamma, trans)
UNARY_FUNCTION(scalar, scalar, j0, trans)
UNARY_FUNCTION(scalar, scalar, j1, trans)
UNARY_FUNCTION(scalar, scalar, y0, trans)
UNARY_FUNCTION(scalar, scalar, y1, trans)


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#define BesselFunc(func)                                                       \
                                                                               \
template<template<class> class PatchField, class GeoMesh>                      \
void func                                                                      \
(                                                                              \
    GeometricDofField<scalar, PatchField, GeoMesh>& Res,                          \
    const int n,                                                               \
    const GeometricDofField<scalar, PatchField, GeoMesh>& sf                      \
);                                                                             \
                                                                               \
template<template<class> class PatchField, class GeoMesh>                      \
tmp<GeometricDofField<scalar, PatchField, GeoMesh>> func                          \
(                                                                              \
    const int n,                                                               \
    const GeometricDofField<scalar, PatchField, GeoMesh>&                         \
);                                                                             \
                                                                               \
template<template<class> class PatchField, class GeoMesh>                      \
tmp<GeometricDofField<scalar, PatchField, GeoMesh>> func                          \
(                                                                              \
    const int n,                                                               \
    const tmp<GeometricDofField<scalar, PatchField, GeoMesh>>&                    \
);

BesselFunc(jn)
BesselFunc(yn)

#undef BesselFunc


// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

} // End namespace Foam

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#include "undefDofFieldFunctionsM.H"

#ifdef NoRepository
    #include "GeometricDofScalarField.C"
#endif

// * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * //

#endif

// ************************************************************************* //
