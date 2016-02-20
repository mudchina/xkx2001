//Cracked by Roath
//GU MU FROM SANTA
//SHULIN1.C

inherit ROOM;

void create()
{
	set("short", "树林");
	set("long", @LONG
你来到了终南山后山的这片树林。光线有点儿暗，
但还看得见。动听的鸟鸣，扑鼻的花香，让你几乎
以为是到了仙境。前方嗡嗡的传来一阵响动，不知
是什么东西。
LONG
	);

	set("exits", ([
		"south" : __DIR__"shulin2",
		"out"	  : __DIR__"houshan",	
	]));
	set("cost", 1);

	setup();
	replace_program(ROOM);
}



