#include "tags.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief Constructs an abstract tags class.
 */
Tags::Tags()
{
    __tegra_safe_instance(m_TagsData, TagsData);
    __tegra_safe_instance(m_TagList, TagList);
}

/*!
 * \brief Destroys the tags class.
 */
Tags::~Tags()
{
    __tegra_safe_delete(m_TagsData);
    __tegra_safe_delete(m_TagList);
}

void Tags::registerTag(const TagsData& tag) __tegra_const_noexcept
{
    {
        m_TagsData->id = tag.id;
        m_TagsData->title = tag.title;
    }
    //For tag list
    if(insertIntoDb(tag))
        m_TagList->push_back(tag);
    ///ToDo...
}

TagsData Tags::getTags() __tegra_const_noexcept
{
    return *m_TagsData;
}

TagList Tags::getList() __tegra_const_noexcept
{
    return *m_TagList;
}

bool Tags::removeTag(const u32 id) __tegra_const_noexcept
{
    ///ToDo...
    return false;
}

bool Tags::updateTag(const u32 id, const TagsData &tag) __tegra_const_noexcept
{
    ///ToDo...
    return false;
}

bool Tags::insertIntoDb(const TagsData& tag) __tegra_const_noexcept
{
    ///ToDo...
    return true;
}

TEGRA_NAMESPACE_END
