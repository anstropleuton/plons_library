/**
 *  @file    plons_math.hpp
 *  @author  Anstro Pleuton (https://github.com/anstropleuton)
 *  @brief   Mathematical functions and translation across dependencies.
 *
 *  @copyright  Copyright (c) 2024 Anstro Pleuton
 *
 *   ____  _
 *  |  _ \| | ___  _ __  ___    _    ___ ___ ___    _   _____   __
 *  | |_) | |/ _ \| '_ \/ __|  | |  |_ _| _ ) _ \  /_\ | _ \ \ / /
 *  |  __/| | (_) | | | \__ \  | |__ | || _ \   / / _ \|   /\ V /
 *  |_|   |_|\___/|_| |_|___/  |____|___|___/_|_\/_/ \_\_|_\ |_|
 *
 *  Plons Library is a collection of frameworks for Anstro Pleuton's programs.
 *
 *  This software is licensed under the terms of MIT License.
 *
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to
 *  deal in the Software without restriction, including without limitation the
 *  rights to use, copy, modify, merge, publish, distribute, sublicense, and/or
 *  sell copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 *
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 *
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.  IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING
 *  FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS
 *  IN THE SOFTWARE.
 *
 *  Credits where credit's due:
 *  - ASCII Art generated using https://www.patorjk.com/software/taag with font
 *    "Standard" (for "Plons") and "Small" (for "LIBRARY").
 */

#pragma once

#include <algorithm>
#include <cstddef>
#include <cstdint>
#include <cstdlib>
#include <limits>

#include "foundation/Px.h"
#include "foundation/PxMat33.h"
#include "foundation/PxMat44.h"
#include "foundation/PxVec2.h"
#include "foundation/PxVec3.h"
#include "glm/detail/qualifier.hpp"
#include "glm/glm.hpp"
#include "plons_property.hpp"

/**
 *  @brief  All Plons Library's contents in this namespace.  Just do
 *          `using namespace plons` to make your life easier.
 */
namespace plons {

/**
 *  @brief  Mathematical functionalities.
 */
namespace m {

/**
 *  @brief  Vector 2 intermediate template type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct v2_t : glm::tvec2<T> {
    /**
     *  @brief  Inherit constructor.
     */
    using glm::tvec2<T>::tvec2;

    /**
     *  @brief  Construct using GLM's Vector type.
     *  @param  v  The vector.
     */
    inline constexpr v2_t(const glm::tvec2<T> &v) : glm::tvec2<T>(v) {}

    /**
     *  @brief  Construct using PhysX's Vector type.
     *  @param  v  The vector.
     */
    inline constexpr v2_t(const physx::PxVec2T<T> &v)
        : glm::tvec2<T>(v.x, v.y) {}

    /**
     *  @brief  Convert to PhysX's Vector type.
     *  @return  Vector in PhysX's Vector type.
     */
    [[nodiscard]] inline constexpr operator physx::PxVec2T<T>() const {
        return physx::PxVec2T<T> { this->x, this->y };
    }
};

/**
 *  @brief  Vector 2 type with float components.
 */
using v2 = v2_t<float>;

/**
 *  @brief  Vector 2 type with int components.
 */
using v2i = v2_t<int>;

/**
 *  @brief  Vector 3 intermediate template type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct v3_t : glm::tvec3<T> {
    /**
     *  @brief  Inherit constructor.
     */
    using glm::tvec3<T>::tvec3;

    /**
     *  @brief  Construct using GLM's Vector type.
     *  @param  v  The vector.
     */
    inline constexpr v3_t(const glm::tvec3<T> &v) : glm::tvec3<T>(v) {}

    /**
     *  @brief  Construct using PhysX's Vector type.
     *  @param  v  The vector.
     */
    inline constexpr v3_t(const physx::PxVec3T<T> &v)
        : glm::tvec3<T>(v.x, v.y, v.z) {}

    /**
     *  @brief  Convert to PhysX's Vector type.
     *  @return  Vector in PhysX's Vector type.
     */
    [[nodiscard]] inline constexpr operator physx::PxVec3T<T>() const {
        return physx::PxVec3T<T> { this->x, this->y, this->z };
    }
};

/**
 *  @brief  Vector 3 type with float components.
 */
