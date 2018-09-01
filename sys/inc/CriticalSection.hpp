/**
 * @file       CriticalSection.hpp
 * @author     Pere Tuset-Peiro (peretuset@openmote.com)
 * @version    v0.1
 * @date       May, 2015
 * @brief
 *
 * @copyright  Copyright 2015, OpenMote Technologies, S.L.
 *             This file is licensed under the GNU General Public License v2.
 */

#ifndef CRITICAL_SECTION_HPP_
#define CRITICAL_SECTION_HPP_

#include <stdint.h>

typedef uint32_t lock_t;

class CriticalSection
{
public:
    CriticalSection(void);
    ~CriticalSection(void);
private:
    lock_t lock;
};

#endif /* CRITICAL_SECTION_HPP_ */
