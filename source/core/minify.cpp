#include "minify.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;

TEGRA_NAMESPACE_BEGIN(Tegra)

Minify::Minify()
{
    m_minifyStruct = new MinifyStruct();
}

Minify::~Minify()
{
    __tegra_safe_delete(m_minifyStruct);
}

TEGRA_NAMESPACE_END
