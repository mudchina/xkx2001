//Cracked by Roath
// tygate1.c ÌÒÔ°Àé°Ê
// by Marz 
// xQin 04/01

inherit ROOM;

void create()
{
	set("short", "ÌÒÔ°Àé°Ê");
	set("long", @LONG
Äã×ßÔÚÒ»ÌõÍ¨ÍùÌÒÊ÷ÁÖÉî´¦µÄÐ¡µÀÉÏ£¬Ç°ÃæÓÐ¸öÀé°ÊÃÅ(fence)¡£
LONG
	);
	set("outdoors", "wudang");
	
	
	set("item_desc",([
		"fence"	:	"\n\t\t\tÀé°ÊÃÅÉÏÓÐÊ×Ê«£º\n\n\n" 
					"\t\t¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡Ó¦¡¡Á¯¡¡åì¡¡³Ý¡¡Ó¡¡¡²Ô¡¡Ì¦¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡Ð¡¡¡¿Û¡¡²ñ¡¡ìé¡¡¾Ã¡¡²»¡¡¿ª¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡´º¡¡É«¡¡Âú¡¡Ô°¡¡¹Ø¡¡²»¡¡×¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡Ò»¡¡Ö¦¡¡ºì¡¡ÐÓ¡¡³ö¡¡Ç½¡¡À´¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡¡Ë¡Ë¡Ë\n"
					"\t\t¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë¡Ë\n\n\n",
							
		]));


	set("exits", ([
		"south" : __DIR__"tyroad10",
	]));

	set("cost", 2);
	setup();
}
