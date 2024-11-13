/**
 *  @author  Anstro Pleuton (https://github.com/anstropleuton)
 *  @brief   Detronade - Plons Mini Programming Language.
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
#include <exception>
#include <print>
#include <string>
#include <string_view>
#include <variant>
#include <vector>

#include "alce_library.hpp"
#include "plons_property.hpp"

/**
 *  @brief  All Plons Library's contents in this namespace.  Just do
 *          `using namespace plons` to make your life easier.
 */
namespace plons {

/**
 *  @brief  Detronade APIs.
 */
namespace dtn {

/**
 *  @brief  Represent a position in the source code.
 */
struct position {
    /**
     *  @brief  The beginning.
     */
    std::size_t begin;

    /**
     *  @brief  The length.
     */
    std::size_t length;

    /**
     *  @brief  The pointer (0..length).
     */
    std::size_t pointer;
};

/**
 *  @brief  Type or severity of message.
 */
enum class message_severity {
    /**
     *  @brief  Uninitialized.
     */
    unknown,
    /**
     *  @brief  A note message.
     */
    note,
    /**
     *  @brief  A warning message.
     */
    warning,
    /**
     *  @brief  An error message.
     */
    error
};

/**
 *  @brief  Convert @c message_severity to string.
 *
 *  @param  severity  The message severity.
 *  @return  String representing @c message_severity enumeration.
 */
[[nodiscard]] inline constexpr auto to_string(message_severity severity)
{
    using namespace std::string_literals;

    switch (severity)
    {
        case message_severity::unknown: return "unknown"s;
        case message_severity::note: return "note"s;
        case message_severity::warning: return "warning"s;
        case message_severity::error: return "error"s;
    }
    return ""s;
}

/**
 *  @brief  The information.
 */
struct message {

    /**
     *  @brief  The message (multi-line string).
     */
    std::string msg;

    /**
     *  @brief  The severity of the message.
     */
    message_severity severity;

    /**
     *  @brief  The position of the fault.
     */
    position pos;

    /**
     *  @brief  Get formatted message (multi-line) ready to be outputted.
     *
     *  @param  name  The name of the source code.
     *  @param  src   The source code.
     *  @return  Formatted message.
     */
    auto str(
        std::string_view name,
        std::string_view src
    ) -> std::string;
};

/**
 *  @brief  The type of token.
 */
enum class token_type {
    /**
     *  @brief  Numerical literal starts with 0-9 and can contain `.` or
     *          `'`.
     *
     *  Numerical literal starts with 0-9 and can contain `.` or `'`.
     *  There cannot be more than one `.`.
     *
     *  Numerical literals can be represented in 4 different types:
     *  - Decimal: `123`, `4.56`, etc.
     *  - Decimal (alternative): `0d123`, `0d4.56`, etc.
     *  - Binary: `0b101`, `0b110.011`, etc.
     *  - Octal: `0o174`, `0o23.5`, etc.
     *  - Hexadecimal: `0x14b`, `3d.7a`, etc.
     */
    numerical_literal,
    /**
     *  @brief  Single character enclosed in `'` (unless it is an escape
     *          sequence).
     *
     *  Single character enclosed in `'` (unless it is an escape sequence).
     *
     *  Escape sequences:
     *  - '\\': Escape `\`.
     *  - '\'': Escape `'`.
     *  - '\"': Escape `"`.
     *  - '\a': Bell (Ascii: 7).
     *  - '\b': Backspace (Ascii: 8).
     *  - '\e': Escape (Ascii: 27).
     *  - '\f': Form Feed (Ascii: 12).
     *  - '\n': New Line (Ascii: 10).
     *  - '\r': Carriage Return (Ascii: 13).
     *  - '\t': Horizontal Tab (Ascii: 9).
     *  - '\v': Vertical Tab (Ascii: 11).
     *
     *  Incorporating numbers in characters:
     *  - '\NNN': Decimal number.
     *  - '\dNNN': Alternative way for decimal number.
     *  - '\iNNN': Binary number.
     *  - '\oNNN': Octal number.
     *  - '\xNNN': Hexadecimal number.
     *
     *  Empty character: '\;'.  Represents nothing, has nothing, not even null
     *  character.  It's just, nothing.  Hence actually writing '\;' will result
     *  in a syntax error.  But doing 'a\;' results in 'a'.
     */
    char_literal,
    /**
     *  @brief  Multiple characters enclosed in `"`.
     */
    string_literal,
    /**
     *  @brief  Character or group of characters that are valid operators.
     *
     *  Valid operators are character or group of character that are any of
     *  `~`, `!`, `%`, `^`, `&`, `*`, `-`, `+`, `=`, `[`, `]`, `\`, `|`,
     *  `:`, `<`, `>`, `/` or `?`.
     */
    operator_,
    /**
     *  @brief  A single character that is of a valid punctuation.
     *
     *  Valid punctuation is a character that is any of `@`, `$`, `(`, `)`,
     *  `{`, `}`, `;`, `,` or `.`.
     */
    punctuation,
    /**
     *  @brief  A name of variable, function, structure, or even keywords.
     *
     *  Identifier must start with a-z, A-Z or _, and can have 0-9 in the
     *  continuation.
     */
    identifier
};

/**
 *  @brief  Convert @c token_type to string.
 *
 *  @param  type  The token type.
 *  @return  String representing @c token_type enumeration.
 */
[[nodiscard]] inline constexpr auto to_string(token_type type)
{
    using namespace std::string_literals;

    switch (type)
    {
    using enum token_type;
        case numerical_literal: return "numerical_literal"s;
        case char_literal: return "char_literal"s;
        case string_literal: return "string_literal"s;
        case operator_: return "operator_"s;
        case punctuation: return "punctuation"s;
        case identifier: return "identifier"s;
    }
    return ""s;
}

/**
 *  @brief  The smallest unit, besides a character.
 */
struct token {

