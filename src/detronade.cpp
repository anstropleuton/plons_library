/**
 *  @author  Anstro Pleuton (https://github.com/anstropleuton)
 *  @brief   Implementations for non-inline functions from
 *           @c plons_detronade.hpp .
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

#include <cmath>
#include <format>
#include <optional>

#include "alce_string_manipulators.hpp"
#include "plons_detronade.hpp"

using namespace alce;
using namespace aec;
using namespace aec_operators;
using namespace sm_operators;
using namespace std::string_literals;
using namespace plons::dtn;

namespace stdr = std::ranges;

/**
 *  @brief  Get formatted message (multi-line) ready to be outputted.
 *
 *  @param  name  The name of the source code.
 *  @param  src   The source code.
 *  @return  Formatted message.
 */
auto message::str(
    std::string_view name,
    std::string_view src
) -> std::string
{
    // Severity highlighting
    std::pair<std::string, aec_t> sev;

    switch (severity)
    {
    using enum message_severity;
        case unknown: sev = { "unknown", bold + white }; break;
        case note: sev    = { "note", bold + cyan }; break;
        case warning: sev = { "warning", bold + magenta }; break;
        case error: sev   = { "error", bold + red }; break;
    }

    auto total_lines     = stdr::count(src, '\n') + 1;
    auto total_lines_str = std::to_string(total_lines);

    /*

My thought process

Multi-line

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |         v-----------|----- begin (28)
| 2 | rty rty rty rty rty |
|   |         ~~~~~~~~~~~ | -> underline begin
| 3 | uio uio uio uio uio |
|   | ~~~~~~~~~~~~~~~~~~~ | -> underline covering from begin to end
|   |          v----------|----- pointer (69... I did not plan this)
| 4 | asd asd asd asd asd |
|   | ~~~~~~~~~^~~~~~~~~~ | -> underline with pointer
| 5 | fgh fgh fgh fgh fgh |
|   | ~~~~~~~~~~~~~~~~~~~ | -> underline covering from begin to end
|   |            v--------|----- end (111)
| 6 | jkl jkl jkl jkl jkl |
|   | ~~~~~~~~~~~         | -> underline end
| 7 | zxc zxc zxc zxc zxc |
| 8 |                     | -> empty line
+---+---------------------+

End result:

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe |
| 2 | rty rty rty rty rty |
|   |         ~~~~~~~~~~~ |
| 3 | uio uio uio uio uio |
|   | ~~~~~~~~~~~~~~~~~~~ |
| 4 | asd asd asd asd asd |
|   | ~~~~~~~~~^~~~~~~~~~ |
| 5 | fgh fgh fgh fgh fgh |
|   | ~~~~~~~~~~~~~~~~~~~ |
| 6 | jkl jkl jkl jkl jkl |
|   | ~~~~~~~~~~~         |
| 7 | zxc zxc zxc zxc zxc |
| 8 |                     | -> empty line
+---+---------------------+

2 lines stretched

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |         v-----------|----- begin (28)
| 2 | rty rty rty rty rty |
|   |         ~~~~~~~~~~~ | -> underline begin
|   |  v------------------|----- pointer (41)
|   |            v--------|----- end (51)
| 3 | uio uio uio uio uio |
|   | ~^~~~~~~~~~         | -> underline end with pointer
| 4 | asd asd asd asd asd |
| 5 |                     | -> empty line
+---+---------------------+

End result:

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe |
| 2 | rty rty rty rty rty |
|   |         ~~~~~~~~~~~ |
| 3 | uio uio uio uio uio |
|   | ~^~~~~~~~~~         |
| 4 | asd asd asd asd asd |
| 5 |                     | -> empty line
+---+---------------------+

1 line stretched

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |     v---------------|----- begin (24)
|   |          v----------|----- pointer (29)
|   |                v----|----- end (35)
| 2 | rty rty rty rty rty |
|   |     ~~~~~^~~~~~     | -> underline begin and end with pointer
| 3 | uio uio uio uio uio |
| 4 |                     | -> empty line
+---+---------------------+

End result:

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe |
| 2 | rty rty rty rty rty |
|   |     ~~~~~^~~~~~     |
| 3 | uio uio uio uio uio |
| 4 |                     | -> empty line
+---+---------------------+

More specifics:

- Begin at 20:
+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   | v-------------------|----- begin
|   |        v------------|----- end
| 2 | rty rty rty rty rty |
|   | ~~~~~~~             |
| 3 |                     | -> empty line
+---+---------------------+

- Begin at 19: (overflow exception (special code to handle it))
+---+---------------------+
|   |                    v|----- begin
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |       v-------------|----- end
| 2 | rty rty rty rty rty |
|   | ~~~~~~              |
| 3 |                     | -> empty line
+---+---------------------+

- Begin at 25 and end at 39:
+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |      v--------------|----- begin
|   |                    v|----- end
| 2 | rty rty rty rty rty |
|   |      ~~~~~~~~~~~~~~ |
| 3 |                     | -> empty line
+---+---------------------+

- Begin at 25 and end at 40: (overflow exception again)
+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |      v--------------|----- begin
| 2 | rty rty rty rty rty |
|   |      ~~~~~~~~~~~~~~ |
|   | v-------------------|----- end
| 3 |                     | -> empty line
+---+---------------------+

Multi-line (again, so I can see and implement)

+---+---------------------+
| 1 | qwe qwe qwe qwe qwe | -> 20 characters per line (including endline)
|   |         v-----------|----- begin (28)
| 2 | rty rty rty rty rty |
|   |         ~~~~~~~~~~~ | -> underline begin
| 3 | uio uio uio uio uio |
|   | ~~~~~~~~~~~~~~~~~~~ | -> underline covering from begin to end
|   |          v----------|----- pointer (69... I did not plan this)
| 4 | asd asd asd asd asd |
|   | ~~~~~~~~~^~~~~~~~~~ | -> underline with pointer
| 5 | fgh fgh fgh fgh fgh |
|   | ~~~~~~~~~~~~~~~~~~~ | -> underline covering from begin to end
|   |            v--------|----- end (111)
| 6 | jkl jkl jkl jkl jkl |
|   | ~~~~~~~~~~~         | -> underline end
| 7 | zxc zxc zxc zxc zxc |
| 8 |                     | -> empty line
+---+---------------------+

    */

    // Helpers
    property<std::size_t> end {
        [&]()
        {
            return pos.begin + pos.length;
        },
        [&](std::size_t value)
        {
            pos.length = value - pos.begin;
        }
    };

    property<std::size_t> pointing_to {
        [&]()
        {
            return pos.begin + pos.pointer;
        },
        [&](std::size_t value)
        {
            pos.pointer = value - pos.begin;
        }
    };

    auto        lines        = sm::split(src, '\n');
    std::string msg_lines    = "";
    std::size_t index        = 0;
    std::size_t line_num     = 0;
    std::size_t msg_line_num = 0;
    std::size_t msg_col_num  = 0;
    for (auto &line : lines)
    {
        line_num++;
        auto line_num_str = std::to_string(line_num);

        // Look, naming is hard ok?
        auto i_begin   = std::string::npos;
        auto i_length  = 0;
        auto i_pointer = std::string::npos;

        // Determine beginning of the squiggle within this line
        if (index <= pos.begin && pos.begin < index + line.size() + 1)
        {
            i_begin      = pos.begin - index;
            msg_line_num = line_num;
            msg_col_num  = i_begin + 1;
        }
        else if (index > pos.begin)
        {
            i_begin = 0;
        }

        // Determine ending of the squiggle within this line
        if (index <= end && end < index + line.size() + 1)
        {
            i_length = end - index - i_begin;
        }
        else if (end > index + line.size() + 1)
        {
            i_length = line.size() + 1 - i_begin;
        }

        // Determine the pointer if it is in this line
        if (index <= pointing_to && pointing_to < index + line.size() + 1)
        {
            i_pointer = pointing_to - index - i_begin;
        }

        if (i_length != 0 && i_begin != std::string::npos)
        {
            // Add decorative line number display
            msg_lines += " "
                       + " "s * (total_lines_str.size() - line_num_str.size())
                       + line_num_str
                       + " |";

            auto msg_squiggles = " "
                               + "-"s * total_lines_str.size()
                               + " |";

            // Sub-line before the fault
            auto pre_line  = line.substr(0, i_begin);
            msg_lines     += pre_line;
            msg_squiggles += " "s * pre_line.size();

            if (i_pointer != std::string::npos)
            {
                // Sub-line before the pointer
                auto pre_point = line.substr(i_begin, i_pointer);
                msg_lines     += (bold + white)(pre_point);
                msg_squiggles += sev.second("~"s * pre_point.size());

                // The pointer
                auto point     = sm::to_string(line[i_begin + i_pointer]);
                msg_lines     += sev.second(point);
                msg_squiggles += sev.second("^");

                // Sub-line after the pointer
                if (i_begin + i_pointer + 1 < line.size() + 1)
                {
                    auto post_point = line.substr(i_begin + i_pointer + 1,
                        i_length - i_pointer - 1);
                    msg_lines     += (bold + white)(post_point);
                    msg_squiggles += sev.second("~"s * post_point.size());
                }
            }
            else
            {
                // The entire line as fault
                auto fault_line = line.substr(i_begin, i_length);
                msg_lines      += (bold + white)(fault_line);
                msg_squiggles  += sev.second("~"s * fault_line.size());

                // Special case: pointer is at newline or at EOF to indicate
                // unexpected newline or EOF
                if (index <= pointing_to
                 && pointing_to <= index + line.size() + 1)
                {
                    msg_squiggles += sev.second("^");
                }
            }

            // Sub-line after the fault
            if (i_begin + i_length < line.size() + 1)
            {
                auto post_line = line.substr(i_begin + i_length);
                msg_lines     += post_line;
            }

            msg_lines += "\n" + msg_squiggles + "\n";
        }
        index += line.size() + 1;
    }

    return std::format("{}{}:{}:{}{}: {}{}{}: {}\n{}",
        bold + white, name, msg_line_num, msg_col_num, !(bold + white),
        sev.second, sev.first, !sev.second, msg,
        msg_lines);
}

