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

#ifndef TAGS_HPP
#define TAGS_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)


struct TagsData __tegra_final
{
    OptionalNumeric id     {};
    OptionalString  title  {};
};

using TagList = std::vector<TagsData>;

/*!
 * \brief The AbstractTags class
 */
class __tegra_export Tags
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Tags)

    /*!
     * \brief registerTag function will sets data in tag list.
     * \param tag is a type of tag.
     */
    void registerTag(const TagsData& tag) __tegra_const_noexcept;

    /*!
     * \brief getTags function will gets tag data.
     * \returns tags by detail.
     */
    __tegra_no_discard TagsData getTags() __tegra_const_noexcept;

    /*!
     * \brief getList function will gets all tags in list type.
     * \returns list of tags.
     */
    __tegra_no_discard TagList getList() __tegra_const_noexcept;

    /*!
     * \brief removeTag function will removes a tag.
     * \param tag as id as u32.
     * \returns as boolean.
     */
    __tegra_no_discard bool removeTag(const u32 id) __tegra_const_noexcept;

    /*!
     * \brief updateTag function will updates (edit) current tag by id or name.
     * \param id
     * \param tag
     * \returns boolean.
     */
    __tegra_no_discard bool updateTag(const u32 id, const TagsData& tag) __tegra_const_noexcept;

protected:
    /*!
     * \brief insertIntoDb function will inserts all data into database.
     * \param tag as Tags data.
     */
    __tegra_no_discard bool insertIntoDb(const TagsData& tag) __tegra_const_noexcept;

private:
    TEGRA_DISABLE_COPY(Tags)
    TagsData* m_tagsData;
    TagList* m_tagList;
};

TEGRA_NAMESPACE_END

#endif  // TAGS_HPP
