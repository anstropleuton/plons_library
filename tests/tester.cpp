/**
 *  @file    tester.cpp
 *  @author  Anstro Pleuton (https://github.com/anstropleuton)
 *  @brief   Test all of Plons Library.
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

/**
 *  @brief  Define global variables for this translation unit.
 */
#define gvar
#include "tester.hpp"

#include <cstddef>

// /**
//  *  @brief  Test ' .
//  *  @return  Number of errors.
//  */
// [[nodiscard]] auto test_() -> std::size_t;

/**
 *  @brief  The biggie.
 *  @return  zero on success.
 */
auto main() -> int try
{
    test_suite suite = {};
    suite.pre_run    = [&](const test *test)
    {
        log_file.open(test->function_name + ".log");
        default_pre_runner('=', 5)(test);
    };
    suite.post_run = [&](const test *test, std::size_t errors)
    {
        default_post_runner('=', 5)(test, errors);
        log_file.close();
    };
    // suite.run_failed = default_run_failed_quitter();

    // test _test = {
    //     "Test ",
    //     "test_",
    //     test_
    // };

    // suite.tests.emplace_back(&_test);

    auto failed_tests = suite.run();
    log_file.open("tester.log");

    print_failed_tests(failed_tests);

    return get_failed_tests_errors(failed_tests);
}
catch (const std::exception &e)
{
    log_file.open("tester.log");
    std::println("Exception occurred during testing: {}", e.what());
    return 1;
}
catch (...)
{
    log_file.open("tester.log");
    std::println("Unknown exception occurred during testing");
    return 1;
}
