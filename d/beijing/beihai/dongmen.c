//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "东门");
	set("long", @LONG
这里是北海的东门，木制的门框被漆成了大红色。虽然经过长期的雨打风吹，
颜色却仍旧十分鲜艳。看的出是有人专门维护的。门上没有显著的标志，但门口
站着几个卫士在聊天。
LONG
	);
	set("cost", 2);
	set("exits", ([
                "south" : __DIR__"shulin",
                "northeast" : __DIR__"huafang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