/**
 *  @brief  Convert the string to a real.
 *
 *  @param  messages        The list of messages to append to.
 *  @param  begin           The beginning of the string.
 *  @param  string          The string to convert to a real.
 *  @param  is_escape_code  Whether the string is from an escape code.
 *  @return  Real number converted from string.
 */
[[nodiscard]] static inline constexpr auto parse_number(
    std::vector<message> &messages,
    std::size_t           begin,
    std::string           string,
    bool                  is_escape_code = false
) -> std::optional<float>
{
    std::size_t start = 0;
    float       base  = 10;

    string = sm::to_lower(string);

    if (is_escape_code)
    {
        if (string.starts_with("\\d"))
        {
            start = 2;
        }
        else if (string.starts_with("\\i"))
        {
            base  = 2;
            start = 2;
        }
        else if (string.starts_with("\\o"))
        {
            base  = 8;
            start = 2;
        }
        else if (string.starts_with("\\x"))
        {
            base  = 16;
            start = 2;
        }
        else if (string.starts_with("\\"))
        {
            start = 1;
        }
    }
    else
    {
        if (string.starts_with("0d"))
        {
            start = 2;
        }
        else if (string.starts_with("0b"))
        {
            base  = 2;
            start = 2;
        }
        else if (string.starts_with("0o"))
        {
            base  = 8;
            start = 2;
        }
        else if (string.starts_with("0x"))
        {
            base  = 16;
            start = 2;
        }
    }

    std::string base_name;

    switch ((int)std::round(base))
    {
        case 2: base_name  = "binary"; break;
        case 8: base_name  = "octal"; break;
        case 10: base_name = "decimal"; break;
        case 16: base_name = "hexadecimal"; break;
        default: base_name = "unknown";
    }

    // Eliminate invalid digits
    std::string digits   = "0123456789abcdef"s.substr(0, base);
    std::string filtered = "";
    std::size_t point    = std::string::npos;

    for (std::size_t i = start; i < string.size(); i++)
    {
        auto pos = digits.find(string[i]);
        if (pos != std::string::npos)
        {
            filtered += string[i];
            continue;
        }

        if (!is_escape_code && string[i] == '.')
        {
            if (point == std::string::npos)
            {
                point = filtered.size();
                continue;
            }

            auto msg = std::format("Multiple decimal points in {}",
                is_escape_code
                ? base_name + " escape code"
                : base_name + " numerical literal");
            messages.emplace_back(message {
                .msg         = msg,
                .severity    = message_severity::error,
                .pos         = {
                    .begin   = begin,
                    .length  = string.length(),
                    .pointer = i
                }
            });
            return std::nullopt;
        }

        if (!is_escape_code && string[i] == '\'')
        {
            continue;
        }

        auto msg = std::format("Invalid character {}`{}`{} in {}",
            bold + white, string[i], !(bold + white),
            is_escape_code
            ? base_name + " escape code"
            : base_name + " numerical literal");
        messages.emplace_back(message {
            .msg         = msg,
            .severity    = message_severity::error,
            .pos         = {
                .begin   = begin,
                .length  = string.length(),
                .pointer = i
            }
        });
        return std::nullopt;
    }

    float result = 0;
    for (auto &c : filtered)
    {
        auto pos = digits.find(c);
        result  *= base;
        result  += pos;
    }

    if (!is_escape_code && point != std::string::npos)
    {
        auto exp = filtered.size() - point;
        result  /= std::pow<float>(base, exp);
    }

    return result;
}

