/**
 *  @author  Anstro Pleuton (https://github.com/anstropleuton)
 *  @brief   C# "property" ported to C++ (kinda).
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

#include <functional>

/**
 *  @brief  All Plons Library's contents in this namespace.  Just do
 *          `using namespace plons` to make your life easier.
 */
namespace plons {

/**
 *  @brief  Read-only Property (only getter).
 *  @tparam  T  The type of property.
 */
template<typename T>
struct property_readonly {

    /**
     *  @brief  Getter function, to return the value when the property is
     *          accessed.
     */
    std::function<T()> getter;

    /**
     *  @brief  Default constructors keeps getter empty.
     */
    inline constexpr property_readonly() = default;

    /**
     *  @brief  Creates property using getter.
     *  @param  getter  The getter function.
     */
    inline constexpr property_readonly(std::function<T()> getter)
        : getter(getter) {}

    /**
     *  @brief  Casting to value type will run getter.
     *  @return  Value returned from getter.
     */
    [[nodiscard]] inline constexpr operator T () const
    {
        return getter();
    }

    /**
     *  @brief  Add value with the property's value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Addition of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator+ (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() + o;
    }

    /**
     *  @brief  Subtract other value from the property's value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Subtraction of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator- (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() - o;
    }

    /**
     *  @brief  Multiply property's value by other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Multiplication of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator* (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() * o;
    }

    /**
     *  @brief  Divide property's value by other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Division of property's value by other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator/ (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() / o;
    }

    /**
     *  @brief  Modulus of property's value by other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Modulus of property's value by other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator% (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() % o;
    }

    /**
     *  @brief  Bitwise XOR of property's value and other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Bitwise XOR of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator^ (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() ^ o;
    }

    /**
     *  @brief  Bitwise AND of property's value and other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Bitwise AND of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator& (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() & o;
    }

    /**
     *  @brief  Bitwise OR of property's value and other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Bitwise OR of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator| (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() | o;
    }

    /**
     *  @brief  Left shift property's value by other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Left shift of property's value by other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator<< (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() << o;
    }

    /**
     *  @brief  Right shift property's value by other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Right shift of property's value by other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator>> (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() >> o;
    }

    /**
     *  @brief  Logical AND of property's value and other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Logical AND of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator&& (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() && o;
    }

    /**
     *  @brief  Logical OR of property's value and other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  Logical OR of property's value and other value.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator|| (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() || o;
    }

    /**
     *  @brief  Get the bitwise NOT of property's value.
     *  @return  Bitwise NOT of property's value.
     */
    [[nodiscard]] friend inline constexpr auto operator~ (
        const property_readonly &prop
    )
    {
        return ~prop.getter();
    }

    /**
     *  @brief  Get the logical NOT of property's value.
     *  @return  Logical NOT of property's value.
     */
    [[nodiscard]] friend inline constexpr auto operator! (
        const property_readonly &prop
    )
    {
        return !prop.getter();
    }

    /**
     *  @brief  Compare if property's value is less than other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  True if property's value is less than other value, false otherwise.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator< (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() < o;
    }

    /**
     *  @brief  Compare if property's value is less than or equal to other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  True if property's value is less than or equal to other value, false otherwise.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator<= (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() <= o;
    }

    /**
     *  @brief  Compare if property's value is greater than other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  True if property's value is greater than other value, false otherwise.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator> (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() > o;
    }

    /**
     *  @brief  Compare if property's value is greater than or equal to other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  True if property's value is greater than or equal to other value, false otherwise.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator>= (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() > o;
    }

    /**
     *  @brief  Compare if property's value is equal to other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  True if property's value is equal to other value, false otherwise.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator== (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() == o;
    }

    /**
     *  @brief  Compare if property's value is not equal to other value.
     *
     *  @tparam  U  The type of other value.
     *  @param   o  The other value.
     *  @return  True if property's value is not equal to other value, false otherwise.
     */
    template<typename U>
    [[nodiscard]] friend inline constexpr auto operator!= (
        const property_readonly &prop,
        const U                 &o
    )
    {
        return prop.getter() != o;
    }

