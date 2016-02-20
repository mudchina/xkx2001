//Cracked by Roath
// road: /zhongnan/haodian.c

#include <ansi.h>
#include <room.h>

inherit ROOM;

void create()
{
        set("short", HIB"重阳宫後殿"NOR);

        set("long",@LONG
	这重阳後殿布置的干净朴素，但也不失其庄严肃穆的气氛。弟子们
静静的走来走去，没人在此逗留，只有殿角一个小道僮在那ㄦ扫地。两旁的
烛架上点了十馀枝巨烛，不时发出啵啵声。一幅字(zi)挂在当眼处。往南走
是重阳宫大殿，北面有一扇小门。
LONG);

		  set("item_desc",(["zi" : "

		金 过 先 大
		锁 膝 从 道  全
		关 徐 涌 初  真
		穿 徐 泉 修  大
		下 至 脚 通  道
		鹊 尾 底 九  歌
		桥 闾 冲 窍
		， ， ， ,
		重 泥 涌 九
		楼 丸 泉 窍
		十 顶 升 原
		二 上 起 在
		降 回 渐 尾
		宫 旋 至 闾
		室 急 膝 穴
		.  .  .  .

\n",]));

		set("exits",
				([	"southdown" : __DIR__"taijie",
					"north" : __DIR__"yuanneixiaojing7",
				]),
			  );

        set("objects", ([
					 CLASS_D("quanzhen") + "/ma" : 1,
		  ]));




	  set("cost",1);
	  create_door("north", "木门", "south", DOOR_CLOSED);

	 setup();

}
