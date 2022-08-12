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

#ifndef SEO_HPP
#define SEO_HPP

#include "common.hpp"
#include "core/core.hpp"

TEGRA_USING_NAMESPACE Tegra;
TEGRA_USING_NAMESPACE Tegra::CMS;
TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra::SEO)

/*!
 * \brief The MetaType enum
 */
enum MetaType : u8
{
  Name      = 0x1,  ///< This attribute is basically used to explain the name of the property.
  Property  = 0x2,  ///< This attribute is used to explain more properties if a tag.
  Extra     = 0x3   ///< This attribute is used to add other and extra.
};

/*!
 * \brief The MetaStruct class
 */
struct MetaStruct final
{
    MetaType type;
    std::vector<std::string> tags;
    std::map<std::string, std::string> items;
    std::string stream;
};

/*!
 * \brief The MetaTag class
 */
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
  void registerTags(const MetaType& type, const MapString& item);

private:
  MetaStruct* m_metaStruct;
};

/*!
 * \brief The StaticStruct class
 */
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
  StaticMeta(const Application& app);
  ~StaticMeta();

  /*!
   * \brief setDefault
   * \param lng
   */
  void setDefault(const std::string& lng);

  /*!
   * \brief metaData
   * \return
   */
  std::vector<std::string> metaData();

  /*!
   * \brief setData
   * \param type
   * \param data
   * \param lng
   */
  void setData(const MetaType& type, const MapString & data, const std::string& lng);

  /*!
   * \brief registerModule
   * \param module
   */
  void registerModule(const std::string& module);

  /*!
   * \brief module
   * \return
   */
  std::string module() const;

private:
  StaticStruct* m_staticStruct;
};

TEGRA_NAMESPACE_END

#endif // SEO_HPP
