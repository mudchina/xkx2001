//Cracked by Roath
// d/emei/jiulao_out.c 九老洞外
// xbc: 96/02/02
// 18th-Aug-2000: modified by yasuko
inherit ROOM;

void create()
{
        set("short", "小山坡");
	set("long", @LONG
眼前豁然一亮，原来是九老洞外的一个小山坡。山坡上种满了花草，不远
处是一间很简陋的小屋子。小屋旁有棵参天的大古树。古树的周围整整齐齐地
排列着几个小坟堆，坟前点着香烛，终年不断。
LONG);
        set("exits", ([
                "north" : __DIR__"jiulao1",
        ]));
        set("objects",([
		"/kungfu/class/emei/zhou.c" :1,
        ]));
	set("invalid_startroom", 1);
	set("outdoors", "emei" );
	set("cost", 1);
	setup();
}
