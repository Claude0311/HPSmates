#include "network_data.h"

ai_handle ai_network_data_weights_get(void)
{

  AI_ALIGNED(4)
  static const ai_u8 s_network_weights[ 2516 ] = {
    0x55, 0xc1, 0xdd, 0xc0, 0x42, 0x6f, 0x45, 0xbf, 0x3d, 0xc7,
    0x5f, 0x40, 0xba, 0x47, 0xf8, 0x3f, 0x94, 0x63, 0x15, 0xc0,
    0x9a, 0x68, 0xdd, 0x3e, 0x79, 0x95, 0x51, 0x40, 0x4e, 0x8f,
    0x1d, 0x40, 0xaf, 0xf1, 0xdc, 0x3f, 0xc7, 0x2a, 0x64, 0x40,
    0xda, 0x13, 0xfb, 0xc0, 0xec, 0x07, 0x64, 0xbf, 0x11, 0xc7,
    0x75, 0x3c, 0x35, 0xec, 0x92, 0xbf, 0x14, 0x48, 0x0a, 0xc0,
    0x6d, 0xa5, 0x62, 0x40, 0x60, 0x2d, 0x63, 0xbf, 0x4f, 0x19,
    0x0a, 0xbf, 0x81, 0x92, 0x41, 0xc0, 0xaf, 0xfd, 0xb1, 0xbe,
    0x39, 0x78, 0xb3, 0x40, 0xaf, 0x95, 0xeb, 0xbf, 0xdb, 0x05,
    0x0c, 0x40, 0xa0, 0x9a, 0x95, 0xc0, 0xdd, 0x15, 0x1d, 0xc1,
    0x48, 0xcf, 0x61, 0x3f, 0x26, 0x30, 0x83, 0x40, 0xc7, 0x3f,
    0xf3, 0x3f, 0x69, 0x94, 0x35, 0x40, 0x80, 0xdc, 0x0e, 0x41,
    0x33, 0x7c, 0x22, 0xc1, 0x11, 0x00, 0x62, 0xc0, 0xc3, 0x15,
    0x88, 0x40, 0x77, 0xca, 0x6a, 0x3f, 0x90, 0xe1, 0xae, 0xc0,
    0x08, 0x95, 0x75, 0x3f, 0x04, 0x86, 0x81, 0x40, 0x1f, 0xd9,
    0x8c, 0x40, 0xfd, 0xc0, 0x5f, 0x40, 0x6c, 0xee, 0xb1, 0xc0,
    0x4b, 0x65, 0x94, 0xbe, 0x8e, 0xc2, 0xa6, 0x3e, 0x84, 0x07,
    0x54, 0xbe, 0x91, 0x1a, 0x6c, 0x3e, 0x2c, 0x91, 0x5e, 0x3f,
    0x1f, 0x4d, 0x3f, 0xbe, 0x9f, 0x76, 0x24, 0xbe, 0x10, 0xd3,
    0x02, 0x3e, 0x34, 0x42, 0xa6, 0x3e, 0x1a, 0x05, 0x07, 0xbf,
    0x3d, 0x08, 0x06, 0x3f, 0xca, 0x8c, 0x9c, 0x3f, 0x03, 0x08,
    0x1f, 0x3e, 0x31, 0xea, 0x2f, 0xbf, 0x70, 0x6f, 0x23, 0x3f,
    0xaa, 0x68, 0x04, 0xbf, 0x29, 0x5e, 0x3f, 0x3f, 0xf7, 0x5f,
    0xd4, 0xbd, 0x07, 0xde, 0x28, 0xbe, 0x04, 0x27, 0xb5, 0xbe,
    0xae, 0x03, 0xf9, 0x3e, 0xac, 0xc2, 0x54, 0xbe, 0xd8, 0x09,
    0xa3, 0x3e, 0x9f, 0x2e, 0xbc, 0xbf, 0x58, 0x1f, 0x05, 0x3f,
    0x32, 0x45, 0x88, 0xbf, 0xad, 0x51, 0x6c, 0xbe, 0xbc, 0x92,
    0x37, 0xbf, 0x4c, 0xda, 0xd1, 0xbe, 0xaa, 0x00, 0x23, 0x3e,
    0xfc, 0x74, 0xf8, 0xbe, 0xc1, 0xc7, 0x08, 0x3f, 0x23, 0x1c,
    0x06, 0x40, 0xff, 0x72, 0x08, 0x40, 0xa0, 0x5e, 0x75, 0x3f,
    0x3e, 0xbe, 0xea, 0xbf, 0x58, 0xcf, 0xc9, 0x3f, 0x25, 0x8b,
    0xae, 0x3f, 0xc9, 0xfc, 0xac, 0x3f, 0x31, 0x07, 0xa2, 0x3e,
    0xd4, 0xca, 0x8e, 0xc0, 0x08, 0x3c, 0xe0, 0xbf, 0xc5, 0xeb,
    0x2b, 0xc0, 0x33, 0x7c, 0xaa, 0x3f, 0xdd, 0xc4, 0x79, 0x3f,
    0x21, 0x9c, 0x60, 0x3f, 0x40, 0xbb, 0x46, 0xc0, 0x5d, 0xf2,
    0x45, 0xbf, 0x8b, 0x4c, 0x0f, 0xbf, 0x6f, 0x2a, 0x8d, 0x3f,
    0x97, 0xb4, 0x1b, 0x3f, 0x6b, 0xb6, 0xa9, 0x3f, 0x42, 0x84,
    0x9a, 0xbf, 0xe8, 0x6f, 0xa9, 0x3f, 0xf0, 0xed, 0x1e, 0xbf,
    0xd3, 0x13, 0x9c, 0xbf, 0xe8, 0xf8, 0xc4, 0xbf, 0xeb, 0x52,
    0xb0, 0xbf, 0xc8, 0xea, 0xfe, 0xbe, 0x42, 0x67, 0x51, 0x3f,
    0x82, 0x2c, 0x74, 0xbf, 0xb3, 0xd0, 0x62, 0xbf, 0xb9, 0x56,
    0x18, 0xbe, 0x9a, 0xca, 0x8d, 0xbf, 0xe0, 0xd0, 0xf6, 0x3f,
    0x7d, 0x0e, 0xaf, 0x3d, 0x0c, 0x91, 0x9c, 0x3f, 0xe8, 0xc6,
    0x16, 0xbe, 0x8f, 0x8f, 0x4a, 0xbe, 0xde, 0x4f, 0xae, 0xbf,
    0x1f, 0xf0, 0x29, 0x3f, 0x88, 0xf0, 0xba, 0x3f, 0xc0, 0x59,
    0x2a, 0xbd, 0x0f, 0x44, 0x74, 0xbf, 0xc9, 0x3c, 0x2e, 0x3f,
    0x39, 0xa8, 0xfd, 0xbe, 0x0a, 0xd3, 0x8d, 0x3e, 0x6f, 0xa4,
    0x53, 0xbe, 0xb1, 0x79, 0x0e, 0x3d, 0x45, 0x0e, 0x8d, 0x3e,
    0xa9, 0x12, 0x6b, 0x3d, 0x1b, 0x0f, 0x74, 0x3f, 0xc5, 0x56,
    0x2d, 0xbf, 0x52, 0xb8, 0x7e, 0xbf, 0xd0, 0x35, 0xf3, 0xbc,
    0x7d, 0x41, 0x72, 0xbe, 0xb7, 0x79, 0x94, 0xbe, 0x69, 0x1a,
    0x97, 0xbf, 0x44, 0xf7, 0x0b, 0xbf, 0xf1, 0xee, 0x37, 0x3e,
    0xa7, 0xf3, 0xa6, 0xc0, 0x27, 0xf3, 0x4f, 0xc0, 0x1c, 0x1f,
    0xa9, 0xbf, 0xe9, 0x3e, 0x10, 0x40, 0x7a, 0x4a, 0x31, 0x3e,
    0x0e, 0x85, 0x1d, 0x40, 0xa2, 0x95, 0x1f, 0xc0, 0x0b, 0xb6,
    0x1b, 0x3f, 0xd0, 0x54, 0x79, 0x3f, 0x0a, 0x0f, 0x1f, 0x3f,
    0x5c, 0xec, 0xb3, 0xbe, 0x96, 0x6a, 0x88, 0x3e, 0x82, 0x40,
    0x04, 0x3e, 0x45, 0x2e, 0x4c, 0xbe, 0xe7, 0x2e, 0xa4, 0x3f,
    0x1e, 0x85, 0x84, 0xbe, 0xb7, 0x56, 0x70, 0xbe, 0x70, 0xe2,
    0x3f, 0x3f, 0x2f, 0xd5, 0x2b, 0x3f, 0x2d, 0xad, 0x9c, 0xbf,
    0x07, 0x84, 0x5b, 0xbd, 0x90, 0xaa, 0x46, 0x3f, 0x20, 0x5b,
    0xd7, 0x3e, 0x21, 0x58, 0xe9, 0xbd, 0xc6, 0xe5, 0xec, 0x3e,
    0x91, 0xee, 0xd0, 0x3e, 0x63, 0x43, 0x85, 0x3f, 0x68, 0xdd,
    0x7b, 0xbe, 0x91, 0xc3, 0x8d, 0xbe, 0xb2, 0x21, 0xd6, 0xbe,
    0x0f, 0x00, 0xff, 0x3f, 0xa4, 0xfe, 0xc7, 0x3f, 0x71, 0xe6,
    0x07, 0x3f, 0xe9, 0x34, 0x99, 0x3e, 0x54, 0x81, 0x9f, 0xbf,
    0x54, 0x27, 0x21, 0xbf, 0xd8, 0xf7, 0xe4, 0x3e, 0x46, 0x13,
    0x0b, 0x3e, 0xe6, 0x1d, 0x7b, 0x3e, 0xe6, 0x01, 0x8d, 0x3f,
    0xf8, 0x80, 0xab, 0x3f, 0xc6, 0xc4, 0x38, 0x3f, 0xad, 0x3d,
    0x34, 0xbf, 0xe3, 0x71, 0xdd, 0xbf, 0xe5, 0xc9, 0x43, 0xc0,
    0xb6, 0xea, 0x20, 0xbf, 0xd4, 0x5e, 0x2f, 0xbe, 0xd3, 0xb2,
    0x9a, 0xbf, 0xf8, 0xf1, 0xd4, 0xbf, 0x70, 0xba, 0x10, 0x40,
    0x8c, 0x43, 0x95, 0x3f, 0x28, 0x79, 0xab, 0x3d, 0x01, 0x58,
    0x14, 0xbf, 0x49, 0x19, 0x22, 0xbf, 0xf2, 0x51, 0x84, 0xbe,
    0x1f, 0x12, 0x6e, 0x3b, 0x1d, 0xea, 0x88, 0x3f, 0x98, 0xe6,
    0x1d, 0xbf, 0x66, 0xb9, 0x80, 0xbf, 0xd5, 0x22, 0x0e, 0xbf,
    0x24, 0xb9, 0x84, 0xbf, 0xbd, 0xa2, 0x4e, 0x3d, 0x19, 0x75,
    0xbc, 0xbd, 0xdb, 0xc4, 0x0a, 0x3f, 0x02, 0x75, 0x19, 0xbf,
    0x44, 0x39, 0x47, 0x3f, 0xc5, 0x5d, 0x2b, 0x3f, 0xed, 0xbb,
    0x08, 0xbd, 0x7e, 0x72, 0xf7, 0xbe, 0x60, 0x3c, 0x97, 0x3f,
    0xc5, 0x19, 0xed, 0x3e, 0x05, 0x28, 0xa1, 0x3f, 0x85, 0xf9,
    0xbc, 0x3e, 0x87, 0x01, 0x9a, 0xbd, 0x1f, 0x42, 0x16, 0xc0,
    0xeb, 0xbb, 0x07, 0xbe, 0x45, 0x3c, 0x8c, 0x3f, 0x29, 0xe4,
    0xe8, 0x3d, 0x15, 0x52, 0x86, 0xbe, 0x2c, 0x07, 0x06, 0x40,
    0xf6, 0x19, 0xac, 0x3f, 0x36, 0x5f, 0x10, 0x40, 0x14, 0x06,
    0x85, 0xbf, 0x8f, 0x62, 0x75, 0x3f, 0x03, 0x8e, 0x61, 0xbf,
    0x61, 0x84, 0xca, 0xbe, 0xf9, 0xa2, 0x5b, 0xbf, 0x3e, 0x75,
    0xd8, 0xbf, 0xfe, 0xac, 0x9c, 0xbf, 0x83, 0x6c, 0x84, 0x3f,
    0x50, 0xa3, 0xf7, 0x3e, 0xe7, 0x9d, 0x10, 0x40, 0x5f, 0x96,
    0x92, 0xbf, 0xda, 0xf8, 0xcf, 0xbe, 0xee, 0x06, 0xa9, 0xbd,
    0xef, 0xc9, 0xcb, 0x3d, 0x77, 0xf5, 0x2d, 0xbf, 0x2d, 0x99,
    0x1d, 0xbf, 0xe5, 0x71, 0x05, 0xbf, 0x8a, 0x7c, 0x0c, 0x3f,
    0xd4, 0x9f, 0xc7, 0x3f, 0x4f, 0x3f, 0x8b, 0xbf, 0x0c, 0x13,
    0xc5, 0xbc, 0xcc, 0xee, 0x40, 0xbf, 0x62, 0x56, 0xe1, 0xbe,
    0xfe, 0x77, 0xf5, 0xbf, 0xbc, 0xb3, 0x4f, 0x3f, 0x9d, 0xf7,
    0xa6, 0xbf, 0x4e, 0x45, 0x81, 0xbd, 0x3e, 0x8f, 0x7c, 0x3e,
    0x08, 0x3d, 0xa8, 0x3f, 0x98, 0xc4, 0x58, 0x3f, 0x76, 0xc5,
    0xb5, 0x3e, 0x9e, 0x14, 0x2a, 0xbf, 0x25, 0x7d, 0x31, 0xbf,
    0x9b, 0x1a, 0x1b, 0xbe, 0xcf, 0xdd, 0xd6, 0x3e, 0xe0, 0xa2,
    0x23, 0xbc, 0x7b, 0x0b, 0x8c, 0x3e, 0x39, 0x66, 0x82, 0x3e,
    0xd3, 0x82, 0x46, 0xbf, 0xec, 0x4f, 0x08, 0x3f, 0x40, 0xed,
    0x10, 0x3f, 0xcc, 0x1d, 0x80, 0x3e, 0xa9, 0x27, 0x87, 0x3f,
    0x98, 0x1a, 0xad, 0xbc, 0x7e, 0x99, 0xc1, 0xbf, 0x99, 0xe0,
    0xdb, 0x3d, 0x26, 0x28, 0x03, 0x3f, 0x10, 0x5d, 0x4b, 0xbf,
    0xfd, 0x7e, 0xf0, 0xbe, 0x14, 0x4c, 0x80, 0x3d, 0xf0, 0xdc,
    0xb0, 0xbf, 0xcb, 0x7f, 0x7b, 0x3f, 0xbd, 0xf6, 0x3e, 0x3f,
    0x6f, 0x3d, 0x65, 0x3f, 0xa0, 0xdc, 0xa9, 0xbe, 0x86, 0x25,
    0x40, 0x3e, 0xef, 0x30, 0xba, 0xbe, 0xcc, 0xf8, 0x1e, 0xbf,
    0x60, 0x7d, 0xa4, 0xbd, 0xc1, 0x95, 0x2f, 0x3f, 0x9d, 0x89,
    0x5b, 0xbf, 0x9c, 0x7f, 0xb7, 0xbe, 0xa8, 0x51, 0x67, 0xbf,
    0x57, 0x84, 0xd3, 0xbe, 0x3d, 0x8a, 0x63, 0xbf, 0x8a, 0xd6,
    0x95, 0xbf, 0x8d, 0x3c, 0xbf, 0xbf, 0x40, 0xb2, 0x6c, 0x3c,
    0x53, 0xfb, 0xfa, 0xbe, 0x20, 0xef, 0x0a, 0xbf, 0xf8, 0x88,
    0xbe, 0xbe, 0x6e, 0x62, 0x12, 0x3f, 0x63, 0x6b, 0x6c, 0xbf,
    0xcd, 0x47, 0xc1, 0xbc, 0x61, 0x56, 0x8e, 0xbd, 0x3f, 0x42,
    0x23, 0x3d, 0x34, 0xdd, 0x16, 0x3c, 0x70, 0xa8, 0xec, 0x3c,
    0xdf, 0x6e, 0x19, 0xbf, 0x7a, 0x28, 0x3b, 0x3f, 0x83, 0xca,
    0x95, 0xbe, 0xac, 0x9e, 0x02, 0xbf, 0x38, 0x3f, 0x10, 0x40,
    0x4f, 0xab, 0x6f, 0x3f, 0x7f, 0x7a, 0xaf, 0xbf, 0x7f, 0x81,
    0xca, 0xbd, 0xbb, 0x80, 0x9b, 0xbd, 0x21, 0x27, 0xd4, 0xbf,
    0xe8, 0x9e, 0xb1, 0x3e, 0xd1, 0xea, 0x86, 0x3f, 0xea, 0x4f,
    0xe1, 0xbd, 0x5d, 0xee, 0x94, 0x3f, 0x81, 0x3b, 0x31, 0xbf,
    0x1a, 0x10, 0x8d, 0x3f, 0x56, 0x14, 0x56, 0xbf, 0x21, 0xfb,
    0x3c, 0x3f, 0x48, 0x73, 0x3c, 0x3f, 0x4c, 0x78, 0xd7, 0x3e,
    0xac, 0xe9, 0x9b, 0xbe, 0x71, 0x87, 0x3d, 0xbe, 0xd3, 0x3d,
    0x10, 0xbf, 0xd7, 0xc6, 0xf5, 0x3e, 0xd1, 0x8e, 0x48, 0x3f,
    0x55, 0x14, 0xe6, 0x3e, 0x60, 0x99, 0x27, 0xbf, 0x26, 0x87,
    0x4b, 0xbf, 0x84, 0x9d, 0x50, 0x3e, 0xca, 0xaf, 0xeb, 0xbf,
    0x6f, 0xf9, 0x5b, 0x3e, 0x93, 0xbe, 0xdb, 0xbc, 0x41, 0xbf,
    0x1f, 0x3d, 0xe8, 0x41, 0xb2, 0x3f, 0xca, 0xdc, 0xbf, 0x3f,
    0x5f, 0x8d, 0xa8, 0xbd, 0x1d, 0x1a, 0x83, 0xbf, 0x68, 0x87,
    0x0e, 0x3e, 0x6a, 0x09, 0x33, 0xbf, 0xdd, 0xcc, 0xcf, 0xbf,
    0x89, 0x87, 0x7b, 0x3e, 0x20, 0x11, 0x0c, 0x3f, 0xe9, 0x35,
    0xc1, 0x3d, 0x5f, 0xc1, 0xb8, 0xbe, 0x39, 0x73, 0x82, 0xbe,
    0x3b, 0xbc, 0x14, 0x3d, 0x7b, 0x8f, 0x45, 0xbd, 0xf1, 0xce,
    0xd0, 0x3e, 0x9c, 0x75, 0x24, 0x3d, 0xcf, 0xca, 0x9c, 0xbf,
    0xfe, 0xac, 0xf6, 0xbd, 0x36, 0x1a, 0x97, 0x3e, 0x2d, 0x38,
    0xd7, 0xbe, 0x53, 0x33, 0x99, 0x3e, 0xc9, 0xee, 0x71, 0x3f,
    0x5f, 0xdd, 0xb0, 0x3e, 0x7f, 0xac, 0xfd, 0xbe, 0x0c, 0xba,
    0x5c, 0xbe, 0x0f, 0x44, 0x03, 0xbe, 0x72, 0xc5, 0xd1, 0xbf,
    0xc0, 0x09, 0x24, 0x3f, 0xb2, 0xe1, 0xc2, 0x3f, 0xbb, 0x3c,
    0x47, 0x3f, 0xc1, 0xff, 0x43, 0x3f, 0xa3, 0x24, 0xf3, 0x3f,
    0x9c, 0x70, 0x73, 0xbf, 0x5b, 0xfc, 0x03, 0x3f, 0xb9, 0xdb,
    0x99, 0x3f, 0xce, 0x43, 0xb7, 0x3f, 0x44, 0xf8, 0x90, 0xbf,
    0x5c, 0xa6, 0x5a, 0x3f, 0x6c, 0x8f, 0x1b, 0xbe, 0x22, 0xc5,
    0x41, 0x3f, 0xf9, 0x34, 0xc4, 0xbf, 0xef, 0x85, 0x9f, 0x3e,
    0x6e, 0xd6, 0x8f, 0xbf, 0xf9, 0x2b, 0x44, 0xbe, 0x0b, 0x3e,
    0x16, 0xbf, 0xcf, 0x92, 0xdb, 0xbe, 0x8c, 0x50, 0xdf, 0x3e,
    0x2b, 0x07, 0x2b, 0xbe, 0x95, 0x9e, 0x1b, 0x3e, 0xfd, 0x19,
    0x85, 0x3f, 0x31, 0x3d, 0x85, 0x3e, 0xcc, 0x16, 0x8f, 0xbf,
    0x63, 0xf7, 0x6f, 0xbf, 0x33, 0x59, 0x9d, 0x3f, 0x53, 0x4a,
    0x7a, 0x3e, 0xf0, 0xb4, 0x47, 0x3d, 0x52, 0xc4, 0xf6, 0x3f,
    0xd5, 0x0a, 0x65, 0xc0, 0x81, 0x4a, 0xe7, 0xbe, 0x65, 0x7f,
    0xbf, 0xbd, 0x47, 0xd2, 0x8b, 0x3f, 0x4e, 0xcf, 0x15, 0x40,
    0x64, 0x4e, 0xb2, 0x3f, 0xd0, 0x05, 0x15, 0xc0, 0xd7, 0x20,
    0xb9, 0x3f, 0xbb, 0xe2, 0x9c, 0x3f, 0x7d, 0xac, 0x72, 0xbf,
    0xbd, 0xd2, 0x58, 0x3e, 0xbc, 0xd7, 0x83, 0x3e, 0xf3, 0xd6,
    0x34, 0xbf, 0x84, 0x26, 0x0f, 0x3f, 0x79, 0x1e, 0x5a, 0xbe,
    0x35, 0x3c, 0x2b, 0xbf, 0x94, 0x3f, 0x10, 0xbf, 0xde, 0xb6,
    0x77, 0xbf, 0x86, 0x6e, 0xe9, 0x3d, 0x91, 0x60, 0xd1, 0x3e,
    0x80, 0x95, 0x18, 0xbf, 0xa3, 0xff, 0x94, 0xbf, 0x0e, 0x06,
    0x72, 0xbe, 0x92, 0x20, 0xab, 0xbf, 0x5b, 0xcb, 0xc1, 0xbe,
    0xab, 0xc2, 0x04, 0x3f, 0x13, 0x97, 0x81, 0x3f, 0xc5, 0x11,
    0xfd, 0xbe, 0x33, 0x58, 0x8d, 0x3e, 0x5c, 0x67, 0x6f, 0x3f,
    0xe2, 0x6b, 0x71, 0x3f, 0x58, 0x8e, 0x94, 0x3f, 0xd5, 0x85,
    0x8c, 0xbe, 0xf1, 0x5e, 0xdd, 0xbf, 0x87, 0xbc, 0xd3, 0x3e,
    0x2f, 0x6d, 0xe2, 0xbe, 0xb2, 0xdb, 0xe1, 0xba, 0xf6, 0x59,
    0x0f, 0xbe, 0x85, 0xa1, 0x29, 0x3d, 0xa7, 0x44, 0xd3, 0x3d,
    0x7e, 0xc6, 0x98, 0x3f, 0x7e, 0x46, 0x7d, 0x3f, 0xb9, 0x19,
    0x28, 0xbf, 0xff, 0x0f, 0xbe, 0xbf, 0x65, 0x83, 0x6d, 0x3e,
    0x2c, 0xb2, 0x80, 0xbe, 0xad, 0x3c, 0xa6, 0xbf, 0xd7, 0xea,
    0x1e, 0xbf, 0xfc, 0x29, 0x35, 0xbf, 0x7c, 0x00, 0x80, 0xbe,
    0x89, 0x85, 0x2d, 0xc0, 0x15, 0x12, 0xb1, 0x3e, 0xfa, 0x8f,
    0xa9, 0xbe, 0x01, 0x1f, 0x84, 0x3f, 0x4c, 0x13, 0x16, 0x40,
    0xfd, 0x94, 0x0e, 0x3f, 0xb8, 0x8a, 0x42, 0xc0, 0xb1, 0x5e,
    0x94, 0x3f, 0x67, 0xbd, 0x75, 0x3f, 0x7f, 0x9f, 0xd2, 0xbf,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x46, 0x5a, 0x3c, 0xbf, 0x06, 0x55, 0xca, 0xbe, 0xc0, 0x96,
    0xec, 0xbe, 0x8e, 0xdf, 0xa3, 0x3d, 0x29, 0x16, 0x95, 0x40,
    0x77, 0x75, 0x99, 0xbf, 0x77, 0x0f, 0x9f, 0x3f, 0x7c, 0x3c,
    0xde, 0xbe, 0x2c, 0x18, 0x06, 0x3f, 0xe5, 0x75, 0xbe, 0x40,
    0xc2, 0xba, 0x31, 0x3f, 0xd6, 0x70, 0xbb, 0x3f, 0xe1, 0x51,
    0x53, 0xbf, 0xf1, 0x9e, 0x87, 0x3f, 0x75, 0xb4, 0x11, 0x3e,
    0xf2, 0x26, 0xe8, 0x3f, 0xa1, 0x14, 0x01, 0x3d, 0xd2, 0x5f,
    0x9f, 0x3d, 0xf9, 0xdd, 0x6c, 0x3d, 0x65, 0x97, 0xb3, 0xbe,
    0x92, 0x5c, 0xa9, 0xbe, 0xb8, 0x6d, 0xad, 0xbe, 0xa1, 0x40,
    0x7c, 0xbe, 0xca, 0x0f, 0x93, 0x3e, 0xd0, 0x88, 0x33, 0x3e,
    0x78, 0xec, 0xe0, 0x3d, 0x62, 0x0f, 0xb3, 0xbe, 0xd1, 0x12,
    0xd8, 0xbc, 0xa9, 0x3c, 0x44, 0xbe, 0x45, 0x94, 0x26, 0xbe,
    0x56, 0x73, 0x5a, 0xbf, 0xb9, 0x50, 0x85, 0xbf, 0x52, 0x9a,
    0x70, 0xbe, 0x6b, 0xe1, 0x45, 0x3f, 0xe4, 0xb0, 0x22, 0x40,
    0x2a, 0x21, 0x36, 0xbf, 0x9b, 0xf1, 0xaf, 0x3f, 0x9c, 0xc5,
    0x9e, 0xbd, 0x60, 0x8d, 0x53, 0x3e, 0x32, 0x1e, 0x03, 0x40,
    0xf1, 0xa8, 0x52, 0xc0, 0x33, 0xa0, 0x07, 0xc0, 0x92, 0x46,
    0x6f, 0xbf, 0x1e, 0xee, 0x6b, 0xbf, 0xff, 0x2f, 0xf4, 0x3f,
    0x24, 0x12, 0x09, 0x40, 0x96, 0x1c, 0x93, 0x3e, 0xa9, 0x45,
    0x13, 0x3d, 0x2d, 0x42, 0x3c, 0xbf, 0x21, 0x8e, 0x67, 0xbf,
    0xc7, 0x26, 0x13, 0xbf, 0x9c, 0x76, 0x1e, 0x3f, 0x7b, 0x69,
    0x66, 0x40, 0xae, 0xf8, 0x47, 0xbf, 0xdb, 0x32, 0x73, 0x40,
    0x92, 0x7f, 0xfa, 0x3e, 0x3a, 0x06, 0x82, 0x3f, 0xb0, 0x7c,
    0x40, 0x40, 0xed, 0x56, 0x5a, 0x40, 0xd2, 0x16, 0x0a, 0xc0,
    0xe6, 0xf3, 0xb6, 0x3f, 0x78, 0xc8, 0x86, 0x3f, 0xa4, 0xbf,
    0x85, 0xbe, 0x8d, 0x13, 0x05, 0x3f, 0x45, 0xe7, 0xbf, 0xbe,
    0x1c, 0x52, 0xa7, 0x3d, 0x57, 0xbc, 0x7a, 0xbf, 0xb0, 0x73,
    0x60, 0xbe, 0x2b, 0xca, 0xa3, 0xbf, 0x84, 0xd2, 0x3f, 0x3e,
    0x9a, 0x94, 0x87, 0xbd, 0x6f, 0x94, 0x58, 0x3f, 0x5c, 0xbb,
    0x56, 0x3e, 0x76, 0xa1, 0x02, 0x3e, 0xad, 0x7f, 0x38, 0x40,
    0x4d, 0xee, 0x45, 0x3f, 0x61, 0x76, 0x2a, 0xbf, 0x0f, 0x71,
    0x77, 0xbf, 0x4a, 0x9d, 0x6c, 0xbb, 0x65, 0x95, 0x7e, 0xc0,
    0x24, 0x36, 0x1a, 0xbf, 0xbf, 0x68, 0xe4, 0x3e, 0x83, 0x79,
    0xf0, 0x3f, 0x18, 0xe8, 0x5d, 0xbe, 0x5c, 0x19, 0xed, 0x40,
    0xcc, 0xe9, 0xdd, 0x3e, 0x68, 0xcf, 0xb1, 0x3e, 0xde, 0x23,
    0xa7, 0x3f, 0xc7, 0xaa, 0x8c, 0x3f, 0x66, 0x07, 0xf6, 0xc0,
    0xc8, 0x34, 0xa0, 0xbf, 0x96, 0x39, 0xd3, 0xbe, 0xe9, 0xd9,
    0x42, 0xc0, 0x2a, 0x49, 0xa9, 0x3f, 0xa6, 0x6e, 0x08, 0x40,
    0xb4, 0x48, 0x98, 0xbe, 0x8e, 0x34, 0xa9, 0xc0, 0xba, 0xb0,
    0x36, 0xbf, 0xf2, 0xc8, 0x35, 0xbf, 0xe1, 0x41, 0xca, 0xbf,
    0xe4, 0xf2, 0x47, 0xc0, 0xbc, 0xc9, 0xe7, 0xbe, 0xbb, 0xaa,
    0x80, 0xbe, 0x16, 0xc8, 0x0e, 0x3b, 0xd8, 0xd2, 0x67, 0xbe,
    0x8b, 0x69, 0x0c, 0x40, 0xe8, 0x01, 0xe9, 0x3c, 0x10, 0x8b,
    0xce, 0xbe, 0xd2, 0xe8, 0x29, 0xbf, 0xe2, 0xc6, 0x45, 0xbf,
    0x2d, 0xcc, 0x15, 0xc0, 0x48, 0xae, 0x01, 0x3f, 0x94, 0xaa,
    0x32, 0x40, 0x0e, 0x11, 0xe1, 0xbe, 0x05, 0x8a, 0x1c, 0x41,
    0x79, 0x61, 0x81, 0x3f, 0xa0, 0xfa, 0x19, 0x3f, 0x1d, 0xe7,
    0x38, 0x40, 0xae, 0x84, 0xe8, 0x3f, 0x86, 0xed, 0xf8, 0xc0,
    0x2c, 0x2a, 0x27, 0xbe, 0xe0, 0xc6, 0xea, 0x3e, 0x0d, 0xb7,
    0x53, 0x3f, 0x84, 0xe4, 0x26, 0x40, 0xef, 0x80, 0x46, 0x3f,
    0x07, 0x3a, 0xda, 0x3e, 0xe5, 0x60, 0x59, 0x3e, 0x84, 0xf5,
    0x03, 0xbf, 0xd1, 0x44, 0x09, 0x3f, 0xdd, 0xeb, 0x5b, 0xbe,
    0x62, 0x2a, 0x9a, 0xbe, 0x19, 0xd2, 0x86, 0x3f, 0x2e, 0xf7,
    0x56, 0xbe, 0x51, 0xa6, 0x93, 0x3f, 0xf9, 0xa0, 0x35, 0x3f,
    0x59, 0xac, 0x16, 0xbe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xa3, 0xbc,
    0x0d, 0x40, 0x3e, 0x8a, 0xf5, 0xbe, 0xff, 0xb7, 0x51, 0xbf,
    0x00, 0x7f, 0xb3, 0xbc, 0x23, 0x72, 0xba, 0x3c, 0x34, 0xf7,
    0x12, 0x3e, 0xc9, 0x58, 0x8d, 0x3f, 0x7c, 0x98, 0x86, 0x3f,
    0xa5, 0xe4, 0x80, 0x40, 0xb2, 0xa3, 0xad, 0x40, 0x42,
    0x7e, 0x4d, 0xc0, 0xff, 0xc6, 0xac, 0x3c, 0xfc, 0xaa,
    0x76, 0x3f, 0x6a, 0x7d, 0xc8, 0xc0, 0x18, 0x17, 0xaa,
    0xbf, 0xe6, 0x43, 0xc9, 0x3f, 0xd6, 0x71, 0x96, 0xbe
  };

  return AI_HANDLE_PTR(s_network_weights);

}