    /**
     *  @brief  Call operator for property's value with arguments.
     *
     *  @tparam  Args  Argument types.
     *  @param   args  Arguments to pass to property's value.
     *  @return  Result of calling property's value with arguments.
     */
    template<typename... Args>
    inline constexpr auto operator() (Args &&... args)
    {
        return getter()(std::forward<Args>(args)...);
    }

    /**
     *  @brief  Subscript operator for property's value with arguments.
     *
     *  @tparam  Args  Argument types.
     *  @param   args  Arguments to index into property's value.
     *  @return  Result of indexing property's value with arguments.
     */
    template<typename... Args>
    inline constexpr auto operator[] (Args &&... args)
    {
        return getter()[std::forward<Args>(args)...];
    }
};

/**
 *  @brief  Read-write Property (both getter and setter)
 *  @tparam  T  The type of property.
 */
template<typename T>
struct property : property_readonly<T> {

    /**
     *  @brief  Setter function, to assign the value when the property is set.
     */
    std::function<void (const T &)> setter;

    /**
     *  @brief  Create property using getter and setter.
     *
     *  @param  getter  The getter function.
     *  @param  setter  The setter function.
     */
    inline constexpr property(
        std::function<T()>              getter,
        std::function<void (const T &)> setter
    ) : property_readonly<T>(getter), setter(setter) {}

    /**
     *  @brief  Assign value to the property.
     *
     *  @param  t  The value to assign.
     *  @return  Reference to the property after assignment.
     */
    inline constexpr auto operator= (const T &t) -> property &
    {
        setter(t);
        return *this;
    }

    /**
     *  @brief  Add other value to property and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after addition assignment.
     */
    inline constexpr auto operator+= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() + o);
        return *this;
    }

    /**
     *  @brief  Subtract other value from property and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after subtraction assignment.
     */
    inline constexpr auto operator-= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() - o);
        return *this;
    }

    /**
     *  @brief  Multiply property by other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after multiplication assignment.
     */
    inline constexpr auto operator*= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() * o);
        return *this;
    }

    /**
     *  @brief  Divide property by other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after division assignment.
     */
    inline constexpr auto operator/= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() / o);
        return *this;
    }

    /**
     *  @brief  Modulus of property by other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after modulus assignment.
     */
    inline constexpr auto operator%= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() % o);
        return *this;
    }

    /**
     *  @brief  Bitwise XOR of property with other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after XOR assignment.
     */
    inline constexpr auto operator^= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() ^ o);
        return *this;
    }

    /**
     *  @brief  Bitwise AND of property with other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after AND assignment.
     */
    inline constexpr auto operator&= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() & o);
        return *this;
    }

    /**
     *  @brief  Bitwise OR of property with other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after OR assignment.
     */
    inline constexpr auto operator|= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() | o);
        return *this;
    }

    /**
     *  @brief  Left shift property by other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after left shift assignment.
     */
    inline constexpr auto operator<<= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() <<= o);
        return *this;
    }

    /**
     *  @brief  Right shift property by other value and assign the result.
     *
     *  @param  o  The other value.
     *  @return  Reference to the property after right shift assignment.
     */
    inline constexpr auto operator>>= (const T &o) -> property &
    {
        setter(property_readonly<T>::getter() >>= o);
        return *this;
    }

    /**
     *  @brief  Pre-increment the property's value.
     *  @return  Reference to the property after increment.
     */
    [[nodiscard]] inline constexpr auto operator++ ()
    {
        T value = property_readonly<T>::getter();
        ++value;
        setter(value);
        return *this;
    }

    /**
     *  @brief  Post-increment the property's value.
     *  @return  Copy of the property's value before increment.
     */
    [[nodiscard]] inline constexpr auto operator++ (int)
    {
        T value = property_readonly<T>::getter();
        T copy  = value;
        value++;
        setter(value);
        return copy;
    }

    /**
     *  @brief  Pre-decrement the property's value.
     *  @return  Reference to the property after decrement.
     */
    [[nodiscard]] inline constexpr auto operator-- ()
    {
        T value = property_readonly<T>::getter();
        --value;
        setter(value);
        return *this;
    }

    /**
     *  @brief  Post-decrement the property's value.
     *  @return  Copy of the property's value before decrement.
     */
    [[nodiscard]] inline constexpr auto operator-- (int)
    {
        T value = property_readonly<T>::getter();
        T copy  = value;
        value--;
        setter(value);
        return copy;
    }
};

} // namespace plons
