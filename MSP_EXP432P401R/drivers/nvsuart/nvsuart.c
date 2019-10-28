/*
 * Copyright (c) 2017, Texas Instruments Incorporated
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * *  Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 *
 * *  Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * *  Neither the name of Texas Instruments Incorporated nor the names of
 *    its contributors may be used to endorse or promote products derived
 *    from this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR
 * CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL,
 * EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
 * PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS;
 * OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY,
 * WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR
 * OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE,
 * EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */
/*
 *  ======== nvsuart.c ========
 */

#include <string.h>
#include <stdlib.h>
#include <stdint.h>

/* Driver Header files */
#include <ti/drivers/NVS.h>
#include <ti/drivers/UART.h>

/* Example/Board Header files */
#include "Board.h"

#define HEADER "=================================================="

void outputDataToConsole(void);
void inputDataFromConsole(void);

static char buf[256];
static const char signature[] = \
    "SimpleLink SDK Non-Volatile Storage (NVS) Example.\r\n";

static struct locationDate {
    char location[64];
    char year[8];
    char month[12];
    char day[4];
} myDataStruct;

UART_Handle uartHandle;

/*
 *  ======== mainThread ========
 */
void *mainThread(void *arg0)
{
    NVS_Handle nvsHandle;
    NVS_Attrs regionAttrs;
    NVS_Params nvsParams;

    UART_Params uartParams;

    NVS_init();
    UART_init();

    /* Create UART */
    UART_Params_init(&uartParams);
    uartHandle = UART_open(Board_UART0, &uartParams);
    if (uartHandle == NULL) {
        /* UART_open() failed */
        while (1);
    }

    UART_write(uartHandle, "\n\r", strlen("\n\r"));

    NVS_Params_init(&nvsParams);
    nvsHandle = NVS_open(Board_NVS0, &nvsParams);
    if (nvsHandle == NULL) {
        /* NVS_open() failed */
        while (1);
    }

    NVS_getAttrs(nvsHandle, &regionAttrs);

    /* Determine if flash contains signature string */
    if (strcmp((char *) regionAttrs.regionBase, (char *) signature) == 0) {

        /* Write to console directly from flash */
        UART_write(uartHandle, regionAttrs.regionBase,
            strlen(regionAttrs.regionBase));

        /* Read the previously stored data and store in myDataStruct */
        NVS_read(nvsHandle, sizeof(signature), &myDataStruct,
            sizeof(myDataStruct));

        /* Output myDataStruct to UART console */
        outputDataToConsole();

        UART_write(uartHandle, "Erasing flash...", strlen("Erasing flash..."));
        UART_write(uartHandle, "\r\n", strlen("\r\n"));

        /* Erase the entire flash region */
        NVS_erase(nvsHandle, 0, regionAttrs.regionSize);
    }
    else {

        /* Write signature to memory */
        NVS_write(nvsHandle, 0, (void *) signature, sizeof(signature),
            NVS_WRITE_ERASE | NVS_WRITE_POST_VERIFY);

        /* Get user input from UART console. */
        inputDataFromConsole();

        UART_write(uartHandle, "Storing to flash...", strlen("Storing to flash..."));
        UART_write(uartHandle, "\r\n", strlen("\r\n"));

        /* Write user input to flash */
        NVS_write(nvsHandle, sizeof(signature), (void *) &myDataStruct,
            sizeof(myDataStruct), NVS_WRITE_POST_VERIFY);
    }

    UART_write(uartHandle, "Reset the device.", strlen("Reset the device."));
    UART_write(uartHandle, "\r\n", strlen("\r\n"));
    UART_write(uartHandle, HEADER, strlen(HEADER));
    UART_write(uartHandle, "\r\n", strlen("\r\n"));

    return (NULL);
}

void outputDataToConsole(void)
{
    /* Clear buffer */
    memset(buf, 0, sizeof(buf));

    /* Format Date & Time String. User input is NULL terminated; hence -1. */
    strncat(buf, myDataStruct.location, strlen(myDataStruct.location) - 1);
    strncat(buf, "\r\n", 2);
    strncat(buf, myDataStruct.year, strlen(myDataStruct.year) - 1);
    strncat(buf, "-", 1);
    strncat(buf, myDataStruct.month, strlen(myDataStruct.month) - 1);
    strncat(buf, "-", 1);
    strncat(buf, myDataStruct.day, strlen(myDataStruct.day) - 1);
    strncat(buf, "\r\n", 2);

    /* Print to console */
    UART_write(uartHandle, buf, strlen(buf));
}

void inputDataFromConsole(void)
{
    /* Reset myDataStruct */
    memset(&myDataStruct, 0, sizeof(myDataStruct));

    /* Get user input from UART console */
    UART_write(uartHandle, "Location (ie. Santa Barbara, CA.): ",
        strlen("Location (ie. Santa Barbara, CA.): "));
    UART_read(uartHandle, myDataStruct.location, sizeof(myDataStruct.location));

    UART_write(uartHandle, "Year: ", strlen("Year: "));
    UART_read(uartHandle, myDataStruct.year, sizeof(myDataStruct.year));

    UART_write(uartHandle, "Month: ", strlen("Month: "));
    UART_read(uartHandle, myDataStruct.month, sizeof(myDataStruct.month));

    UART_write(uartHandle, "Day: ", strlen("Day: "));
    UART_read(uartHandle, myDataStruct.day, sizeof(myDataStruct.day));
}