using v3 = v3_t<float>;

/**
 *  @brief  Vector 3 type with int components.
 */
using v3i = v3_t<int>;

/**
 *  @brief  Vector 4 intermediate template type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct v4_t : glm::tvec4<T> {
    /**
     *  @brief  Inherit constructor.
     */
    using glm::tvec4<T>::tvec4;

    /**
     *  @brief  Construct using GLM's Vector type.
     *  @param  v  The vector.
     */
    inline constexpr v4_t(const glm::tvec4<T> &v) : glm::tvec4<T>(v) {}

    /**
     *  @brief  Construct using PhysX's Vector type.
     *  @param  v  The vector.
     */
    inline constexpr v4_t(const physx::PxVec4T<T> &v)
        : glm::tvec4<T>(v.x, v.y, v.z, v.z) {}

    /**
     *  @brief  Convert to PhysX's Vector type.
     *  @return  Vector in PhysX's Vector type.
     */
    [[nodiscard]] inline constexpr operator physx::PxVec4T<T>() const {
        return physx::PxVec4T<T> { this->x, this->y, this->z, this->w };
    }
};

/**
 *  @brief  Vector 4 type with float components.
 */
using v4 = v4_t<float>;

/**
 *  @brief  Vector 4 type with int components.
 */
using v4i = v4_t<int>;

/**
 *  @brief  Matrix 3x3 intermediate template type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct m3_t : glm::tmat3x3<T> {

    /**
     *  @brief  Inherit constructor.
     */
    using glm::tmat3x3<T>::tmat3x3;

    /**
     *  @brief  Construct using GLM's Matrix type.
     *  @param  m  The matrix.
     */
    inline constexpr m3_t(const glm::tmat3x3<T> &m) : glm::tmat3x3<T>(m) {}

    /**
     *  @brief  Construct using PhysX's Matrix type.
     *  @param  m  The matrix.
     */
    inline constexpr m3_t(const physx::PxMat33T<T> &m)
        : glm::tmat3x3<T>(
            glm::tvec3<T>(m.column0.x, m.column0.y, m.column0.z),
            glm::tvec3<T>(m.column1.x, m.column1.y, m.column1.z),
            glm::tvec3<T>(m.column2.x, m.column2.y, m.column2.z)
        ) {}

    /**
     *  @brief  Convert to PhysX's Matrix type.
     *  @return  Matrix in PhysX's Matrix type.
     */
    [[nodiscard]] inline constexpr operator physx::PxMat33T<T>() const {
        return physx::PxMat33T<T>(
            physx::PxVec3T<T>((*this)[0].x, (*this)[0].y, (*this)[0].z),
            physx::PxVec3T<T>((*this)[1].x, (*this)[1].y, (*this)[1].z),
            physx::PxVec3T<T>((*this)[2].x, (*this)[2].y, (*this)[2].z)
        );
    }
};

/**
 *  @brief  Matrix 3x3 with float components.
 */
using m3 = m3_t<float>;

/**
 *  @brief  Matrix 3x3 with int components.
 */
using m3i = m3_t<int>;

/**
 *  @brief  Matrix 4x4 intermediate template type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct m4_t : glm::tmat4x4<T> {

    /**
     *  @brief  Inherit constructor.
     */
    using glm::tmat4x4<T>::tmat4x4;

    /**
     *  @brief  Construct using GLM's Matrix type.
     *  @param  m  The matrix.
     */
    inline constexpr m4_t(const glm::tmat4x4<T> &m) : glm::tmat4x4<T>(m) {}

    /**
     *  @brief  Construct using PhysX's Matrix type.
     *  @param  m  The matrix.
     */
    inline constexpr m4_t(const physx::PxMat44T<T> &m)
        : glm::tmat4x4<T>(
            glm::tvec4<T>(m.column0.x, m.column0.y, m.column0.z, m.column0.w),
            glm::tvec4<T>(m.column1.x, m.column1.y, m.column1.z, m.column1.w),
            glm::tvec4<T>(m.column2.x, m.column2.y, m.column2.z, m.column2.w),
            glm::tvec4<T>(m.column3.x, m.column3.y, m.column3.z, m.column3.w)
        ) {}

    /**
     *  @brief  Convert to PhysX's Matrix type.
     *  @return  Matrix in PhysX's Matrix type.
     */
    [[nodiscard]] inline constexpr operator physx::PxMat44T<T>() const {
        return physx::PxMat44T<T>(
            physx::PxVec4T<T>((*this)[0].x, (*this)[0].y, (*this)[0].z),
            physx::PxVec4T<T>((*this)[1].x, (*this)[1].y, (*this)[1].z),
            physx::PxVec4T<T>((*this)[2].x, (*this)[2].y, (*this)[2].z)
        );
    }
};

