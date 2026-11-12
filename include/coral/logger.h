#ifndef CORAL_LOGGER_H
#define CORAL_LOGGER_H

void coral_log_init(void);
void coral_log_info(const char *format, ...);
void coral_log_warn(const char *format, ...);
void coral_log_error(const char *format, ...);

#endif /* CORAL_LOGGER_H */
