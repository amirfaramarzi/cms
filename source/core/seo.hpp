/*!
 * MIT License
 *
 * Copyright (c) 2022 Kambiz Asadzadeh
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

#ifndef SEO_HPP
#define SEO_HPP

#include <iostream>
#include <map>
#include <vector>
#include <cerrno>
#include <string>
#include <optional>
#include <filesystem>
#include <string>
#include <vector>
#include <map>

#include "common.hpp"

#include "utilities/types.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::SEO)

enum MetaType : u8
{
  Name      = 0x1,
  Property  = 0x2,
  Extra     = 0x3
};

struct MetaStruct final
{
    MetaType type;
    std::vector<std::string> tags;
    std::map<std::string, std::string> items;
    std::string stream;
};

class MetaTag
{
public:
  MetaTag();
  ~MetaTag();

  /*!
   * @brief tags will returns list of meta tags.
   * @returns list of array.
   */
  std::vector<std::string> tags() const;

  /*!
   * @brief registerTags will sets meta data into list.
   * @param type gets meta types as [Name, Property].
   * @param item gets meta data key and value.
   */
  void registerTags(const MetaType& type, const std::map<std::string, std::string>& item);

private:
  MetaStruct* m_metaStruct;
};

struct StaticStruct final
{
    std::vector<std::string> data;
    std::vector<std::string> items;
    std::string module;
};

class StaticMeta
{
public:
  StaticMeta();
  StaticMeta(const std::string& module);
  ~StaticMeta();

  void setDefault(const std::string& lng);

  std::vector<std::string> metaData();

  void setData(const MetaType& type, const std::map<std::string, std::string>& data, const std::string& lng);

  void registerModule(const std::string& module);

  std::string module() const;

private:
  StaticStruct* m_staticStruct;;
};

TEGRA_NAMESPACE_END

#endif // SEO_HPP
