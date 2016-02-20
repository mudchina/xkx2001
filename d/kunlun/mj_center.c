//Cracked by Roath
// Room: /d/kunlun/mj_center.c
// Zhangchi 3/00

#include <ansi.h>
inherit ROOM;

int do_check();
int f_set_jingtie(string);
int f_set_didao(string);
string word_string();
string show_data();

void create()
{
	set("short", HIR"Ã÷½ÌÖ¸»ÓÖĞĞÄ"NOR);
	set("long", @LONG
ÕâÀïÊÇÃ÷½ÌÖ¸»ÓÖĞĞÄ¡£ËÄÖÜ°ÚÂúÁË¸÷ÖÖ¸÷ÑùµÄÒÇÆ÷¡£Ç½ÉÏÃæ»¹ÓĞ
Ò»ĞĞĞ¡×Ö(word)¡£ÕıÃæÒ»¸öÒ»°ÙÁã°Ë´çµÄ´óÆÁÄ»(screen)ÉÏÏÔÊ¾×ÅÒ»
Ğ©Êı¾İ¡£º
LONG
);
	set("exits", ([
		"out": "/u/zhangchi/workroom",
	]));
	set("valid_startroom", 1);
	set("item_desc", ([
		"word": (: word_string :),
		"screen": (: show_data :),
	]) );
	set("jingtie", 0);
	set("no_clean_up", 1);
	set("didao", ([
		"east":1,
		"west":0,
		"north":0,
		"south":0,
	]));

	setup();
}

void reset()
{
        ::reset();
        set("no_clean_up", 1);
}

void init()
{
	add_action("do_check","check_jingtie");
	add_action("f_set_jingtie","set_jingtie");
	add_action("f_set_didao","set_didao");
}

int do_check()
{
	write("ÏÖÓĞ"+query("jingtie")+"¿é¾«Ìú\n");
	return 1;
}

int f_set_jingtie(string arg)
{
	int num;

	if (arg)
	{	
		if (sscanf(arg, "%d",num) != 1)
			return notify_fail("Ö¸Áî¸ñÊ½£ºset_jingtie <num>\n");
	}
	else
		return notify_fail("Ö¸Áî¸ñÊ½£ºset_jingtie <num>\n");
	set("jingtie",num);
	write("OK!\n");
	return 1;
}

int f_set_didao(string arg)
{
	string dir;
	int num;
	
	if (arg)
	{
		if (sscanf(arg, "%s %d", dir, num) != 2)
			return notify_fail("Ö¸Áî¸ñÊ½£ºset_didao <dir> <num>\n");
	}
	else
		return notify_fail("Ö¸Áî¸ñÊ½£ºset_didao <dir> <num>\n");
	set("didao/"+dir, num);
	write("OK!\n");
	return 1;
}

string word_string()
{
	return HIC
		"²é¾«Ìú´¢²ØÁ¿:		check_jingtie\n"+
		"ÉèÖÃ¾«Ìú´¢²Ø:		set_jingtie <num>\n"+
		"ÉèÖÃºñÍÁµØµÀ:		set_didao <dir> <num>\n"
		NOR
		HIR"\n\nÕıÔÚ½¨ÉèÖĞ¡£\n"NOR;
}

string show_data()
{	return HIY
"\n    *-------------------------------------------*"+
	"\n\t¾«Ìú´¢²ØÁ¿		"+query("jingtie")+
	"\n\tºñÍÁµØµÀ£º"+
	"\n\t		¶«£º	"+query("didao/east")+
	"\n\t		Î÷£º	"+query("didao/west")+
	"\n\t		±±£º	"+query("didao/north")+
	"\n\t		ÄÏ£º	"+query("didao/south")+
"\n    *-------------------------------------------*\n\n"+NOR;
}