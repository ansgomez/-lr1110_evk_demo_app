/**
 * @file      command_get_almanac_dates.h
 *
 * @brief     Definitions of the HCI command to get almanac dates class.
 *
 * Revised BSD License
 * Copyright Semtech Corporation 2020. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Semtech corporation nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL SEMTECH CORPORATION BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef __COMMAND_GET_ALMANAC_DATES_H__
#define __COMMAND_GET_ALMANAC_DATES_H__

#include "command_interface.h"
#include "hci.h"
#include "device_interface.h"
#include "lr1110_gnss_types.h"

class CommandGetAlmanacDates : public CommandInterface
{
   public:
    CommandGetAlmanacDates( DeviceInterface* device, Hci& hci );
    virtual ~CommandGetAlmanacDates( );

    virtual uint16_t       GetComCode( );
    virtual bool           ConfigureFromPayload( const uint8_t* buffer, const uint16_t buffer_size );
    virtual CommandEvent_t Execute( );

   protected:
    void GetAlmanacDateAndCrcForSatellites( const lr1110_gnss_satellite_id_t* satellites, const uint8_t n_satellites,
                                            uint16_t* dates );

   private:
    Hci*             hci;
    DeviceInterface* device;
};

#endif  // __COMMAND_GET_ALMANAC_DATES_H__
