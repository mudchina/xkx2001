//Cracked by Roath
inherit ROOM;

void create()
{
  set ("short", "石窟");
  set ("long", @LONG
这是最宽敞一间石窟，里面各种塑像、浮雕众多，其中多以真人为模，莫
不栩栩如生。宁静温和的佛、丰满健美的菩萨、仪态威武的天王、壮健有力的
武士，衬着瑰丽的壁画和典雅的建筑，互相依存、互相辉影，成为动静和谐统
一的整体，展示了无穷深远的意境。
LONG);
set("exits", ([
  "west" : __DIR__"dtongdao5",
]));
  replace_program(ROOM);
	set("cost", 2);
  setup();
}

