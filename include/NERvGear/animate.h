
/***************************************************************
 * Name:      AnimateT.h
 * Purpose:   Defines Animate Template Class
 * Author:    GPBeta ()
 * Created:   2015-01-25
 * Copyright: GPBeta ()
 * License:
 **************************************************************/

#ifndef NVG_ANIMATE_H
#define NVG_ANIMATE_H

#include <NERvGear/interface/IUnknown.h>

#include "interpolator.h"

namespace NERvGear {

namespace UI {

namespace ANIMATE {

enum ID {
    NONE = 0,

    MOVE = 100,
    MOVE_X,
    MOVE_Y,

    SIZE = 200,
    SIZE_W,
    SIZE_H,

    ALPHA = 300,

    TRANSLATE = 500,
    TRANSLATE_X,
    TRANSLATE_Y,
    TRANSLATE_Z,

    SCALE = 600,
    SCALE_X,
    SCALE_Y,
    SCALE_Z,

    ROTATE = 700,
    ROTATE_X,
    ROTATE_Y,
    ROTATE_Z,

    CUSTOM = 1000
};

typedef int TYPE;

}

/// ----------------------------------------------------------------------------
/// Animate: \brief Base class of animation.
/// ----------------------------------------------------------------------------
class Animate : public UnknownImpl {
public:

    enum STATE { STOP, WAIT, PLAY };

    // getters
    unsigned long   GetEnding() const { return m_delay + m_duration; }
    unsigned long GetDuration() const { return m_duration; }
    unsigned long    GetDelay() const { return m_delay; }
    bool              GetLoop() const { return m_loop; }
    STATE    GetState() const { return m_state; }

    // setters

    void SetDuration(unsigned long msDuration) { m_duration = msDuration; }
    void SetDelay(unsigned long msDelay)       { m_delay = msDelay; }
    void SetLoop(bool loop = true)             { m_loop = loop; }
    void SetState(STATE state)                 { m_state =  state; }

    /// Interfaces
    /// --------------------------------------------------------------

    virtual void* NVG_METHOD GetObject() const = 0;
    virtual ANIMATE::TYPE NVG_METHOD GetAnimateType() const = 0;

    virtual void NVG_METHOD OnStart(unsigned long ms) = 0;
    virtual void NVG_METHOD OnFrame(unsigned long ms) = 0;
    virtual void NVG_METHOD OnStop(unsigned long ms) = 0;

    /// Constructors & Destructor
    /// --------------------------------------------------------------

    Animate(unsigned long msDuration, unsigned long msDelay, bool loop) : m_duration(msDuration), m_delay(msDelay), m_loop(loop), m_state(STOP) {}
    virtual ~Animate() {};

protected:

    unsigned long m_duration;
    unsigned long m_delay;
    bool m_loop;

    STATE m_state;
};

template <ANIMATE::TYPE A, class O, class T>
class AssigAnimateT {
public:
    static inline void Set(O* object, const T& value);
};

/// ----------------------------------------------------------------------------
/// AnimateT: \brief Animate class template.
/// template \param I: An Interpolator class for calculation, available value see "Interpolate.h"
/// template \param O: Associated animate object, should implement SetAttribute template function
/// template \param A: Specify unique animate type, available value see above
/// template \param T: Specify animate value type
/// ----------------------------------------------------------------------------
template <template <class, class> class I, class O, ANIMATE::TYPE A, class T>
class AnimateT : public Animate {
public:

    const T& GetSource()      const { return m_source; }
    const T& GetDestination() const { return m_destin; }

    void SetObject(O* object)         { m_object = object; }

    void SetSource(const T& src)      { m_source = src; }
    void SetDestination(const T& dst) { m_destin = dst; }

    /// Overridden Functions
    /// --------------------------------------------------------------

    virtual void* NVG_METHOD GetObject() const { return m_object; }
    virtual ANIMATE::TYPE NVG_METHOD GetAnimateType() const { return A; };

    virtual void NVG_METHOD OnStart(unsigned long ms) { /* currently not used */ }
    virtual void NVG_METHOD OnFrame(unsigned long ms) { AssigAnimateT<A, O, T>::Set(m_object, m_source + I<long, T>::Value(ms - m_delay, m_duration, m_destin - m_source)); }
    virtual void NVG_METHOD OnStop(unsigned long ms) { AssigAnimateT<A, O, T>::Set(m_object, m_destin); }

    /// Constructors & Destructor
    /// --------------------------------------------------------------

    AnimateT(O* object, const T& src, const T& dst, unsigned long msDuration = 1000, unsigned long msDelay = 0, bool loop = false) :
        Animate(msDuration, msDelay, loop), m_object(object), m_source(src), m_destin(dst) {}
    virtual ~AnimateT() {}

private:

    /// Declarations
    /// -----------------

    O* m_object;

    T m_source;
    T m_destin; /* calculating rather than storing delta value every time to improve precision */
};

template <class O, class T>
class AssigAnimateT<ANIMATE::ALPHA,       O, T> { public: static inline void Set(O* object, const T& value) { object->SetAlpha(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::MOVE,        O, T> { public: static inline void Set(O* object, const T& value) { object->SetPosition(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::SIZE,        O, T> { public: static inline void Set(O* object, const T& value) { object->SetSize(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::TRANSLATE,   O, T> { public: static inline void Set(O* object, const T& value) { object->SetTranslate(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::TRANSLATE_X, O, T> { public: static inline void Set(O* object, const T& value) { object->SetTranslateX(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::TRANSLATE_Y, O, T> { public: static inline void Set(O* object, const T& value) { object->SetTranslateY(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::TRANSLATE_Z, O, T> { public: static inline void Set(O* object, const T& value) { object->SetTranslateZ(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::SCALE,       O, T> { public: static inline void Set(O* object, const T& value) { object->SetScale(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::SCALE_X,     O, T> { public: static inline void Set(O* object, const T& value) { object->SetScaleX(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::SCALE_Y,     O, T> { public: static inline void Set(O* object, const T& value) { object->SetScaleY(value); } };

template <class O, class T>
class AssigAnimateT<ANIMATE::SCALE_Z,     O, T> { public: static inline void Set(O* object, const T& value) { object->SetScaleZ(value); } };

} // UI

} // NERvGear

#endif // NVG_ANIMATE_H
