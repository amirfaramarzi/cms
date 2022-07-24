#include "setting.hpp"

TEGRA_USING_NAMESPACE Tegra;

TEGRA_NAMESPACE_BEGIN(Tegra)

AbstractSetting::AbstractSetting()
{
    __tegra_safe_instance(m_optionData, OptionData);
}

AbstractSetting::~AbstractSetting()
{
    __tegra_safe_delete(m_optionData);
}

TEGRA_NAMESPACE_END
