//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "雨花院");
        set("long", @LONG
这是一个独立的小院，院中绿油油的生了几簇青竹，地下用彩色圆石铺出一
条小径。脚下踏踏而行，碎石红绿相杂，恰似雨后彩虹一般。
LONG
        );
      set("exits", ([
		"east" : __DIR__"tianls9.c",
        "eastup" : __DIR__"tianls10",
		]));
set("no_clean_up", 0);
        set("cost", 3);

setup();
}

