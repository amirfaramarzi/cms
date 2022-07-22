/*!
 * MIT License
 *
 * Copyright (c) 2022 Kambiz Asadzadeh
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
 */

#ifndef TEGRA_DICTIONARY_HPP
#define TEGRA_DICTIONARY_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Translation)

using DicType       = MultiMap<std::string, Map<std::string, std::string>>;
using Alphabet      = VectorString;
using DicTypePair   = PairString;
using DictonaryType = MultiMap<std::string, DicTypePair>;

/*!
 * \brief The LanguageStruct struct
 */
struct LanguageStruct final
{
    std::string m_wordKey       {};         //Key
    std::string m_module        {};         //Module
    std::string m_defaultValue  {};         //Default Value
    std::string m_customValue   {};         //Custom Value
};

/*!
 * \brief The LanguageType enum
 */
enum class LanguageType : u8
{
    AUTO            =  0x0, //In this case, the system checks the language status automatically.
    SINGLE          =  0x1, //In this casem the system will sets all system interface based on single activated language.
    MULTILANGUAGE   =  0x2  //In this casem the system will sets all system interface based on multi-language for only activated language.
};

/*!
 * \brief The LanguageTemplate class
 */
class LanguageTemplate {
public:
    LanguageTemplate() = default;
    explicit LanguageTemplate(const LanguageStruct& rhs);
    ~LanguageTemplate();

    /*!
     * \brief wordKey function will gets key as string.
     * \returns string.
     */
    __tegra_no_discard std::string wordKey () __tegra_const_noexcept;

    /*!
     * \brief module function will gets module name as string.
     * \returns string.
     */
    __tegra_no_discard std::string module () __tegra_const_noexcept;

    /*!
     * \brief defaultValue function will gets default value if there is no any value in custom value.
     * \returns string.
     */
    __tegra_no_discard std::string defaultValue () __tegra_const_noexcept;

    /*!
     * \brief customValue function will gets custom value.
     * \returns string.
     */
    __tegra_no_discard std::string customValue () __tegra_const_noexcept;

private:
    LanguageStruct* m_languageStruct;
};

TEGRA_NAMESPACE_END

#endif // TEGRA_DICTIONARY_HPP
