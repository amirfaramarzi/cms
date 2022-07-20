#ifndef PRESTRUCTURE_HPP
#define PRESTRUCTURE_HPP

#include "common.hpp"

TEGRA_USING_NAMESPACE Tegra::Types;

/*!
 * \brief The SystemStatus enum
 */
enum struct SystemStatus : u8
{
    Off             = 0x1, //The system is off.
    On              = 0x2, //The system is on.
    Suspened        = 0x3, //The system is on suspended mode.
    Ready           = 0x4, //The system is ready.
    Maintainance    = 0x5, //The system is under maintainance.
    Unknown         = 0x6  //It is not clear what state the system is in.
};

/*!
 * \brief The SystemType enum
 */
enum struct SystemType: u8
{
    Private      = 0x1,
    General      = 0x2,
    Commercial   = 0x3,
    Professional = 0x4,
    Premium      = 0x5,
    Default      = 0x6
};

/*!
 * \brief The SystemLicense enum
 */
enum struct SystemLicense: u8
{
    Free            = 0x1,
    Commercial      = 0x2
};

/*!
 * \brief The CompatibilityLevel struct
 */
struct CompatibilityLevel
{
    u8 NoneCompatibility;
    u8 SimpleCompatibility;
    u8 GreenCompatibility;
    u8 PerfectCompatibility;
};

/*!
 * \brief The SystemInfo struct
 */
struct SystemInfo
{
    std::string     name    {};
    std::string     model   {};
    SystemType      type    {};
    SystemLicense   license {};
};

#endif // PRESTRUCTURE_HPP
