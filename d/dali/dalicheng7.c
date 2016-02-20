//Cracked by Roath
// Room: /d/dali/dalicheng7.c

inherit ROOM;

void create()
{
	set("short", "石铺");
	set("long", @LONG
大理地段有一山石以其天然的花纹而闻名天下，那便是大名鼎鼎的大理石。
用大理石中的水墨花石制作的画屏，其奇妙程度，使人叹为观止。唐宋时代，许
多官商将儒都喜好以大理石作家居摆设。石铺里人头济济，敲打钻磨之声不绝于
耳。一个白族老头光着膀子，来回踱着小步，指导着新伙计。
LONG);
	set("objects", ([
		__DIR__"npc/shijiang" : 1,
		]));
	set("exits", ([
		"west" : __DIR__"dalicheng5",
		]));
	set("cost", 1);
	set("no_clean_up", 0);
	setup();
	replace_program(ROOM);
}
