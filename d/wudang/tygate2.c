//Cracked by Roath
// tygate2.c ÌÒÔ°Ä¾ÃÅ
// by Marz 
// xQin 04/01
inherit ROOM;

void create()
{
	set("short", "ÌÒÔ°Ä¾ÃÅ");
	set("long", @LONG
Äã×ßÔÚÒ»ÌõÍ¨ÍùÌÒÊ÷ÁÖÉî´¦µÄÐ¡µÀÉÏ£¬Ç°ÃæÓÐ¸öÌÒÄ¾ÃÅ(door)¡£
LONG
	);
	set("outdoors", "wudang");
	
	
	set("item_desc",([
		"door"	:	"\n\t\t\tÌÒÄ¾ÃÅÉÏÓÐÊ×Ê«£º\n\n\n" 
					"\t\t¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡È¥¡¡Äê¡¡½ñ¡¡ÈÕ¡¡´Ë¡¡ÃÅ¡¡ÖÐ¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡ÈË¡¡Ãæ¡¡ÌÒ¡¡»¨¡¡Ïà¡¡Ó³¡¡ºì¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡ÈË¡¡Ãæ¡¡²»¡¡Öª¡¡ºÎ¡¡´¦¡¡È¥¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡ÌÒ¡¡»¨¡¡ÒÀ¡¡¾É¡¡Ð¦¡¡´º¡¡·ç¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë\n\n\n",
							
		]));


	set("exits", ([
		"north" : __DIR__"tyroad10",
	]));

	set("cost", 1);
	setup();
}
