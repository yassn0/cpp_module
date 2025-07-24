#include <iostream>
#include <fstream>
#include <string>

void replace_s1_s2(std::ifstream &fd, std::ofstream &new_fd, std::string const s1, std::string const s2)
{
	std::string line;
	std::string tmp;
	size_t pos;
	size_t found;

	while (std::getline(fd, line))
	{
		tmp.clear();
		pos = 0;
		while ((found = line.find(s1, pos)) != std::string::npos)
		{
			tmp += line.substr(pos, found - pos);
			tmp += s2;
			pos = found + s1.length();
		}
		tmp += line.substr(pos);
		new_fd << tmp << std::endl;
	}
}

int main(int ac, char **av)
{
	if (ac != 4)
		return (1);
		
	std::ifstream fd;
	std::ofstream new_fd;
	const std::string s1 = av[2];
	const std::string s2 = av[3];

	fd.open(av[1]);
	if (fd.fail())
		return (1);
	new_fd.open("out.txt");
	if (new_fd.fail())
		return (fd.close(), 1);

	replace_s1_s2(fd, new_fd, s1, s2);
	
	fd.close();
	new_fd.close();
	return (0);
}