    /**
     *  @brief  The type of token.
     */
    token_type type;

    /**
     *  @brief  The value of the token.
     */
    std::variant<std::monostate, float, std::string, char> value;
};

/**
 *  @brief  Contains every information regarding the source code.
 */
struct detronade {

    /**
     *  @brief  Name of the source code, which can be a filename.
     */
    std::string name;

    /**
     *  @brief  The entire source code.
     */
    std::string source_code;

    /**
     *  @brief  All the messages regarding the source code.
     */
    std::vector<message> messages;

    /**
     *  @brief  Parsed tokens.
     */
    std::vector<token> tokens;

    /**
     *  @brief  Number of lines in the source code.
     */
    std::size_t num_lines;

    /**
     *  @brief  This is set to true when the last compilation is successful.
     */
    bool compilation_successful;

    /**
     *  @brief  Default constructor.
     */
    inline constexpr detronade() = default;

    /**
     *  @brief  Creates the source from name and content.
     *
     *  @param  name         The name of the source, can be a filename.
     *  @param  source_code  The source code.
     */
    inline constexpr detronade(
        std::string_view name,
        std::string_view source_code
    ) : name(name), source_code(source_code) {}

    /**
     *  @brief  Creates the source from filename and reads contents.
     *  @param  filename  The filename for the source name.
     */
    inline constexpr detronade(std::string_view filename)
        : name(filename)
    {
        load_file(filename);
    }

    /**
     *  @brief  Loads file contents into @c source_code .
     *
     *  @param  filename  The file to load.
     *  @return  True if successfully loaded.
     *  @note  Does not set the source name to the filename.
     */
    inline constexpr auto load_file(
        std::string_view filename
    ) -> bool
    {
        try
        {
            source_code = alce::file::read_all(filename);
        }
        catch (const std::exception &e)
        {
            using namespace alce::aec;
            using namespace alce::aec_operators;
            auto msg      = message {
                .msg      = "Unable to open file " + (bold + white)(filename),
                .severity = message_severity::error
            };
            messages.emplace_back(msg);
            return false;
        }

        return true;
    }

    /**
     *  @brief  Tokenize the source.
     *  @return  Individual tokens of the source.
     */
    [[nodiscard]] auto tokenize() -> std::optional<std::vector<token>>;

    /**
     *  @brief  Compile the source code.
     */
    inline constexpr auto compile()
    {
        num_lines   = std::ranges::count(source_code, '\n') + 1;
        auto tokens = tokenize();
        if (!tokens.has_value())
        {
            return;
        }

        this->tokens = tokens.value();
    }

    inline constexpr auto print_messages()
    {
        for (auto &message : messages)
        {
            std::print("{}", message.str(name, source_code));
        }
    }
};

} // namespace dtn

} // namespace plons
