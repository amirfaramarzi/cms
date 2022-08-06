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

#ifndef MESSAGE_HPP
#define MESSAGE_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

TEGRA_NAMESPACE_BEGIN(Tegra)

/*!
 * \brief The MessageStyle enum
 */
__tegra_enum_class MessageStyle : u8
{
    Default,
    Information,
    Warning,
    Critical,
    Success,
    Custom
};

struct MessageData final
{
    OptionalString  message {}; ///< Message to send.
    OptionalString  author  {}; ///< Author of message.
    OptionalNumeric postId  {}; ///< Post id for message.
    MessageStyle    style   {}; ///< Message style for post section.
};

/*!
 * \brief The AbstractTags class
 */
class __tegra_export Message
{
public:
    TEGRA_DEFAULT_INTERFACE_OCTORS(Message)

    /*!
     * \brief create function will insert the message for post.
     * \param messageData is messsage's data.
     * \returns as boolean.
     */
    bool create(const MessageData& messageData) __tegra_const_noexcept;

    /*!
     * \brief edit function will update the message of post.
     * \param id is unique number of post.
     * \param messageData is messsage's data.
     * \returns as boolean.
     */
    bool edit(const u32 id, const MessageData& messageData) __tegra_const_noexcept;

    /*!
     * \brief remove function will remove the message of post.
     * \param id is unique number of post.
     * \param messageData is messsage's data.
     * \returns as boolean.
     */
    bool remove(const u32 id, const MessageData& messageData) __tegra_const_noexcept;

private:
    TEGRA_DISABLE_COPY(Message)
    MessageData* m_messageData;
};

TEGRA_NAMESPACE_END

#endif  // MESSAGE_HPP
