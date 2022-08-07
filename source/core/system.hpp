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

#ifndef TEGRA_SYSTEM_HPP
#define TEGRA_SYSTEM_HPP

#include "common.hpp"

TEGRA_NAMESPACE_BEGIN(Tegra::CMS)

class SystemInfo;
/*!
 * \brief The SystemInfo class
 */
class SystemInfo {
public:
    SystemInfo();
    ~SystemInfo();

    /*!
     * \brief getHostName function gets local host name.
     * \returns string of host name.
     */
    static std::string getHostName();

    /*!
     * \brief getOsName function will gets os name.
     * \returns string of os name.
     */
    static std::string getOsName();

    /*!
     * \brief macAddressAsByteArray
     */
    static std::string macAddressAsByteArray(unsigned char MACData[]);
    /*!
     * \brief getMacAddress function gets Mac Address.
     * \returns string of Mac address.
     */
    static std::string getMacAddress();

    /*!
     * \brief getIpAddress function gets Ip Version 4 Address.
     * \returns as string of ip address.
     */
    static std::string getIpV4Address();

    /*!
     * \brief getIpV6Address function gets Ip Version 6 Address.
     * \returns as string of ip address.
     */
    static std::string getIpV6Address();

    /*!
     * \brief getMachineUniqueId function gets machine unique id.
     * \returns string of uniqueId
     */
    static std::string getMachineUniqueId();

    /*!
     * \brief getSerialNumber function gets setial number
     * \returns as string.
     */
    static std::string getSerialNumber();

    /*!
     * \brief getStorageDiskModel function gets storage disk model.
     * \returns as string.
     */
    static std::string getStorageDiskModel();

    /*!
     * \brief getStorageDiskSerialNumber function gets storage disk model.
     * \returns as string.
     */
    static std::string getStorageDiskSerialNumber();

    /*!
     * \brief getGpuModel function gets gpu type.
     * \returns as string of gpu type.
     */
    static std::string getGpuModel();

private:
    std::list<std::string> m_macAddressList{};

};


TEGRA_NAMESPACE_END

#endif // TEGRA_SYSTEM_HPP
