// Velodyne HDL Packet Decoder Values
// Iurii Ivanov (iurii@proviz.io), Proviz.io 2020
// shared library to decode a Velodyne packet

#ifndef PACKET_DECODER_GLOBAL_VARS_H_INCLUDED
#define PACKET_DECODER_GLOBAL_VARS_H_INCLUDED

#include "PacketDecoder.h"

namespace
{
double *cos_lookup_table_;
double *sin_lookup_table_;
HDLLaserCorrection laser_corrections_[HDL_MAX_NUM_LASERS];
}

#endif // PACKET_DECODER_GLOBAL_VARS_H_INCLUDED
