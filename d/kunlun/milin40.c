//Cracked by Roath
// Room: /d/mingjiao/milin40.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "密林");
	set("long", @LONG
林深处，参天巨松结根盘骨，错干攀枝，偶有几线光亮渗进，更显万
般豪姿雄态。不远处，时时传来声声巨木旗弟子们昂扬的号令，又使这古
老的密林平添了几分不可言语的威严。
LONG	);
	set("exits", ([ /* sizeof() == 1 */
  "south" : __DIR__"mguangchang",
]));
	set("objects", ([
		__DIR__"obj/pine" : 2,
	]));
	set("cost", 2);

	setup();
	replace_program(ROOM);
}
