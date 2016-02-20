//Cracked by Kafei
// ban.c
// Created by Xiang@XKX

// #include <net/telnet.h>

#define BANNED_SITES "/adm/etc/banned_sites"

void load_sites();
void add(string pattern);
void remove(string pattern);
int  is_banned(string site);
void print();

string *Sites;

void create()
{
	seteuid(getuid());
	load_sites();
}

void load_sites()
{
	string *tmp, file;
	int loop;

	Sites = ({});
	
	// reads in the list of the banned sites

	file = read_file(BANNED_SITES);
	if (!file) return;
	
	tmp = explode(file, "\n");
   	for(loop=0; loop<sizeof(tmp); loop++)
        	if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
           		continue;
        	else Sites += ({ tmp[loop] });
}

int is_banned(string site)
{
	string *line;
	int i;

	line = ({});
	line += ({site});

	for (i = 0; i < sizeof(Sites); i++)
		if (sizeof(regexp(line, Sites[i])) == 1)
			return 1;
	return 0;
}	

void print()
{
	int i;
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
}

void add(string site)
{
	int i;
	
	Sites += ({site});
	write_file(BANNED_SITES, Sites[sizeof(Sites)-1] + "\n", 0);
	load_sites();
}

void remove(string site)
{
	int i;
	Sites = filter_array(Sites, (:strcmp:), site);
	rm(BANNED_SITES);
	for (i = 0; i < sizeof(Sites); i++)
		write_file(BANNED_SITES, Sites[i] + "\n", 0);
	load_sites();
}
