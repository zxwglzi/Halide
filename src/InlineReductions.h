#ifndef HALIDE_INLINE_REDUCTIONS_H
#define HALIDE_INLINE_REDUCTIONS_H

#include "IR.h"
#include "Tuple.h"

/** \file
 * Defines some inline reductions: sum, product, minimum, maximum.
 */
namespace Halide {

/** An inline reduction. This is suitable for convolution-type
 * operations - the reduction will be computed in the innermost loop
 * that it is used in. The argument may contain free or implicit
 * variables, and must refer to some reduction domain. The free
 * variables are still free in the return value, but the reduction
 * domain is captured - the result expression does not refer to a
 * reduction domain and can be used in a pure function definition.
 *
 * An example:
 *
 \code
 Func f, g;
 Var x;
 RDom r(0, 10);
 f(x) = x*x;
 g(x) = sum(f(x + r));
 \endcode
 *
 * Here g computes some blur of x, but g is still a pure function. The
 * sum is being computed by an anonymous reduction function that is
 * scheduled innermost within g.
 */
//@{
EXPORT Expr sum(Expr);
EXPORT Expr product(Expr);
EXPORT Expr maximum(Expr);
EXPORT Expr minimum(Expr);
EXPORT Expr sum(Expr, const std::string &);
EXPORT Expr product(Expr, const std::string &);
EXPORT Expr maximum(Expr, const std::string &);
EXPORT Expr minimum(Expr, const std::string &);
//@}

/** Returns an Expr or Tuple representing the coordinates of the point
 * in the RDom which minimizes or maximizes the expression. The
 * expression must refer to some RDom. Also returns the extreme value
 * of the expression as the last element of the tuple. */
// @{
EXPORT Tuple argmax(Expr);
EXPORT Tuple argmin(Expr);
EXPORT Tuple argmax(Expr, const std::string &);
EXPORT Tuple argmin(Expr, const std::string &);
// @}

}

#endif
