//Cracked by Roath
// Room: /d/shaolin/duchuan.c
// Date: YZC 96/01/19

inherit ROOM;




void create()
{
	set("short", "渡船");
	set("long", @LONG
离岸渐远，四望空阔，真是莫知天地之在湖海，抑惑是湖海之
在天地。
LONG
	);


	set("outdoors", "shaolin");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



