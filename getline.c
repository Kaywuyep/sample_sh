#include "shell.h"
/**
 * init_string - a function that initializes the string
 * @str: string to be initializes
 * @str_len: length of the string
 */
void init_string(size_t *str_len, char **str)
{
	*str = NULL;
	*str_len = 0;
}
/**
 * append_string - afunction that appends to the string
 * @str:pointer to the string to be used
 * @c: char type value
 * @str_len: the length of the string
 */
void append_string(char **str, size_t *str_len, char c)
{
	*str = realloc(*str, (*str_len) + 1);
	(*str)[(*str_len)++] = c;
}
/**
 * read_buffer - a function that reads from the input stream (stdin)
 * into the buffer
 * @buffer:  A static character array that acts as a buffer to store
 * input from the user
 * @buffer_pos: Keeps track of the current position within the buffer
 * @bytes_read: The amount of valid data in the buffer
 *
 * Return: 1
 */
int read_buffer(char *buffer, size_t *buffer_pos, ssize_t *bytes_read)
{
	if (*buffer_pos >= (size_t)*bytes_read)
	{
		*bytes_read = read(STDIN_FILENO, buffer, BUFF_SIZE);
		*buffer_pos = 0;
		if (*bytes_read <= 0)
		{
			return (0); /*End of file reached or error occured*/
		}
	}
	return (1);/*successfully read data*/
}
/**
 * _getline - a function that reads the input stream
 * @line: a char pointer
 * @line_len:a pointer to the size or length of data
 * @stream: the input stream
 * Return: number of data in the line
 */
ssize_t _getline(char **line, size_t *line_len, FILE *stream)
{
	static char buffer[BUFF_SIZE];
	size_t buffer_pos = 0;
	ssize_t bytes_read = 0;
	char current_char;

	(void) stream;
	/*Clear the previous line data and start fresh*/
	init_string(line_len, line);

	while (1)
	{
		if (buffer_pos >= (size_t)bytes_read)
                {
                        bytes_read = read(STDIN_FILENO, buffer, BUFF_SIZE);
                        buffer_pos = 0;/*Reset buffer position for each call*/
			/*if (*line_len == 0) Handle null command*/
                                /*return (0);*/

                        if (bytes_read <= 0)
                        {
                                return (-1);/* Return -1 to indicate EOF or error*/
                        }
		}

		current_char = buffer[buffer_pos++];

		if (current_char == '\n')
		{
			append_string(line, line_len, '\0');
			buffer_pos = 0;
			break;
		}
		else
		{
			append_string(line, line_len, current_char);
		}
	}
	return (*line_len);
}
