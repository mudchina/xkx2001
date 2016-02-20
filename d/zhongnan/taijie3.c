//Cracked by Roath
// Room: /d/zhongnan/taijie3.c
// Date: sdong 07/23/98

inherit ROOM;


void create()
{
		  set("short", "台阶");
		  set("long", @LONG
青石台阶通向西边的一个宫殿。台阶上精工镂刻着麒麟，玄龟，松鹤等瑞兽，形态逼
真动人。再往前就是养心殿。东面有一条小路通往长春殿。
LONG
		  );

		  set("exits", ([
					 "westup" : __DIR__"yangxin",
					 "east" : __DIR__"zhoulang",
		  ]));

		  set("outdoors", "zhongnan");
		  set("objects",([
					 __DIR__"npc/zhang" : 1,
		  ]));
		  set("cost", 2);
		  setup();
}
int valid_leave(object me, string dir)
{
	 mapping myfam;
	 myfam = (mapping)me->query("family");


	 if (dir == "westup" && objectp(present("zhang zhiguang", environment(me)))) {
		  if ( !myfam || myfam["family_name"] != "全真教")
			  return notify_fail("张志光拦住说道：对不起，养心殿不对外开放！\n");
	 }

	 return ::valid_leave(me, dir);
}



