#include "pluginmanager.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract plugin manager.
 */
AbstractPluginManager::AbstractPluginManager()
{
    __tegra_safe_instance(m_pluginManagerData, PluginManagerData);
}

/*!
 * \brief Destroys the plugin manager.
 */
AbstractPluginManager::~AbstractPluginManager()
{
    __tegra_safe_delete(m_pluginManagerData);
}


TEGRA_NAMESPACE_END
