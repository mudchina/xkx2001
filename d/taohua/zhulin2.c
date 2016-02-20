//Cracked by Roath
//Chaos, Ryu, 3/10/97

inherit ROOM;

void create()
{
	set("short", "绿竹林");
	set("long", @LONG
竹林全是由绿色方竹构成，林内有座竹枝搭成的凉亭，亭上横额写着“积翠亭”
三字。亭中竹几竹椅全是多年之物，用得润了，现出淡淡黄光。竹亭之侧并肩生着两
棵大树，枝干虬盘，只怕已是数百年的古树。苍桦翠竹，清幽无比。
LONG
	);
	 set("exits", ([
                "east" : __DIR__"zhulin3",
                "south" : __DIR__"zhulin",
        ]));
	set("cost", 2);
	set("outdoors", "taohua");

	setup();
	replace_program(ROOM);
}