/**
 *  @brief  Matrix 4x4 with float components.
 */
using m4 = m4_t<float>;

/**
 *  @brief  Matrix 4x4 with int components.
 */
using m4i = m4_t<int>;

/**
 *  @brief  Quaternion intermediate template type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct q_t : glm::tquat<T> {

    /**
     *  @brief  Inherit constructor.
     */
    using glm::tquat<T>::tquat;

    /**
     *  @brief  Construct using GLM's Quaternion type.
     *  @param  q  The quaternion.
     */
    inline constexpr q_t(const glm::tquat<T> &q) : glm::tquat<T>(q) {}

    /**
     *  @brief  Construct using PhysX's Quaternion type.
     *  @param  q  The quaternion.
     */
    inline constexpr q_t(const physx::PxQuatT<T> &q)
        : glm::tquat<T>(q.x, q.y, q.x, q.w) {}

    /**
     *  @brief  Convert to PhysX's Quaternion type.
     *  @return  Quaternion in PhysX's Quaternion type.
     */
    [[nodiscard]] inline constexpr operator physx::PxQuatT<T>() const {
        return physx::PxQuatT<T>(this->x, this->t, this->z, this->w);
    }
};

/**
 *  @brief  Quaternion with float components.
 */
using q = q_t<float>;

/**
 *  @brief  Quaternion with int components.
 */
using qi = q_t<int>;

/**
 *  @brief  Template to return true if two values are (almost) equal.
 *
 *  @tparam  T  The type of value.
 *  @param   a  The first value.
 *  @param   b  The second value.
 *  @return  True if two values are (almost) equal.
 *
 *  @note  If you find this useless, check below.
 */
template<typename T>
[[nodiscard]] inline constexpr auto is_almost_equal(
    const T &a,
    const T &b
) -> bool
{
    // Return true if they are exactly equal for all types by default
    return a == b;
}

/**
 *  @brief  Template to return true if two values are (almost) equal.
 *
 *  @param   a  The first value.
 *  @param   b  The second value.
 *  @return  True if two values are (almost) equal.
 */
template<>
[[nodiscard]] inline constexpr auto is_almost_equal<float>(
    const float &a,
    const float &b
) -> bool
{
    return std::abs(a - b) <= std::numeric_limits<float>::epsilon();
}

/**
 *  @brief  Template to return true if two float values are (almost) equal.
 *
 *  @param   a  The first float value.
 *  @param   b  The second float value.
 *  @return  True if two values are (almost) equal.
 */
template<>
[[nodiscard]] inline constexpr auto is_almost_equal<double>(
    const double &a,
    const double &b
) -> bool
{
    return std::abs(a - b) <= std::numeric_limits<double>::epsilon();
}

/**
 *  @brief  Template to return true if two float values are (almost) equal.
 *
 *  @param   a  The first float value.
 *  @param   b  The second float value.
 *  @return  True if two values are (almost) equal.
 */
template<>
[[nodiscard]] inline constexpr auto is_almost_equal<long double>(
    const long double &a,
    const long double &b
) -> bool
{
    return std::abs(a - b) <= std::numeric_limits<long double>::epsilon();
}

/**
 *  @brief  Rectangle type.
 *  @tparam  T  The type of component.
 */
template<typename T>
struct r_t {

    /**
     *  @brief  Rectangle's X position.
     */
    T x;

    /**
     *  @brief  Rectangle's Y position.
     */
    T y;

    /**
     *  @brief  Rectangle's width.
     */
    T w;

    /**
     *  @brief  Rectangle's height.
     */
    T h;

    /**
     *  @brief  Rectangle's position.
     */
    property<v2_t<T>> pos = {
        [&]() -> v2_t<T>
        {
            return v2_t<T>(x, y);
        },
        [&](const v2_t<T> &value)
        {
            x = value.x;
            y = value.y;
        }
    };

