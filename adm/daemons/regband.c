//Cracked by Kafei
// regband.c
// Created by Dts@XKX, 1997-04-15

// #include <net/telnet.h>

#define BANNED_SITES "/adm/etc/noreg_sites"
#define LOGFILE "/log/regban.log"

void load_sites();
void add(string pattern);
void remove(string pattern);
void print();
int is_banned(string site);
void check(string site);

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
	{
		if(tmp[loop][0] == '#' || tmp[loop][0] == '\n' || tmp[loop] == "")
			continue;
		Sites += ({ tmp[loop] });
	}
}

int is_banned(string site)
{
	string *line;
	int i, at;
	string csite = lower_case(site);

	line = ({});
	line += ({csite});

	at = strsrch(csite, "@");
	for (i = 0; i < sizeof(Sites); i++)
	{
		if ( at >= 0 && strsrch(Sites[i], "@") == -1)
			continue;

		if (sizeof(regexp(line, Sites[i])) == 1)
		{
			write_file(LOGFILE, "BANNED: " + csite + "\n", 0);
			return 1;
		}
	}
	write_file(LOGFILE, "PASS: " + csite + "\n", 0);
	return 0;
}

void print()
{
	int i;

	write("Banned Sites:\n");
	for (i = 0; i < sizeof(Sites); i++)
		write(Sites[i] + "\n");
}

void add(string site)
{
	int i;
	string csite = lower_case(site);
	
	Sites += ({csite});
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

void check (string site)
{
	string *line;
	int i, at;
	string csite = lower_case(site);

	line = ({});
	line += ({csite});

	at = strsrch(csite, "@");
	write("Check: [" + csite + "]\n", 0);
	for (i = 0; i < sizeof(Sites); i++)
	{
		write("---->[" + Sites[i] + "]\n", 0);
		if ( at >= 0 && strsrch(Sites[i], "@") == -1)
			continue;

		if (sizeof(regexp(line, Sites[i])) == 1)
		{
			write("BANNED: " + csite + "\n", 0);
			return;
		}
	}
	write("PASS: " + csite + "\n", 0);
	return;
}
