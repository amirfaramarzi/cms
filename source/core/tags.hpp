/*!
 * @file        tags.hpp
 * @brief       This file is part of the Tegra CMS.
 * @details     Tags structure for contents.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/cms/blob/main/LICENSE.md
 *
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
