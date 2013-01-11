
#include "XkStable.h"
#include "XkGC.h"

#include <iostream>
#include <fstream>

                                                                                       

namespace Xk
{

                                                                                       

namespace GC
{

                                                                                       

#if XK_DEBUG_MEMORY == 1
char gc_debugger_html_begin[] = {
	60, 33, 100, 111, 99, 116, 121, 112, 101, 32, 104, 116, 109, 108, 62,
	10, 60, 104, 116, 109, 108, 32, 108, 97, 110, 103, 61, 34, 101, 110,
	34, 62, 10, 60, 104, 101, 97, 100, 62, 10, 32, 32, 32, 32, 60, 116,
	105, 116, 108, 101, 62, 78, 120, 79, 103, 114, 101, 32, 38, 109, 100,
	97, 115, 104, 59, 32, 77, 101, 109, 111, 114, 121, 60, 47, 116, 105,
	116, 108, 101, 62, 10, 32, 32, 32, 32, 60, 115, 116, 121, 108, 101,
	32, 116, 121, 112, 101, 61, 34, 116, 101, 120, 116, 47, 99, 115, 115,
	34, 32, 109, 101, 100, 105, 97, 61, 34, 115, 99, 114, 101, 101, 110,
	34, 62, 10, 32, 32, 32, 32, 98, 111, 100, 121, 32, 123, 10, 32, 32,
	32, 32, 32, 32, 32, 32, 109, 97, 114, 103, 105, 110, 58, 48, 59, 10,
	32, 32, 32, 32, 32, 32, 32, 32, 112, 97, 100, 100, 105, 110, 103, 58,
	48, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 98, 97, 99, 107, 103, 114,
	111, 117, 110, 100, 45, 99, 111, 108, 111, 114, 58, 35, 50, 50, 50,
	59, 10, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 104, 49, 32, 123, 10,
	32, 32, 32, 32, 32, 32, 32, 32, 99, 111, 108, 111, 114, 58, 82, 71,
	66, 65, 40, 50, 53, 53, 44, 50, 53, 53, 44, 50, 53, 53, 44, 48, 46,
	54, 41, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116, 101, 120, 116,
	45, 115, 104, 97, 100, 111, 119, 58, 32, 35, 101, 101, 101, 32, 48,
	32, 48, 32, 54, 112, 120, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 116,
	101, 120, 116, 45, 97, 108, 105, 103, 110, 58, 32, 99, 101, 110, 116,
	101, 114, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 108, 101, 116, 116,
	101, 114, 45, 115, 112, 97, 99, 105, 110, 103, 58, 45, 49, 112, 120,
	59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 102, 111, 110, 116, 58, 53,
	48, 112, 120, 32, 97, 114, 105, 97, 108, 59, 10, 32, 32, 32, 32, 32,
	32, 32, 32, 102, 111, 110, 116, 45, 119, 101, 105, 103, 104, 116, 58,
	110, 111, 114, 109, 97, 108, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32,
	108, 105, 110, 101, 45, 104, 101, 105, 103, 104, 116, 58, 49, 48, 48,
	112, 120, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 109, 97, 114, 103,
	105, 110, 58, 48, 59, 112, 97, 100, 100, 105, 110, 103, 58, 48, 59,
	10, 32, 32, 32, 32, 32, 32, 32, 32, 104, 101, 105, 103, 104, 116, 58,
	49, 48, 48, 112, 120, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 98, 111,
	114, 100, 101, 114, 45, 98, 111, 116, 116, 111, 109, 58, 49, 112, 120,
	32, 115, 111, 108, 105, 100, 32, 35, 50, 50, 50, 59, 10, 32, 32, 32,
	32, 32, 32, 32, 32, 100, 105, 115, 112, 108, 97, 121, 58, 98, 108,
	111, 99, 107, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 47, 42, 32, 70,
	111, 114, 32, 87, 101, 98, 75, 105, 116, 32, 40, 83, 97, 102, 97, 114,
	105, 44, 32, 71, 111, 111, 103, 108, 101, 32, 67, 104, 114, 111, 109,
	101, 32, 101, 116, 99, 41, 32, 42, 47, 10, 32, 32, 32, 32, 32, 32, 32,
	32, 98, 97, 99, 107, 103, 114, 111, 117, 110, 100, 58, 32, 45, 109,
	111, 122, 45, 108, 105, 110, 101, 97, 114, 45, 103, 114, 97, 100, 105,
	101, 110, 116, 40, 116, 111, 112, 44, 32, 35, 50, 50, 50, 44, 32, 35,
	51, 51, 51, 41, 32, 35, 50, 50, 50, 32, 116, 111, 112, 32, 108, 101,
	102, 116, 32, 110, 111, 45, 114, 101, 112, 101, 97, 116, 59, 10, 32,
	32, 32, 32, 32, 32, 32, 32, 47, 42, 32, 70, 111, 114, 32, 77, 111,
	122, 105, 108, 108, 97, 47, 71, 101, 99, 107, 111, 32, 40, 70, 105,
	114, 101, 102, 111, 120, 32, 101, 116, 99, 41, 32, 42, 47, 10, 32, 32,
	32, 32, 32, 32, 32, 32, 47, 42, 32, 70, 111, 114, 32, 73, 110, 116,
	101, 114, 110, 101, 116, 32, 69, 120, 112, 108, 111, 114, 101, 114,
	32, 56, 32, 42, 47, 10, 32, 32, 32, 32, 32, 32, 32, 32, 45, 109, 115,
	45, 102, 105, 108, 116, 101, 114, 58, 32, 34, 112, 114, 111, 103, 105,
	100, 58, 68, 88, 73, 109, 97, 103, 101, 84, 114, 97, 110, 115, 102,
	111, 114, 109, 46, 77, 105, 99, 114, 111, 115, 111, 102, 116, 46, 103,
	114, 97, 100, 105, 101, 110, 116, 40, 115, 116, 97, 114, 116, 67, 111,
	108, 111, 114, 115, 116, 114, 61, 35, 49, 49, 49, 49, 49, 49, 44, 32,
	101, 110, 100, 67, 111, 108, 111, 114, 115, 116, 114, 61, 35, 51, 51,
	51, 51, 51, 51, 41, 34, 59, 10, 32, 32, 32, 32, 125, 10, 32, 32, 32,
	32, 104, 50, 32, 123, 99, 111, 108, 111, 114, 58, 116, 114, 97, 110,
	115, 112, 97, 114, 101, 110, 116, 59, 10, 32, 32, 32, 32, 32, 32, 32,
	32, 116, 101, 120, 116, 45, 115, 104, 97, 100, 111, 119, 58, 32, 35,
	101, 101, 101, 32, 48, 32, 48, 32, 49, 112, 120, 59, 10, 32, 32, 32,
	32, 32, 32, 32, 32, 116, 101, 120, 116, 45, 97, 108, 105, 103, 110,
	58, 32, 99, 101, 110, 116, 101, 114, 59, 10, 32, 32, 32, 32, 32, 32,
	32, 32, 102, 111, 110, 116, 58, 50, 48, 112, 120, 32, 97, 114, 105,
	97, 108, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 108, 105, 110, 101,
	45, 104, 101, 105, 103, 104, 116, 58, 49, 48, 48, 112, 120, 59, 10,
	32, 32, 32, 32, 32, 32, 32, 32, 109, 97, 114, 103, 105, 110, 58, 48,
	59, 112, 97, 100, 100, 105, 110, 103, 58, 48, 59, 10, 32, 32, 32, 32,
	32, 32, 32, 32, 98, 111, 114, 100, 101, 114, 45, 116, 111, 112, 58,
	49, 112, 120, 32, 115, 111, 108, 105, 100, 32, 35, 53, 53, 53, 59, 10,
	32, 32, 32, 32, 32, 32, 32, 32, 98, 97, 99, 107, 103, 114, 111, 117,
	110, 100, 58, 32, 45, 109, 111, 122, 45, 108, 105, 110, 101, 97, 114,
	45, 103, 114, 97, 100, 105, 101, 110, 116, 40, 116, 111, 112, 44, 32,
	35, 52, 52, 52, 44, 32, 35, 50, 50, 50, 41, 32, 35, 52, 52, 52, 32,
	116, 111, 112, 32, 108, 101, 102, 116, 32, 110, 111, 45, 114, 101,
	112, 101, 97, 116, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 45, 109,
	115, 45, 102, 105, 108, 116, 101, 114, 58, 32, 34, 112, 114, 111, 103,
	105, 100, 58, 68, 88, 73, 109, 97, 103, 101, 84, 114, 97, 110, 115,
	102, 111, 114, 109, 46, 77, 105, 99, 114, 111, 115, 111, 102, 116, 46,
	103, 114, 97, 100, 105, 101, 110, 116, 40, 115, 116, 97, 114, 116, 67,
	111, 108, 111, 114, 115, 116, 114, 61, 35, 52, 52, 52, 52, 52, 52, 44,
	32, 101, 110, 100, 67, 111, 108, 111, 114, 115, 116, 114, 61, 35, 50,
	50, 50, 50, 50, 50, 41, 34, 59, 10, 32, 32, 32, 32, 125, 10, 32, 32,
	32, 32, 116, 97, 98, 108, 101, 32, 123, 10, 32, 32, 32, 32, 32, 32,
	32, 32, 119, 105, 100, 116, 104, 58, 56, 48, 37, 59, 10, 32, 32, 32,
	32, 32, 32, 32, 32, 109, 97, 114, 103, 105, 110, 58, 32, 48, 32, 97,
	117, 116, 111, 59, 10, 32, 32, 32, 32, 125, 10, 32, 32, 32, 32, 115,
	112, 97, 110, 46, 101, 110, 100, 32, 123, 100, 105, 115, 112, 108, 97,
	121, 58, 98, 108, 111, 99, 107, 59, 112, 97, 100, 100, 105, 110, 103,
	45, 116, 111, 112, 58, 51, 48, 112, 120, 59, 98, 111, 114, 100, 101,
	114, 45, 98, 111, 116, 116, 111, 109, 58, 49, 112, 120, 32, 115, 111,
	108, 105, 100, 32, 35, 48, 53, 48, 53, 48, 53, 59, 125, 10, 32, 32,
	32, 32, 116, 97, 98, 108, 101, 32, 116, 104, 101, 97, 100, 32, 123,
	102, 111, 110, 116, 58, 49, 50, 46, 53, 112, 120, 32, 118, 101, 114,
	100, 97, 110, 97, 59, 102, 111, 110, 116, 45, 119, 101, 105, 103, 104,
	116, 58, 110, 111, 114, 109, 97, 108, 59, 99, 111, 108, 111, 114, 58,
	119, 104, 105, 116, 101, 59, 98, 97, 99, 107, 103, 114, 111, 117, 110,
	100, 58, 32, 45, 109, 111, 122, 45, 108, 105, 110, 101, 97, 114, 45,
	103, 114, 97, 100, 105, 101, 110, 116, 40, 116, 111, 112, 44, 32, 35,
	50, 50, 50, 44, 32, 35, 52, 52, 52, 41, 32, 35, 50, 50, 50, 32, 116,
	111, 112, 32, 108, 101, 102, 116, 32, 110, 111, 45, 114, 101, 112,
	101, 97, 116, 59, 10, 32, 32, 32, 32, 32, 32, 32, 32, 112, 97, 100,
	100, 105, 110, 103, 45, 116, 111, 112, 58, 51, 48, 112, 120, 59, 10,
	32, 32, 32, 32, 32, 32, 32, 32, 116, 101, 120, 116, 45, 115, 104, 97,
	100, 111, 119, 58, 32, 35, 102, 102, 102, 102, 102, 102, 32, 48, 32,
	48, 32, 48, 46, 53, 101, 109, 59, 125, 10, 32, 32, 32, 32, 116, 97,
	98, 108, 101, 32, 116, 104, 101, 97, 100, 32, 116, 114, 32, 116, 104,
	32, 123, 102, 111, 110, 116, 45, 119, 101, 105, 103, 104, 116, 58,
	110, 111, 114, 109, 97, 108, 32, 33, 105, 109, 112, 111, 114, 116, 97,
	110, 116, 59, 98, 111, 114, 100, 101, 114, 45, 116, 111, 112, 58, 49,
	112, 120, 32, 115, 111, 108, 105, 100, 32, 35, 52, 52, 52, 59, 98,
	111, 114, 100, 101, 114, 45, 108, 101, 102, 116, 58, 49, 112, 120, 32,
	115, 111, 108, 105, 100, 32, 35, 52, 52, 52, 59, 98, 111, 114, 100,
	101, 114, 45, 114, 105, 103, 104, 116, 58, 49, 112, 120, 32, 115, 111,
	108, 105, 100, 32, 35, 50, 50, 50, 59, 108, 105, 110, 101, 45, 104,
	101, 105, 103, 104, 116, 58, 50, 50, 112, 120, 59, 98, 111, 114, 100,
	101, 114, 45, 98, 111, 116, 116, 111, 109, 58, 49, 112, 120, 32, 115,
	111, 108, 105, 100, 32, 35, 50, 50, 50, 59, 125, 10, 32, 32, 32, 32,
	116, 97, 98, 108, 101, 32, 116, 98, 111, 100, 121, 32, 116, 114, 58,
	110, 116, 104, 45, 99, 104, 105, 108, 100, 40, 111, 100, 100, 41, 32,
	123, 98, 97, 99, 107, 103, 114, 111, 117, 110, 100, 45, 99, 111, 108,
	111, 114, 58, 35, 51, 51, 51, 59, 99, 111, 108, 111, 114, 58, 35, 101,
	101, 101, 59, 125, 10, 32, 32, 32, 32, 116, 97, 98, 108, 101, 32, 116,
	98, 111, 100, 121, 32, 116, 114, 32, 123, 98, 97, 99, 107, 103, 114,
	111, 117, 110, 100, 45, 99, 111, 108, 111, 114, 58, 35, 51, 65, 51,
	65, 51, 65, 59, 99, 111, 108, 111, 114, 58, 35, 101, 101, 101, 59,
	125, 10, 32, 32, 32, 32, 116, 97, 98, 108, 101, 32, 116, 98, 111, 100,
	121, 32, 116, 114, 32, 116, 100, 32, 123, 98, 111, 114, 100, 101, 114,
	45, 116, 111, 112, 58, 49, 112, 120, 32, 115, 111, 108, 105, 100, 32,
	35, 52, 52, 52, 59, 98, 111, 114, 100, 101, 114, 45, 108, 101, 102,
	116, 58, 49, 112, 120, 32, 115, 111, 108, 105, 100, 32, 35, 52, 52,
	52, 59, 98, 111, 114, 100, 101, 114, 45, 114, 105, 103, 104, 116, 58,
	49, 112, 120, 32, 115, 111, 108, 105, 100, 32, 35, 50, 50, 50, 59,
	108, 105, 110, 101, 45, 104, 101, 105, 103, 104, 116, 58, 50, 50, 112,
	120, 59, 98, 111, 114, 100, 101, 114, 45, 98, 111, 116, 116, 111, 109,
	58, 49, 112, 120, 32, 115, 111, 108, 105, 100, 32, 35, 50, 50, 50, 59,
	112, 97, 100, 100, 105, 110, 103, 58, 48, 32, 52, 112, 120, 32, 48,
	32, 52, 112, 120, 59, 125, 10, 32, 32, 32, 32, 116, 97, 98, 108, 101,
	32, 116, 98, 111, 100, 121, 32, 116, 114, 32, 116, 100, 46, 112, 116,
	114, 32, 123, 119, 105, 100, 116, 104, 58, 49, 48, 37, 59, 116, 101,
	120, 116, 45, 97, 108, 105, 103, 110, 58, 99, 101, 110, 116, 101, 114,
	59, 125, 10, 32, 32, 32, 32, 116, 97, 98, 108, 101, 32, 116, 98, 111,
	100, 121, 32, 116, 114, 32, 116, 100, 46, 115, 105, 122, 101, 32, 123,
	119, 105, 100, 116, 104, 58, 49, 48, 37, 59, 116, 101, 120, 116, 45,
	97, 108, 105, 103, 110, 58, 99, 101, 110, 116, 101, 114, 59, 125, 10,
	32, 32, 32, 32, 116, 97, 98, 108, 101, 32, 116, 98, 111, 100, 121, 32,
	116, 114, 32, 116, 100, 46, 116, 121, 112, 101, 32, 123, 119, 105,
	100, 116, 104, 58, 50, 50, 46, 53, 37, 59, 116, 101, 120, 116, 45, 97,
	108, 105, 103, 110, 58, 99, 101, 110, 116, 101, 114, 59, 125, 10, 32,
	32, 32, 32, 97, 46, 97, 108, 108, 111, 99, 32, 123, 116, 101, 120,
	116, 45, 100, 101, 99, 111, 114, 97, 116, 105, 111, 110, 58, 110, 111,
	110, 101, 59, 99, 111, 108, 111, 114, 58, 108, 105, 109, 101, 59, 102,
	111, 110, 116, 45, 102, 97, 109, 105, 108, 121, 58, 97, 114, 105, 97,
	108, 59, 102, 111, 110, 116, 45, 115, 105, 122, 101, 58, 50, 50, 112,
	120, 59, 102, 111, 110, 116, 45, 119, 101, 105, 103, 104, 116, 58, 98,
	111, 108, 100, 101, 114, 59, 116, 101, 120, 116, 45, 115, 104, 97,
	100, 111, 119, 58, 32, 108, 105, 109, 101, 32, 48, 32, 48, 32, 48, 46,
	50, 101, 109, 59, 108, 105, 110, 101, 45, 104, 101, 105, 103, 104,
	116, 58, 49, 112, 120, 59, 125, 10, 32, 32, 32, 32, 97, 46, 100, 101,
	97, 108, 108, 111, 99, 32, 123, 116, 101, 120, 116, 45, 100, 101, 99,
	111, 114, 97, 116, 105, 111, 110, 58, 110, 111, 110, 101, 59, 102,
	111, 110, 116, 45, 102, 97, 109, 105, 108, 121, 58, 97, 114, 105, 97,
	108, 59, 102, 111, 110, 116, 45, 115, 105, 122, 101, 58, 50, 56, 112,
	120, 59, 99, 111, 108, 111, 114, 58, 114, 101, 100, 59, 102, 111, 110,
	116, 45, 119, 101, 105, 103, 104, 116, 58, 98, 111, 108, 100, 101,
	114, 59, 116, 101, 120, 116, 45, 115, 104, 97, 100, 111, 119, 58, 32,
	114, 101, 100, 32, 48, 32, 48, 32, 48, 46, 50, 101, 109, 59, 108, 105,
	110, 101, 45, 104, 101, 105, 103, 104, 116, 58, 49, 112, 120, 59, 125,
	10, 32, 32, 32, 32, 97, 46, 114, 101, 97, 108, 108, 111, 99, 32, 123,
	116, 101, 120, 116, 45, 100, 101, 99, 111, 114, 97, 116, 105, 111,
	110, 58, 110, 111, 110, 101, 59, 99, 111, 108, 111, 114, 58, 121, 101,
	108, 108, 111, 119, 59, 102, 111, 110, 116, 45, 102, 97, 109, 105,
	108, 121, 58, 97, 114, 105, 97, 108, 59, 102, 111, 110, 116, 45, 115,
	105, 122, 101, 58, 50, 56, 112, 120, 59, 102, 111, 110, 116, 45, 119,
	101, 105, 103, 104, 116, 58, 98, 111, 108, 100, 101, 114, 59, 116,
	101, 120, 116, 45, 115, 104, 97, 100, 111, 119, 58, 32, 121, 101, 108,
	108, 111, 119, 32, 48, 32, 48, 32, 48, 46, 50, 101, 109, 59, 108, 105,
	110, 101, 45, 104, 101, 105, 103, 104, 116, 58, 49, 112, 120, 59, 125,
	10, 32, 32, 32, 32, 115, 112, 97, 110, 46, 112, 111, 115, 110, 101,
	103, 32, 123, 99, 111, 108, 111, 114, 58, 108, 105, 109, 101, 59, 98,
	111, 114, 100, 101, 114, 45, 98, 111, 116, 116, 111, 109, 58, 49, 112,
	120, 32, 115, 111, 108, 105, 100, 32, 114, 101, 100, 59, 102, 111,
	110, 116, 45, 119, 101, 105, 103, 104, 116, 58, 98, 111, 108, 100,
	101, 114, 59, 125, 10, 32, 32, 32, 32, 116, 100, 32, 123, 104, 101,
	105, 103, 104, 116, 58, 50, 54, 112, 120, 59, 125, 10, 32, 32, 32, 32,
	116, 100, 46, 97, 108, 108, 111, 99, 44, 32, 116, 100, 46, 100, 101,
	97, 108, 108, 111, 99, 44, 116, 100, 46, 114, 101, 97, 108, 108, 111,
	99, 123, 119, 105, 100, 116, 104, 58, 53, 37, 59, 116, 101, 120, 116,
	45, 97, 108, 105, 103, 110, 58, 99, 101, 110, 116, 101, 114, 59, 125,
	10, 32, 32, 32, 32, 116, 100, 46, 112, 116, 114, 44, 32, 116, 100, 46,
	115, 105, 122, 101, 44, 32, 116, 100, 46, 116, 121, 112, 101, 44, 32,
	116, 100, 46, 115, 111, 117, 114, 99, 101, 123, 102, 111, 110, 116,
	58, 49, 49, 46, 53, 112, 120, 32, 97, 114, 105, 97, 108, 59, 125, 10,
	32, 32, 32, 32, 116, 100, 46, 115, 111, 117, 114, 99, 101, 44, 32,
	116, 100, 46, 116, 121, 112, 101, 32, 123, 99, 111, 108, 111, 114, 58,
	35, 100, 100, 100, 59, 125, 10, 32, 32, 32, 32, 116, 100, 46, 115,
	105, 122, 101, 44, 32, 116, 100, 46, 115, 111, 117, 114, 99, 101, 32,
	101, 109, 32, 123, 102, 111, 110, 116, 45, 115, 116, 121, 108, 101,
	58, 110, 111, 114, 109, 97, 108, 59, 99, 111, 108, 111, 114, 58, 35,
	101, 101, 101, 59, 125, 10, 32, 32, 32, 32, 100, 105, 118, 35, 115,
	116, 97, 116, 115, 32, 123, 119, 105, 100, 116, 104, 58, 54, 48, 48,
	112, 120, 59, 104, 101, 105, 103, 104, 116, 58, 49, 56, 48, 112, 120,
	59, 109, 97, 114, 103, 105, 110, 58, 48, 32, 97, 117, 116, 111, 59,
	98, 111, 114, 100, 101, 114, 58, 49, 112, 120, 32, 115, 111, 108, 105,
	100, 32, 35, 50, 48, 50, 48, 50, 48, 59, 98, 97, 99, 107, 103, 114,
	111, 117, 110, 100, 58, 35, 50, 53, 50, 53, 50, 53, 59, 125, 10, 32,
	32, 32, 32, 116, 100, 46, 98, 111, 117, 110, 100, 97, 114, 121, 32,
	123, 98, 97, 99, 107, 103, 114, 111, 117, 110, 100, 45, 99, 111, 108,
	111, 114, 58, 103, 114, 101, 101, 110, 59, 104, 101, 105, 103, 104,
	116, 58, 56, 112, 120, 32, 33, 105, 109, 112, 111, 114, 116, 97, 110,
	116, 59, 98, 111, 114, 100, 101, 114, 58, 48, 59, 98, 111, 114, 100,
	101, 114, 45, 116, 111, 112, 58, 51, 112, 120, 32, 115, 111, 108, 105,
	100, 32, 35, 50, 50, 50, 59, 98, 111, 114, 100, 101, 114, 45, 98, 111,
	116, 116, 111, 109, 58, 51, 112, 120, 32, 115, 111, 108, 105, 100, 32,
	35, 50, 50, 50, 59, 125, 10, 32, 32, 32, 32, 60, 47, 115, 116, 121,
	108, 101, 62, 10, 60, 47, 104, 101, 97, 100, 62, 10, 60, 98, 111, 100,
	121, 62
};

char gc_debugger_html_end[] = {
	60, 47, 98, 111, 100, 121, 62, 10, 60, 47, 104, 116, 109, 108, 62
};

char gc_debugger_allocations_begin[] = {
	32, 32, 32, 32, 60, 104, 50, 32, 99, 108, 97, 115, 115, 61, 34, 97,
	108, 108, 111, 99, 115, 34, 62, 65, 108, 108, 111, 99, 97, 116, 105,
	111, 110, 115, 60, 47, 104, 50, 62, 10, 32, 32, 32, 32, 60, 116, 97,
	98, 108, 101, 32, 99, 101, 108, 108, 115, 112, 97, 99, 105, 110, 103,
	61, 48, 32, 99, 101, 108, 108, 112, 97, 100, 100, 105, 110, 103, 61,
	48, 32, 98, 111, 114, 100, 101, 114, 61, 48, 62, 10, 32, 32, 32, 32,
	32, 32, 32, 32, 60, 116, 104, 101, 97, 100, 62, 10, 32, 32, 32, 32,
	32, 32, 32, 32, 32, 32, 32, 32, 60, 116, 114, 62, 10, 32, 32, 32, 32,
	32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 60, 116, 104, 62, 60, 115,
	112, 97, 110, 32, 99, 108, 97, 115, 115, 61, 34, 112, 111, 115, 110,
	101, 103, 34, 62, 43, 60, 47, 115, 112, 97, 110, 62, 60, 47, 116, 104,
	62, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
	60, 116, 104, 62, 80, 116, 114, 60, 47, 116, 104, 62, 10, 32, 32, 32,
	32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 60, 116, 104, 62, 83,
	105, 122, 101, 60, 47, 116, 104, 62, 10, 32, 32, 32, 32, 32, 32, 32,
	32, 32, 32, 32, 32, 32, 32, 32, 60, 116, 104, 62, 84, 121, 112, 101,
	60, 47, 116, 104, 62, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
	32, 32, 32, 32, 60, 116, 104, 62, 83, 111, 117, 114, 99, 101, 60, 47,
	116, 104, 62, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 60,
	47, 116, 114, 62, 10, 32, 32, 32, 32, 32, 32, 32, 32, 60, 47, 116,
	104, 101, 97, 100, 62, 10, 32, 32, 32, 32, 32, 32, 32, 32, 60, 116,
	98, 111, 100, 121, 62, 10, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32, 32,
	32
};

char gc_debugger_allocations_end[] = {
	32, 32, 32, 32, 32, 32, 32, 32, 60, 47, 116, 98, 111, 100, 121, 62,
	10, 32, 32, 32, 32, 60, 47, 116, 97, 98, 108, 101, 62, 10, 32, 32, 32,
	32, 60, 115, 112, 97, 110, 32, 99, 108, 97, 115, 115, 61, 34, 101,
	110, 100, 34, 62, 60, 47, 115, 112, 97, 110, 62
};

class MemoryDebugger
{
  
