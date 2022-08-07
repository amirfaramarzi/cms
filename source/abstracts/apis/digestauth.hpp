/*!
 * MIT License
 *
 * Copyright (c) 2022 The Genyleap. All rights reserved.
 * Copyright (c) 2022 Kambiz Asadzadeh.
 *
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

#ifndef DIGEST_AUTH_ABSTRACT_HPP
#define DIGEST_AUTH_ABSTRACT_HPP

#include "common.hpp"
#include "abstracts/api.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts::Apis)

/*!
 * \brief The AuthorizationInfo class
 * The digest data for mixing.
 */
struct AuthorizationInfo __tegra_final
{
    OptionalString username;    ///< Username of user.
    OptionalString password;    ///< Password of user.
    OptionalString realm;       ///< A string describing a protected area.
    OptionalString nonce;       ///< A server-specified quoted string that the server can use to control the lifetime in which particular credentials will be considered valid.
    OptionalString algorithm;   ///< Algorithm used to produce the digest.
    OptionalString qop;         ///< Quoted string indicating the quality of protection supported by the server.
    OptionalString nonceCount;  ///< The nonce counter.
    OptionalString clientNonce; ///< The nonce value is opaque to the client.
    OptionalString opaque;      ///< A server-specified quoted string that should be returned unchanged in the Authorization.
    OptionalString result;      ///< Result of final mixed string.
};

/*!
 * \brief HTTP Digest Auth.
 * A Bearer Token is an opaque string, not intended to have any meaning to clients using it.
 */
class __tegra_export AbstractDigestAuth : protected AbstractApi
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractDigestAuth)

    /*!
     * \brief get function will gets output of access string.
     * \returns as final string.
     */
   __tegra_no_discard __tegra_virtual OptionalString get() __tegra_const_noexcept = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractDigestAuth)
};

TEGRA_NAMESPACE_END

#endif  // DIGEST_AUTH_ABSTRACT_HPP
