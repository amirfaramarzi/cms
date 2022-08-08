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

#ifndef URL_HPP
#define URL_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The UrlStructure class
 */
struct UrlStructure
{
    OptionalString scheme       {}; ///< The scheme tells web servers which protocol to use when it accesses a page on your website.
    OptionalString subdomain    {}; ///< A subdomain in a URL indicates which particular page of your website the web browser should serve up.
    OptionalString secondLevel  {}; ///< Your second-level domain (SLD) is the name of your website.
    OptionalString topLevel     {}; ///< The top-level domain (TLD) specifies what type of entity your organization registers as on the internet.
    OptionalString subdirectory {}; ///< A subdirectory — also known as a subfolder — helps people as well as web crawlers understand which particular section of a webpage they’re on.
};

/*!
 * \brief The LanguageUrl class
 */
struct LanguageUrl
{
    OptionalString uri {};  ///< Uri for language [https://localhost/{language-uri}=en-us, fa-ir]
};

/*!
 * \brief The Url class
 */
class __tegra_export Url
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Url)
    Url(const std::string& uri);
    /*!
     * \brief registerTag function will sets data in tag list.
     * \param urlStructure is a type of UrlStructure.
     */
    void registerUrl(const UrlStructure& urlStructure) __tegra_const_noexcept;

    /*!
     * \brief getAsStructure will gets url by seprated sections.
     * \returns url as UrlStructure.
     */
    UrlStructure getAsStructure() __tegra_const_noexcept;

    /*!
     * \brief getAsUrl function will gets url as full string.
     * \returns as string.
     */
    OptionalString getAsUrl() __tegra_const_noexcept;

    /*!
     * \brief setLanguageUri function will sets a string for language.
     * \param uri as string.
     */
    void setLanguageUri(const std::string& uri) __tegra_const_noexcept;

    /*!
     * \brief getLanguageUri function will gets language based on url.
     * \returns as string.
     */
    OptionalString getLanguageUri() __tegra_const_noexcept;

protected:
    LanguageUrl* m_languageUrl{};

private:
    TEGRA_DISABLE_COPY(Url)
    UrlStructure* m_urlStructure{};
};

TEGRA_NAMESPACE_END

#endif  // URL_HPP
