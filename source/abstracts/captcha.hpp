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

#ifndef CAPTCHA_ABSTRACT_HPP
#define CAPTCHA_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The AbstractCaptcha class
 */
class __tegra_export AbstractCaptcha
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractCaptcha)


    /*!
     * \brief Get the HTML code of the captcha.
     * \returns as string output.
     */
    __tegra_constexpr_virtual OptionalString getCode() __tegra_const = __tegra_zero;

    /*!
     * \brief Checking if the user passed the captcha or not.
     * \returns as boolean.
     */
    __tegra_constexpr_virtual OptionalBool checkCode() __tegra_const = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractCaptcha)
};

TEGRA_NAMESPACE_END

#endif  // CAPTCHA_ABSTRACT_HPP
