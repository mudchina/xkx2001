//Cracked by Roath
// yelin 野林
// Ssy

inherit __DIR__"no_pk_room";

void create()
{
    	set("short", "野林");
    	set("long", @LONG
一片阴森森的野林，不知通向何方。偶然有几只乌鸦飞过，凄凉
地叫几声．你不由得只想尽快走出这片野林。
LONG
    	);

    	set("exits", ([
		       "northup": __DIR__"shanding",
		       "east" : __DIR__"yelin",
		       "west" : __DIR__"yelin",
		       "south" : __DIR__"haidaowo",
		       ]));
    	set("outdoors", "xiakedao");
        set("objects", ([ 
                         __DIR__ + "npc/wuya" : 2,
                         ]));

    	setup();
}


