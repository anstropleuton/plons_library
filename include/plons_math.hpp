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

#include "foundation/Px.h"
#include "foundation/PxMat33.h"
#include "foundation/PxMat44.h"
#include "foundation/PxVec2.h"
#include "foundation/PxVec3.h"
#include "glm/detail/qualifier.hpp"
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
        [&]() -> v2_t<T>          {
            return v2_t<T>(x, y);
        },
        [&](const v2_t<T> &value) {
            x = value.x;
            y = value.y;
        }
    };

    /**
     *  @brief  Rectangle's size.
     */
    property<v2_t<T>> size = {
        [&]() -> v2_t<T>          {
            return v2_t<T>(w, h);
        },
        [&](const v2_t<T> &value) {
            w = value.x;
            h = value.y;
        }
    };

    /**
     *  @brief  Rectangle's center position.
     */
    property<v2_t<T>> center = {
        [&]() -> v2_t<T>          {
            return pos + size / T(2.0);
        },
        [&](const v2_t<T> &value) {
            pos = value - size / T(2.0);
        }
    };

    /**
     *  @brief  Rectangle's half size.
     */
    property<v2_t<T>> half_extents = {
        [&]() -> v2_t<T>          {
            return size / T(2.0);
        },
        [&](const v2_t<T> &value) {
            size = value * T(2.0);
        }
    };

    /**
     *  @brief  Rectangle's top edge.
     */
    property<T> top = {
        [&]() -> T          {
            return y;
        },
        [&](const T &value) {
            auto diff = y - value;
            y        += diff;
            h        -= diff;
        }
    };

    /**
     *  @brief  Rectangle's bottom edge.
     */
    property<T> bottom = {
        [&]() -> T          {
            return y + h;
        },
        [&](const T &value) {
            auto diff = y + h - value;
            h        += diff;
        }
    };

    /**
     *  @brief  Rectangle's left edge.
     */
    property<T> left = {
        [&]() -> T          {
            return x;
        },
        [&](const T &value) {
            auto diff = x - value;
            x        += diff;
            w        -= diff;
        }
    };

    /**
     *  @brief  Rectangle's right edge.
     */
    property<T> right = {
        [&]() -> T          {
            return x + w;
        },
        [&](const T &value) {
            auto diff = x + w - value;
            w        += diff;
        }
    };

    /**
     *  @brief  Rectangle's left-top corner.
     */
    property<v2_t<T>> left_top = {
        [&]() -> v2_t<T>          {
            return v2_t(left, top);
        },
        [&](const v2_t<T> &value) {
            left = value.x;
            top  = value.y;
        }
    };

    /**
     *  @brief  Rectangle's right-top corner.
     */
    property<v2_t<T>> right_top = {
        [&]() -> v2_t<T>          {
            return v2_t(right, top);
        },
        [&](const v2_t<T> &value) {
            right = value.x;
            top   = value.y;
        }
    };

    /**
     *  @brief  Rectangle's left-bottom corner.
     */
    property<v2_t<T>> left_bottom = {
        [&]() -> v2_t<T>          {
            return v2_t(left, bottom);
        },
        [&](const v2_t<T> &value) {
            left   = value.x;
            bottom = value.y;
        }
    };

    /**
     *  @brief  Rectangle's right-bottom corner.
     */
    property<v2_t<T>> right_bottom = {
        [&]() -> v2_t<T>          {
            return v2_t(right, bottom);
        },
        [&](const v2_t<T> &value) {
            right  = value.x;
            bottom = value.y;
        }
    };
};

/**
 *  @brief  Rectangle with float components.
 */
using r = r_t<float>;

/**
 *  @brief  Rectangle with int components.
 */
using ri = r_t<int>;

} // namespace m

} // namespace plons
