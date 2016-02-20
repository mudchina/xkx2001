//Cracked by Kafei
// editord.c
// Created by yzc@XKX
// Copyright (C) XKX Organisation, 1996. All rights reserved.
// Fixed bug if the dir not exist, sdong, 2/20/2000
#define XKX_ARCHIVE "/open/archive/"
#define XKX_EDITOR "/open/wenxuan/"

string *Articles;

void create()
{
	seteuid(getuid());
}

int add(int arc, string article, string fname)
{
	string filename;

	if ( arc )
	{
	if (fname)
		filename = XKX_ARCHIVE + fname;
	else
		filename = XKX_ARCHIVE + "Unknown";
	}
	else
	{
	if (fname)
		filename = XKX_EDITOR + fname;
	else
		filename = XKX_EDITOR + "Unknown";
	}


	Articles = ({article});

	if (file_size(filename) <= 0)
		return ( write_file(filename, Articles[sizeof(Articles)-1] + "\n", 1) );

	return ( write_file(filename, Articles[sizeof(Articles)-1] + "\n", 0) );
}

int get_file_num(int arc, string year, string month)
{
	string filename;
	string text;
	int i, numb, size;
	string base;
	numb = 0;

	if (month)
	{
		if (arc)
		filename = XKX_ARCHIVE + "/" + year + "/wenxuan." + month;
		else
		filename = XKX_EDITOR + "/" + year + "/wenxuan." + month;
	}
	else
		return (-1);
	
        base = XKX_EDITOR+"/"+year+"/";
        if (file_size(base) != -2)
           mkdir(base);

	base = XKX_EDITOR+"/"+year+"/"+month+"/";
        if (file_size(base) != -2)
	   mkdir(base);

	if( file_size(filename) < 0 )
		return (numb);

	/* read in the whole file */
	text = read_file(filename);

	size = sizeof(text);
	
	for (i = size ; i > 0; i--)
	{
		if ( text[i] == '\n' && text[i+1..i+2] == "¡í")
		{
			numb = atoi(text[i+3..i+5]);
			break;
		}
	}

	if ( numb < 2 && text[0..1] == "¡í" )
		numb = 1;

	return (numb);
}
