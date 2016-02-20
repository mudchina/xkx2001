//Cracked by Roath
//Jay 9/30/96

inherit ROOM;

void create()
{
        set("short", "小树林");
	set("long", @LONG
这是峨嵋山金顶华藏庵外的一片小树林。林中没有路，但地上依稀有些足
迹，似乎刚有人走过。
LONG);
	set("exits", ([
		"southeast" : __DIR__"hztrip4",
		"north": __DIR__"hztrip2",
	]));

        set("outdoors", "emei" );

	set("cost", 2);
	setup();
        replace_program(ROOM);

}