/**
 *  @brief  Evaluate the escape code.
 *
 *  @param  messages   The list of messages to append to.
 *  @param  src        The boundless source code.
 *  @param  index      The current char in the source code that has `\`.
 *  @return  Character representing the escape code.
 */
[[nodiscard]] static inline constexpr auto parse_escape_code(
    std::vector<message>      &messages,
    cu::boundless_string_view &src,
    std::size_t               &index
) -> std::optional<std::variant<std::monostate, char>>
{
    std::size_t begin = index;
    index++;
    char c = src[index];
    index++;

    switch (c)
    {
        case '\\':
        case '\'':
        case '\"':
            return c;
        case ';':
            return std::monostate {};

        case 'a': return '\a';
        case 'b': return '\b';
        case 'e': return '\e';
        case 'f': return '\f';
        case 'n': return '\n';
        case 'r': return '\r';
        case 't': return '\t';
        case 'v': return '\v';
        default:
        {
            auto msg = std::format("Unexpected EOF");
            messages.emplace_back(message {
                .msg         = msg,
                .severity    = message_severity::error,
                .pos         = {
                    .begin   = begin,
                    .length  = index - begin + 1,
                    .pointer = index - begin
                }
            });
            return std::nullopt;
        }
    }

    int base = 0;

    switch (c)
    {
        case 'd':
        case '0' ... '9':
            base = 10;
            break;

        case 'i': base = 2; break;
        case 'o': base = 8; break;
        case 'x': base = 16; break;
    }

    if (base == 0)
    {
        auto msg = std::format("Invalid character {}`{}`{} in escape code",
            bold + white, src[index], !(bold + white));
        messages.emplace_back(message {
            .msg         = msg,
            .severity    = message_severity::error,
            .pos         = {
                .begin   = begin,
                .length  = index - begin + 1,
                .pointer = index - begin
            }
        });
        return std::nullopt;
    }

    std::string digits = "0123456789abcdef"s.substr(0, base);
    while (digits.contains(std::tolower(src[index])))
    {
        index++;
    }

    auto result = parse_number(messages, begin,
        std::string(src.substr(begin, index - begin)), true);

    if (!result.has_value())
    {
        return std::nullopt;
    }

    auto value = result.value();
    if (value > 255)
    {
        auto msg = std::format("Number {}`{}`{} too large for character",
            bold + white, value, !(bold + white));
        messages.emplace_back(message {
            .msg         = msg,
            .severity    = message_severity::warning,
            .pos         = {
                .begin   = begin,
                .length  = index - begin,
                .pointer = 0
            }
        });
    }

    return (char)value;
}

