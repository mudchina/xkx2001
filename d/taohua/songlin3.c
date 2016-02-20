//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "松柏林");
	set("long", @LONG
这座松柏林每株树木之间错落有致，枝条交互掩映，抬头望去，松针柏叶密密重
重，遮云蔽日，但林中却光线充足，纤毫毕现。真不知是天然生就，还是妙手偶得。
林中一条小径斗折蛇行，指向北方。东北面似乎有一排竹林。
LONG
	);
	 set("exits", ([
                "north" : __DIR__"hanbi",
                "south" : __DIR__"songlin2",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
