/*
 * configure.h
 *
 *  Created on: Nov 1, 2017
 *      Author: Xucheng
 */

#ifndef CONFIGURE_H_
#define CONFIGURE_H_

void GPIO_configure(void);
void timer_a0_config(void);
void UART_Configure(void);
void SysTick_Configure(void);
void add_to_array(uint32_t *array);
void uart_putchar0(uint8_t tx_data);
void uart_putchar3(uint8_t tx_data);
void uart_putchar_n(uint8_t* data, uint32_t length);
void configure_ADC(void);
void RTC_configure(void);
void I2C_Configure(void);
void user_i2c_read(uint8_t length);
void user_i2c_write(uint8_t reg_addr, uint8_t value);
//void BME_Init(void);


#endif /* CONFIGURE_H_ */
