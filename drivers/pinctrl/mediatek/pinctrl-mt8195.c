// SPDX-License-Identifier: GPL-2.0
/*
 * Copyright (C) 2020 MediaTek Inc.
 *
 * Author: Zhiyong Tao <zhiyong.tao@mediatek.com>
 *
 */

#include "pinctrl-mtk-mt8195.h"
#include "pinctrl-paris.h"

/* MT8195 have multiple bases to program pin configuration listed as the below:
 * iocfg[0]:0x10005000, iocfg[1]:0x11d10000, iocfg[2]:0x11d30000,
 * iocfg[3]:0x11d40000, iocfg[4]:0x11e20000, iocfg[5]:0x11eb0000,
 * iocfg[6]:0x11f40000.
 * _i_based could be used to indicate what base the pin should be mapped into.
 */

#define PIN_FIELD_BASE(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits) \
	PIN_FIELD_CALC(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits, \
		       32, 0)

#define PINS_FIELD_BASE(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits) \
	PIN_FIELD_CALC(s_pin, e_pin, i_base, s_addr, x_addrs, s_bit, x_bits,  \
		       32, 1)

static const struct mtk_pin_field_calc mt8195_pin_mode_range[] = {
	PIN_FIELD(0, 144, 0x300, 0x10, 0, 4),
};