/**
 *  @brief  Parse string literal.
 *
 *  @param  messages   The list of messages to append to.
 *  @param  src        The boundless source code.
 *  @param  index      The current char (enclosing char) in the source code.
 *  @param  encloser   The character that encloses a string.
 *  @return constexpr auto
 */
[[nodiscard]] static inline constexpr auto parse_string(
    std::vector<message>      &messages,
    cu::boundless_string_view &src,
    std::size_t               &index,
    char                       encloser
) -> std::optional<std::string>
{
    std::size_t begin = index;
    std::string value = "";
    index++;

    while (src[index] != encloser)
    {
        if (src[index] == '\0')
        {
            auto msg = std::format("Unexpected EOF");
            messages.emplace_back(message {
                .msg         = msg,
                .severity    = message_severity::error,
                .pos         = {
                    .begin   = begin,
                    .length  = index - begin + 1,
                    .pointer = index - begin
                }
            });
            return std::nullopt;
        }

        if (src[index] == '\\')
        {
            auto escape_code = parse_escape_code(messages, src, index);
            if (!escape_code.has_value())
            {
                return std::nullopt;
            }

            // No character
            if (std::holds_alternative<std::monostate>(
                escape_code.value()))
            {
                continue;
            }
            value += std::get<char>(escape_code.value());
        }
        else
        {
            value += src[index];
            index++;
        }
    }
    index++;

    return value;
}

