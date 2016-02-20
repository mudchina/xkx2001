//Cracked by Roath
// Jay 10/11/96

inherit ROOM;

void create()
{
        set("short", "黄土高原");
        set("long", @LONG
黄河像一把厉刃将黄土高原切开。无数条小溪流夹带着泥沙
汇入黄河，形成千沟万壑。沟壑之间的一块块平地叫做台塬。
LONG
        );

        set("exits", ([
		"southwest" : __DIR__"huanghe",
		"northeast" : __DIR__"hetao",
        ]));

	set("outdoors", "huanghe");
	set("cost", 3);
        setup();
	replace_program(ROOM);
}

