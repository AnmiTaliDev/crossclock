/* SPDX-FileCopyrightText: 2026 AnmiTaliDev <anmitalidev@nuros.org> */
/* SPDX-License-Identifier: GPL-3.0-or-later */

#define _POSIX_C_SOURCE 199309L
#include "time_util.h"
#include <time.h>

#if defined(_WIN32) || defined(_WIN64)
#include <windows.h>
#elif defined(__plan9__)
#include <u.h>
#include <libc.h>
#else
#include <unistd.h>
#endif

void time_util_sleep_ms(int milliseconds) {
#if defined(_WIN32) || defined(_WIN64)
    Sleep(milliseconds);
#elif defined(__plan9__)
    sleep(milliseconds); /* Plan 9 sleep is in milliseconds */
#else
    struct timespec ts;
    ts.tv_sec = milliseconds / 1000;
    ts.tv_nsec = (milliseconds % 1000) * 1000000L;
    nanosleep(&ts, NULL);
#endif
}

void time_util_get_now(int *hours, int *minutes, int *seconds) {
    time_t now = time(NULL);
    struct tm *t = localtime(&now);
    if (t) {
        *hours = t->tm_hour;
        *minutes = t->tm_min;
        *seconds = t->tm_sec;
    }
}
