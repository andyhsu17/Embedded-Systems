---
# nvsuart

---

## Example Summary

Example to read and write data into non-volatile storage using the NVS driver.

##Peripherals Exercised

* `Board_UART0` - Used for console input and output.

## Resources & Jumper Settings

> If you're using an IDE (such as CCS or IAR), please refer to Board.html in
 your project directory for resources used and board-specific jumper settings.
 Otherwise, you can find Board.html in the directory
 &lt;SDK_INSTALL_DIR&gt;/source/ti/boards/&lt;BOARD&gt;.

## Example Usage

* Open a serial session (e.g. [`PuTTY`](http://www.putty.org/ "PuTTY's
 Homepage"), etc.) to the appropriate COM port.
* The COM port can be determined via Device Manager in Windows or via
 `ls /dev/tty*` in Linux.

The connection will have the following settings:
```
    Baud-rate:     115200
    Data bits:          8
    Stop bits:          1
    Parity:          None
    Flow Control:    None
```

* Run the example.

* The example checks if the signature, __"SimpleLink SDK Non-Volatile Storage
 (NVS) Example"__ is saved in flash.

 * If the signature is present in flash, previously saved inputs are
 displayed on the UART console and the flash is erased. Otherwise, the
 application will prompt for input.

 * When prompted, reset the device.

The following is example input and output (after reset).
```
    Location (ie. Santa Barbara, CA.): Syracuse, Sicily
    Month: 3
    Day: 14
    Year: 1592
    Reset the device.
    ==================================================
```

After device reset:
```
    SimpleLink SDK Non-Volatile Storage (NVS) Example.
    Syracuse, Sicily
    3-14-1592
    Erasing flash...
    Reset the device.
    ==================================================
```

## Application Design Details

* The application utilizes a single thread to demonstrate using the
 non-volatile storage.

* A block of memory the size of `signature` bytes is compared to `signature`.
If equal, the application writes the signature as stored in flash directly to
the UART console. A block of memory the size of `myDataStruct` is read from
flash and stored into `myDataStruct`. The contents are then displayed on the
UART console. If `signature` is not present in flash memory, it is written to
flash.

* At the end of execution, the application prompts the user to reset the
device. Upon a reset, the processor will restart. The application will
automatically start over.

* `NVS_getAttrs()` will populate a `NVS_Attrs` struct with properties specific
to a `NVS_Handle`. These include the flash region base address, region size and
sector size.
```C
NVS_getAttrs(nvsHandle, &regionAttrs);
```

* This application demonstrates how to use the `NVS_read()`, `NVS_write()` and
`NVS_erase()` APIs with appropriate offsets.

* This application also demonstrates the UART writing data directly from flash
to the console through utilization of the `NVS_Attrs`.
```C
/* Write to console directly from flash */
UART_write(uartHandle, regionAttrs.regionBase, strlen(regionAttrs.regionBase));
```
* The `NVS_WRITE_ERASE` flag is used with the `NVS_write()` API to ensure the
flash region is erased prior to performing a write. This flag will erase
`NVS_Attrs.sectorSize` bytes of memory.

TI-RTOS:

* When building in Code Composer Studio, the kernel configuration project will
be imported along with the example. The kernel configuration project is
referenced by the example, so it will be built first. The "release" kernel
configuration is the default project used. It has many debug features disabled.
These feature include assert checking, logging and runtime stack checks. For a
detailed difference between the "release" and "debug" kernel configurations and
how to switch between them, please refer to the SimpleLink MCU SDK User's
Guide. The "release" and "debug" kernel configuration projects can be found
under &lt;SDK_INSTALL_DIR&gt;/kernel/tirtos/builds/&lt;BOARD&gt;/(release|debug)/(ccs|gcc).

FreeRTOS:

* Please view the `FreeRTOSConfig.h` header file for example configuration
information.
