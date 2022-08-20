/*!
 * @file        version.hpp
 * @brief       This file is part of the Tegra CMS.
 * @details     System version structure.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/cms/blob/main/LICENSE.md
 *
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
