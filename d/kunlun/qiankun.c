//Cracked by Roath
// Room: /d/mingjiao/qiankun.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "乾坤坊");
	set("long", @LONG
此处立一不大不小的石做牌坊，上刻一匾，书篆体“乾坤”二字。东
边可见一座大殿，向西是一条昏暗的走廊，过了此坊再往北上就到了明教
光明顶的中央大广场。
LONG
	);
	set("exits", ([ /* sizeof() == 4 */
  "northup" : __DIR__"shijie77",
  "southdown" : __DIR__"shijie51",
  "west" : __DIR__"zoulang46",
  "east" : __DIR__"dashidian",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
