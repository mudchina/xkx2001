//Cracked by Roath
// Room: /d/mingjiao/shuyuan.c
// Zhangchi 3/00

inherit ROOM;

void create()
{
	set("short", "书院");
	set("long", @LONG
室中布置得一尘不染，清洁非常。四壁陈挂几幅字画，岁月颇久，笔
法依是不俗。窗前有一书案，上面笔墨纸砚，无一不全。案旁炉中香烟未
歇，也不知焚得什么香，时闻一股奇馨，顿感心旷神怡。
LONG
);
	set("exits", ([ /* sizeof() == 1 */
  "west" : __DIR__"shijie51",
]));
	set("no_clean_up", 0);
	set("cost", 1);

	setup();
	replace_program(ROOM);
}
