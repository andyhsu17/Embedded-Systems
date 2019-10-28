/* Copyright (c) 2012, Texas Instruments Incorporated
All rights reserved.

Redistribution and use in source and binary forms, with or without
modification, are permitted provided that the following conditions
are met:

*  Redistributions of source code must retain the above copyright
   notice, this list of conditions and the following disclaimer.

*  Redistributions in binary form must reproduce the above copyright
   notice, this list of conditions and the following disclaimer in the
   documentation and/or other materials provided with the distribution.

*  Neither the name of Texas Instruments Incorporated nor the names of
   its contributors may be used to endorse or promote products derived
   from this software without specific prior written permission.

THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.*/


#include <ti/grlib/grlib.h>

static const unsigned char pixel_TI_Logo_69x64_1BPP_UNCOMP[] =
{
0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xe1, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xc0, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xc0, 0x7f, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xc0, 0x7f, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x3f, 0xc0, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x1f, 0xe1, 0xff, 0xff, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xf0, 0x00, 0xf8, 
0xff, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x00, 0x03, 0x80, 0xe0, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x00, 0x03, 0x80, 0xe0, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x00, 0x07, 0x80, 0xe0, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x00, 0x07, 0x00, 0xe0, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x01, 0xff, 0x00, 0xff, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x01, 0xff, 0x01, 0xff, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x01, 0xff, 0x01, 0xff, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x03, 0xff, 0x01, 0xff, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x03, 0xfe, 0x01, 0xff, 0x00, 0x78, 
0xff, 0xff, 0xc0, 0x03, 0xfe, 0x03, 0xfe, 0x00, 0x38, 
0x00, 0x00, 0x00, 0x03, 0xfe, 0x03, 0xfe, 0x00, 0x38, 
0x00, 0x00, 0x00, 0x00, 0x1e, 0x03, 0x80, 0x00, 0x18, 
0x00, 0x00, 0x00, 0x00, 0x1c, 0x03, 0x80, 0x00, 0x08, 
0x80, 0x00, 0x00, 0x00, 0x1c, 0x03, 0x80, 0x00, 0x00, 
0xc0, 0x00, 0x00, 0x00, 0x1c, 0x07, 0x00, 0x00, 0x00, 
0xf0, 0x00, 0x00, 0x00, 0x1c, 0x07, 0x00, 0x00, 0x00, 
0xf8, 0x00, 0x00, 0x00, 0x3c, 0x07, 0x00, 0x00, 0x00, 
0xfc, 0x00, 0x00, 0x00, 0x38, 0x07, 0x00, 0x00, 0x00, 
0xfe, 0x00, 0x00, 0x00, 0x38, 0x07, 0x00, 0x00, 0x00, 
0xff, 0x00, 0x00, 0x00, 0x38, 0x0e, 0x00, 0x00, 0x00, 
0xff, 0x00, 0x00, 0x00, 0x78, 0x0e, 0x00, 0x00, 0x00, 
0xff, 0x80, 0x00, 0x00, 0x78, 0x0e, 0x00, 0x00, 0x08, 
0xff, 0x80, 0x00, 0x00, 0x70, 0x0e, 0x00, 0x00, 0x08, 
0xff, 0x80, 0x00, 0x00, 0x70, 0x1c, 0x00, 0x00, 0x18, 
0xff, 0xc0, 0x00, 0x00, 0x7f, 0xfc, 0x00, 0x00, 0x78, 
0xff, 0xc0, 0x00, 0x00, 0x7f, 0xfc, 0x40, 0x01, 0xf8, 
0xff, 0xe0, 0x07, 0xc0, 0x7f, 0xff, 0xc0, 0x07, 0xf8, 
0xff, 0xf0, 0x0f, 0xe0, 0x7f, 0xff, 0x80, 0x1f, 0xf8, 
0xff, 0xf8, 0x3f, 0xf0, 0x3f, 0xff, 0x80, 0x3f, 0xf8, 
0xff, 0xff, 0xff, 0xf8, 0x3f, 0xff, 0x80, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0x81, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xfc, 0x03, 0xfc, 0x03, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x0f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0x00, 0x00, 0x1f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xfc, 0x00, 0x3f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xf8, 
0xff, 0xff, 0xff, 0xff, 0xff, 0xe0, 0x3f, 0xff, 0xff
};

static const uint32_t palette_TI_Logo_69x64_1BPP_UNCOMP[]=
{
	0x000000, 	0xffffff
};

const Graphics_Image  TI_Logo_69x64_1BPP_UNCOMP=
{
	GRAPHICS_IMAGE_FMT_1BPP_UNCOMP,
	69,
	64,
	2,
	palette_TI_Logo_69x64_1BPP_UNCOMP,
	pixel_TI_Logo_69x64_1BPP_UNCOMP,
};

