//Cracked by Roath
// Room: /city/xiangnanjie.c
// YZC 1996/11/13 

inherit ROOM;

void create()
{
	set("short", "象南街");
	set("long", @LONG
南面有一家店铺，店铺墙上挂了一面白色的招牌，上面写着‘米铺’两个红
色大字。一来到便可看见许多老百姓正围着南面的一家店铺高声叫嚷。东北面是
一条小路，向北就可以进入老乡的住宅。
LONG
	);
        set("outdoors", "city");

	set("exits", ([
		"west" : __DIR__"dongnanjie",
		"south" : __DIR__"mipu",
		"north" : __DIR__ "minwu1",
		"northeast" : __DIR__ "xiaotulu",
	]));

        set("objects", ([
        ]));

	set("cost", 1);
	setup();
	replace_program(ROOM);
}

