//Cracked by Roath
// d/emei/jiulao_out.c 九老洞外
// xbc: 96/02/02

inherit ROOM;

void create()
{
        set("short", "小山坡");
	set("long", @LONG
眼前豁然一亮，原来是九老洞外的一个小山坡。山坡上杂草丛生，风很大，
刮得树枝乱摇。一棵古树下放着几个骷髅，上面都插了五个手指洞，看起来阴
森森的。
LONG
	);

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


