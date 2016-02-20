//Cracked by Roath
// Room: /d/beijing/west/guanganmen.c

inherit ROOM;

void create()
{
	set("short", "广安门");
	set("long", @LONG
这是北京城外城五大城门中朝西向的城门--广安门，这里
的城墙相比显得略微破旧，守备也不如内城森严，但毕竟京畿
重地，气度不凡；守军又是全国精兵，训练有素，比之一般戍
卒，不仅装备精良得多，气势也胜上一筹。
LONG
	);
	set("exits", ([ /* sizeof() == 2 */
  "up" : __DIR__"guanganmenlou",
  "east" : __DIR__"guangandajie",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