static const struct mtk_pin_field_calc mt8195_pin_dir_range[] = {
	PIN_FIELD(0, 144, 0x0, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_di_range[] = {
	PIN_FIELD(0, 144, 0x200, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_do_range[] = {
	PIN_FIELD(0, 144, 0x100, 0x10, 0, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_ies_range[] = {
	PIN_FIELD_BASE(0, 0, 4, 0x040, 0x10, 0, 1),
	PIN_FIELD_BASE(1, 1, 4, 0x040, 0x10, 1, 1),
	PIN_FIELD_BASE(2, 2, 4, 0x040, 0x10, 2, 1),
	PIN_FIELD_BASE(3, 3, 4, 0x040, 0x10, 3, 1),
	PIN_FIELD_BASE(4, 4, 4, 0x040, 0x10, 4, 1),
	PIN_FIELD_BASE(5, 5, 4, 0x040, 0x10, 5, 1),
	PIN_FIELD_BASE(6, 6, 4, 0x040, 0x10, 6, 1),
	PIN_FIELD_BASE(7, 7, 4, 0x040, 0x10, 7, 1),
	PIN_FIELD_BASE(8, 8, 4, 0x040, 0x10, 13, 1),
	PIN_FIELD_BASE(9, 9, 4, 0x040, 0x10, 8, 1),
	PIN_FIELD_BASE(10, 10, 4, 0x040, 0x10, 14, 1),
	PIN_FIELD_BASE(11, 11, 4, 0x040, 0x10, 9, 1),
	PIN_FIELD_BASE(12, 12, 4, 0x040, 0x10, 15, 1),
	PIN_FIELD_BASE(13, 13, 4, 0x040, 0x10, 10, 1),
	PIN_FIELD_BASE(14, 14, 4, 0x040, 0x10, 16, 1),
	PIN_FIELD_BASE(15, 15, 4, 0x040, 0x10, 11, 1),
	PIN_FIELD_BASE(16, 16, 4, 0x040, 0x10, 17, 1),
	PIN_FIELD_BASE(17, 17, 4, 0x040, 0x10, 12, 1),
	PIN_FIELD_BASE(18, 18, 2, 0x040, 0x10, 5, 1),
	PIN_FIELD_BASE(19, 19, 2, 0x040, 0x10, 12, 1),
	PIN_FIELD_BASE(20, 20, 2, 0x040, 0x10, 11, 1),
	PIN_FIELD_BASE(21, 21, 2, 0x040, 0x10, 10, 1),
	PIN_FIELD_BASE(22, 22, 2, 0x040, 0x10, 0, 1),
	PIN_FIELD_BASE(23, 23, 2, 0x040, 0x10, 1, 1),
	PIN_FIELD_BASE(24, 24, 2, 0x040, 0x10, 2, 1),
	PIN_FIELD_BASE(25, 25, 2, 0x040, 0x10, 4, 1),
	PIN_FIELD_BASE(26, 26, 2, 0x040, 0x10, 3, 1),
	PIN_FIELD_BASE(27, 27, 2, 0x040, 0x10, 6, 1),
	PIN_FIELD_BASE(28, 28, 2, 0x040, 0x10, 7, 1),
	PIN_FIELD_BASE(29, 29, 2, 0x040, 0x10, 8, 1),
	PIN_FIELD_BASE(30, 30, 2, 0x040, 0x10, 9, 1),
	PIN_FIELD_BASE(31, 31, 1, 0x060, 0x10, 13, 1),
	PIN_FIELD_BASE(32, 32, 1, 0x060, 0x10, 12, 1),
	PIN_FIELD_BASE(33, 33, 1, 0x060, 0x10, 11, 1),
	PIN_FIELD_BASE(34, 34, 1, 0x060, 0x10, 14, 1),
	PIN_FIELD_BASE(35, 35, 1, 0x060, 0x10, 15, 1),
	PIN_FIELD_BASE(36, 36, 1, 0x070, 0x10, 3, 1),
	PIN_FIELD_BASE(37, 37, 1, 0x070, 0x10, 6, 1),
	PIN_FIELD_BASE(38, 38, 1, 0x070, 0x10, 4, 1),
	PIN_FIELD_BASE(39, 39, 1, 0x070, 0x10, 5, 1),
	PIN_FIELD_BASE(40, 40, 1, 0x070, 0x10, 8, 1),
	PIN_FIELD_BASE(41, 41, 1, 0x070, 0x10, 7, 1),
	PIN_FIELD_BASE(42, 42, 1, 0x070, 0x10, 10, 1),
	PIN_FIELD_BASE(43, 43, 1, 0x070, 0x10, 9, 1),
	PIN_FIELD_BASE(44, 44, 1, 0x070, 0x10, 20, 1),
	PIN_FIELD_BASE(45, 45, 1, 0x070, 0x10, 21, 1),
	PIN_FIELD_BASE(46, 46, 1, 0x060, 0x10, 18, 1),
	PIN_FIELD_BASE(47, 47, 1, 0x060, 0x10, 16, 1),
	PIN_FIELD_BASE(48, 48, 1, 0x060, 0x10, 19, 1),
	PIN_FIELD_BASE(49, 49, 1, 0x060, 0x10, 17, 1),
	PIN_FIELD_BASE(50, 50, 1, 0x060, 0x10, 25, 1),
	PIN_FIELD_BASE(51, 51, 1, 0x060, 0x10, 20, 1),
	PIN_FIELD_BASE(52, 52, 1, 0x060, 0x10, 26, 1),
	PIN_FIELD_BASE(53, 53, 1, 0x060, 0x10, 21, 1),
	PIN_FIELD_BASE(54, 54, 1, 0x060, 0x10, 22, 1),
	PIN_FIELD_BASE(55, 55, 1, 0x060, 0x10, 23, 1),
	PIN_FIELD_BASE(56, 56, 1, 0x060, 0x10, 24, 1),
	PIN_FIELD_BASE(57, 57, 1, 0x060, 0x10, 29, 1),
	PIN_FIELD_BASE(58, 58, 1, 0x060, 0x10, 27, 1),
	PIN_FIELD_BASE(59, 59, 1, 0x060, 0x10, 30, 1),
	PIN_FIELD_BASE(60, 60, 1, 0x060, 0x10, 28, 1),
	PIN_FIELD_BASE(61, 61, 1, 0x060, 0x10, 8, 1),
	PIN_FIELD_BASE(62, 62, 1, 0x060, 0x10, 7, 1),
	PIN_FIELD_BASE(63, 63, 1, 0x060, 0x10, 10, 1),
	PIN_FIELD_BASE(64, 64, 1, 0x060, 0x10, 9, 1),
	PIN_FIELD_BASE(65, 65, 1, 0x070, 0x10, 1, 1),
	PIN_FIELD_BASE(66, 66, 1, 0x060, 0x10, 31, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x070, 0x10, 0, 1),
	PIN_FIELD_BASE(68, 68, 1, 0x070, 0x10, 2, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x060, 0x10, 0, 1),
	PIN_FIELD_BASE(70, 70, 1, 0x060, 0x10, 6, 1),
	PIN_FIELD_BASE(71, 71, 1, 0x060, 0x10, 4, 1),
	PIN_FIELD_BASE(72, 72, 1, 0x060, 0x10, 5, 1),
	PIN_FIELD_BASE(73, 73, 1, 0x060, 0x10, 1, 1),
	PIN_FIELD_BASE(74, 74, 1, 0x060, 0x10, 2, 1),
	PIN_FIELD_BASE(75, 75, 1, 0x060, 0x10, 3, 1),
	PIN_FIELD_BASE(76, 76, 1, 0x070, 0x10, 11, 1),
	PIN_FIELD_BASE(77, 77, 3, 0x030, 0x10, 1, 1),
	PIN_FIELD_BASE(78, 78, 3, 0x030, 0x10, 2, 1),
	PIN_FIELD_BASE(79, 79, 3, 0x030, 0x10, 9, 1),
	PIN_FIELD_BASE(80, 80, 3, 0x030, 0x10, 10, 1),
	PIN_FIELD_BASE(81, 81, 3, 0x030, 0x10, 11, 1),
	PIN_FIELD_BASE(82, 82, 3, 0x030, 0x10, 12, 1),
	PIN_FIELD_BASE(83, 83, 3, 0x030, 0x10, 13, 1),
	PIN_FIELD_BASE(84, 84, 3, 0x030, 0x10, 14, 1),
	PIN_FIELD_BASE(85, 85, 3, 0x030, 0x10, 15, 1),
	PIN_FIELD_BASE(86, 86, 3, 0x030, 0x10, 16, 1),
	PIN_FIELD_BASE(87, 87, 3, 0x030, 0x10, 3, 1),
	PIN_FIELD_BASE(88, 88, 3, 0x030, 0x10, 4, 1),
	PIN_FIELD_BASE(89, 89, 3, 0x030, 0x10, 5, 1),
	PIN_FIELD_BASE(90, 90, 3, 0x030, 0x10, 6, 1),
	PIN_FIELD_BASE(91, 91, 3, 0x030, 0x10, 7, 1),
	PIN_FIELD_BASE(92, 92, 3, 0x030, 0x10, 8, 1),
	PIN_FIELD_BASE(93, 93, 3, 0x030, 0x10, 18, 1),
	PIN_FIELD_BASE(94, 94, 3, 0x030, 0x10, 19, 1),
	PIN_FIELD_BASE(95, 95, 3, 0x030, 0x10, 17, 1),
	PIN_FIELD_BASE(96, 96, 3, 0x030, 0x10, 0, 1),
	PIN_FIELD_BASE(97, 97, 3, 0x030, 0x10, 20, 1),
	PIN_FIELD_BASE(98, 98, 3, 0x030, 0x10, 28, 1),
	PIN_FIELD_BASE(99, 99, 3, 0x030, 0x10, 27, 1),
	PIN_FIELD_BASE(100, 100, 3, 0x030, 0x10, 30, 1),
	PIN_FIELD_BASE(101, 101, 3, 0x030, 0x10, 29, 1),
	PIN_FIELD_BASE(102, 102, 3, 0x040, 0x10, 0, 1),
	PIN_FIELD_BASE(103, 103, 3, 0x030, 0x10, 31, 1),
	PIN_FIELD_BASE(104, 104, 3, 0x030, 0x10, 25, 1),
	PIN_FIELD_BASE(105, 105, 3, 0x030, 0x10, 26, 1),
	PIN_FIELD_BASE(106, 106, 3, 0x030, 0x10, 23, 1),
	PIN_FIELD_BASE(107, 107, 3, 0x030, 0x10, 24, 1),
	PIN_FIELD_BASE(108, 108, 3, 0x030, 0x10, 22, 1),
	PIN_FIELD_BASE(109, 109, 3, 0x030, 0x10, 21, 1),
	PIN_FIELD_BASE(110, 110, 5, 0x010, 0x10, 1, 1),
	PIN_FIELD_BASE(111, 111, 5, 0x010, 0x10, 0, 1),
	PIN_FIELD_BASE(112, 112, 5, 0x010, 0x10, 2, 1),
	PIN_FIELD_BASE(113, 113, 5, 0x010, 0x10, 3, 1),
	PIN_FIELD_BASE(114, 114, 5, 0x010, 0x10, 4, 1),
	PIN_FIELD_BASE(115, 115, 5, 0x010, 0x10, 5, 1),
	PIN_FIELD_BASE(116, 116, 6, 0x030, 0x10, 9, 1),
	PIN_FIELD_BASE(117, 117, 6, 0x030, 0x10, 8, 1),
	PIN_FIELD_BASE(118, 118, 6, 0x030, 0x10, 7, 1),
	PIN_FIELD_BASE(119, 119, 6, 0x030, 0x10, 6, 1),
	PIN_FIELD_BASE(120, 120, 6, 0x030, 0x10, 11, 1),
	PIN_FIELD_BASE(121, 121, 6, 0x030, 0x10, 1, 1),
	PIN_FIELD_BASE(122, 122, 6, 0x030, 0x10, 0, 1),
	PIN_FIELD_BASE(123, 123, 6, 0x030, 0x10, 5, 1),
	PIN_FIELD_BASE(124, 124, 6, 0x030, 0x10, 4, 1),
	PIN_FIELD_BASE(125, 125, 6, 0x030, 0x10, 3, 1),
	PIN_FIELD_BASE(126, 126, 6, 0x030, 0x10, 2, 1),
	PIN_FIELD_BASE(127, 127, 6, 0x030, 0x10, 10, 1),
	PIN_FIELD_BASE(128, 128, 3, 0x040, 0x10, 3, 1),
	PIN_FIELD_BASE(129, 129, 3, 0x040, 0x10, 1, 1),
	PIN_FIELD_BASE(130, 130, 3, 0x040, 0x10, 4, 1),
	PIN_FIELD_BASE(131, 131, 3, 0x040, 0x10, 2, 1),
	PIN_FIELD_BASE(132, 132, 6, 0x030, 0x10, 13, 1),
	PIN_FIELD_BASE(133, 133, 6, 0x030, 0x10, 12, 1),
	PIN_FIELD_BASE(134, 134, 6, 0x030, 0x10, 15, 1),
	PIN_FIELD_BASE(135, 135, 6, 0x030, 0x10, 14, 1),
	PIN_FIELD_BASE(136, 136, 1, 0x070, 0x10, 13, 1),
	PIN_FIELD_BASE(137, 137, 1, 0x070, 0x10, 12, 1),
	PIN_FIELD_BASE(138, 138, 1, 0x070, 0x10, 15, 1),
	PIN_FIELD_BASE(139, 139, 1, 0x070, 0x10, 14, 1),
	PIN_FIELD_BASE(140, 140, 1, 0x070, 0x10, 17, 1),
	PIN_FIELD_BASE(141, 141, 1, 0x070, 0x10, 16, 1),
	PIN_FIELD_BASE(142, 142, 1, 0x070, 0x10, 19, 1),
	PIN_FIELD_BASE(143, 143, 1, 0x070, 0x10, 18, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_smt_range[] = {
	PIN_FIELD_BASE(0, 0, 4, 0x0d0, 0x10, 0, 1),
	PIN_FIELD_BASE(1, 1, 4, 0x0d0, 0x10, 1, 1),
	PIN_FIELD_BASE(2, 2, 4, 0x0d0, 0x10, 2, 1),
	PIN_FIELD_BASE(3, 3, 4, 0x0d0, 0x10, 3, 1),
	PIN_FIELD_BASE(4, 4, 4, 0x0d0, 0x10, 4, 1),
	PIN_FIELD_BASE(5, 5, 4, 0x0d0, 0x10, 5, 1),
	PINS_FIELD_BASE(6, 7, 4, 0x0d0, 0x10, 6, 1),
	PIN_FIELD_BASE(8, 8, 4, 0x0d0, 0x10, 12, 1),
	PIN_FIELD_BASE(9, 9, 4, 0x0d0, 0x10, 7, 1),
	PIN_FIELD_BASE(10, 10, 4, 0x0d0, 0x10, 13, 1),
	PIN_FIELD_BASE(11, 11, 4, 0x0d0, 0x10, 8, 1),
	PIN_FIELD_BASE(12, 12, 4, 0x0d0, 0x10, 14, 1),
	PIN_FIELD_BASE(13, 13, 4, 0x0d0, 0x10, 9, 1),
	PIN_FIELD_BASE(14, 14, 4, 0x0d0, 0x10, 15, 1),
	PIN_FIELD_BASE(15, 15, 4, 0x0d0, 0x10, 10, 1),
	PIN_FIELD_BASE(16, 16, 4, 0x0d0, 0x10, 16, 1),
	PIN_FIELD_BASE(17, 17, 4, 0x0d0, 0x10, 11, 1),
	PIN_FIELD_BASE(18, 18, 2, 0x090, 0x10, 11, 1),
	PIN_FIELD_BASE(19, 19, 2, 0x090, 0x10, 10, 1),
	PIN_FIELD_BASE(20, 20, 2, 0x090, 0x10, 9, 1),
	PIN_FIELD_BASE(21, 21, 2, 0x090, 0x10, 11, 1),
	PIN_FIELD_BASE(22, 22, 2, 0x090, 0x10, 0, 1),
	PIN_FIELD_BASE(23, 23, 2, 0x090, 0x10, 1, 1),
	PIN_FIELD_BASE(24, 24, 2, 0x090, 0x10, 2, 1),
	PIN_FIELD_BASE(25, 25, 2, 0x090, 0x10, 4, 1),
	PIN_FIELD_BASE(26, 26, 2, 0x090, 0x10, 3, 1),
	PIN_FIELD_BASE(27, 27, 2, 0x090, 0x10, 5, 1),
	PIN_FIELD_BASE(28, 28, 2, 0x090, 0x10, 6, 1),
	PIN_FIELD_BASE(29, 29, 2, 0x090, 0x10, 7, 1),
	PIN_FIELD_BASE(30, 30, 2, 0x090, 0x10, 8, 1),
	PINS_FIELD_BASE(31, 33, 1, 0x0f0, 0x10, 4, 1),
	PIN_FIELD_BASE(34, 34, 1, 0x0f0, 0x10, 0, 1),
	PIN_FIELD_BASE(35, 35, 1, 0x0f0, 0x10, 1, 1),
	PIN_FIELD_BASE(36, 36, 1, 0x0f0, 0x10, 4, 1),
	PIN_FIELD_BASE(37, 37, 1, 0x0f0, 0x10, 2, 1),
	PINS_FIELD_BASE(38, 39, 1, 0x0f0, 0x10, 5, 1),
	PIN_FIELD_BASE(40, 40, 1, 0x0f0, 0x10, 14, 1),
	PIN_FIELD_BASE(41, 41, 1, 0x0f0, 0x10, 13, 1),
	PIN_FIELD_BASE(42, 42, 1, 0x0f0, 0x10, 16, 1),
	PIN_FIELD_BASE(43, 43, 1, 0x0f0, 0x10, 15, 1),
	PIN_FIELD_BASE(44, 44, 1, 0x0f0, 0x10, 25, 1),
	PIN_FIELD_BASE(45, 45, 1, 0x0f0, 0x10, 26, 1),
	PINS_FIELD_BASE(46, 47, 1, 0x0f0, 0x10, 5, 1),
	PINS_FIELD_BASE(48, 51, 1, 0x0f0, 0x10, 6, 1),
	PINS_FIELD_BASE(52, 55, 1, 0x0f0, 0x10, 7, 1),
	PINS_FIELD_BASE(56, 59, 1, 0x0f0, 0x10, 8, 1),
	PINS_FIELD_BASE(60, 63, 1, 0x0f0, 0x10, 9, 1),
	PIN_FIELD_BASE(64, 64, 1, 0x0f0, 0x10, 10, 1),
	PINS_FIELD_BASE(65, 68, 1, 0x0f0, 0x10, 3, 1),
	PINS_FIELD_BASE(69, 71, 1, 0x0f0, 0x10, 10, 1),
	PINS_FIELD_BASE(72, 75, 1, 0x0f0, 0x10, 11, 1),
	PIN_FIELD_BASE(76, 76, 1, 0x0f0, 0x10, 12, 1),
	PIN_FIELD_BASE(77, 77, 3, 0x0e0, 0x10, 0, 1),
	PIN_FIELD_BASE(78, 78, 3, 0x0e0, 0x10, 1, 1),
	PIN_FIELD_BASE(79, 79, 3, 0x0e0, 0x10, 6, 1),
	PIN_FIELD_BASE(80, 80, 3, 0x0e0, 0x10, 7, 1),
	PIN_FIELD_BASE(81, 81, 3, 0x0e0, 0x10, 8, 1),
	PIN_FIELD_BASE(82, 82, 3, 0x0e0, 0x10, 9, 1),
	PIN_FIELD_BASE(83, 83, 3, 0x0e0, 0x10, 10, 1),
	PIN_FIELD_BASE(84, 84, 3, 0x0e0, 0x10, 11, 1),
	PINS_FIELD_BASE(85, 88, 3, 0x0e0, 0x10, 14, 1),
	PIN_FIELD_BASE(89, 89, 3, 0x0e0, 0x10, 2, 1),
	PIN_FIELD_BASE(90, 90, 3, 0x0e0, 0x10, 3, 1),
	PIN_FIELD_BASE(91, 91, 3, 0x0e0, 0x10, 4, 1),
	PIN_FIELD_BASE(92, 92, 3, 0x0e0, 0x10, 5, 1),
	PIN_FIELD_BASE(93, 93, 3, 0x0e0, 0x10, 12, 1),
	PIN_FIELD_BASE(94, 94, 3, 0x0e0, 0x10, 13, 1),
	PINS_FIELD_BASE(95, 98, 3, 0x0e0, 0x10, 15, 1),
	PINS_FIELD_BASE(99, 102, 3, 0x0e0, 0x10, 16, 1),
	PINS_FIELD_BASE(103, 104, 3, 0x0e0, 0x10, 17, 1),
	PIN_FIELD_BASE(105, 105, 3, 0x0e0, 0x10, 18, 1),
	PINS_FIELD_BASE(106, 107, 3, 0x0e0, 0x10, 17, 1),
	PINS_FIELD_BASE(108, 109, 3, 0x0e0, 0x10, 18, 1),
	PIN_FIELD_BASE(110, 110, 5, 0x070, 0x10, 1, 1),
	PIN_FIELD_BASE(111, 111, 5, 0x070, 0x10, 0, 1),
	PIN_FIELD_BASE(112, 112, 5, 0x070, 0x10, 2, 1),
	PIN_FIELD_BASE(113, 113, 5, 0x070, 0x10, 3, 1),
	PIN_FIELD_BASE(114, 114, 5, 0x070, 0x10, 4, 1),
	PIN_FIELD_BASE(115, 115, 5, 0x070, 0x10, 5, 1),
	PIN_FIELD_BASE(116, 116, 6, 0x0c0, 0x10, 9, 1),
	PIN_FIELD_BASE(117, 117, 6, 0x0c0, 0x10, 8, 1),
	PIN_FIELD_BASE(118, 118, 6, 0x0c0, 0x10, 7, 1),
	PIN_FIELD_BASE(119, 119, 6, 0x0c0, 0x10, 6, 1),
	PIN_FIELD_BASE(120, 120, 6, 0x0c0, 0x10, 11, 1),
	PIN_FIELD_BASE(121, 121, 6, 0x0c0, 0x10, 1, 1),
	PIN_FIELD_BASE(122, 122, 6, 0x0c0, 0x10, 0, 1),
	PIN_FIELD_BASE(123, 123, 6, 0x0c0, 0x10, 5, 1),
	PIN_FIELD_BASE(124, 124, 6, 0x0c0, 0x10, 4, 1),
	PIN_FIELD_BASE(125, 125, 6, 0x0c0, 0x10, 3, 1),
	PIN_FIELD_BASE(126, 126, 6, 0x0c0, 0x10, 2, 1),
	PIN_FIELD_BASE(127, 127, 6, 0x0c0, 0x10, 10, 1),
	PIN_FIELD_BASE(128, 128, 3, 0x0e0, 0x10, 18, 1),
	PINS_FIELD_BASE(129, 131, 3, 0x0e0, 0x10, 19, 1),
	PIN_FIELD_BASE(132, 132, 6, 0x0c0, 0x10, 13, 1),
	PIN_FIELD_BASE(133, 133, 6, 0x0c0, 0x10, 12, 1),
	PIN_FIELD_BASE(134, 134, 6, 0x0c0, 0x10, 15, 1),
	PIN_FIELD_BASE(135, 135, 6, 0x0c0, 0x10, 14, 1),
	PIN_FIELD_BASE(136, 136, 1, 0x0f0, 0x10, 18, 1),
	PIN_FIELD_BASE(137, 137, 1, 0x0f0, 0x10, 17, 1),
	PIN_FIELD_BASE(138, 138, 1, 0x0f0, 0x10, 20, 1),
	PIN_FIELD_BASE(139, 139, 1, 0x0f0, 0x10, 19, 1),
	PIN_FIELD_BASE(140, 140, 1, 0x0f0, 0x10, 22, 1),
	PIN_FIELD_BASE(141, 141, 1, 0x0f0, 0x10, 21, 1),
	PIN_FIELD_BASE(142, 142, 1, 0x0f0, 0x10, 24, 1),
	PIN_FIELD_BASE(143, 143, 1, 0x0f0, 0x10, 23, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_pu_range[] = {
	PIN_FIELD_BASE(6, 6, 4, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(7, 7, 4, 0x0070, 0x10, 1, 1),
	PIN_FIELD_BASE(8, 8, 4, 0x0070, 0x10, 7, 1),
	PIN_FIELD_BASE(9, 9, 4, 0x0070, 0x10, 2, 1),
	PIN_FIELD_BASE(10, 10, 4, 0x0070, 0x10, 8, 1),
	PIN_FIELD_BASE(11, 11, 4, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(12, 12, 4, 0x0070, 0x10, 9, 1),
	PIN_FIELD_BASE(13, 13, 4, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(14, 14, 4, 0x0070, 0x10, 10, 1),
	PIN_FIELD_BASE(15, 15, 4, 0x0070, 0x10, 5, 1),
	PIN_FIELD_BASE(16, 16, 4, 0x0070, 0x10, 11, 1),
	PIN_FIELD_BASE(17, 17, 4, 0x0070, 0x10, 6, 1),
	PIN_FIELD_BASE(18, 18, 2, 0x0060, 0x10, 5, 1),
	PIN_FIELD_BASE(19, 19, 2, 0x0060, 0x10, 12, 1),
	PIN_FIELD_BASE(20, 20, 2, 0x0060, 0x10, 11, 1),
	PIN_FIELD_BASE(21, 21, 2, 0x0060, 0x10, 10, 1),
	PIN_FIELD_BASE(22, 22, 2, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(23, 23, 2, 0x0060, 0x10, 1, 1),
	PIN_FIELD_BASE(24, 24, 2, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(25, 25, 2, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(26, 26, 2, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(27, 27, 2, 0x0060, 0x10, 6, 1),
	PIN_FIELD_BASE(28, 28, 2, 0x0060, 0x10, 7, 1),
	PIN_FIELD_BASE(29, 29, 2, 0x0060, 0x10, 8, 1),
	PIN_FIELD_BASE(30, 30, 2, 0x0060, 0x10, 9, 1),
	PIN_FIELD_BASE(31, 31, 1, 0x00a0, 0x10, 13, 1),
	PIN_FIELD_BASE(32, 32, 1, 0x00a0, 0x10, 12, 1),
	PIN_FIELD_BASE(33, 33, 1, 0x00a0, 0x10, 11, 1),
	PIN_FIELD_BASE(34, 34, 1, 0x00a0, 0x10, 14, 1),
	PIN_FIELD_BASE(35, 35, 1, 0x00a0, 0x10, 15, 1),
	PIN_FIELD_BASE(36, 36, 1, 0x00b0, 0x10, 3, 1),
	PIN_FIELD_BASE(37, 37, 1, 0x00b0, 0x10, 6, 1),
	PIN_FIELD_BASE(38, 38, 1, 0x00b0, 0x10, 4, 1),
	PIN_FIELD_BASE(39, 39, 1, 0x00b0, 0x10, 5, 1),
	PIN_FIELD_BASE(40, 40, 1, 0x00b0, 0x10, 8, 1),
	PIN_FIELD_BASE(41, 41, 1, 0x00b0, 0x10, 7, 1),
	PIN_FIELD_BASE(42, 42, 1, 0x00b0, 0x10, 10, 1),
	PIN_FIELD_BASE(43, 43, 1, 0x00b0, 0x10, 9, 1),
	PIN_FIELD_BASE(44, 44, 1, 0x00b0, 0x10, 21, 1),
	PIN_FIELD_BASE(45, 45, 1, 0x00b0, 0x10, 22, 1),
	PIN_FIELD_BASE(46, 46, 1, 0x00a0, 0x10, 18, 1),
	PIN_FIELD_BASE(47, 47, 1, 0x00a0, 0x10, 16, 1),
	PIN_FIELD_BASE(48, 48, 1, 0x00a0, 0x10, 19, 1),
	PIN_FIELD_BASE(49, 49, 1, 0x00a0, 0x10, 17, 1),
	PIN_FIELD_BASE(50, 50, 1, 0x00a0, 0x10, 25, 1),
	PIN_FIELD_BASE(51, 51, 1, 0x00a0, 0x10, 20, 1),
	PIN_FIELD_BASE(52, 52, 1, 0x00a0, 0x10, 26, 1),
	PIN_FIELD_BASE(53, 53, 1, 0x00a0, 0x10, 21, 1),
	PIN_FIELD_BASE(54, 54, 1, 0x00a0, 0x10, 22, 1),
	PIN_FIELD_BASE(55, 55, 1, 0x00a0, 0x10, 23, 1),
	PIN_FIELD_BASE(56, 56, 1, 0x00a0, 0x10, 24, 1),
	PIN_FIELD_BASE(57, 57, 1, 0x00a0, 0x10, 29, 1),
	PIN_FIELD_BASE(58, 58, 1, 0x00a0, 0x10, 27, 1),
	PIN_FIELD_BASE(59, 59, 1, 0x00a0, 0x10, 30, 1),
	PIN_FIELD_BASE(60, 60, 1, 0x00a0, 0x10, 28, 1),
	PIN_FIELD_BASE(61, 61, 1, 0x00a0, 0x10, 8, 1),
	PIN_FIELD_BASE(62, 62, 1, 0x00a0, 0x10, 7, 1),
	PIN_FIELD_BASE(63, 63, 1, 0x00a0, 0x10, 10, 1),
	PIN_FIELD_BASE(64, 64, 1, 0x00a0, 0x10, 9, 1),
	PIN_FIELD_BASE(65, 65, 1, 0x00b0, 0x10, 1, 1),
	PIN_FIELD_BASE(66, 66, 1, 0x00a0, 0x10, 31, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x00b0, 0x10, 0, 1),
	PIN_FIELD_BASE(68, 68, 1, 0x00b0, 0x10, 2, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x00a0, 0x10, 0, 1),
	PIN_FIELD_BASE(70, 70, 1, 0x00a0, 0x10, 6, 1),
	PIN_FIELD_BASE(71, 71, 1, 0x00a0, 0x10, 4, 1),
	PIN_FIELD_BASE(72, 72, 1, 0x00a0, 0x10, 5, 1),
	PIN_FIELD_BASE(73, 73, 1, 0x00a0, 0x10, 1, 1),
	PIN_FIELD_BASE(74, 74, 1, 0x00a0, 0x10, 2, 1),
	PIN_FIELD_BASE(75, 75, 1, 0x00a0, 0x10, 3, 1),
	PIN_FIELD_BASE(76, 76, 1, 0x00b0, 0x10, 11, 1),
	PIN_FIELD_BASE(97, 97, 3, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(98, 98, 3, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(99, 99, 3, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(100, 100, 3, 0x0070, 0x10, 6, 1),
	PIN_FIELD_BASE(101, 101, 3, 0x0070, 0x10, 5, 1),
	PIN_FIELD_BASE(102, 102, 3, 0x0070, 0x10, 8, 1),
	PIN_FIELD_BASE(103, 103, 3, 0x0070, 0x10, 7, 1),
	PIN_FIELD_BASE(108, 108, 3, 0x0070, 0x10, 2, 1),
	PIN_FIELD_BASE(109, 109, 3, 0x0070, 0x10, 1, 1),
	PIN_FIELD_BASE(128, 128, 3, 0x0070, 0x10, 11, 1),
	PIN_FIELD_BASE(129, 129, 3, 0x0070, 0x10, 9, 1),
	PIN_FIELD_BASE(130, 130, 3, 0x0070, 0x10, 12, 1),
	PIN_FIELD_BASE(131, 131, 3, 0x0070, 0x10, 10, 1),
	PIN_FIELD_BASE(132, 132, 6, 0x0060, 0x10, 1, 1),
	PIN_FIELD_BASE(133, 133, 6, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(134, 134, 6, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(135, 135, 6, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(136, 136, 1, 0x00b0, 0x10, 14, 1),
	PIN_FIELD_BASE(137, 137, 1, 0x00b0, 0x10, 13, 1),
	PIN_FIELD_BASE(138, 138, 1, 0x00b0, 0x10, 16, 1),
	PIN_FIELD_BASE(139, 139, 1, 0x00b0, 0x10, 15, 1),
	PIN_FIELD_BASE(140, 140, 1, 0x00b0, 0x10, 18, 1),
	PIN_FIELD_BASE(141, 141, 1, 0x00b0, 0x10, 17, 1),
	PIN_FIELD_BASE(142, 142, 1, 0x00b0, 0x10, 20, 1),
	PIN_FIELD_BASE(143, 143, 1, 0x00b0, 0x10, 19, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_pd_range[] = {
	PIN_FIELD_BASE(6, 6, 4, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(7, 7, 4, 0x0050, 0x10, 1, 1),
	PIN_FIELD_BASE(8, 8, 4, 0x0050, 0x10, 7, 1),
	PIN_FIELD_BASE(9, 9, 4, 0x0050, 0x10, 2, 1),
	PIN_FIELD_BASE(10, 10, 4, 0x0050, 0x10, 8, 1),
	PIN_FIELD_BASE(11, 11, 4, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(12, 12, 4, 0x0050, 0x10, 9, 1),
	PIN_FIELD_BASE(13, 13, 4, 0x0050, 0x10, 4, 1),
	PIN_FIELD_BASE(14, 14, 4, 0x0050, 0x10, 10, 1),
	PIN_FIELD_BASE(15, 15, 4, 0x0050, 0x10, 5, 1),
	PIN_FIELD_BASE(16, 16, 4, 0x0050, 0x10, 11, 1),
	PIN_FIELD_BASE(17, 17, 4, 0x0050, 0x10, 6, 1),
	PIN_FIELD_BASE(18, 18, 2, 0x0050, 0x10, 5, 1),
	PIN_FIELD_BASE(19, 19, 2, 0x0050, 0x10, 12, 1),
	PIN_FIELD_BASE(20, 20, 2, 0x0050, 0x10, 11, 1),
	PIN_FIELD_BASE(21, 21, 2, 0x0050, 0x10, 10, 1),
	PIN_FIELD_BASE(22, 22, 2, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(23, 23, 2, 0x0050, 0x10, 1, 1),
	PIN_FIELD_BASE(24, 24, 2, 0x0050, 0x10, 2, 1),
	PIN_FIELD_BASE(25, 25, 2, 0x0050, 0x10, 4, 1),
	PIN_FIELD_BASE(26, 26, 2, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(27, 27, 2, 0x0050, 0x10, 6, 1),
	PIN_FIELD_BASE(28, 28, 2, 0x0050, 0x10, 7, 1),
	PIN_FIELD_BASE(29, 29, 2, 0x0050, 0x10, 8, 1),
	PIN_FIELD_BASE(30, 30, 2, 0x0050, 0x10, 9, 1),
	PIN_FIELD_BASE(31, 31, 1, 0x0080, 0x10, 13, 1),
	PIN_FIELD_BASE(32, 32, 1, 0x0080, 0x10, 12, 1),
	PIN_FIELD_BASE(33, 33, 1, 0x0080, 0x10, 11, 1),
	PIN_FIELD_BASE(34, 34, 1, 0x0080, 0x10, 14, 1),
	PIN_FIELD_BASE(35, 35, 1, 0x0080, 0x10, 15, 1),
	PIN_FIELD_BASE(36, 36, 1, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(37, 37, 1, 0x0090, 0x10, 6, 1),
	PIN_FIELD_BASE(38, 38, 1, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(39, 39, 1, 0x0090, 0x10, 5, 1),
	PIN_FIELD_BASE(40, 40, 1, 0x0090, 0x10, 8, 1),
	PIN_FIELD_BASE(41, 41, 1, 0x0090, 0x10, 7, 1),
	PIN_FIELD_BASE(42, 42, 1, 0x0090, 0x10, 10, 1),
	PIN_FIELD_BASE(43, 43, 1, 0x0090, 0x10, 9, 1),
	PIN_FIELD_BASE(44, 44, 1, 0x0090, 0x10, 21, 1),
	PIN_FIELD_BASE(45, 45, 1, 0x0090, 0x10, 22, 1),
	PIN_FIELD_BASE(46, 46, 1, 0x0080, 0x10, 18, 1),
	PIN_FIELD_BASE(47, 47, 1, 0x0080, 0x10, 16, 1),
	PIN_FIELD_BASE(48, 48, 1, 0x0080, 0x10, 19, 1),
	PIN_FIELD_BASE(49, 49, 1, 0x0080, 0x10, 17, 1),
	PIN_FIELD_BASE(50, 50, 1, 0x0080, 0x10, 25, 1),
	PIN_FIELD_BASE(51, 51, 1, 0x0080, 0x10, 20, 1),
	PIN_FIELD_BASE(52, 52, 1, 0x0080, 0x10, 26, 1),
	PIN_FIELD_BASE(53, 53, 1, 0x0080, 0x10, 21, 1),
	PIN_FIELD_BASE(54, 54, 1, 0x0080, 0x10, 22, 1),
	PIN_FIELD_BASE(55, 55, 1, 0x0080, 0x10, 23, 1),
	PIN_FIELD_BASE(56, 56, 1, 0x0080, 0x10, 24, 1),
	PIN_FIELD_BASE(57, 57, 1, 0x0080, 0x10, 29, 1),
	PIN_FIELD_BASE(58, 58, 1, 0x0080, 0x10, 27, 1),
	PIN_FIELD_BASE(59, 59, 1, 0x0080, 0x10, 30, 1),
	PIN_FIELD_BASE(60, 60, 1, 0x0080, 0x10, 28, 1),
	PIN_FIELD_BASE(61, 61, 1, 0x0080, 0x10, 8, 1),
	PIN_FIELD_BASE(62, 62, 1, 0x0080, 0x10, 7, 1),
	PIN_FIELD_BASE(63, 63, 1, 0x0080, 0x10, 10, 1),
	PIN_FIELD_BASE(64, 64, 1, 0x0080, 0x10, 9, 1),
	PIN_FIELD_BASE(65, 65, 1, 0x0090, 0x10, 1, 1),
	PIN_FIELD_BASE(66, 66, 1, 0x0080, 0x10, 31, 1),
	PIN_FIELD_BASE(67, 67, 1, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(68, 68, 1, 0x0090, 0x10, 2, 1),
	PIN_FIELD_BASE(69, 69, 1, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(70, 70, 1, 0x0080, 0x10, 6, 1),
	PIN_FIELD_BASE(71, 71, 1, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(72, 72, 1, 0x0080, 0x10, 5, 1),
	PIN_FIELD_BASE(73, 73, 1, 0x0080, 0x10, 1, 1),
	PIN_FIELD_BASE(74, 74, 1, 0x0080, 0x10, 2, 1),
	PIN_FIELD_BASE(75, 75, 1, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(76, 76, 1, 0x0090, 0x10, 11, 1),
	PIN_FIELD_BASE(97, 97, 3, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(98, 98, 3, 0x0050, 0x10, 4, 1),
	PIN_FIELD_BASE(99, 99, 3, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(100, 100, 3, 0x0050, 0x10, 6, 1),
	PIN_FIELD_BASE(101, 101, 3, 0x0050, 0x10, 5, 1),
	PIN_FIELD_BASE(102, 102, 3, 0x0050, 0x10, 8, 1),
	PIN_FIELD_BASE(103, 103, 3, 0x0050, 0x10, 7, 1),
	PIN_FIELD_BASE(108, 108, 3, 0x0050, 0x10, 2, 1),
	PIN_FIELD_BASE(109, 109, 3, 0x0050, 0x10, 1, 1),
	PIN_FIELD_BASE(128, 128, 3, 0x0050, 0x10, 11, 1),
	PIN_FIELD_BASE(129, 129, 3, 0x0050, 0x10, 9, 1),
	PIN_FIELD_BASE(130, 130, 3, 0x0050, 0x10, 12, 1),
	PIN_FIELD_BASE(131, 131, 3, 0x0050, 0x10, 10, 1),
	PIN_FIELD_BASE(132, 132, 6, 0x0040, 0x10, 1, 1),
	PIN_FIELD_BASE(133, 133, 6, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(134, 134, 6, 0x0040, 0x10, 3, 1),
	PIN_FIELD_BASE(135, 135, 6, 0x0040, 0x10, 2, 1),
	PIN_FIELD_BASE(136, 136, 1, 0x0090, 0x10, 14, 1),
	PIN_FIELD_BASE(137, 137, 1, 0x0090, 0x10, 13, 1),
	PIN_FIELD_BASE(138, 138, 1, 0x0090, 0x10, 16, 1),
	PIN_FIELD_BASE(139, 139, 1, 0x0090, 0x10, 15, 1),
	PIN_FIELD_BASE(140, 140, 1, 0x0090, 0x10, 18, 1),
	PIN_FIELD_BASE(141, 141, 1, 0x0090, 0x10, 17, 1),
	PIN_FIELD_BASE(142, 142, 1, 0x0090, 0x10, 20, 1),
	PIN_FIELD_BASE(143, 143, 1, 0x0090, 0x10, 19, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_pupd_range[] = {
	PIN_FIELD_BASE(0, 0, 4, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(1, 1, 4, 0x0060, 0x10, 1, 1),
	PIN_FIELD_BASE(2, 2, 4, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(3, 3, 4, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(4, 4, 4, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(5, 5, 4, 0x0060, 0x10, 5, 1),
	PIN_FIELD_BASE(77, 77, 3, 0x0060, 0x10, 1, 1),
	PIN_FIELD_BASE(78, 78, 3, 0x0060, 0x10, 2, 1),
	PIN_FIELD_BASE(79, 79, 3, 0x0060, 0x10, 9, 1),
	PIN_FIELD_BASE(80, 80, 3, 0x0060, 0x10, 10, 1),
	PIN_FIELD_BASE(81, 81, 3, 0x0060, 0x10, 11, 1),
	PIN_FIELD_BASE(82, 82, 3, 0x0060, 0x10, 12, 1),
	PIN_FIELD_BASE(83, 83, 3, 0x0060, 0x10, 13, 1),
	PIN_FIELD_BASE(84, 84, 3, 0x0060, 0x10, 14, 1),
	PIN_FIELD_BASE(85, 85, 3, 0x0060, 0x10, 15, 1),
	PIN_FIELD_BASE(86, 86, 3, 0x0060, 0x10, 16, 1),
	PIN_FIELD_BASE(87, 87, 3, 0x0060, 0x10, 3, 1),
	PIN_FIELD_BASE(88, 88, 3, 0x0060, 0x10, 4, 1),
	PIN_FIELD_BASE(89, 89, 3, 0x0060, 0x10, 5, 1),
	PIN_FIELD_BASE(90, 90, 3, 0x0060, 0x10, 6, 1),
	PIN_FIELD_BASE(91, 91, 3, 0x0060, 0x10, 7, 1),
	PIN_FIELD_BASE(92, 92, 3, 0x0060, 0x10, 8, 1),
	PIN_FIELD_BASE(93, 93, 3, 0x0060, 0x10, 18, 1),
	PIN_FIELD_BASE(94, 94, 3, 0x0060, 0x10, 19, 1),
	PIN_FIELD_BASE(95, 95, 3, 0x0060, 0x10, 17, 1),
	PIN_FIELD_BASE(96, 96, 3, 0x0060, 0x10, 0, 1),
	PIN_FIELD_BASE(104, 104, 3, 0x0060, 0x10, 22, 1),
	PIN_FIELD_BASE(105, 105, 3, 0x0060, 0x10, 23, 1),
	PIN_FIELD_BASE(106, 106, 3, 0x0060, 0x10, 20, 1),
	PIN_FIELD_BASE(107, 107, 3, 0x0060, 0x10, 21, 1),
	PIN_FIELD_BASE(110, 110, 5, 0x0020, 0x10, 1, 1),
	PIN_FIELD_BASE(111, 111, 5, 0x0020, 0x10, 0, 1),
	PIN_FIELD_BASE(112, 112, 5, 0x0020, 0x10, 2, 1),
	PIN_FIELD_BASE(113, 113, 5, 0x0020, 0x10, 3, 1),
	PIN_FIELD_BASE(114, 114, 5, 0x0020, 0x10, 4, 1),
	PIN_FIELD_BASE(115, 115, 5, 0x0020, 0x10, 5, 1),
	PIN_FIELD_BASE(116, 116, 6, 0x0050, 0x10, 9, 1),
	PIN_FIELD_BASE(117, 117, 6, 0x0050, 0x10, 8, 1),
	PIN_FIELD_BASE(118, 118, 6, 0x0050, 0x10, 7, 1),
	PIN_FIELD_BASE(119, 119, 6, 0x0050, 0x10, 6, 1),
	PIN_FIELD_BASE(120, 120, 6, 0x0050, 0x10, 11, 1),
	PIN_FIELD_BASE(121, 121, 6, 0x0050, 0x10, 1, 1),
	PIN_FIELD_BASE(122, 122, 6, 0x0050, 0x10, 0, 1),
	PIN_FIELD_BASE(123, 123, 6, 0x0050, 0x10, 5, 1),
	PIN_FIELD_BASE(124, 124, 6, 0x0050, 0x10, 4, 1),
	PIN_FIELD_BASE(125, 125, 6, 0x0050, 0x10, 3, 1),
	PIN_FIELD_BASE(126, 126, 6, 0x0050, 0x10, 2, 1),
	PIN_FIELD_BASE(127, 127, 6, 0x0050, 0x10, 10, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_r0_range[] = {
	PIN_FIELD_BASE(0, 0, 4, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(1, 1, 4, 0x0080, 0x10, 1, 1),
	PIN_FIELD_BASE(2, 2, 4, 0x0080, 0x10, 2, 1),
	PIN_FIELD_BASE(3, 3, 4, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(4, 4, 4, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(5, 5, 4, 0x0080, 0x10, 5, 1),
	PIN_FIELD_BASE(77, 77, 3, 0x0080, 0x10, 1, 1),
	PIN_FIELD_BASE(78, 78, 3, 0x0080, 0x10, 2, 1),
	PIN_FIELD_BASE(79, 79, 3, 0x0080, 0x10, 9, 1),
	PIN_FIELD_BASE(80, 80, 3, 0x0080, 0x10, 10, 1),
	PIN_FIELD_BASE(81, 81, 3, 0x0080, 0x10, 11, 1),
	PIN_FIELD_BASE(82, 82, 3, 0x0080, 0x10, 12, 1),
	PIN_FIELD_BASE(83, 83, 3, 0x0080, 0x10, 13, 1),
	PIN_FIELD_BASE(84, 84, 3, 0x0080, 0x10, 14, 1),
	PIN_FIELD_BASE(85, 85, 3, 0x0080, 0x10, 15, 1),
	PIN_FIELD_BASE(86, 86, 3, 0x0080, 0x10, 16, 1),
	PIN_FIELD_BASE(87, 87, 3, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(88, 88, 3, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(89, 89, 3, 0x0080, 0x10, 5, 1),
	PIN_FIELD_BASE(90, 90, 3, 0x0080, 0x10, 6, 1),
	PIN_FIELD_BASE(91, 91, 3, 0x0080, 0x10, 7, 1),
	PIN_FIELD_BASE(92, 92, 3, 0x0080, 0x10, 8, 1),
	PIN_FIELD_BASE(93, 93, 3, 0x0080, 0x10, 18, 1),
	PIN_FIELD_BASE(94, 94, 3, 0x0080, 0x10, 19, 1),
	PIN_FIELD_BASE(95, 95, 3, 0x0080, 0x10, 17, 1),
	PIN_FIELD_BASE(96, 96, 3, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(104, 104, 3, 0x0080, 0x10, 22, 1),
	PIN_FIELD_BASE(105, 105, 3, 0x0080, 0x10, 23, 1),
	PIN_FIELD_BASE(106, 106, 3, 0x0080, 0x10, 20, 1),
	PIN_FIELD_BASE(107, 107, 3, 0x0080, 0x10, 21, 1),
	PIN_FIELD_BASE(110, 110, 5, 0x0030, 0x10, 1, 1),
	PIN_FIELD_BASE(111, 111, 5, 0x0030, 0x10, 0, 1),
	PIN_FIELD_BASE(112, 112, 5, 0x0030, 0x10, 2, 1),
	PIN_FIELD_BASE(113, 113, 5, 0x0030, 0x10, 3, 1),
	PIN_FIELD_BASE(114, 114, 5, 0x0030, 0x10, 4, 1),
	PIN_FIELD_BASE(115, 115, 5, 0x0030, 0x10, 5, 1),
	PIN_FIELD_BASE(116, 116, 6, 0x0070, 0x10, 9, 1),
	PIN_FIELD_BASE(117, 117, 6, 0x0070, 0x10, 8, 1),
	PIN_FIELD_BASE(118, 118, 6, 0x0070, 0x10, 7, 1),
	PIN_FIELD_BASE(119, 119, 6, 0x0070, 0x10, 6, 1),
	PIN_FIELD_BASE(120, 120, 6, 0x0070, 0x10, 11, 1),
	PIN_FIELD_BASE(121, 121, 6, 0x0070, 0x10, 1, 1),
	PIN_FIELD_BASE(122, 122, 6, 0x0070, 0x10, 0, 1),
	PIN_FIELD_BASE(123, 123, 6, 0x0070, 0x10, 5, 1),
	PIN_FIELD_BASE(124, 124, 6, 0x0070, 0x10, 4, 1),
	PIN_FIELD_BASE(125, 125, 6, 0x0070, 0x10, 3, 1),
	PIN_FIELD_BASE(126, 126, 6, 0x0070, 0x10, 2, 1),
	PIN_FIELD_BASE(127, 127, 6, 0x0070, 0x10, 10, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_r1_range[] = {
	PIN_FIELD_BASE(0, 0, 4, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(1, 1, 4, 0x0090, 0x10, 1, 1),
	PIN_FIELD_BASE(2, 2, 4, 0x0090, 0x10, 2, 1),
	PIN_FIELD_BASE(3, 3, 4, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(4, 4, 4, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(5, 5, 4, 0x0090, 0x10, 5, 1),
	PIN_FIELD_BASE(77, 77, 3, 0x0090, 0x10, 1, 1),
	PIN_FIELD_BASE(78, 78, 3, 0x0090, 0x10, 2, 1),
	PIN_FIELD_BASE(79, 79, 3, 0x0090, 0x10, 9, 1),
	PIN_FIELD_BASE(80, 80, 3, 0x0090, 0x10, 10, 1),
	PIN_FIELD_BASE(81, 81, 3, 0x0090, 0x10, 11, 1),
	PIN_FIELD_BASE(82, 82, 3, 0x0090, 0x10, 12, 1),
	PIN_FIELD_BASE(83, 83, 3, 0x0090, 0x10, 13, 1),
	PIN_FIELD_BASE(84, 84, 3, 0x0090, 0x10, 14, 1),
	PIN_FIELD_BASE(85, 85, 3, 0x0090, 0x10, 15, 1),
	PIN_FIELD_BASE(86, 86, 3, 0x0090, 0x10, 16, 1),
	PIN_FIELD_BASE(87, 87, 3, 0x0090, 0x10, 3, 1),
	PIN_FIELD_BASE(88, 88, 3, 0x0090, 0x10, 4, 1),
	PIN_FIELD_BASE(89, 89, 3, 0x0090, 0x10, 5, 1),
	PIN_FIELD_BASE(90, 90, 3, 0x0090, 0x10, 6, 1),
	PIN_FIELD_BASE(91, 91, 3, 0x0090, 0x10, 7, 1),
	PIN_FIELD_BASE(92, 92, 3, 0x0090, 0x10, 8, 1),
	PIN_FIELD_BASE(93, 93, 3, 0x0090, 0x10, 18, 1),
	PIN_FIELD_BASE(94, 94, 3, 0x0090, 0x10, 19, 1),
	PIN_FIELD_BASE(95, 95, 3, 0x0090, 0x10, 17, 1),
	PIN_FIELD_BASE(96, 96, 3, 0x0090, 0x10, 0, 1),
	PIN_FIELD_BASE(104, 104, 3, 0x0090, 0x10, 22, 1),
	PIN_FIELD_BASE(105, 105, 3, 0x0090, 0x10, 23, 1),
	PIN_FIELD_BASE(106, 106, 3, 0x0090, 0x10, 20, 1),
	PIN_FIELD_BASE(107, 107, 3, 0x0090, 0x10, 21, 1),
	PIN_FIELD_BASE(110, 110, 5, 0x0040, 0x10, 1, 1),
	PIN_FIELD_BASE(111, 111, 5, 0x0040, 0x10, 0, 1),
	PIN_FIELD_BASE(112, 112, 5, 0x0040, 0x10, 2, 1),
	PIN_FIELD_BASE(113, 113, 5, 0x0040, 0x10, 3, 1),
	PIN_FIELD_BASE(114, 114, 5, 0x0040, 0x10, 4, 1),
	PIN_FIELD_BASE(115, 115, 5, 0x0040, 0x10, 5, 1),
	PIN_FIELD_BASE(116, 116, 6, 0x0080, 0x10, 9, 1),
	PIN_FIELD_BASE(117, 117, 6, 0x0080, 0x10, 8, 1),
	PIN_FIELD_BASE(118, 118, 6, 0x0080, 0x10, 7, 1),
	PIN_FIELD_BASE(119, 119, 6, 0x0080, 0x10, 6, 1),
	PIN_FIELD_BASE(120, 120, 6, 0x0080, 0x10, 11, 1),
	PIN_FIELD_BASE(121, 121, 6, 0x0080, 0x10, 1, 1),
	PIN_FIELD_BASE(122, 122, 6, 0x0080, 0x10, 0, 1),
	PIN_FIELD_BASE(123, 123, 6, 0x0080, 0x10, 5, 1),
	PIN_FIELD_BASE(124, 124, 6, 0x0080, 0x10, 4, 1),
	PIN_FIELD_BASE(125, 125, 6, 0x0080, 0x10, 3, 1),
	PIN_FIELD_BASE(126, 126, 6, 0x0080, 0x10, 2, 1),
	PIN_FIELD_BASE(127, 127, 6, 0x0080, 0x10, 10, 1),
};

static const struct mtk_pin_field_calc mt8195_pin_drv_range[] = {
	PIN_FIELD_BASE(0, 0, 4, 0x000, 0x10, 0, 3),
	PIN_FIELD_BASE(1, 1, 4, 0x000, 0x10, 3, 3),
	PIN_FIELD_BASE(2, 2, 4, 0x000, 0x10, 6, 3),
	PIN_FIELD_BASE(3, 3, 4, 0x000, 0x10, 9, 3),
	PIN_FIELD_BASE(4, 4, 4, 0x000, 0x10, 12, 3),
	PIN_FIELD_BASE(5, 5, 4, 0x000, 0x10, 15, 3),
	PINS_FIELD_BASE(6, 7, 4, 0x000, 0x10, 18, 3),
	PIN_FIELD_BASE(8, 8, 4, 0x010, 0x10, 6, 3),
	PIN_FIELD_BASE(9, 9, 4, 0x000, 0x10, 21, 3),
	PIN_FIELD_BASE(10, 10, 4, 0x010, 0x10, 9, 3),
	PIN_FIELD_BASE(11, 11, 4, 0x000, 0x10, 24, 3),
	PIN_FIELD_BASE(12, 12, 4, 0x010, 0x10, 12, 3),
	PIN_FIELD_BASE(13, 13, 4, 0x000, 0x10, 27, 3),
	PIN_FIELD_BASE(14, 14, 4, 0x010, 0x10, 15, 3),
	PIN_FIELD_BASE(15, 15, 4, 0x010, 0x10, 0, 3),
	PIN_FIELD_BASE(16, 16, 4, 0x010, 0x10, 18, 3),
	PIN_FIELD_BASE(17, 17, 4, 0x010, 0x10, 3, 3),
	PIN_FIELD_BASE(18, 18, 2, 0x010, 0x10, 6, 3),
	PIN_FIELD_BASE(19, 19, 2, 0x010, 0x10, 3, 3),
	PIN_FIELD_BASE(20, 20, 2, 0x010, 0x10, 0, 3),
	PIN_FIELD_BASE(21, 21, 2, 0x000, 0x10, 27, 3),
	PIN_FIELD_BASE(22, 22, 2, 0x000, 0x10, 0, 3),
	PIN_FIELD_BASE(23, 23, 2, 0x000, 0x10, 3, 3),
	PIN_FIELD_BASE(24, 24, 2, 0x000, 0x10, 6, 3),
	PIN_FIELD_BASE(25, 25, 2, 0x000, 0x10, 12, 3),
	PIN_FIELD_BASE(26, 26, 2, 0x000, 0x10, 9, 3),
	PIN_FIELD_BASE(27, 27, 2, 0x000, 0x10, 15, 3),
	PIN_FIELD_BASE(28, 28, 2, 0x000, 0x10, 18, 3),
	PIN_FIELD_BASE(29, 29, 2, 0x000, 0x10, 21, 3),
	PIN_FIELD_BASE(30, 30, 2, 0x000, 0x10, 24, 3),
	PINS_FIELD_BASE(31, 33, 1, 0x010, 0x10, 0, 3),
	PIN_FIELD_BASE(34, 34, 1, 0x000, 0x10, 21, 3),
	PIN_FIELD_BASE(35, 35, 1, 0x000, 0x10, 24, 3),
	PIN_FIELD_BASE(36, 36, 1, 0x010, 0x10, 0, 3),
	PIN_FIELD_BASE(37, 37, 1, 0x010, 0x10, 21, 3),
	PINS_FIELD_BASE(38, 39, 1, 0x010, 0x10, 3, 3),
	PIN_FIELD_BASE(40, 40, 1, 0x010, 0x10, 27, 3),
	PIN_FIELD_BASE(41, 41, 1, 0x010, 0x10, 24, 3),
	PIN_FIELD_BASE(42, 42, 1, 0x020, 0x10, 3, 3),
	PIN_FIELD_BASE(43, 43, 1, 0x020, 0x10, 0, 3),
	PIN_FIELD_BASE(44, 44, 1, 0x030, 0x10, 0, 3),
	PIN_FIELD_BASE(45, 45, 1, 0x030, 0x10, 3, 3),
	PINS_FIELD_BASE(46, 47, 1, 0x010, 0x10, 3, 3),
	PINS_FIELD_BASE(48, 51, 1, 0x010, 0x10, 6, 3),
	PINS_FIELD_BASE(52, 55, 1, 0x010, 0x10, 9, 3),
	PINS_FIELD_BASE(56, 59, 1, 0x010, 0x10, 12, 3),
	PINS_FIELD_BASE(60, 63, 1, 0x010, 0x10, 15, 3),
	PIN_FIELD_BASE(64, 64, 1, 0x010, 0x10, 18, 3),
	PINS_FIELD_BASE(65, 68, 1, 0x000, 0x10, 27, 3),
	PIN_FIELD_BASE(69, 69, 1, 0x000, 0x10, 0, 3),
	PIN_FIELD_BASE(70, 70, 1, 0x000, 0x10, 18, 3),
	PIN_FIELD_BASE(71, 71, 1, 0x000, 0x10, 12, 3),
	PIN_FIELD_BASE(72, 72, 1, 0x000, 0x10, 15, 3),
	PIN_FIELD_BASE(73, 73, 1, 0x000, 0x10, 3, 3),
	PIN_FIELD_BASE(74, 74, 1, 0x000, 0x10, 6, 3),
	PIN_FIELD_BASE(75, 75, 1, 0x000, 0x10, 9, 3),
	PIN_FIELD_BASE(76, 76, 1, 0x010, 0x10, 18, 3),
	PIN_FIELD_BASE(77, 77, 3, 0x000, 0x10, 0, 3),
	PIN_FIELD_BASE(78, 78, 3, 0x000, 0x10, 15, 3),
	PIN_FIELD_BASE(79, 79, 3, 0x000, 0x10, 18, 3),
	PIN_FIELD_BASE(80, 80, 3, 0x000, 0x10, 21, 3),
	PIN_FIELD_BASE(81, 81, 3, 0x000, 0x10, 24, 3),
	PIN_FIELD_BASE(82, 82, 3, 0x000, 0x10, 27, 3),
	PIN_FIELD_BASE(83, 83, 3, 0x010, 0x10, 0, 3),
	PIN_FIELD_BASE(84, 84, 3, 0x010, 0x10, 3, 3),
	PINS_FIELD_BASE(85, 88, 3, 0x010, 0x10, 15, 3),
	PIN_FIELD_BASE(89, 89, 3, 0x000, 0x10, 3, 3),
	PIN_FIELD_BASE(90, 90, 3, 0x000, 0x10, 6, 3),
	PIN_FIELD_BASE(91, 91, 3, 0x000, 0x10, 9, 3),
	PIN_FIELD_BASE(92, 92, 3, 0x000, 0x10, 12, 3),
	PIN_FIELD_BASE(93, 93, 3, 0x010, 0x10, 6, 3),
	PIN_FIELD_BASE(94, 94, 3, 0x010, 0x10, 9, 3),
	PINS_FIELD_BASE(95, 98, 3, 0x010, 0x10, 18, 3),
	PINS_FIELD_BASE(99, 102, 3, 0x010, 0x10, 21, 3),
	PINS_FIELD_BASE(103, 104, 3, 0x010, 0x10, 24, 3),
	PIN_FIELD_BASE(105, 105, 3, 0x010, 0x10, 27, 3),
	PINS_FIELD_BASE(106, 107, 3, 0x010, 0x10, 24, 3),
	PINS_FIELD_BASE(108, 109, 3, 0x010, 0x10, 27, 3),
	PIN_FIELD_BASE(110, 110, 5, 0x000, 0x10, 3, 3),
	PIN_FIELD_BASE(111, 111, 5, 0x000, 0x10, 0, 3),
	PIN_FIELD_BASE(112, 112, 5, 0x000, 0x10, 6, 3),
	PIN_FIELD_BASE(113, 113, 5, 0x000, 0x10, 9, 3),
	PIN_FIELD_BASE(114, 114, 5, 0x000, 0x10, 12, 3),
	PIN_FIELD_BASE(115, 115, 5, 0x000, 0x10, 15, 3),
	PIN_FIELD_BASE(116, 116, 6, 0x000, 0x10, 27, 3),
	PIN_FIELD_BASE(117, 117, 6, 0x000, 0x10, 24, 3),
	PIN_FIELD_BASE(118, 118, 6, 0x000, 0x10, 21, 3),
	PIN_FIELD_BASE(119, 119, 6, 0x000, 0x10, 18, 3),
	PIN_FIELD_BASE(120, 120, 6, 0x010, 0x10, 3, 3),
	PIN_FIELD_BASE(121, 121, 6, 0x000, 0x10, 3, 3),
	PIN_FIELD_BASE(122, 122, 6, 0x000, 0x10, 0, 3),
	PIN_FIELD_BASE(123, 123, 6, 0x000, 0x10, 15, 3),
	PIN_FIELD_BASE(124, 124, 6, 0x000, 0x10, 12, 3),
	PIN_FIELD_BASE(125, 125, 6, 0x000, 0x10, 9, 3),
	PIN_FIELD_BASE(126, 126, 6, 0x000, 0x10, 6, 3),
	PIN_FIELD_BASE(127, 127, 6, 0x010, 0x10, 0, 3),
	PIN_FIELD_BASE(128, 128, 3, 0x010, 0x10, 27, 3),
	PINS_FIELD_BASE(129, 130, 3, 0x020, 0x10, 0, 3),
	PINS_FIELD_BASE(131, 131, 3, 0x010, 0x10, 12, 3),
	PIN_FIELD_BASE(132, 132, 6, 0x010, 0x10, 9, 3),
	PIN_FIELD_BASE(133, 133, 6, 0x010, 0x10, 6, 3),
	PIN_FIELD_BASE(134, 134, 6, 0x010, 0x10, 15, 3),
	PIN_FIELD_BASE(135, 135, 6, 0x010, 0x10, 12, 3),
	PIN_FIELD_BASE(136, 136, 1, 0x020, 0x10, 9, 3),
	PIN_FIELD_BASE(137, 137, 1, 0x020, 0x10, 6, 3),
	PIN_FIELD_BASE(138, 138, 1, 0x020, 0x10, 15, 3),
	PIN_FIELD_BASE(139, 139, 1, 0x020, 0x10, 12, 3),
	PIN_FIELD_BASE(140, 140, 1, 0x020, 0x10, 21, 3),
	PIN_FIELD_BASE(141, 141, 1, 0x020, 0x10, 18, 3),
	PIN_FIELD_BASE(142, 142, 1, 0x020, 0x10, 27, 3),
	PIN_FIELD_BASE(143, 143, 1, 0x020, 0x10, 24, 3),
};

static const struct mtk_pin_field_calc mt8195_pin_drv_adv_range[] = {
	PIN_FIELD_BASE(8, 8, 4, 0x020, 0x10, 15, 3),
	PIN_FIELD_BASE(9, 9, 4, 0x020, 0x10, 0, 3),
	PIN_FIELD_BASE(10, 10, 4, 0x020, 0x10, 18, 3),
	PIN_FIELD_BASE(11, 11, 4, 0x020, 0x10, 3, 3),
	PIN_FIELD_BASE(12, 12, 4, 0x020, 0x10, 21, 3),
	PIN_FIELD_BASE(13, 13, 4, 0x020, 0x10, 6, 3),
	PIN_FIELD_BASE(14, 14, 4, 0x020, 0x10, 24, 3),
	PIN_FIELD_BASE(15, 15, 4, 0x020, 0x10, 9, 3),
	PIN_FIELD_BASE(16, 16, 4, 0x020, 0x10, 27, 3),
	PIN_FIELD_BASE(17, 17, 4, 0x020, 0x10, 12, 3),
	PIN_FIELD_BASE(29, 29, 2, 0x020, 0x10, 0, 3),
	PIN_FIELD_BASE(30, 30, 2, 0x020, 0x10, 3, 3),
	PIN_FIELD_BASE(34, 34, 1, 0x040, 0x10, 0, 3),
	PIN_FIELD_BASE(35, 35, 1, 0x040, 0x10, 3, 3),
	PIN_FIELD_BASE(44, 44, 1, 0x040, 0x10, 6, 3),
	PIN_FIELD_BASE(45, 45, 1, 0x040, 0x10, 9, 3),
};

static const struct mtk_pin_reg_calc mt8195_reg_cals[PINCTRL_PIN_REG_MAX] = {
	[PINCTRL_PIN_REG_MODE] = MTK_RANGE(mt8195_pin_mode_range),
	[PINCTRL_PIN_REG_DIR] = MTK_RANGE(mt8195_pin_dir_range),
	[PINCTRL_PIN_REG_DI] = MTK_RANGE(mt8195_pin_di_range),
	[PINCTRL_PIN_REG_DO] = MTK_RANGE(mt8195_pin_do_range),
	[PINCTRL_PIN_REG_SMT] = MTK_RANGE(mt8195_pin_smt_range),
	[PINCTRL_PIN_REG_IES] = MTK_RANGE(mt8195_pin_ies_range),
	[PINCTRL_PIN_REG_PU] = MTK_RANGE(mt8195_pin_pu_range),
	[PINCTRL_PIN_REG_PD] = MTK_RANGE(mt8195_pin_pd_range),
	[PINCTRL_PIN_REG_DRV] = MTK_RANGE(mt8195_pin_drv_range),
	[PINCTRL_PIN_REG_PUPD] = MTK_RANGE(mt8195_pin_pupd_range),
	[PINCTRL_PIN_REG_R0] = MTK_RANGE(mt8195_pin_r0_range),
	[PINCTRL_PIN_REG_R1] = MTK_RANGE(mt8195_pin_r1_range),
	[PINCTRL_PIN_REG_DRV_ADV] = MTK_RANGE(mt8195_pin_drv_adv_range),
};

static const char * const mt8195_pinctrl_register_base_names[] = {
	"iocfg0", "iocfg_bm", "iocfg_bl", "iocfg_br", "iocfg_lm",
	"iocfg_rb", "iocfg_tl",
};

static const struct mtk_eint_hw mt8195_eint_hw = {
	.port_mask = 0xf,
	.ports     = 7,
	.ap_num    = 225,
	.db_cnt    = 32,
};

static const struct mtk_pin_soc mt8195_data = {
	.reg_cal = mt8195_reg_cals,
	.pins = mtk_pins_mt8195,
	.npins = ARRAY_SIZE(mtk_pins_mt8195),
	.ngrps = ARRAY_SIZE(mtk_pins_mt8195),
	.eint_hw = &mt8195_eint_hw,
	.nfuncs = 8,
	.gpio_m = 0,
	.base_names = mt8195_pinctrl_register_base_names,
	.nbase_names = ARRAY_SIZE(mt8195_pinctrl_register_base_names),
	.bias_set_combo = mtk_pinconf_bias_set_combo,
	.bias_get_combo = mtk_pinconf_bias_get_combo,
	.drive_set = mtk_pinconf_drive_set_rev1,
	.drive_get = mtk_pinconf_drive_get_rev1,
	.adv_drive_get = mtk_pinconf_adv_drive_get_raw,
	.adv_drive_set = mtk_pinconf_adv_drive_set_raw,
};

static const struct of_device_id mt8195_pinctrl_of_match[] = {
	{ .compatible = "mediatek,mt8195-pinctrl", },
	{ }
};

static int mt8195_pinctrl_probe(struct platform_device *pdev)
{
	return mtk_paris_pinctrl_probe(pdev, &mt8195_data);
}

static struct platform_driver mt8195_pinctrl_driver = {
	.driver = {
		.name = "mt8195-pinctrl",
		.of_match_table = mt8195_pinctrl_of_match,
	},
	.probe = mt8195_pinctrl_probe,
};

static int __init mt8195_pinctrl_init(void)
{
	return platform_driver_register(&mt8195_pinctrl_driver);
}
arch_initcall(mt8195_pinctrl_init);
