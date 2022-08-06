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

#ifndef API_ABSTRACT_HPP
#define API_ABSTRACT_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The API authentication process validates the identity of the client attempting to make a connection by using an authentication protocol.
 * And for this there are different methods that we cover.
 */
__tegra_enum_class AuthenticationType : u8
{
    NoAuth          =   0x0,  ///< No any authorization.
    ApiKey          =   0x1,  ///< Authentication based on ApiKey.
    BearerToken     =   0x2,  ///< Authentication based on BearerToken.
    BasicAuth       =   0x3,  ///< Authentication based on BasicAuth.
    DigestAuth      =   0x4,  ///< Authentication based on DigestAuth.
    OAuth1_0        =   0x5,  ///< Authentication based on OAuth1.0.
    OAuth2_0        =   0x6,  ///< Authentication based on OAuth2.0.
    Hawk            =   0x7,  ///< Authentication based on Hawk.
    AwsSignature    =   0x8,  ///< Authentication based on AWS Signature.
    Customized      =   0x9   ///< Authentication based on Customized method.
};

/*!
 * \brief The AbstractApi class
 */
class __tegra_export AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractApi)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
    __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractApi)
};

TEGRA_NAMESPACE_END

#endif  // API_ABSTRACT_HPP
