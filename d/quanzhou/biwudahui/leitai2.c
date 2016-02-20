//Cracked by Roath
// /d/quanzhou/leitai2.c 擂台一角
// Shan: 96/06/22

inherit ROOM;

void create()
{
        set("short", "擂台一角");
	set("long", @LONG
这是擂台东面的一块空地。小摊贩们在此摆摊售卖各种武器，膏药及
酒肉。有的摊上还放了大水桶，给江湖豪客们提供清水。一面新刷的墙上
满满的贴着大大小小的布告，许多都是关于近期在此举行的武林大会的张
贴。很多人围在墙前看着，一面看一面大声评论着。
LONG
	);
	set("exits", ([
		"west" : __DIR__"leitai",
		"southwest" : __DIR__"leitai_gate",
	]));

        set("objects",([
                __DIR__"npc/seller2" : 1,
        ]));

//        set("outdoors", "quanzhou" );

        set("valid_startroom", 1);
        set("resource/water", 1);
	set("no_fight", 1);
	set("cost", 0);
	setup();
//	replace_program(ROOM);
        "/clone/board/leitai_b"->foo();

}
int valid_leave(object me, string dir)
{
        if( dir=="west" && !wizardp(me) )
                return notify_fail("那里只有巫师才能进去。\n");
        return ::valid_leave(me, dir);
}

