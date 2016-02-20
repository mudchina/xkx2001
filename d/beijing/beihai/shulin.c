//Cracked by Roath
//dlc

inherit ROOM;

void create()
{
	set("short", "小树林");
	set("long", @LONG
这是湖边一片小松树林，面积并不大。林中有一条小径蜿蜒曲折向西延伸开去。
穿过这片松林就可以看见北海的前大门了。
LONG
	);
	set("cost", 2);
	 
	set("exits", ([
                "west" : __DIR__"qianmen",
                "north" : __DIR__"dongmen",
        ]));
	
	setup();
	replace_program(ROOM);
}