    /**
     *  @brief  Rectangle's size.
     */
    property<v2_t<T>> size = {
        [&]() -> v2_t<T>
        {
            return v2_t<T>(w, h);
        },
        [&](const v2_t<T> &value)
        {
            w = value.x;
            h = value.y;
        }
    };

    /**
     *  @brief  Rectangle's center position.
     */
    property<v2_t<T>> center = {
        [&]() -> v2_t<T>
        {
            return pos + size / T(2.0);
        },
        [&](const v2_t<T> &value)
        {
            pos = value - size / T(2.0);
        }
    };

    /**
     *  @brief  Rectangle's half size.
     */
    property<v2_t<T>> half_extents = {
        [&]() -> v2_t<T>
        {
            return size / T(2.0);
        },
        [&](const v2_t<T> &value)
        {
            size = value * T(2.0);
        }
    };

    /**
     *  @brief  Rectangle's top edge.
     */
    property<T> top = {
        [&]() -> T
        {
            return y;
        },
        [&](const T &value)
        {
            auto diff = y - value;
            y        += diff;
            h        -= diff;
        }
    };

    /**
     *  @brief  Rectangle's bottom edge.
     */
    property<T> bottom = {
        [&]() -> T
        {
            return y + h;
        },
        [&](const T &value)
        {
            auto diff = y + h - value;
            h        += diff;
        }
    };

    /**
     *  @brief  Rectangle's left edge.
     */
    property<T> left = {
        [&]() -> T
        {
            return x;
        },
        [&](const T &value)
        {
            auto diff = x - value;
            x        += diff;
            w        -= diff;
        }
    };

    /**
     *  @brief  Rectangle's right edge.
     */
    property<T> right = {
        [&]() -> T
        {
            return x + w;
        },
        [&](const T &value)
        {
            auto diff = x + w - value;
            w        += diff;
        }
    };

    /**
     *  @brief  Rectangle's left-top corner.
     */
    property<v2_t<T>> left_top = {
        [&]() -> v2_t<T>
        {
            return v2_t(left, top);
        },
        [&](const v2_t<T> &value)
        {
            left = value.x;
            top  = value.y;
        }
    };

    /**
     *  @brief  Rectangle's right-top corner.
     */
    property<v2_t<T>> right_top = {
        [&]() -> v2_t<T>
        {
            return v2_t(right, top);
        },
        [&](const v2_t<T> &value)
        {
            right = value.x;
            top   = value.y;
        }
    };

    /**
     *  @brief  Rectangle's left-bottom corner.
     */
    property<v2_t<T>> left_bottom = {
        [&]() -> v2_t<T>
        {
            return v2_t(left, bottom);
        },
        [&](const v2_t<T> &value)
        {
            left   = value.x;
            bottom = value.y;
        }
    };

    /**
     *  @brief  Rectangle's right-bottom corner.
     */
    property<v2_t<T>> right_bottom = {
        [&]() -> v2_t<T>
        {
            return v2_t(right, bottom);
        },
        [&](const v2_t<T> &value)
        {
            right  = value.x;
            bottom = value.y;
        }
    };

    /**
     *  @brief  Check if two rectangles are (almost) equal.
     *
     *  @param  o  The other rectangle.
     *  @return  True if two rectangles are (almost) equal.
     */
    [[nodiscard]] inline constexpr auto operator== (const r_t &o)
    {
        return is_almost_equal(x, o.x)
            && is_almost_equal(y, o.y)
            && is_almost_equal(w, o.w)
            && is_almost_equal(h, o.h);
    }
};

/**
 *  @brief  Rectangle with float components.
 */
using r = r_t<float>;

/**
 *  @brief  Rectangle with int components.
 */
using ri = r_t<int>;

/**
 *  @brief  Color type.
 */
struct c {

    /**
     *  @brief  Color's red channel.
     */
    std::byte r;

    /**
     *  @brief  Color's green channel.
     */
    std::byte g;

    /**
     *  @brief  Color's blue channel.
     */
    std::byte b;

    /**
     *  @brief  Color's alpha channel.
     */
    std::byte a;

