//Cracked by Kafei
inherit ROOM;

void create()
{
        set("short", "瑞鹤门");
        set("long", @LONG
这里是天龙寺的入口，迎面两根大汉白玉石柱，上面是巧手匠人所刻的
龟鹤延年图纹。脚下一条青石大路，正是通向东首的幌天门。
LONG
        );
        set("no_clean_up", 0);
        set("cost", 2);

        set("exits", ([
		"eastup" : __DIR__"tianls3.c",
        "out" : __DIR__"tianls13.c",		]));
setup();
replace_program(ROOM);
}

