//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "休息室");
	set("long", @LONG
这是桃花岛弟子的休息室。几张木床整整齐齐的排列于屋角，茶几
花瓶中插着几枝疏密相间的新开桃花，散发出阵阵花香。地下纤尘不染，
看来是常常打扫。 
LONG
	);

        set("sleep_room", 1);
        set("no_fight", 1);

	 set("exits", ([
                "south" : __DIR__"changlang2",
        ]));
	setup();
	replace_program(ROOM);
}
