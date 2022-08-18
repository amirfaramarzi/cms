#include "index.hpp"
#include "core/core.hpp"

//!Tegra
TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Framework;

TEGRA_NAMESPACE_BEGIN(Pages)

void Home::index(const Framework::HttpRequestPtr& req, std::function<void(const HttpResponsePtr &)>&& callback) const
{
    Scope<ApplicationData> appDataPtr(new ApplicationData());
    Scope<Multilangual::Language> languagePtr(new Multilangual::Language(appDataPtr->path.value()));
    appDataPtr->path    = req->getPath();
    appDataPtr->module  = "index";
    auto resp = HttpResponse::newHttpResponse();
    std::string message = "Hello, I am " + TEGRA_TRANSLATOR("global","name");
    resp->setBody(message);
    callback(resp);
}


TEGRA_NAMESPACE_END
