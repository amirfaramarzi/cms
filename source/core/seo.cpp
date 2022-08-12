#include "common.hpp"
#include "core/core.hpp"
#include "core/seo.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::SEO)

using iterMap = std::map<std::string, std::string>::iterator;

MetaTag::MetaTag()
{
    m_metaStruct = new MetaStruct();
}

MetaTag::~MetaTag()
{
    __tegra_safe_delete(m_metaStruct);
}

std::vector<std::string> MetaTag::tags() const
{
    return m_metaStruct->tags;
}

void MetaTag::registerTags(const MetaType& type, const MapString& item)
{
    std::stringstream stream;
    switch (type) {
    case MetaType::Name:
        for(const auto& i : item) {
            stream << "<meta name=" << '"' << i.first << '"' << ' ' << "content=" << '"' << i.second << '"' << "/>" << __tegra_newline;
            m_metaStruct->tags.push_back(stream.str());
            stream.str("");
        }
        break;
    case MetaType::Property:
        for(const auto& i : item) {
            stream << "<meta property=" << '"' << i.first << '"' << ' ' << "content=" << '"' << i.second << '"' << "/>" << __tegra_newline;
            m_metaStruct->tags.push_back(stream.str());
            stream.str("");
        }
        break;
    case MetaType::Extra:
        for(const auto& i : item) {
            stream << "<meta " << i.first << "=" << '"' << i.second << '"' << "/>" << __tegra_newline;
            m_metaStruct->tags.push_back(stream.str());
            stream.str("");
        }
        break;
    }
}

StaticMeta::StaticMeta()
{
    m_staticStruct = new StaticStruct();
}

StaticMeta::StaticMeta(const Application& app)
{
    if(app.module().has_value()) {
        registerModule(app.module().value());
    } else {
        registerModule(__tegra_null_str);
    }
}

StaticMeta::~StaticMeta()
{
    __tegra_safe_delete(m_staticStruct);
}

std::vector<std::string> StaticMeta::metaData()
{
    return m_staticStruct->items;
}

void StaticMeta::setDefault(const std::string& lng)
{
  //ToDo...
}

void StaticMeta::setData(const MetaType& type, const MapString& data, const std::string& lng)
{
  //ToDo...
}

void StaticMeta::registerModule(const std::string& module)
{
    m_staticStruct->module = module;
}

std::string StaticMeta::module() const
{
    return m_staticStruct->module;
}

TEGRA_NAMESPACE_END