 public:
  
  struct Allocation
  {
   
   Allocation() {}
   
   Allocation(unsigned int size, const char* type)
   : mSize(size)
   {
    if (type)
     mType = type;
   }
   
   unsigned int mSize;
   std::string mType;
  };
  
  MemoryDebugger() : mIsSimulating(false)
  {
   mStream.open(Xk_Stringify(XK_DEBUG_MEMORY_FILE));
   mStream << "<h1>Xk <small>" << /*XkBranch << "/" << XkCommit << */"</small></h1>\n";
   mStream << gc_debugger_html_begin;
   write_allocations_header();
   mStream.flush();
  }

 ~MemoryDebugger()
  {
   write_allocations_footer();
   mStream << gc_debugger_html_end;
   mStream.close();
  }
  
  inline void begin()
  {
   mStream << "<tr><td class=\"boundary\" colspan=\"6\">Timesteps Begin</td></tr>\n";
   mIsSimulating = true;
  }

  inline void end()
  {
   mIsSimulating = false;
   mStream << "<tr><td class=\"boundary\" colspan=\"6\">Timesteps end</td></tr>\n";
  }

  inline void timestep(unsigned int timestep, float deltaTime)
  {
  }

  inline void push(void* ptr, unsigned int size, const char* type, const char* file, unsigned int line)
  {
   mNextID++;
   write_allocation(mNextID, 0, ptr, size, type, file, line);
  }

