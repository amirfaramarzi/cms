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

#ifndef BASIC_API_ABSTRACT_HPP
#define BASIC_API_ABSTRACT_HPP

#include "common.hpp"
#include "abstracts/api.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief The AuthorizationInfo class
 * The user’s username and password are combined with a colon.
 * The resulting string is base64 encoded.
 */
struct AuthorizationInfo __tegra_final
{
    OptionalString username;  ///< Username of user.
    OptionalString password;  ///< Password of user.
    OptionalString result;    ///< Result of encoded.
};

/*!
 * \brief HTTP Basic Authentication.
 * The simplest way to handle authentication is through the use of HTTP, where the username and password are sent alongside every API call.
 * You can use an HTTP header and encode the username and password. Note that does not mean.
 * If you end up using HTTP Basic Authentication, use it through HTTPS so the connection between the parties is encrypted.
 */
class __tegra_export AbstractBasicApi : protected AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractBasicApi)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
   __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractBasicApi)
};

TEGRA_NAMESPACE_END

#endif  // BASIC_API_ABSTRACT_HPP
