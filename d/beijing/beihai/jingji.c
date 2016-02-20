//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "敬跻堂");
	set("long", @LONG
这里是承光殿北的敬跻堂，阔十五间，缘城墙成环抱之势。临窗眺望，
可以一览北海南面的风光。堂内整齐的放着几把檀木椅子。中间是一张八
仙桌。虽然不经常有人来坐，却仍然被打扫的一尘不染。
LONG
	);
	set("cost", 2);
        
	 
	set("exits", ([
                "south" : __DIR__"chengguang",
        ]));
	
	
	setup();
	replace_program(ROOM);
}

