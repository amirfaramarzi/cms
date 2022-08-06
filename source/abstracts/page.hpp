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

#ifndef PAGE_ABSTRACT_HPP
#define PAGE_ABSTRACT_HPP

#include "common.hpp"
#include "core/core.hpp"
#include "core/tags.hpp"

TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The PageType enum
 */
__tegra_enum_class PageType : u8
{
    Default     =   0x0,    ///< Page as default.
    Static      =   0x1,    ///< Page as static mode.
    Dynamic     =   0x2,    ///< Page as dynamic mode.
    Custom      =   0x3     ///< Page as custom design.
};

/*!
 * \brief The PageStatus enum
 */
__tegra_enum_class PageStatus : u8
{
    Locked          =   0x0,
    Important       =   0x1,
    Special         =   0x2,
    Hidden          =   0x3
};

__tegra_enum_class PageThemeStyle : u8
{
    Default         =   0x0,
    AsPage          =   0x1,
    BySystemDesign  =   0x2,
    ByCustomDesign  =   0x3
};

/*!
 * \brief The PageProperties class
 */
struct PageProperties __tegra_final
{
    ///!BASIC
    OptionalNumeric id              {};    ///< Index of page.
    OptionalNumeric priority        {};    ///< Index of page position.
    OptionalString  title           {};    ///< Title (subject) of page.
    OptionalString  url             {};    ///< Url for page.
    Tags            tags            {};    ///< Tags list for page.
    OptionalString  text            {};    ///< Text (main content) for page.
    OptionalString  documentTitle   {};    ///< Document title (title of page).
    OptionalString  metaDescr       {};    ///< Meta description (more details) for page.
    ///!MEDIA
    MediaType  cover    {};    ///< Image or video for page.
    IconType   icon     {};    ///< Icon for page.
    ///!DATETIME
    OptionalString  createdDate  {};    ///< Created date time.
    OptionalString  publishTime  {};    ///< Publishing time.
    OptionalString  pinnedTime   {};    ///< Pinned time.
    OptionalString  lastModified {};    ///< Last Modified date-time.
    ///!EXTRA
    OptionalBool    inclueInSitemap            {};  ///< If included in sitemap section.
    OptionalBool    canBeModeratedFromFrontend {};  ///< Can be moderated from frontend?!
    OptionalBool    accessByApi {};  ///< Can be access from api output.
    OptionalString  theme       {};  ///< Page theme.
};

/*!
 * \brief The AbstractPage class
 */
class __tegra_export AbstractPage
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPage)

    /*!
     * \brief id will gets index number of page.
     * \returns as numeric.
     */
    __tegra_no_discard_virtual OptionalString id() __tegra_const = __tegra_zero;

    /*!
     * \brief priority will gets position number of page.
     * \returns as numeric.
     */
    __tegra_no_discard_virtual OptionalString priority() __tegra_const = __tegra_zero;

    /*!
     * \brief title will gets title of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString title() __tegra_const = __tegra_zero;

    /*!
     * \brief url will gets url of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString url() __tegra_const = __tegra_zero;

    /*!
     * \brief tags will gets inserted tags for page.
     * \returns as Tags class.
     */
    __tegra_no_discard_virtual Tags tags() __tegra_const = __tegra_zero;

    /*!
     * \brief text will gets content of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString text() __tegra_const = __tegra_zero;

    /*!
     * \brief documentTitle will gets document title of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString documentTitle() __tegra_const = __tegra_zero;

    /*!
     * \brief metaDescr will gets meta description of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString metaDescr() __tegra_const = __tegra_zero;

    /*!
     * \brief icon will gets icon of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString icon() __tegra_const = __tegra_zero;

    /*!
     * \brief publishTime will gets publish time of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString publishTime() __tegra_const = __tegra_zero;

    /*!
     * \brief pinnedTime will gets pinned time of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString pinnedTime() __tegra_const = __tegra_zero;

    /*!
     * \brief lastModified will gets last modified date and time of page.
     * \returns as string.
     */
    __tegra_no_discard_virtual OptionalString lastModified() __tegra_const = __tegra_zero;

    /*!
     * \brief inclueInSitemap will gets included status in map.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual OptionalBool inclueInSitemap() __tegra_const = __tegra_zero;

    /*!
     * \brief canBeModeratedFromFrontend will gets moderated to frontend.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual OptionalBool canBeModeratedFromFrontend() __tegra_const = __tegra_zero;

    /*!
     * \brief accessByApi will generates output as api strcuture.
     * \returns as boolean.
     */
    __tegra_no_discard_virtual OptionalBool accessByApi() __tegra_const = __tegra_zero;

    /*!
     * \brief create function will add a new page.
     * \param properties are the page information.
     * \returns true, if the page is created successfully.
     */
    __tegra_no_discard_virtual OptionalBool create(const PageProperties& properties) __tegra_const = __tegra_zero;

    /*!
     * \brief remove function will delete a page by own id.
     * \param id is unique index of page.
     * \returns true, if the page is removed successfully.
     */
    __tegra_no_discard_virtual OptionalBool remove(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief update function will edit a page by own id.
     * \param id is unique index of page.
     * \param properties are the page's data.
     * \returns true, if the page is updated successfully.
     */
    __tegra_no_discard_virtual OptionalBool update(const u32 id, const PageProperties& properties) __tegra_const = __tegra_zero;

    /*!
     * \brief move function will move a page to sub page.
     * \param id is unique index of page.
     * \param toParentId is parent page id.
     * \returns true, if the page is moved successfully.
     */
    __tegra_no_discard_virtual OptionalBool move(const u32 id, const u32 toParentId) __tegra_const = __tegra_zero;

    /*!
     * \brief lock function will lock and set a page as uneditable from users.
     * \param id is unique index of page.
     * \returns true, if the page is locked successfully.
     */
    __tegra_no_discard_virtual OptionalBool lock(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief hide function will hide a page from users.
     * \param id is unique index of page.
     * \returns true, if the page is hidden successfully.
     */
    __tegra_no_discard_virtual OptionalBool hide(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief status function will change the page status.
     * \param status is a parameter based on PageStatus.
     * \returns true, if the page status changed successfully.
     */
    __tegra_no_discard_virtual OptionalBool status(const PageStatus status) __tegra_const = __tegra_zero;

    /*!
     * \brief theme function will gets theme for page.
     * \param theme parameter as PageThemeStyle.
     * \returns output of theme.
     */
    __tegra_no_discard_virtual OptionalString theme(const PageThemeStyle theme) __tegra_const = __tegra_zero;

private:
    TEGRA_DISABLE_COPY(AbstractPage)
};

TEGRA_NAMESPACE_END

#endif  // PAGE_ABSTRACT_HPP
