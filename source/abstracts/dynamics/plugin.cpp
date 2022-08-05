#include "plugin.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra::Abstracts)

/*!
 * \brief Constructs an abstract plugin.
 */
AbstractPlugin::AbstractPlugin()
{
    __tegra_safe_instance(m_pluginInfo, PluginInfo);
}

/*!
 * \brief Destroys the plugin.
 */
AbstractPlugin::~AbstractPlugin()
{
    __tegra_safe_delete(m_pluginInfo);
}


TEGRA_NAMESPACE_END
