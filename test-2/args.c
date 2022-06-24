#include "shell.h"
/**
 * _add_log - add input to log
 * @ptr_sev: ptr to shell env var link list
 * Return: 1 - success, 0 - fail
 */
int _add_log(sev *ptr_sev)
{
	if (add_node(&ptr_sev->log, NULL, _strdup(ptr_sev->input, &ptr_sev->mem)))
	{
		ptr_sev->log_cnt++;
		ptr_sev->cmd_cnt++;
		return (1);
	}
	return (0);
}
/**
 * _write_log - write sessions log in a file
 * @ptr_sev: ptr to the shell env var
 * Return: 1 - success, 0 - fail
 */
int _write_log(sev *ptr_sev)
{
	char *fullpath = NULL, *entry = NULL;


	list *walker = NULL;
	int _fds = 0, len = 0;


	fullpath = _strcat(_getenviron("HOME", ptr_sev), "/", &ptr_sev->mem);
	fullpath = _strcat(fullpath, LOGFILE, &ptr_sev->mem);
	_fds = open(fullpath, O_WRONLY | O_CREAT | O_TRUNC, 0600);
	if (_fds == -1)
	{
		return (0);
	}
	reverse_list(&(ptr_sev->log));
	walker = ptr_sev->log;
	while (walker)
	{
		entry = walker->value;
		entry = _strcat(entry, "\n", &ptr_sev->mem);
		len = _strlen(entry);
		if (write(_fds, entry, len) < len)
		{
			close(_fds);
			return (0);
		}
		walker = walker->next;
	}
	close(_fds);
	return (1);
}
/**
 * _log_count - read and get log file count
 *
 * @ptr_sev: ptr to shell env var struct
 *
 * Return: num of entries in log file, 0 in empty or fail
 *
 */
int _log_count(sev *ptr_sev)
{
	char *fullpath = NULL, buffer[MAXBUFREAD];
	int _fds = 0;
	size_t _size = MAXBUFREAD, lines = 0;
	ssize_t num_read = 1, i = 0;


	fullpath = _strcat(_getenviron("HOME", ptr_sev), "/", &ptr_sev->mem);
	fullpath = _strcat(fullpath, LOGFILE, &ptr_sev->mem);
	_fds = open(fullpath, O_RDONLY);
	if (_fds == -1)
	{
		return (0);
	}
	while (num_read)
	{
		num_read = read(_fds, &buffer, size);
		if (num_read == -1)
		{
			close(_fds);
			return (0);
		}
		for (i = 0; i < num_read; i++)
		{
			if (buffer[i] == '\n')
				lines++;

		}
	}
	return (lines % MAXLOGSIZE);
}