    /**
     *  @brief  Color's values in RGBA integral hexadecimal.
     */
    property<std::uint32_t> rgba_hex = {
        [&]() -> std::uint32_t
        {
            return ((std::uint32_t)r << 24)
                 | ((std::uint32_t)g << 16)
                 | ((std::uint32_t)b << 8)
                 | ((std::uint32_t)a);
        },
        [&](std::uint32_t value)
        {
            r = (std::byte)((value >> 24) & 0xff);
            g = (std::byte)((value >> 16) & 0xff);
            b = (std::byte)((value >> 8) & 0xff);
            a = (std::byte)(value & 0xff);
        }
    };

    /**
     *  @brief  Color's values in ARGB integral hexadecimal.
     */
    property<std::uint32_t> argb_hex = {
        [&]() -> std::uint32_t
        {
            return ((std::uint32_t)a << 24)
                 | ((std::uint32_t)r << 16)
                 | ((std::uint32_t)g << 8)
                 | ((std::uint32_t)b);
        },
        [&](std::uint32_t value)
        {
            a = (std::byte)((value >> 24) & 0xff);
            r = (std::byte)((value >> 16) & 0xff);
            g = (std::byte)((value >> 8) & 0xff);
            b = (std::byte)(value & 0xff);
        }
    };

    /**
     *  @brief  Color's values in normalized form.
     */
    property<v4> normalized = {
        [&]() -> v4
        {
            return v4(
                (float)r / (float)(std::byte)-1,
                (float)g / (float)(std::byte)-1,
                (float)b / (float)(std::byte)-1,
                (float)a / (float)(std::byte)-1
            );
        },
        [&](const v4 &value)
        {
            r = (std::byte)(value.x * (float)(std::byte)-1);
            g = (std::byte)(value.x * (float)(std::byte)-1);
            b = (std::byte)(value.x * (float)(std::byte)-1);
            a = (std::byte)(value.x * (float)(std::byte)-1);
        }
    };

    /**
     *  @brief  Color's values in HSV and alpha form.
     */
    property<v4> hsva = {
        // It's unclear where this piece of code originates from
        // But I have found it here https://stackoverflow.com/a/6930407
        [&]() -> v4
        {
            v4 norm = normalized;

            float min = norm.r < norm.g ? norm.r : norm.g;
            min       = min < norm.b ? min : norm.b;

            float max = norm.r > norm.g ? norm.r : norm.g;
            max       = max > norm.b ? max : norm.b;

            v4 result;
            result.z    = max; // v
            float delta = max - min;
            if (delta < 0.00001)
            {
                result.y = 0; // s
                result.x = 0; // h undefined, maybe nan?
                return result;
            }
            if (max > 0.0) // NOTE: if Max is == 0, this divide would cause a
                           // crash
            {
                result.y = (delta / max); // s
            }
            else
            {
                // if max is 0, then r = g = b = 0
                // s = 0, h is undefined
                result.y = 0.0; // s
                result.x = NAN; // h is now undefined
                return result;
            }
            if (norm.r >= max) // > is bogus, just keeps compilor happy
            {
                // between yellow & magenta
                result.x = (norm.g - norm.b) / delta; // h
            }
            else if (norm.g >= max)
            {
                // between cyan & yellow
                result.x = 2.0 + (norm.b - norm.r) / delta; // h
            }
            else
            {
                // between magenta & cyan
                result.x = 4.0 + (norm.r - norm.g) / delta; // h
            }

            result.x *= 60.0; // h, degrees
            if (result.x < 0.0)
                result.x += 360.0;

            return result;
        },
        [&](const v4 &value) {
            v4 norm;

            if (value.y <= 0.0) // < is bogus, just shuts up warnings
            {
                norm.r     = value.z;
                norm.g     = value.z;
                norm.b     = value.z;
                normalized = norm;
                return;
            }
            float hh = value.x;
            if (hh >= 360.0) hh = 0.0;
            hh      /= 60.0;
            int i    = (int)hh;
            float ff = hh - i;
            float p  = value.z * (1.0 - value.y);
            float q  = value.z * (1.0 - (value.y * ff));
            float t  = value.z * (1.0 - (value.y * (1.0 - ff)));

            switch (i)
            {
                case 0:
                    norm.r = value.z;
                    norm.g = t;
                    norm.b = p;
                    break;
                case 1:
                    norm.r = q;
                    norm.g = value.z;
                    norm.b = p;
                    break;
                case 2:
                    norm.r = p;
                    norm.g = value.z;
                    norm.b = t;
                    break;

                case 3:
                    norm.r = p;
                    norm.g = q;
                    norm.b = value.z;
                    break;
                case 4:
                    norm.r = t;
                    norm.g = p;
                    norm.b = value.z;
                    break;
                case 5:
                default:
                    norm.r = value.z;
                    norm.g = p;
                    norm.b = q;
                    break;
            }

            normalized = norm;
            return;
        }
    };

