//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "°ãÈôÌ¨");
        set("long", @LONG
ÕâÊÇÒ»×ù¹ÂÁæÁæµÄ¸ßÌ¨£¬Ì¨ÉÏ³ıÁË¼¸¸öÆÑÍÅÍâ¿Õ¿ÕÈçÒ°¡£¾İÎÅĞí¶à¸ßÉ®°®ÔÚ
´ËÚ¤Ë¼£¬ÒÔÇó½øÒ»²½µÄĞŞĞĞ¡£·½°¸ÉÏµÄÄÇ°ë²¿èó¾­£¬È´ÊÇÀ´×ÔÎ÷ÓòµÕäÆæÖ®Îï¡£
LONG
        );
       set("exits", ([
		"west" : __DIR__"tianls8.c",
        "east" : __DIR__"tianls7",
        "southeast" : __DIR__"tianls6",
        "northup" : __DIR__"tianls10",		]));

set("no_clean_up", 0);
        set("cost", 3);

setup();
}

