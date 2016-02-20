//Cracked by Roath
// Room: /d/beijing/zijincheng/maoqindian.c

inherit ROOM;

void create()
{
	set("short", "懋勤殿");
	set("long", @LONG
    这是内翰林官的值班处,御用图书,文具存在
此处.康熙皇帝曾在此读书。
    每年秋季,皇帝亲自审阅裁定一些刑部经办的
重大案件也在这里进行.
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "south" : __DIR__"pibenchu",
  "eastup" : __DIR__"qianqinggong",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
