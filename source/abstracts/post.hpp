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

#ifndef POST_ABSTRACT_HPP
#define POST_ABSTRACT_HPP

#include "common.hpp"
#include "core/core.hpp"
#include "core/tags.hpp"
#include "core/share.hpp"
#include "core/message.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief The PostStatus enum
 */
__tegra_enum_class PostStatus : u8
{
    Publish,        ///< Viewable by everyone.
    Future,         ///< Scheduled to be published in a future date.
    Draft,          ///< Incomplete post viewable by anyone with proper user role.
    Pending,        ///< Awaiting a user with the publish capability.
    Private,        ///< Viewable only to Tegra users at Administrator level.
    Trash,          ///< Posts in the Trash are assigned the trash status.
    AutoDraft,      ///< Revisions that Tegra saves automatically while you are editing.
    Inherit,        ///< Used with a child post (such as Attachments and Revisions) to determine the actual status from the parent post.
    Custom          ///< As custom status.
};

/*!
 * \brief The PostShare class
 */
struct PostData final
{
    ///!BASIC
    OptionalNumeric id              {};    ///< Index of post.
    OptionalNumeric priority        {};    ///< Index of post position.
    OptionalString  title           {};    ///< Title (subject) of post.
    OptionalString  url             {};    ///< Url for post.
    Tags            tags            {};    ///< Tags list for post.
    OptionalString  text            {};    ///< Text (main content) for post.
    OptionalString  documentTitle   {};    ///< Document title (title of post).
    OptionalString  metaDescr       {};    ///< Meta description (more details) for post.
    ///!MEDIA
    CMS::MediaType  cover           {};    ///< Image or video for post.
    CMS::IconType   icon            {};    ///< Icon for post.
    ///!DATETIME
    OptionalString  createdDate     {};    ///< Created date time.
    OptionalString  publishTime     {};    ///< Publishing time.
    OptionalString  pinnedTime      {};    ///< Pinned time.
    OptionalString  lastModified    {};    ///< Last Modified date-time.
    ///!EXTRA
    OptionalBool    inclueInSitemap            {};  ///< If included in sitemap section.
    OptionalBool    canBeModeratedFromFrontend {};  ///< Can be moderated from frontend?!
    OptionalBool    accessByApi     {};  ///< Can be access from api output.
    OptionalString  theme           {};  ///< Post theme.
    OptionalString  link            {};  ///< Post link.
    PostStatus      postStatus      {};  ///< Post status.
    Share           shareAction     {};  ///< Share action.
    ShareData       shareData       {};  ///< Share data.
    Message         message         {};  ///< Messahe for post.
};

/*!
 * \brief The AbstractPost class
 */
class __tegra_export AbstractPost
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(AbstractPost)

    /*!
     * \brief publish function will create and publish post by PostStatus state.
     * \param specifies data from the PostData.
     * \returns boolean.
     */
    __tegra_no_discard_virtual OptionalBool publish(const PostData& postData) __tegra_const = __tegra_zero;

    /*!
     * \brief remove function will delete a post by own id.
     * \param id is unique index of post.
     * \returns true, if the post is removed successfully.
     */
    __tegra_no_discard_virtual OptionalBool remove(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief update function will edit a post by own id.
     * \param id is unique index of post.
     * \param postData are the post's data.
     * \returns true, if the post is updated successfully.
     */
    __tegra_no_discard_virtual OptionalBool update(const u32 id, const PostData& postData) __tegra_const = __tegra_zero;

    /*!
     * \brief copy function will copy a post.
     * \param id is unique index of post.
     * \returns true, if the post is copied successfully.
     */
    __tegra_no_discard_virtual OptionalBool copy(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief move function will move a post to sub post.
     * \param id is unique index of post.
     * \param toParentId is parent post id.
     * \returns true, if the post is moved successfully.
     */
    __tegra_no_discard_virtual OptionalBool move(const u32 id, const u32 toParentId) __tegra_const = __tegra_zero;

    /*!
     * \brief lock function will lock and set a post as uneditable from users.
     * \param id is unique index of post.
     * \returns true, if the post is locked successfully.
     */
    __tegra_no_discard_virtual OptionalBool lock(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief hide function will hide a post from users.
     * \param id is unique index of post.
     * \returns true, if the post is hidden successfully.
     */
    __tegra_no_discard_virtual OptionalBool hide(const u32 id) __tegra_const = __tegra_zero;

    /*!
     * \brief status function will change the post status.
     * \param status is a parameter based on PostStatus.
     * \returns true, if the post status changed successfully.
     */
    __tegra_no_discard_virtual OptionalBool status(const PostStatus status) __tegra_const = __tegra_zero;

    /*!
     * \brief addMessage function will add new message for the post.
     * \param message is a parameter based on MessageData.
     * \returns true, if the post message added successfully.
     */
    __tegra_no_discard_virtual OptionalBool addMessage(const MessageData& messageData) __tegra_const = __tegra_zero;


private:
    TEGRA_DISABLE_COPY(AbstractPost)
    PostData* m_postData{};
};

TEGRA_NAMESPACE_END

#endif  // POST_ABSTRACT_HPP
