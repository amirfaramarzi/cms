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

#ifndef VERSION_HPP
#define VERSION_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The Version class
 */
class __tegra_export Version
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Version)

    enum class ReleaseType : u8
    {
        PreAlpha,               ///< Pre-alpha refers to all activities performed during the software project before formal testing.
        Alpha,                  ///< The alpha phase of the release life cycle is the first phase of software testing (alpha is the first letter of the Greek alphabet, used as the number 1).
        Beta,                   ///< Beta, named after the second letter of the Greek alphabet, is the software development phase following alpha.
        ReleaseCandidate,       ///< A release candidate (RC), also known as "going silver", is a beta version with potential to be a stable product, which is ready to release unless significant bugs emerge.
        StableRelease           ///< Also called production release, the stable release is the last release candidate (RC) which has passed all verifications / tests. The remaining bugs are considered as acceptable.
    };

    /*!
     * \brief setVersion will sets value to version.
     * \param version is parameter as SemanticVersion.
     */
    void setVersion(const SemanticVersion& version, const ReleaseType releaseType);

    /*!
     * \brief getVersion will gets version data.
     * \returns SemanticVersion.
     */
    SemanticVersion getVersion() __tegra_noexcept;

    /*!
     * \brief getAsString will gets version data as string.
     * \returns string of version.
     */
    std::string getAsString() __tegra_const __tegra_noexcept;

private:
    SemanticVersion* m_SemanticVersion{};
    TEGRA_DISABLE_COPY(Version)
    TEGRA_DISABLE_MOVE(Version)
};

TEGRA_NAMESPACE_END

#endif  // VERSION_HPP
