//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "西门");
	set("long", @LONG
这里是北海的西门，木制的门框被漆成了大红色。虽然经过长期的雨打风
吹，颜色却仍旧十分鲜艳。看的出是有人专门维护的。门上没有显著的标志，
但门口站着几个卫士在聊天。东面远远可以看见团城上飘扬的旗帜。
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "north" : __DIR__"xiaolu1",
                "east" : __DIR__"yanxiang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
