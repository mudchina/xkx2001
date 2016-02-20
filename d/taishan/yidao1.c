//Cracked by Roath
// Room: /d/shaolin/yidao1.c
// Date: YZC 96/01/19

inherit ROOM;

void create()
{
	set("short", "大驿道");
	set("long", @LONG
你走在一条尘土飞扬的大驿道上。四周人来人往。挑担子的行商，赶着大车
的马夫，上京赶考的书生，熙熙攘攘，非常热闹。不时还有两三骑快马从身边飞
驰而过，扬起一路尘埃。马上的人个个身着劲装，衣甲鲜明，有的还随身佩带着
刀剑。看来都是些些习武的江湖人。道路两旁是整整齐齐的杨树林。
LONG
	);

	set("exits", ([
		"west" : __DIR__"yidao",
		"northeast" : __DIR__"yidao2",
	]));

	set("objects",([
		__DIR__"npc/tangzi" : 2,
              //   "/clone/npc/zuo" : 1,
	]));

	set("outdoors", "taishan");
	set("cost", 2);
	setup();
	replace_program(ROOM);
}



