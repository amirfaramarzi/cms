#include "configuration.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

AbstractConfiguration::AbstractConfiguration()
{
    __tegra_safe_instance(m_abstractConfigMember, AbstractConfigMember);
}

AbstractConfiguration::~AbstractConfiguration()
{
    __tegra_safe_delete(m_abstractConfigMember);
}

TEGRA_NAMESPACE_END
