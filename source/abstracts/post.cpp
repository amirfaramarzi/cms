#include "post.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract page class.
 */
AbstractPost::AbstractPost()
{
    __tegra_safe_instance(m_postData, PostData);
}

/*!
 * \brief Destroys the page class.
 */
AbstractPost::~AbstractPost()
{
    __tegra_safe_delete(m_postData);
}


TEGRA_NAMESPACE_END
