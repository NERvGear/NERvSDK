/***************************************************************
 * Name:      Interpolator.h
 * Purpose:   Defines Interpolate Classes
 * Author:    GPBeta ()
 * Created:   2015-01-25
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_INTERPOLATOR_H
#define NVG_INTERPOLATOR_H

namespace NERvGear {

/// \declns{NERvGear::Interpolator}
namespace Interpolator {

// include math.h to use these interpolator
template <class P, class T> class       Sin { public: inline static T Value(P cur, P max, const T& src) { return          src * sinf(2 * 3.141592654f * cur / max); } };
template <class P, class T> class       Cos { public: inline static T Value(P cur, P max, const T& src) { return          src * cosf(2 * 3.141592654f * cur / max); } };

template <class P, class T> class    Linear { public: inline static T Value(P cur, P max, const T& src) { return                                  src  * cur / max; } };
template <class P, class T> class Quadratic { public: inline static T Value(P cur, P max, const T& src) { return    Linear<P, T>::Value(cur, max, src) * cur / max; } };
template <class P, class T> class     Cubic { public: inline static T Value(P cur, P max, const T& src) { return Quadratic<P, T>::Value(cur, max, src) * cur / max; } };
template <class P, class T> class   Quartic { public: inline static T Value(P cur, P max, const T& src) { return     Cubic<P, T>::Value(cur, max, src) * cur / max; } };
template <class P, class T> class   Quintic { public: inline static T Value(P cur, P max, const T& src) { return   Quartic<P, T>::Value(cur, max, src) * cur / max; } };
template <class P, class T> class   Bicubic { public: inline static T Value(P cur, P max, const T& src) { return   Quintic<P, T>::Value(cur, max, src) * cur / max; } };

// partial specialization
// for float
template <class T> class Quadratic<float, T> { public: inline static T Value(float cur, float max, const T& src) { float lin = cur / max; float qua = lin * lin;       return src * qua; } };
template <class T> class     Cubic<float, T> { public: inline static T Value(float cur, float max, const T& src) { float lin = cur / max; float cub = lin * lin * lin; return src * cub; } };
template <class T> class   Quartic<float, T> { public: inline static T Value(float cur, float max, const T& src) { float lin = cur / max; float qua = lin * lin;       return src * qua * qua; } };
template <class T> class   Quintic<float, T> { public: inline static T Value(float cur, float max, const T& src) { float lin = cur / max; float qua = lin * lin;       return src * qua * qua * lin; } };
template <class T> class   Bicubic<float, T> { public: inline static T Value(float cur, float max, const T& src) { float lin = cur / max; float cub = lin * lin * lin; return src * cub * cub; } };
// for double
template <class T> class Quadratic<double, T> { public: inline static T Value(double cur, double max, const T& src) { double lin = cur / max; double qua = lin * lin;       return src * qua; } };
template <class T> class     Cubic<double, T> { public: inline static T Value(double cur, double max, const T& src) { double lin = cur / max; double cub = lin * lin * lin; return src * cub; } };
template <class T> class   Quartic<double, T> { public: inline static T Value(double cur, double max, const T& src) { double lin = cur / max; double qua = lin * lin;       return src * qua * qua; } };
template <class T> class   Quintic<double, T> { public: inline static T Value(double cur, double max, const T& src) { double lin = cur / max; double qua = lin * lin;       return src * qua * qua * lin; } };
template <class T> class   Bicubic<double, T> { public: inline static T Value(double cur, double max, const T& src) { double lin = cur / max; double cub = lin * lin * lin; return src * cub * cub; } };

// reverse
template <class P, class T> class QuadraticR { public: inline static T Value(P cur, P max, const T& src) { return src - Quadratic<P, T>::Value(max - cur, max, src); } };
template <class P, class T> class     CubicR { public: inline static T Value(P cur, P max, const T& src) { return src -     Cubic<P, T>::Value(max - cur, max, src); } };
template <class P, class T> class   QuarticR { public: inline static T Value(P cur, P max, const T& src) { return src -   Quartic<P, T>::Value(max - cur, max, src); } };
template <class P, class T> class   QuinticR { public: inline static T Value(P cur, P max, const T& src) { return src -   Quintic<P, T>::Value(max - cur, max, src); } };
template <class P, class T> class   BicubicR { public: inline static T Value(P cur, P max, const T& src) { return src -   Bicubic<P, T>::Value(max - cur, max, src); } };

} // Interpolator

} // NERvGear


#endif // NVG_INTERPOLATOR_H