  inline void pop(void* ptr, const char* file, unsigned int line)
  {
   mNextID++;
   write_allocation(mNextID, 1, ptr, 0, 0, file, line);
  }

  inline void change(void* old_ptr, void*  new_ptr, unsigned int new_size, const char* file, unsigned int line)
  {
   mNextID++;
   write_allocation(mNextID, 2, new_ptr, new_size, 0, file, line);
  }
  
 protected:
  
  inline void write_allocations_header()
  {
   mStream << gc_debugger_allocations_begin;
  }

  inline void write_allocation(unsigned int id, int alloc_type, void* ptr, unsigned int size, const char* type, const char* file, unsigned int line)
  {
   
   if (mIsSimulating)
    return;
   
   std::stringstream s;
   
   
   s << "            <tr>\n"
              "                <td class=\"";
   if (alloc_type == 0)
    s << "alloc";
   else if (alloc_type == 1)
    s << "dealloc";
   else if (alloc_type == 2)
    s << "realloc";

   s << "\"><a href=\"#";

   if (alloc_type == 0)
    s << "dealloc_" << id << "\" class=\"alloc\" name=\"alloc_#" << id << "\">++</a></td>\n";
   else if (alloc_type == 1)
    s << "alloc_" << id << "\" class=\"dealloc\" name=\"dealloc_#" << id << "\">--</a></td>\n";
   else if (alloc_type == 2)
    s << "alloc_"  << id << "\" class=\"realloc\" name=\"realloc_#" << id << "\">+-</a></td>\n";


   s << "                <td class=\"ptr\">" << ptr << "</td>\n";
   s << "                <td class=\"size\">" << size << "</td>\n";
   s << "                <td class=\"type\">";

   if (type != 0)
    s << type << "</td>\n";
   else
    s << "<em>Unknown</em>" << "</td>\n";

   s << "                <td class=\"source\">";

   if (file != 0)
   {
    std::string file_str(file);
    size_t n = file_str.find_last_of('/');
    if (n != std::string::npos)
     s << file_str.substr(n) << ":<em>" << line << "</em></td>\n";
    else
     s << file << ":<em>" << line << "</em></td>\n";
   }
   else
    s << "<em>Unknown</em></td>\n";
   
   s << "            </tr>";
   
   std::string str(s.str());
   mStream.write(str.c_str(), str.length());
   mStream.flush();
  }

