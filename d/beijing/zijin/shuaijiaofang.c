//Cracked by Roath
// Room: /d/beijing/zijincheng/shuaijiaofang.c

inherit ROOM;

void create()
{
	set("short", "摔跤房");
	set("long", @LONG
屋子里空空洞洞，墙壁边倚着几个牛皮制的人形，梁上垂下来几
只大布袋，里面似乎装着米麦或是沙土。正中一张桌子，上面放了十
来碟点心。
LONG
	);
	set("exits", ([ /* sizeof() == 1 */
  "southwest" : __DIR__"neizuomen",
]));
	set("no_clean_up", 0);

	setup();
	replace_program(ROOM);
}
