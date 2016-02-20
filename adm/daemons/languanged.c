//Cracked by Kafei
// languaged.c
//
//	GB <-> Big5
//
// Kenny@EC (1998/3/21)
// (Ported from @(#)$Id: ccf.c,v 1.2 1994/04/30 19:49:36 shin Exp shin $)

#pragma optimize
#pragma save_binary

//inherit F_CLEAN_UP;

#define B2G_TAB		__DIR__"language/BtoG.tab"
#define G2B_TAB		__DIR__"language/GtoB.tab"
#define B2G		0
#define G2B		1

#define B2G_bad1	0xa1
#define B2G_bad2	0xf5
#define G2B_bad1	0xa1
#define G2B_bad2	0xbc

#define is_GB1(x)       ((x)>=0xa1 && (x)<=0xf7)
#define is_GB2(x)       ((x)>=0xa1 && (x)<=0xfe)
#define is_B51(x)       ((x)>=0xa1&&(x)<=0xfe)
#define is_B52(x)       (((x)>=0x40 && (x)<=0x7e) || ((x)>=0xa1 && (x)<=0xfe))

private int G2B_cols, B2G_cols;
private mapping B2G_Cache=([]),
		G2B_Cache=([]);


private int Fetch(int key, int flag)
{
	int    col_limit=flag? G2B_cols: B2G_cols,
	       col = key%col_limit;
	string buf, file=flag? G2B_TAB: B2G_TAB;

	if (flag && G2B_Cache[key]) return G2B_Cache[key];
	if (!flag && B2G_Cache[key]) return B2G_Cache[key];

	if (buf = read_file(file, key/col_limit+1, 1))
	{
		string *field = explode(buf, ",");

		if (col < sizeof(field))
		{
			int value;

			sscanf(field[col], "%x", value);
			if (flag) G2B_Cache[key] = value;
			else B2G_Cache[key] = value;
			return value;
		} // if
	} // if
	return 0;
} // Fetch()


private int *g2b(int c1, int c2)
{
	int i;

	if ((c2>=0xa1) && (c2<=0xfe))
	{
		if ((c1>=0xa1) && (c1<=0xa9))
		{
			i = ((c1-0xa1)*94 + (c2-0xa1)) * 2;
			return ({ Fetch(i++, G2B), Fetch(i, G2B) });
		} // if
		else if ((c2>=0xa1) && (c2<=0xfe))
		{
			i = ((c1-0xb0+9)*94 + (c2-0xa1)) * 2;
			return ({ Fetch(i++, G2B), Fetch(i, G2B) });
		} // if
	} // if
	return ({ G2B_bad1, G2B_bad2 });
} // g2b()


private int *b2g(int c1, int c2)
{
	int i;

	if ((c1 >= 0xa1) && (c1 <= 0xf6))
	{
		if ((c2 >= 0x40) && (c2 <= 0x7e))
		{
			i = ((c1 - 0xa1) * 157 + (c2 - 0x40)) * 2;
			return ({ Fetch(i++, B2G), Fetch(i, B2G) });
		} // if
		else if ((c2 >= 0xa1) && (c2 <= 0xfe))
		{
			i = ((c1 - 0xa1) * 157 + (c2 - 0xa1) + 63) * 2;
			return ({ Fetch(i++, B2G), Fetch(i, B2G) });
		} // if
	} // if
	else if ((c1 == 0xf7) && (c2 >= 0x40) && (c2 <= 0x55))
	{
		i = ((c1 - 0xa1) * 157 + (c2 - 0x40)) * 2;
		return ({ Fetch(i++, B2G), Fetch(i, B2G) });
	} // if
	return ({ B2G_bad1, B2G_bad2 });
} // b2g()


string GB2Big5(string src)
{
	string str=src;			// duplicate string
	int    len=strlen(str);

	for (int i=0; i<len;)
		if (is_GB1(str[i]) && is_GB2(str[i+1]))
		{
			int *code=g2b(str[i], str[i+1]);
			str[i] = code[0];
			str[i+1] = code[1];
			i += 2;
		} // if
		else	i++;
	return str+"";			// assure string
} // GB2Big5()


string Big52GB(string src)
{
	string str=src;			// duplicate string
	int    len=strlen(str);

	for (int i=0; i<len;)
		if (is_B51(str[i]) && is_B52(str[i+1]))
		{
			int *code=b2g(str[i], str[i+1]);
			str[i] = code[0];
			str[i+1] = code[1];
			i += 2;
		} // if
		else	i++;
	return str+"";			// assure string
} // Big52GB()


string toBig5(string str)
{
	if (!stringp(str)) return "";
	return GB2Big5(str);
} // toBig5()

string toGB(string str)
{
	if (!stringp(str)) return "";
	return Big52GB(str);
} // toGB()


void create()
{
	string buf;

	seteuid(getuid());
	if (buf = read_file(B2G_TAB, 1, 1))
		B2G_cols = sizeof(explode(buf, ","))-1;
	if (buf = read_file(G2B_TAB, 1, 1))
		G2B_cols = sizeof(explode(buf, ","))-1;
} // create()
