//Cracked by Roath
// Room: /d/xixia/weiwu.c

inherit ROOM;

void create()
{
	set("short", "威武");
	set("long", @LONG
武威是西夏国的西南重镇，驻有重兵，城楼高达三丈，门口有两排官兵正在
认真的盘查过往行人，城门口的告示上画着最近通缉的江洋大盗的图形，城里头
看上去还挺热闹。东南就是去永登的方向了，西南面就是祁连山脉。
LONG
	);
	set("cost", 2);
	set("outdoors", "xixia");
	set("exits", ([ /* sizeof() == 2 */
  "southeast" : __DIR__"wsling",
  "north" : __DIR__"tumenzi",
]));
	set("objects", ([
		__DIR__"npc/xxbing" : 3,
	]));
	setup();
	replace_program(ROOM);
}
