/*!
 * MIT License
 *
 * Copyright (c) 2022 The Genyleap. All rights reserved.
 * Copyright (c) 2022 Kambiz Asadzadeh.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
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
