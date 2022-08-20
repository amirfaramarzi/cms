/*!
 * @file        message.hpp
 * @brief       This file is part of the Tegra CMS.
 * @details     Message system.
 * @author      <a href='https://www.kambizasadzadeh.com'>Kambiz Asadzadeh</a>
 * @package     The Genyleap
 * @since       29 Aug 2022
 * @copyright   Copyright (c) 2022 The Genyleap. All rights reserved.
 * @license     https://github.com/genyleap/cms/blob/main/LICENSE.md
 *
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
