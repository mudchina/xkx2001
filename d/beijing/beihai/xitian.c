//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "西天梵境");
	set("long", @LONG
清朝时建的宗教建筑，主要是喇嘛教庙的样式。附近还有小西天、阐福寺、
大西天、极乐世界等。由这里向南就是去琼华岛的渡口。
LONG
	);
	set("cost", 2);
	
	set("exits", ([
                "west" : __DIR__"jiulongbi",
                "southwest" : __DIR__"dukou1",
                "northeast" : __DIR__"jingqing",
        ]));
	
	
	setup();
	replace_program(ROOM);
}
