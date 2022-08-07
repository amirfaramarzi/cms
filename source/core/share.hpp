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

#ifndef SHARE_HPP
#define SHARE_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The ShareMethod enum
 */
__tegra_enum_class ShareMethod : u8
{
    InSelf,
    SocialNetwork,
    ByEmail,
    BySms,
    ForApi,
    Custom
};

struct ShareData final
{
    ShareMethod method  {};
    OptionalString link {};
};

/*!
 * \brief The AbstractTags class
 */
class __tegra_export Share
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Share)

    /*!
     * \brief registerToShare function will share post via share methods.
     * \param shareData is data for sharing.
     */
    void registerToShare(const ShareData& shareData) __tegra_const_noexcept;

private:
    TEGRA_DISABLE_COPY(Share)
    ShareData* m_shareData;
};

TEGRA_NAMESPACE_END

#endif  // SHARE_HPP
