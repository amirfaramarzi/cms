#include "index.hpp"
#include "core/core.hpp"
#include "core/database.hpp"

//!Tegra
TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Tegra::Database;
TEGRA_USING_NAMESPACE Framework;

TEGRA_NAMESPACE_BEGIN(Pages)

void Home::index(const Framework::HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)>&& callback) const
{
    Scope<ApplicationData> appDataPtr(new ApplicationData());
    {
        appDataPtr->path    = req->getPath();
        appDataPtr->module  = "index";
    }
    Scope<Multilangual::Language> languagePtr(new Multilangual::Language(appDataPtr->path.value()));

    auto resp = HttpResponse::newHttpResponse();

    std::string message{TEGRA_RUNTIME_FORMAT(TEGRA_TRANSLATOR("global", "greeting"), TEGRA_TRANSLATOR("global", "name"))};

    resp->setBody(message);

    callback(resp);
}


TEGRA_NAMESPACE_END
