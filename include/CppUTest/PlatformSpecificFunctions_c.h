/*
 * Copyright (c) 2007, Michael Feathers, James Grenning and Bas Vodde
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the <organization> nor the
 *       names of its contributors may be used to endorse or promote products
 *       derived from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE EARLIER MENTIONED AUTHORS ``AS IS'' AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL <copyright holder> BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS
 * SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/******************************************************************************
 *
 * PlatformSpecificFunctions_c.H
 *
 * Provides an interface for when working with pure C
 *
 *******************************************************************************/


#ifndef PLATFORMSPECIFICFUNCTIONS_C_H_
#define PLATFORMSPECIFICFUNCTIONS_C_H_

#ifdef __cplusplus
extern "C" {
#endif

/* Jumping operations. They manage their own jump buffers */
int PlatformSpecificSetJmp(void (*function) (void*), void* data);
void PlatformSpecificLongJmp(void);
void PlatformSpecificRestoreJumpBuffer(void);

/* Time operations */
extern long (*GetPlatformSpecificTimeInMillis)(void);
extern const char* (*GetPlatformSpecificTimeString)(void);

/* String operations */
int PlatformSpecificVSNprintf(char *str, size_t size, const char* format, va_list va_args_list);

char PlatformSpecificToLower(char c);

/* Misc */
double PlatformSpecificFabs(double d);
extern int (*PlatformSpecificIsNan)(double d);
int PlatformSpecificAtExit(void(*func)(void));

/* IO operations */
typedef void* PlatformSpecificFile;

PlatformSpecificFile PlatformSpecificFOpen(const char* filename, const char* flag);
void PlatformSpecificFPuts(const char* str, PlatformSpecificFile file);
void PlatformSpecificFClose(PlatformSpecificFile file);

int PlatformSpecificPutchar(int c);
void PlatformSpecificFlush(void);

/* Dynamic Memory operations */
void* PlatformSpecificMalloc(size_t size);
void* PlatformSpecificRealloc(void* memory, size_t size);
void PlatformSpecificFree(void* memory);
void* PlatformSpecificMemCpy(void* s1, const void* s2, size_t size);
void* PlatformSpecificMemset(void* mem, int c, size_t size);

#ifdef __cplusplus
}
#endif

#endif /* PLATFORMSPECIFICFUNCTIONS_C_H_ */
