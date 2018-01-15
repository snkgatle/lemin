
#include "../includes/header.h"

int		ft_file_errors(size_t err_no)
{
	if (err_no == 1)
		ft_putendl("No number of ants specified");
	else if (err_no == 2)
		ft_putendl("No starting/ending point supplied");
	else if (err_no == 3)
		ft_putendl("Error in information supplied for starting room");
	else if (err_no == 4)
		ft_putendl(("Error: command specified is invalid"));
	else if (err_no == 5)
		ft_putendl("Error in information supplied for end room");
	else if (err_no == 6)
		ft_putendl("Edges specified invalid");
	else if (err_no == 7)
		ft_putendl("No paths are available");
	return (1);
}

void	ft_error_handler(size_t err_no, char ext)
{
	ft_file_errors(err_no);
	if (ext == 'e')
		exit(EXIT_FAILURE);
}
