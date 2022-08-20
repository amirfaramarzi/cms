/*!
 * @file        index.hpp
 * @brief       This file is part of the Tegra CMS.
 * @details     Index page.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/cms/blob/main/LICENSE.md
 *
 */

#ifndef INDEX_HPP
#define INDEX_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;

TEGRA_NAMESPACE_BEGIN(Pages)

class Home : public Framework::HttpController<Home>
{
public:
    METHOD_LIST_BEGIN

    {
        ADD_METHOD_TO(Home::index, "", {Framework::Get});
        ADD_METHOD_TO(Home::index, "/", {Framework::Get});
        ADD_METHOD_VIA_REGEX(Home::index,  "/([a-z]*-[a-z]*)/", Framework::Get, Framework::Post);
        ADD_METHOD_VIA_REGEX(Home::index,  "/([a-z]*-[a-z]*)", Framework::Get, Framework::Post);
    }

    METHOD_LIST_END

    /*!
    * \brief index is the first page of web root.
    * \param req for Http request.
    * \param callback for Http response.
    */
    void index(const Framework::HttpRequestPtr& req, std::function<void(const Framework::HttpResponsePtr &)>&& callback) const;
};


TEGRA_NAMESPACE_END

#endif // INDEX_HPP
