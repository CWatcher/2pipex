void	print_strs(char *strs[])
{
	while (*strs)
	{
		printf("%s\n", *strs);
		strs++;
	}
}
