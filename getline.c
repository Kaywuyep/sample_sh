#include "shell.h"
/**
 * init_string - a function that initializes the string
 * @str: string to be initializes
 */
void init_string(String *str)
{
	str->data = NULL;
	str->size = 0;
}
/**
 * append_string - afunction that appends to the string
 * @str:pointer to the string to be used
 * @c: char type value
 */
void append_string(String *str, char c)
{
	str->data = realloc(str->data, str->size + 1);
	str->data[str->size++] = c;
}
/**
 * read_buffer - a function that reads from the input stream (stdin)
 * into the buffer
 * @buffer:  A static character array that acts as a buffer to store
 * input from the user
 * @buffer_pos: Keeps track of the current position within the buffer
 * @bytes_in_buffer: The amount of valid data in the buffer
 *
 * Return: 1
 */
int read_buffer(char *buffer, size_t *buffer_pos, ssize_t *bytes_in_buffer)
{
	if (*buffer_pos >= *bytes_in_buffer)
	{
		*bytes_in_buffer = read(STDIN_FILENO, buffer, BUFF_SIZE);
		*buffer_pos = 0;
		if (*bytes_in_buffer <= 0)
		{
			return (0); /*End of file reached*/
		}
	}
	return (1);
}
/**
 * _getline - a function that reads the input stream
 *
 * Return: number of data in the line
 */
char *_getline(void)
{
	static char buffer[BUFF_SIZE];
	static size_t buffer_pos;
	static ssize_t bytes_in_buffer;
	char current_char;
	String line;/*line: A dynamic char array to store the user input line*/

	init_string(&line);

	while (1)
	{
		if (!read_buffer(buffer, &buffer_pos, &bytes_in_buffer))
		{
			break;
		}

		current_char = buffer[buffer_pos++];
		if (current_char == '\n')
		{
			append_string(&line, '\0');
			buffer_pos = 0; /*Reset buffer position*/
			break;
		}
		else
		{
			append_string(&line, current_char);
		}
	}

	if (line.size == 0)/*line.size stores the current size (length)*/
		/* of the string stored in line.data*/
	{
		/*line.data points to the dynamically allocated character*/
		/* array that holds the string data*/
		free(line.data);
		return (NULL);
	}

	return (line.data);
}