  inline void write_allocations_footer()
  {
   mStream << gc_debugger_allocations_end;
  }

  void write_leaks_header()
  {
  }

  void write_leak(unsigned int id, void* ptr, unsigned int size, const char* type, const char* file, unsigned int line)
  {
   
  }

  void write_leak_footer()
  {
  }
  
  bool                         mIsSimulating;
  unsigned int                 mNextID;
  std::ofstream                mStream;
  std::map<void*, Allocation>  mAllocations;
  
} gMemoryDebuggerImpl;


void gc_debugger_push_ptr(void* ptr, unsigned int size, const char* type, const char* file, unsigned int line)
{
 gMemoryDebuggerImpl.push(ptr, size, type, file, line);
}

void gc_debugger_pop_ptr(void* ptr, const char* file, unsigned int line)
{
 gMemoryDebuggerImpl.pop(ptr, file, line);
}

void gc_debugger_change_ptr(void* old_ptr, void*  new_ptr, unsigned int new_size, const char* file, unsigned int line)
{
 gMemoryDebuggerImpl.change(old_ptr, new_ptr, new_size, file, line);
}

void XkPublicFunction gc_debugger_first_frame()
{
 gMemoryDebuggerImpl.begin();
}

void XkPublicFunction gc_debugger_frame(unsigned int id, float time)
{
 gMemoryDebuggerImpl.timestep(id, time);
}

void XkPublicFunction gc_debugger_last_frame()
{
 gMemoryDebuggerImpl.end();
}

#endif

                                                                                       

} // GC

                                                                                       

} // namespace Xk

                                                                                       