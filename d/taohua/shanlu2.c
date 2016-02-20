//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "山路");
	set("long", @LONG
山路走到这里已非常陡峭，山路也东弯西曲，盘旋往复，好不怪异，每走几步都
要费不少力气。抬头望去，上面已是峰顶。
LONG
	);
	 set("exits", ([
                "southdown" : __DIR__"shanlu1",
                "northup" : __DIR__"tzfeng",
        ]));
	set("cost", 4);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