/**
 *  @brief  Tokenize the source code.
 *  @return  Individual tokens of the source code.
 */
[[nodiscard]] auto detronade::tokenize()
-> std::optional<std::vector<token>>
{
    std::vector<token>        tokens = {};
    cu::boundless_string_view src    = std::string_view(source_code);

    const std::string whitespaces  = " \t\n\r\f\v";
    const std::string operators    = "~!%^&*-+=[]\\|:<>/?";
    const std::string punctuations = "@$(){};,.";

    // Is this inefficient?  Yes.  Does it matter?  No
    const std::string id_start
        = "abcdefghijklmnopqrstuvwxyz_ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    const std::string num_start    = "0123456789";
    const std::string id_continue  = id_start + num_start;
    const std::string num_continue = num_start + id_continue + ".'";

    // Do not need to worry about out of bounds in boundless sv!
    std::size_t index = 0;
    while (src[index] != '\0')
    {
        if (whitespaces.contains(src[index]))
        {
            while (whitespaces.contains(src[index]))
            {
                index++;
            }
        }
        // Skip comment
        else if (src[index] == '#')
        {
            do
            {
                index++;
            }
            while (src[index] != '\n' && src[index] != '\0');
            index++;
        }
        else if (src[index] == '\'')
        {
            std::size_t begin  = index;
            auto        string = parse_string(messages, src, index, '\'');
            if (!string.has_value())
            {
                return std::nullopt;
            }

            if (string.value().size() > 1)
            {
                auto msg = std::format("Too many characters in char literal");
                messages.emplace_back(message {
                    .msg         = msg,
                    .severity    = message_severity::error,
                    .pos         = {
                        .begin   = begin,
                        .length  = index,
                        .pointer = 2
                    }
                });
                return std::nullopt;
            }

            if (string.value().size() < 1)
            {
                auto msg = std::format("Char literal cannot be empty");
                messages.emplace_back(message {
                    .msg         = msg,
                    .severity    = message_severity::error,
                    .pos         = {
                        .begin   = begin,
                        .length  = 2,
                        .pointer = 1
                    }
                });
                return std::nullopt;
            }

            tokens.emplace_back(token {
                .type  = token_type::char_literal,
                .value = string.value().front()
            });
        }
        else if (src[index] == '\"')
        {
            auto string = parse_string(messages, src, index, '\"');
            if (!string.has_value())
            {
                return std::nullopt;
            }

            tokens.emplace_back(token {
                .type  = token_type::string_literal,
                .value = string.value()
            });
        }
        else if (num_start.contains(src[index]))
        {
            std::size_t begin = index;
            index++;

            while (num_continue.contains(src[index]))
            {
                index++;
            }

            auto parsed_num = parse_number(messages, begin,
                std::string(src.substr(begin, index - begin)));
            if (!parsed_num.has_value())
            {
                return std::nullopt;
            }

            tokens.emplace_back(token {
                .type  = token_type::numerical_literal,
                .value = parsed_num.value()
            });
        }
        else if (id_start.contains(src[index]))
        {
            std::size_t begin = index;
            index++;

            while (id_continue.contains(src[index]))
            {
                index++;
            }

            tokens.emplace_back(token {
                .type  = token_type::identifier,
                .value = std::string(src.substr(begin, index - begin))
            });
        }
        else if (operators.contains(src[index]))
        {
            std::size_t begin = index;
            index++;

            while (operators.contains(src[index]))
            {
                index++;
            }

            tokens.emplace_back(token {
                .type  = token_type::operator_,
                .value = std::string(src.substr(begin, index - begin))
            });
        }
        else if (punctuations.contains(src[index]))
        {
            while (punctuations.contains(src[index]))
            {
                tokens.emplace_back(token {
                    .type  = token_type::punctuation,
                    .value = src[index]
                });
                index++;
            }
        }
        else
        {
            auto msg = std::format("Invalid character {}`{}`{} in source code",
                bold + white, src[index], !(bold + white));
            messages.emplace_back(message {
                .msg         = msg,
                .severity    = message_severity::error,
                .pos         = {
                    .begin   = index,
                    .length  = 1,
                    .pointer = 0
                }
            });
            return std::nullopt;
        }
    }

    return tokens;
}
