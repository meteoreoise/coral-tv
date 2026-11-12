#include <stdarg.h>
#include <stdio.h>

#include "coral/logger.h"

void coral_log_init(void)
{
	printf("[CORAL]\tlogger ready\n");
}

void coral_log_info(const char *format, ...)
{
	va_list args;

	printf("[CORAL][INFO]\t");
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	printf("\n");
}

void coral_log_warn(const char *format, ...)
{
	va_list args;

	printf("[CORAL][WARN]\t");
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	printf("\n");
}

void coral_log_error(const char *format, ...)
{
	va_list args;

	printf("[CORAL][ERROR]\t");
	va_start(args, format);
	vprintf(format, args);
	va_end(args);
	printf("\n");
}