    /**
     *  @brief  Default constructor sets everything to zero.
     */
    inline constexpr c() = default;

    /**
     *  @brief  Create color using 0..255 integer values.
     *
     *  @param  r  The color's red channel.
     *  @param  g  The color's green channel.
     *  @param  b  The color's blue channel.
     *  @param  a  The color's alpha channel.
     */
    inline c(
        std::byte r,
        std::byte g,
        std::byte b,
        std::byte a
    ) : r(r), g(g), b(b), a(a) {}

    /**
     *  @brief  Create color using 0..255 integer values.
     *
     *  @param  r  The color's red channel.
     *  @param  g  The color's green channel.
     *  @param  b  The color's blue channel.
     */
    inline c(
        std::byte r,
        std::byte g,
        std::byte b
    ) : r(r), g(g), b(b), a((std::byte)-1) {}

    /**
     *  @brief  Create color using 0..255 integer values (narrowing conversion).
     *
     *  @param  r  The color's red channel.
     *  @param  g  The color's green channel.
     *  @param  b  The color's blue channel.
     *  @param  a  The color's alpha channel.
     */
    inline c(
        int r,
        int g,
        int b,
        int a
    ) : r((std::byte)r), g((std::byte)g), b((std::byte)b), a((std::byte)a) {}

    /**
     *  @brief  Create color using 0..255 integer values (narrowing conversion).
     *
     *  @param  r  The color's red channel.
     *  @param  g  The color's green channel.
     *  @param  b  The color's blue channel.
     */
    inline c(
        int r,
        int g,
        int b
    ) : r((std::byte)r), g((std::byte)g), b((std::byte)b), a((std::byte)-1) {}

    /**
     *  @brief  Copy constructor.
     *  @param  c  The color to copy from.
     */
    inline c(const c &c) : r(c.r), g(c.g), b(c.b), a(c.a) {}

    /**
     *  @brief  Tint the color.
     *  @param  tint  The color to tint this color with.
     */
    inline constexpr auto tint(const c &tint)
    {
        normalized *= tint.normalized;
    }

    /**
     *  @brief  Brighten the color.
     *  @param  factor  The factor (-1..1) to brighten this color with.
     */
    inline constexpr auto brighten(float factor)
    {
        auto alpha = a;
        if (factor < 0.0f)
        {
            factor      = 1.0 + factor;
            normalized *= v4(factor);
        }
        else
        {
            normalized = (v4(1.0f) - (v4)normalized) * factor + (v4)normalized;
        }

        // Restore alpha
        a = alpha;
    }

    /**
     *  @brief  Modify the contrast of the color.
     *  @param  factor  The factor (-1..1) to modify this color's contrast with.
     */
    inline constexpr auto contrast(float factor)
    {
        auto alpha = a;

        factor  = 1.0f + factor;
        factor *= factor;

        v4 norm = normalized;

        norm -= v4(0.5f);
        norm *= v4(factor);
        norm += v4(0.5f);

        // Clamp
        norm.x = std::clamp(norm.x, 0.0f, 1.0f);
        norm.y = std::clamp(norm.y, 0.0f, 1.0f);
        norm.z = std::clamp(norm.z, 0.0f, 1.0f);

        normalized = norm;

        // Restore alpha
        a = alpha;
    }

    /**
     *  @brief  Check if two colors are equal.
     *
     *  @param  o  The other color.
     *  @return  True if two colors are equal.
     */
    [[nodiscard]] inline constexpr auto operator== (const c &o)
    {
        return r == o.r
            && g == o.g
            && b == o.b
            && a == o.a;
    }
};

} // namespace m

} // namespace plons
