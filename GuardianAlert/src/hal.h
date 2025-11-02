#ifndef HAL_H
#define HAL_H

void hal_init(void);
void hal_delay(int milliseconds);
void uart_send(const char* data);
int uart_receive(char* buffer, int buffer_size);

#endif