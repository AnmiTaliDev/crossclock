/* SPDX-FileCopyrightText: 2026 AnmiTaliDev <anmitalidev@nuros.org> */
/* SPDX-License-Identifier: GPL-3.0-or-later */

#include "display.h"
#include "time_util.h"
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>

static volatile bool keep_running = true;

static void handle_signal(int sig) {
    (void)sig;
    keep_running = false;
}

int main(void) {
    int h, m, s;

    signal(SIGINT, handle_signal);
    signal(SIGTERM, handle_signal);

    while (keep_running) {
        time_util_get_now(&h, &m, &s);
        display_clear();
        display_time(h, m, s);
        time_util_sleep_ms(1000);
    }

    printf("\nStopped.\n");
    return 0;
}
