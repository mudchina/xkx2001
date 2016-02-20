//Cracked by Roath
// 草店 caodian.c
// xQin 11/00

inherit ROOM;


void create()
{
	set("short", "草店");
	set("long", @LONG
这是黄土路旁的一间草店。这里四周昏暗，布置十分简陋。草店外的黄
土路正好是一条三岔路，往东南是佛山，西北可通三不管，而西南则是上武
当山的路。店夥计正在一旁招呼路过打尖的客人。
LONG );

	set("outdoors", "wudang");
	set("exits", ([
		"east" : __DIR__"wdroad6",
		
		]));
	set("objects", ([
	"/d/wudang/npc/huoji" : 1,
	"/d/shaolin/obj/caoliao" : 2,
	
	]));
      setup();
      replace_program(ROOM);
}

