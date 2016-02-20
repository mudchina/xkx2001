//Cracked by Roath
// Room: /d/xiangyang/bingyi.c

inherit ROOM;

void create()
{
	set("short", "精忠堂");
	set("long", @LONG
正厅中东西各有两根楹柱，正墙上悬挂一个额匾，写着岳武穆所书的“还我
河山”四个大字。岳飞镇守襄阳期间，常於此处讨议军情。这时屋坐着不少人
，为首一名全身披挂的中年武人正蹙眉看著桌上横放的地图(ditu)。一旁众人却
是大气不敢吭一声，生怕打乱了那武人的思绪。
LONG
	);
	set("no_clean_up", 0);
        set("coordinates", ([ "x" : -2, "y" : -4 ]) );
	set("exits", ([ /* sizeof() == 3 */
  "north" : __DIR__"lianwuc",
  "west" : __DIR__"ceting",
  "out" : __DIR__"ysfdamen",
]));
	set("item_desc", ([
		"ditu" : "地图横摆在桌上，你看得不清楚，依稀瞧见上面有些圈圈点点。\n",
	]));
        set("objects", ([
               __DIR__"npc/menggong" : 1, 
        ]));
	setup();
	replace_program(ROOM);
}

