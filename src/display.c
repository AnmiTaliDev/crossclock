/* SPDX-FileCopyrightText: 2026 AnmiTaliDev <anmitalidev@nuros.org> */
/* SPDX-License-Identifier: GPL-3.0-or-later */

#include "display.h"
#include <stdio.h>

static const char *font[11][5] = {
    { " ### ", "#   #", "#   #", "#   #", " ### " }, /* 0 */
    { "  #  ", " ##  ", "  #  ", "  #  ", " ### " }, /* 1 */
    { " ### ", "#   #", "  ## ", " #   ", "#####" }, /* 2 */
    { " ### ", "    #", " ### ", "    #", " ### " }, /* 3 */
    { "   # ", "  ## ", " # # ", "#####", "   # " }, /* 4 */
    { "#####", "#    ", "#### ", "    #", "#### " }, /* 5 */
    { " ### ", "#    ", "#### ", "#   #", " ### " }, /* 6 */
    { "#####", "    #", "   # ", "  #  ", "  #  " }, /* 7 */
    { " ### ", "#   #", " ### ", "#   #", " ### " }, /* 8 */
    { " ### ", "#   #", " ####", "    #", " ### " }, /* 9 */
    { "  ", " #", "  ", " #", "  " }              /* : */
};

void display_clear(void) {
    printf("\033[H\033[J");
}

void display_time(int hours, int minutes, int seconds) {
    int digits[8];
    digits[0] = hours / 10;
    digits[1] = hours % 10;
    digits[2] = 10;
    digits[3] = minutes / 10;
    digits[4] = minutes % 10;
    digits[5] = 10;
    digits[6] = seconds / 10;
    digits[7] = seconds % 10;

    for (int row = 0; row < 5; row++) {
        for (int i = 0; i < 8; i++) {
            printf("%s  ", font[digits[i]][row]);
        }
        printf("\n");
    }
}
