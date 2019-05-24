/*===================================================================================================
* The MIT License (MIT)
*
* Copyright:  $
*
* Permission is hereby granted, free of charge, to any person obtaining a copy of this software
* and associated documentation files (the "Software"), to deal in the Software without restriction,
* including without limitation the rights to use, copy, modify, merge, publish, distribute,
* sublicense, and/or sell copies of the Software, and to permit persons to whom the Software
* is furnished to do so, subject to the following conditions:
*
* The above copyright notice and this permission notice shall be included in all copies
* or substantial portions of the Software.
*
* THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
* BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE
* AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM,
* DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
* OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
*
*===================================================================================================*/

#ifndef _TYPE_H_
#define _TYPE_H_

#define NULL_PTR                ((void *) 0)

/* Simple data types */
typedef unsigned char           UINT8;
typedef signed char             INT8;

typedef unsigned short int      UINT16;
typedef short int               INT16;

typedef unsigned int            UINT32;
typedef signed int              INT32;

typedef unsigned long           uint32;
typedef volatile UINT32         vuint32_t;

typedef unsigned long long      UINT64;

#ifdef HISTORY
/***********************************************************************
*
*  $Log: llm_tyde.he,v $
*  Revision 1.0  2019/05/10
*  Initial Version
*  [Lam Huynh Van]
*
***********************************************************************/
#endif /* HISTORY */

#endif /* _TYPE_H_ */
