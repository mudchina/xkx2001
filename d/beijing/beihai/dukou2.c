//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "渡口");
	set("long", @LONG
这里是一座渡口，专门负责摆渡游客离开琼岛去湖北面的。渡口是用结实的
木料建造的，还铺上了一层垫子。渡船也是很新的双层游船，坐起来稳稳当当的。
两个船家分别坐在船头很船尾，随时准备开船了。
LONG
	);
	set("cost", 2);
  
	set("exits", ([
                "southwest" : __DIR__"yilan",
                ]));
	
	
	setup();
	replace_program(ROOM);
}