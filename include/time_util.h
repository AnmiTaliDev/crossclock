/* SPDX-FileCopyrightText: 2026 AnmiTaliDev <anmitalidev@nuros.org> */
/* SPDX-License-Identifier: GPL-3.0-or-later */

#ifndef TIME_UTIL_H
#define TIME_UTIL_H

void time_util_sleep_ms(int milliseconds);
void time_util_get_now(int *hours, int *minutes, int *seconds);

#endif
